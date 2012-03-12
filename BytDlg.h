// BytDlg.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


// CBytDlgApp:
// See BytDlg.cpp for the implementation of this class
//

class CBytDlgApp : public CWinApp
{
public:
	CBytDlgApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CBytDlgApp theApp;