
// MFC project 1Dlg.h : header file
//

#pragma once
#include "myTrapeze.h"
#include "DeleteShape.h"
#include "AddColor.h"
#include "command.h"
#include "Figure.h"
#include "AddShape.h"
#include "myLine.h"
#include "myRectangle.h"
#include "myEllipse.h"
#include "stdafx.h"
#include "MFC project 1.h"
#include "MFC project 1Dlg.h"
#include "afxdialogex.h"
#include <iostream>
#include "resource.h"
#include "afxbutton.h"
#include <stack>
#include <vector>
#include "afxwin.h"
using namespace std;

// CMFCproject1Dlg dialog
class CMFCproject1Dlg : public CDialogEx
{
	enum myShapess { RECTANGLE, ELLIPSE, LINE , TRAPEZE	};
	myShapess futureFigKIND;
	COLORREF curColor ;

	bool isPressed;
	CPoint start;
	CPoint end;
	CTypedPtrArray<CObArray, Figure*> myShapes;
	stack<command*> commands, undoes;
// Construction
public:
	CMFCproject1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	int mythickness;
	CBrush BGColorB;
	int MoveIndex;
	RECT r;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnTRBNThumbPosChangingSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRadio3();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();

	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton6();
	bool Fillpressed;
	bool DeleteBotton;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRadio4();
	double m_xPoint;
	double m_yPoint;
	double m_XP;
	double m_YP;

	

	afx_msg void OnBnClickedButtonNewPage();
};
