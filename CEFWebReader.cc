#include "stdafx.h"
#include "CEFWebReader.h"

// WKEWebkitBrowser.cpp : 定义应用程序的入口点。
//
#include "stdafx.h"
#include "CEFWebReader.h"
#include <strsafe.h>


#define 	E_GOFORWORD_TIMER  100
#define 	E_PROGRESS_TIMER  101
CEFWebReaderWnd* CEFWebReaderWnd::pCEFWebReaderWnd = NULL;

CEFWebReaderWnd::CEFWebReaderWnd()
{

	pSearchEditCtrl_ = NULL;
	pSearchCtrl_ = NULL;
	pWKEWebkitCtrl_ = NULL;
	pWebTabContainer_ = NULL;
	pProgressCtrl_ = NULL;
	Progress_state = 0;
	DoSearch = false;

	pCEFWebReaderWnd = this;

}

CEFWebReaderWnd::~CEFWebReaderWnd()
{

}


CControlUI* CEFWebReaderWnd::CreateControl(LPCTSTR pstrClassName)
{
	if (_tcsicmp(pstrClassName, _T("CEFWebReader")) == 0)
	{
		return  (pWKEWebkitCtrl_ = new CCEFWebkitUI(GetSafeHwnd()));
	}

	return NULL;
}

void CEFWebReaderWnd::OnFinalMessage(HWND hWnd)
{


	__super::OnFinalMessage(hWnd);
}

LRESULT CEFWebReaderWnd::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	::PostQuitMessage(0L);
	return __super::OnDestroy(uMsg, wParam, lParam, bHandled);
}

//截取WM_CLOSE消息
LRESULT CEFWebReaderWnd::OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
{

	if ((pWKEWebkitCtrl_ != NULL) && (!pWKEWebkitCtrl_->IsClosed()))
	{
		//pWKEWebkitCtrl_->CloseAllPage();
		bHandled = TRUE;
		//  Cancel the close.

	}
	else
	{
		bHandled = TRUE;
	}

	return 0;
}

void CEFWebReaderWnd::OnClick(TNotifyUI & msg)
{
	CDuiString strName = msg.pSender->GetName();

	if (_T("ui_btn_close") == strName)
	{
		if ((pWKEWebkitCtrl_ != NULL) && (!pWKEWebkitCtrl_->IsClosed()))
		{
			pWKEWebkitCtrl_->CloseAllPage();
			//pWKEWebkitCtrl_->clientHandler_->CloseAllBrowsers(false);
		}

	}

	__super::OnClick(msg);

}


void CEFWebReaderWnd::InitWindow()
{

	pSearchEditCtrl_ = dynamic_cast<CEditUI*>(FindControl(_T("ui_et_search")));
	pWebTabContainer_ = dynamic_cast<CHorizontalLayoutUI*>(FindControl(_T("ui_hl_urltabs")));
	pSearchCtrl_ = dynamic_cast<CButtonUI*>(FindControl(_T("ui_btn_search")));
	pProgressCtrl_ = static_cast<CProgressUI*>(FindControl(_T("ui_progress_load")));
	pSearchComboCtrl_= dynamic_cast<CComboUI*>(FindControl(_T("ui_combo_search")));

	if ( (!pWebTabContainer_) || (!pSearchCtrl_) || (!pSearchEditCtrl_) || (!pProgressCtrl_) || (!pSearchComboCtrl_))
	{
		MessageBox(GetSafeHwnd(), _T("控件初始化失败，检查界面"), _T("Err"), MB_OK);
		PostQuitMessage(0);
	}

}

