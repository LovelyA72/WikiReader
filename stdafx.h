// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
#define _CRT_SECURE_NO_DEPRECATE


#include <cef_client.h>
#include <cef_app.h>
#include <capi/cef_app_capi.h>

#include <sstream>
#include <string>

#include <base/cef_bind.h>
#include <wrapper/cef_closure_task.h>
#include <cef_app.h>
#include <cef_base.h>
#include <base/cef_lock.h>
#include <wrapper/cef_helpers.h>


// Windows ͷ�ļ�:
#include <windows.h>
#include <objbase.h>
#include <Commdlg.h>
// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
//
// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�


// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�

#include "DuiLib\UIlib.h"
#include "DuiLib\Ex\ShadowWindow.h"

using namespace DuiLib;
#ifdef _DEBUG
#   ifdef _UNICODE
#       pragma comment(lib, "lib\\DuiLib_ud.lib")
#   else
#      pragma comment(lib, "lib\\DuiLib_d.lib")
#   endif
#else
#   ifdef _UNICODE
#       pragma comment(lib, "lib\\DuiLib_u.lib")
#   else
#       pragma comment(lib, "lib\\DuiLib.lib")
#   endif
#endif


#define  UM_CEF_WEBLOADSTART			WM_USER+100
#define  UM_CEF_WEBLOADEND				WM_USER+101
#define  UM_CEF_WEBLOADPOPUP			WM_USER+102

#define  UM_CEF_WEBTITLECHANGE			WM_USER+104
#define  UM_CEF_AFTERCREATED			WM_USER+105
#define  UM_CEF_BROWSERCLOSE			WM_USER+106

#define UM_CEF_POSTQUITMESSAGE			WM_USER+107

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
