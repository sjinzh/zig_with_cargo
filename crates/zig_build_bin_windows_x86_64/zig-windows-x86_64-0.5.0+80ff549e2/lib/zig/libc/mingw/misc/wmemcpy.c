/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define __CRT__NO_INLINE
#include	<wchar.h>

#if 0
wchar_t *
wmemcpy(s1, s2, n)
	register wchar_t * __restrict__		s1;
	register const wchar_t * __restrict__	s2;
	register size_t					n;
{
	wchar_t						*orig_s1 = s1;

	if ( s1 == NULL || s2 == NULL || n == 0 )
		return orig_s1;		/* robust */

	for ( ; n > 0; --n )
		*s1++ = *s2++;

	return orig_s1;
}
#endif

wchar_t *__cdecl wmemcpy(wchar_t *_S1,const wchar_t *_S2,size_t _N)
{
	return (wchar_t *)memcpy(_S1,_S2,_N*sizeof(wchar_t));
}

