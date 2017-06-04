#include "stdafx.h"
#include "CEFV8HandlerEx.h"
#include <strsafe.h>

CCEFV8HandlerEx::CCEFV8HandlerEx()
{

}

CCEFV8HandlerEx::~CCEFV8HandlerEx()
{

	int a = 20;

}


bool CCEFV8HandlerEx::Execute(const CefString& name  /*JavaScript���õ�C++��������*/, CefRefPtr<CefV8Value> object /*JavaScript�����߶���*/, const CefV8ValueList& arguments /*JavaScript���ݵĲ���*/, CefRefPtr<CefV8Value>& retval /*���ظ�JS��ֵ���ø��������*/, CefString& exception/*֪ͨ�쳣��Ϣ��JavaScript*/)
{
	if (name == _T("jsInvokeCPlusPlus"))
	{
		if (arguments.size() == 2)
		{
			CefString strParam1 = arguments.at(0)->GetStringValue();
			CefString strParam2 = arguments.at(1)->GetStringValue();

			TCHAR szBuffer[512];
			StringCbPrintf(szBuffer, sizeof(szBuffer), _T("jsInvokeCPlusPlus(%s,%s)"), strParam1.c_str(), strParam2.c_str());
			::MessageBox(GetForegroundWindow(), szBuffer, _T("jsInvokeCPlusPlus"), MB_OK);

			////ִ��js����
			//CefRefPtr<CefBrowser> pBrower = pWKEWebkitCtrl_->GetBrowserByID(nBrowserID);
			//if (pBrower)
			//{
			//	pBrower->GetMainFrame().get()->ExecuteJavaScript("alert('ExecuteJavaScript succeed!');", pBrower->GetMainFrame().get()->GetURL(), 0);
			//}

			retval = CefV8Value::CreateInt(0);
		}
		else
		{
			retval = CefV8Value::CreateInt(2);
		}

		return true;

	}



	// Function does not exist.
	return false;


}