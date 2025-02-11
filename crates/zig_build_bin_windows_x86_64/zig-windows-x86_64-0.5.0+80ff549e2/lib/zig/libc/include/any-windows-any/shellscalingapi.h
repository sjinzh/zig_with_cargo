/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _SHELLSCALINGAPI_H_
#define _SHELLSCALINGAPI_H_

#include <shtypes.h>
#include <winapifamily.h>

#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#ifndef SCALING_ENUMS_DECLARED
typedef enum {
  SCF_VALUE_NONE = 0x00,
  SCF_SCALE = 0x01,
  SCF_PHYSICAL = 0x02
} SCALE_CHANGE_FLAGS;
DEFINE_ENUM_FLAG_OPERATORS(SCALE_CHANGE_FLAGS);

typedef enum {
  DEVICE_PRIMARY = 0,
  DEVICE_IMMERSIVE = 1
} DISPLAY_DEVICE_TYPE;

#define SCALING_ENUMS_DECLARED
#endif /* SCALING_ENUMS_DECLARED */

#if NTDDI_VERSION >= NTDDI_WIN8
STDAPI_(DEVICE_SCALE_FACTOR) GetScaleFactorForDevice(DISPLAY_DEVICE_TYPE deviceType);
STDAPI RegisterScaleChangeNotifications(DISPLAY_DEVICE_TYPE displayDevice, HWND hwndNotify, UINT uMsgNotify,
  DWORD *pdwCookie);
STDAPI RevokeScaleChangeNotifications(DISPLAY_DEVICE_TYPE displayDevice, DWORD dwCookie);
#endif /* NTDDI_VERSION >= NTDDI_WIN8 */

#ifndef DPI_ENUMS_DECLARED
typedef enum MONITOR_DPI_TYPE {
  MDT_EFFECTIVE_DPI = 0,
  MDT_ANGULAR_DPI = 1,
  MDT_RAW_DPI = 2,
  MDT_DEFAULT = MDT_EFFECTIVE_DPI
} MONITOR_DPI_TYPE;

typedef enum PROCESS_DPI_AWARENESS {
  PROCESS_DPI_UNAWARE = 0,
  PROCESS_SYSTEM_DPI_AWARE = 1,
  PROCESS_PER_MONITOR_DPI_AWARE = 2
} PROCESS_DPI_AWARENESS;

#define DPI_ENUMS_DECLARED
#endif /* DPI_ENUMS_DECLARED */

#if NTDDI_VERSION >= NTDDI_WINBLUE
STDAPI GetScaleFactorForMonitor(HMONITOR hMon, DEVICE_SCALE_FACTOR *pScale);
STDAPI RegisterScaleChangeEvent(HANDLE hEvent, DWORD_PTR *pdwCookie);
STDAPI UnregisterScaleChangeEvent(DWORD_PTR dwCookie);

STDAPI GetDpiForMonitor(HMONITOR hmonitor, MONITOR_DPI_TYPE dpiType, UINT *dpiX, UINT *dpiY);
STDAPI GetProcessDpiAwareness(HANDLE hprocess, PROCESS_DPI_AWARENESS *value);
STDAPI SetProcessDpiAwareness(PROCESS_DPI_AWARENESS value);
#endif /* NTDDI_VERSION >= NTDDI_WINBLUE */

#if NTDDI_VERSION >= NTDDI_WINTHRESHOLD
#ifndef SHELL_UI_COMPONENT_ENUMS_DECLARED
typedef enum {
  SHELL_UI_COMPONENT_TASKBARS = 0,
  SHELL_UI_COMPONENT_NOTIFICATIONAREA = 1,
  SHELL_UI_COMPONENT_DESKBAND = 2
} SHELL_UI_COMPONENT;

#define SHELL_UI_COMPONENT_ENUMS_DECLARED
#endif /* SHELL_UI_COMPONENT_ENUMS_DECLARED */

UINT WINAPI GetDpiForShellUIComponent(SHELL_UI_COMPONENT component);
#endif /* NTDDI_VERSION >= NTDDI_WINTHRESHOLD */

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#endif /* _SHELLSCALINGAPI_H_ */
