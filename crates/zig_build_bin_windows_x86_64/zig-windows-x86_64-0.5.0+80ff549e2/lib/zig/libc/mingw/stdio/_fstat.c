#define __CRT__NO_INLINE
#include <sys/stat.h>

/* FIXME: Relying on _USE_32BIT_TIME_T, which is a user-macro,
during CRT compilation is plainly broken.  Need an appropriate
implementation to provide users the ability of compiling the
CRT only with 32-bit time_t behavior. */
#if defined(_USE_32BIT_TIME_T)
int __cdecl
fstat(int _Desc,struct stat *_Stat)
{
  struct _stat32 st;
  int ret=_fstat32(_Desc,&st);
  if (ret == -1) {
    memset(_Stat,0,sizeof(struct stat));
    return -1;
  }
  /* struct stat and struct _stat32
     are the same for this case. */
  memcpy(_Stat, &st, sizeof(struct _stat32));
  return ret;
}
#else
int __cdecl
fstat(int _Desc,struct stat *_Stat)
{
  struct _stat64 st;
  int ret=_fstat64(_Desc,&st);
  if (ret == -1) {
    memset(_Stat,0,sizeof(struct stat));
    return -1;
  }
  /* struct stat and struct _stat64i32
     are the same for this case. */
  _Stat->st_dev=st.st_dev;
  _Stat->st_ino=st.st_ino;
  _Stat->st_mode=st.st_mode;
  _Stat->st_nlink=st.st_nlink;
  _Stat->st_uid=st.st_uid;
  _Stat->st_gid=st.st_gid;
  _Stat->st_rdev=st.st_rdev;
  _Stat->st_size=(_off_t) st.st_size;
  _Stat->st_atime=st.st_atime;
  _Stat->st_mtime=st.st_mtime;
  _Stat->st_ctime=st.st_ctime;
  return ret;
}
#endif

/* Add __imp__fstat and __imp__stat symbols.  */
int (*__MINGW_IMP_SYMBOL(fstat))(int, struct stat *) = &fstat;

