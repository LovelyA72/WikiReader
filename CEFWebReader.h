#pragma once

#include "resource.h"
#include "CEFWebkit.h"

class CEFWebReaderWnd : public WindowImplBase
{

public:
    CEFWebReaderWnd();
    ~CEFWebReaderWnd();


    virtual LPCTSTR GetWindowClassName() const      { return _T("CEFWebReaderWnd"); }
    virtual CDuiString GetSkinFile()                { return _T("UI.xml"); }
    virtual CDuiString GetSkinFolder()              { return _T("ReaderUI"); }
    virtual CControlUI* CreateControl(LPCTSTR pstrClass);
	virtual void OnFinalMessage(HWND hWnd);
	virtual LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	virtual	LRESULT OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	virtual void OnClick(TNotifyUI& msg) override;
    virtual void InitWindow();
    virtual void Notify(TNotifyUI& msg);
    virtual LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

public:
	void OnInitComplate();
	//标题栏发生改变
	void OnTitleChanged(int nWebBrowserID,const CefString str);
	//浏览器页创建成功
	void OnAfterCreate(int nWebBrowserID);
	//浏览器页关闭
	void OnBrowserClose(int nBrowserID);

	void OnWebLoadEnd(WPARAM wparam,LPARAM lparam);
	void OnWebLoadStart(WPARAM wParam, LPARAM lParam);
	COptionUI* GetActiveOption() const;

	void SwitchUIState();
	void SwitchProgressUIState();

public:
    static CEFWebReaderWnd* pCEFWebReaderWnd;
    
    wstring strURL_;
    wstring strTitle_;
    CCEFWebkitUI* pWKEWebkitCtrl_; 
	void Search_mainfunc(void);
private:
	CHorizontalLayoutUI*	pWebTabContainer_;
	CEditUI*				pSearchEditCtrl_;
	CButtonUI*				pSearchCtrl_;			
	CProgressUI*			pProgressCtrl_;
	CComboUI*				pSearchComboCtrl_;
	int Progress_state;
	bool DoSearch;

	class COptionTag
	{
	public:
		int nID_;
		COptionTag::COptionTag(int nID) :nID_(nID)
		{

		};
	};

	


};