void CEFWebReaderWnd::Search_mainfunc()
{
	CefRefPtr<CefBrowser> pBrower = pWKEWebkitCtrl_->clientHandler_->browser_list_[0];
	if (pBrower)
	{
		
		//pWKEWebkitCtrl_->NewPage(_T("file:///htmls/launch.html"));
		//MessageBox(GetSafeHwnd(), _T("es pBrower"), _T("OnClick"), MB_OK);
		//pBrower->GetMainFrame().get()->ExecuteJavaScript("alert('ExecuteJavaScript succeed!');", pBrower->GetMainFrame().get()->GetURL(), 0);
		//pBrower->GetMainFrame().get()->ExecuteJavaScript("window.location.href='http://www.baidu.com'", pBrower->GetMainFrame().get()->GetURL(), 0);
		//pBrower->GetMainFrame().get()->ExecuteJavaScript("Change_Func();", pBrower->GetMainFrame().get()->GetURL(), 0);
		//pBrower->GetMainFrame().get()->ExecuteJavaScript("$.ajax({url: '//www.yzwiki.com/api.php',data : { action: 'query', list : 'search', srsearch : 'A72', format : 'json' },dataType : 'json',success : function(x) {alert(x.query.search[0].title);}});", pBrower->GetMainFrame().get()->GetURL(), 0);
		//pBrower->GetMainFrame().get()->ExecuteJavaScript("var ajaxUrl = 'https://www.yzwiki.com/api.php?action=query&format=json&list=search&srsearch=A72&srlimit=10&srenablerewrites=1';$.ajax({type:'get',url:ajaxUrl,cache:false,dataType:'jsonp',jsonp:'jsonpCallback',jsonpCallback:'callback',success:function(returnData){alert(returnData);},error:function(){alert('error');}});", pBrower->GetMainFrame().get()->GetURL(), 0);

		//wstring cmd_str = _T("$.ajax({type: 'GET',url: 'https://www.yzwiki.com/api.php?',dataType : 'jsonp',data : { action: 'opensearch', search : '");
		//cmd_str += pSearchEditCtrl_->GetText().GetData();
		//cmd_str += _T("', format : 'json' },success : function(result) {alert(result[0]);},error : function(xhr, errorText) {alert('Error ' + xhr.responseText);}});");
		

		pBrower->GetMainFrame()->LoadURL(_T("file:///htmls/launch.html"));
		//pBrower->GetMainFrame().get()->ExecuteJavaScript("window.location.href='file:///htmls/launch.html'", pBrower->GetMainFrame().get()->GetURL(), 0);
		
		//pWKEWebkitCtrl_->clientHandler_->browser_list_[0]->Reload();
		

		DoSearch = true;

		//wstring cmd_str = _T("Search_Wiki_ajaxjsonp('");
		//cmd_str += pSearchEditCtrl_->GetText().GetData();
		//cmd_str += _T("');");


		//pBrower->GetMainFrame().get()->ExecuteJavaScript(cmd_str, pBrower->GetMainFrame().get()->GetURL(), 0);


		//pWKEWebkitCtrl_->NewPage(_T("https://www.yzwiki.com/item/API"));
	}
}

void CEFWebReaderWnd::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		if (msg.pSender->GetName() == _T("ui_btn_search"))
		{
			Search_mainfunc();
		


		}
		
	

	}
	//需要关闭richedit的want return属性
	 if (msg.sType == DUI_MSGTYPE_RETURN)
	{
		Search_mainfunc();
	}
	else if (msg.sType == _T("windowinit"))
	{
		OnInitComplate();
	}
	else if (msg.sType == DUI_MSGTYPE_TIMER)
	{
		if (msg.pSender == pWKEWebkitCtrl_)
		{
			if (msg.wParam == E_GOFORWORD_TIMER)
			{
				SwitchUIState();
				//MessageBox(GetSafeHwnd(), _T("123"), _T("222"), MB_OK);
			}
			else if (msg.wParam == E_PROGRESS_TIMER)
			{
				SwitchProgressUIState();
			}

		}

	}


	__super::Notify(msg);
}


