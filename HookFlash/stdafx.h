// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include <easyhook.h>

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����
// Windows ͷ�ļ�: 
#include <windows.h>
#include <tchar.h>
#include <iostream>


#if _WIN64
#pragma comment(lib, "EasyHook\\EasyHook64.lib")
#else
#pragma comment(lib, "EasyHook\\EasyHook32.lib")
#endif





// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
