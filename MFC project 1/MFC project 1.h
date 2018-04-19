
// MFC project 1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCproject1App:
// See MFC project 1.cpp for the implementation of this class
//

class CMFCproject1App : public CWinApp
{
public:
	CMFCproject1App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCproject1App theApp;