LRESULT CEFWebReaderWnd::HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	//TCHAR szBuf[256];

	switch (uMsg)
	{

	case UM_CEF_POSTQUITMESSAGE:
		bHandled = TRUE;
		//Sleep(2000);
	//	CefQuitMessageLoop();
		PostQuitMessage(0L);
		break;
	case UM_CEF_WEBLOADPOPUP:
	{

		CefString* pStrComplateURL = (CefString*)lParam;
		if (pStrComplateURL != NULL)
		{
			pWKEWebkitCtrl_->NewPage(*pStrComplateURL);

			delete pStrComplateURL;
		}

	}
	break;
	case UM_CEF_WEBLOADEND:
	{
		OnWebLoadEnd(wParam, lParam);
	}
	break;

	case UM_CEF_WEBLOADSTART:
	{
		OnWebLoadStart(wParam, lParam);
	}
	break;
	case UM_CEF_WEBTITLECHANGE:
	{
		CefString* pStrComplateURL = (CefString*)lParam;
		if (pStrComplateURL != NULL)
		{
			OnTitleChanged(wParam, *pStrComplateURL);
			delete pStrComplateURL;
		}
	}
	break;
	case UM_CEF_AFTERCREATED:
	{
		OnAfterCreate(wParam);
	}
	break;
	case UM_CEF_BROWSERCLOSE:
	{
		OnBrowserClose(wParam);
	}
	break;
	default:
		break;
	}

	bHandled = FALSE;

	return 0;
}



void CEFWebReaderWnd::OnInitComplate()
{
	if (pWKEWebkitCtrl_)
	{
		//pWKEWebkitCtrl_->NewPage(_T("https://www.yzwiki.com/item/Main_Page"));
		//pWKEWebkitCtrl_->NewPage(_T("file:///htmls/index.html"));
		//pWKEWebkitCtrl_->NewPage(_T("https://www.yzwiki.com/item/API"));
		pWKEWebkitCtrl_->NewPage(_T("file:///htmls/launch.html"));
	}

	GetPaintManager()->SetTimer(pWKEWebkitCtrl_, E_GOFORWORD_TIMER, 500);
	GetPaintManager()->SetTimer(pWKEWebkitCtrl_, E_PROGRESS_TIMER, 20);

}


void CEFWebReaderWnd::OnTitleChanged(int nID, const CefString str)
{

	return;
}




void CEFWebReaderWnd::OnAfterCreate(int nWebBrowserID)
{
	// 创建标签OPTION按钮
	//CDuiString sAttr;
	COptionUI* pOpt = new COptionUI;
	//sAttr.Format(_T("name=\"webtab\" width=\"100\" height=\"30\" normalimage=\"tabbar_normal.png\" hotimage=\"tabbar_hover.png\" \
	//		pushedimage=\"tabbar_pushed.png\" selectedimage=\"tabbar_pushed.png\" group=\"ui_grp_webtab\""));
	//pOpt->ApplyAttributeList(sAttr);

	int iCount = pWebTabContainer_->GetCount();
	pWebTabContainer_->AddAt(pOpt, iCount - 1);

	// 把标签按钮和浏览器id关联起来
	COptionTag* pTag = new COptionTag(nWebBrowserID);

	pWKEWebkitCtrl_->ReFresh(pTag->nID_);

	//pOpt->SetTag((UINT_PTR)pTag);
	//pOpt->Selected(true);

}

void CEFWebReaderWnd::OnBrowserClose(int nBrowserID)
{
	TCHAR strDebugMsg[128];

	int nCountWebtab = pWebTabContainer_->GetCount();

	for (int idx = 0; idx < nCountWebtab; idx++)
	{

		COptionUI* pOpt = (COptionUI*)pWebTabContainer_->GetItemAt(idx);


		COptionTag* pTag = (COptionTag*)pOpt->GetTag();


		if ((pTag != NULL) && (pTag->nID_ == nBrowserID))
		{

			int nSize = pWebTabContainer_->GetCount();

			int nIdx = pWebTabContainer_->GetItemIndex(pOpt);

			pWebTabContainer_->Remove(pOpt);

			if (nIdx != -1)
			{

				if (nIdx == (nSize - 2))
				{
					--nIdx;
				}

				COptionUI* pShilfOption = dynamic_cast<COptionUI*>(pWebTabContainer_->GetItemAt(nIdx));
				COptionTag* pShilfTag = (COptionTag*)pShilfOption->GetTag();


				if ((pShilfOption) && (pShilfTag != NULL))
				{
					pWKEWebkitCtrl_->ReFresh(pShilfTag->nID_);
					//pURLEditCtrl_->SetText(pWKEWebkitCtrl_->GetFinalURL(pShilfTag->nID_).c_str());
					pShilfOption->Selected(true);

				}

			}

			break;
		}
	}

	StringCbPrintf(strDebugMsg, sizeof(strDebugMsg), _T("delete id=%d\n"), nBrowserID);
	OutputDebugString(strDebugMsg);

}

void CEFWebReaderWnd::OnWebLoadEnd(WPARAM wParam, LPARAM lParam)
{
	Progress_state = 2;

}

void CEFWebReaderWnd::OnWebLoadStart(WPARAM wParam, LPARAM lParam)
{
	Progress_state = 1;

}

COptionUI * CEFWebReaderWnd::GetActiveOption() const
{
	COptionUI* pCurrentOpt = NULL;
	int nCountWebtab = pWebTabContainer_->GetCount();

	for (int idx = 0; idx < nCountWebtab; idx++)
	{
		COptionUI* pOpt = (COptionUI*)pWebTabContainer_->GetItemAt(idx);

		if (pOpt->IsSelected())
		{
			pCurrentOpt = pOpt;
		}

	}

	return pCurrentOpt;
}

void CEFWebReaderWnd::SwitchUIState()
{
	if (DoSearch)
	{
		CefRefPtr<CefBrowser> pBrower = pWKEWebkitCtrl_->clientHandler_->browser_list_[0];
		if (pBrower)
		{
			int nsel = pSearchComboCtrl_->GetCurSel();
			CListLabelElementUI *pItemEle = (CListLabelElementUI *)pSearchComboCtrl_->GetItemAt(nsel);
			CDuiString strText = pItemEle->GetText().GetData();
			//if (wcscmp(strText, L" 常规")==0)strText = _T("");
			if (strText == _T(" 词条"))strText = _T("");
			if (strText == _T(" 用户"))strText = _T("User:");
			if (strText == _T(" 分类"))strText = _T("Category:");
			if (strText == _T(" 模板"))strText = _T("Template:");
			if (strText == _T(" 站务"))strText = _T("A72Wiki:");
			if (strText == _T(" 模拟器"))strText = _T("Emulator:");


			DoSearch = false;
			wstring cmd_str = _T("Search_Wiki_ajaxjsonp('");
			cmd_str += strText;
			cmd_str += pSearchEditCtrl_->GetText().GetData();
			cmd_str += _T("');");
			pBrower->GetMainFrame().get()->ExecuteJavaScript(cmd_str, pBrower->GetMainFrame().get()->GetURL(), 0);
		}
	}


}

void CEFWebReaderWnd::SwitchProgressUIState()
{
	if (Progress_state == 0)
	{
		pProgressCtrl_->SetValue(0);
	}
	else if (Progress_state == 1)
	{
		int c_pos = pProgressCtrl_->GetValue();
		if (c_pos < 95)
		{
			pProgressCtrl_->SetValue(c_pos + 1);
		}

	}
	else if (Progress_state == 2)
	{
		int c_pos = pProgressCtrl_->GetValue();
		if (c_pos < 95)c_pos = 95;
		if (c_pos < 100)
		{
			pProgressCtrl_->SetValue(c_pos + 1);
		}
		else Progress_state = 0;
	}

}
