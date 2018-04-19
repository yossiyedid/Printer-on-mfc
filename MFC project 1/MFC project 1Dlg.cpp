
// MFC project 1Dlg.cpp : implementation file
//
#include  <afxdlgs.h>
#include "afx.h"
#include "stdafx.h"
#include "MFC project 1.h"
#include "MFC project 1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCproject1Dlg dialog

void HSVtoRGB(float& fR, float& fG, float& fB, float& fH, float& fS, float& fV) {
	float fC = fV * fS; // Chroma
	float fHPrime = fmod(fH / 60.0, 6);
	float fX = fC * (1 - fabs(fmod(fHPrime, 2) - 1));
	float fM = fV - fC;

	if (0 <= fHPrime && fHPrime < 1) {
		fR = fC;
		fG = fX;
		fB = 0;
	}
	else if (1 <= fHPrime && fHPrime < 2) {
		fR = fX;
		fG = fC;
		fB = 0;
	}
	else if (2 <= fHPrime && fHPrime < 3) {
		fR = 0;
		fG = fC;
		fB = fX;
	}
	else if (3 <= fHPrime && fHPrime < 4) {
		fR = 0;
		fG = fX;
		fB = fC;
	}
	else if (4 <= fHPrime && fHPrime < 5) {
		fR = fX;
		fG = 0;
		fB = fC;
	}
	else if (5 <= fHPrime && fHPrime < 6) {
		fR = fC;
		fG = 0;
		fB = fX;
	}
	else {
		fR = 0;
		fG = 0;
		fB = 0;
	}

	fR += fM;
	fG += fM;
	fB += fM;
}


CMFCproject1Dlg::CMFCproject1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCPROJECT1_DIALOG, pParent), isPressed(false)
	, Fillpressed(false)
	, DeleteBotton(false),
	mythickness(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	futureFigKIND = RECTANGLE;		//defualt shape on init
	curColor = RGB(0, 110, 150);   //defualt color on init
	m_XP = 0.0;
	m_YP = 0.0;
	
}

void CMFCproject1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER1, mythickness);
	DDV_MinMaxInt(pDX, mythickness, 1, 25);
	DDX_Text(pDX, IDC_STATIC_xCord, m_XP);
	DDX_Text(pDX, IDC_STATIC_yCord, m_YP);


}

BEGIN_MESSAGE_MAP(CMFCproject1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CMFCproject1Dlg::OnBnClickedCancel)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CMFCproject1Dlg::OnNMCustomdrawSlider1)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCproject1Dlg::OnBnClickedRadio1)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO2, &CMFCproject1Dlg::OnBnClickedRadio2)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()

ON_WM_MBUTTONDOWN()
ON_WM_HSCROLL()
ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER1, &CMFCproject1Dlg::OnTRBNThumbPosChangingSlider1)
ON_BN_CLICKED(IDC_RADIO3, &CMFCproject1Dlg::OnBnClickedRadio3)
ON_BN_CLICKED(IDC_RADIO4, &CMFCproject1Dlg::OnBnClickedRadio4)
ON_WM_CTLCOLOR()
ON_BN_CLICKED(IDC_BUTTON1, &CMFCproject1Dlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CMFCproject1Dlg::OnBnClickedButton2)

ON_BN_CLICKED(IDC_BUTTON4, &CMFCproject1Dlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON5, &CMFCproject1Dlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON7, &CMFCproject1Dlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON6, &CMFCproject1Dlg::OnBnClickedButton6)
ON_WM_RBUTTONDOWN()


ON_BN_CLICKED(IDC_BUTTON3, &CMFCproject1Dlg::OnBnClickedButtonNewPage)
END_MESSAGE_MAP()

static int Memory = 0;
// CMFCproject1Dlg message handlers

BOOL CMFCproject1Dlg::OnInitDialog()
{
	
	CDialogEx::OnInitDialog();

	//{
	//	CButton* pBtn = (CButton*)GetDlgItem(IDC_BUTTON6);
	//	pBtn->ModifyStyle(0, BS_ICON);
	//	HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR); // Redo Icon
	//	pBtn->SetIcon(hIcn);
	//}

	{
		CButton* pBtn = (CButton*)GetDlgItem(IDCANCEL);
		pBtn->ModifyStyle(0, BS_ICON);
		HICON hIcn = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON4), IMAGE_ICON, 60, 60, LR_DEFAULTCOLOR); // exit icon
		pBtn->SetIcon(hIcn);
	}

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

									//x1046 y573
									//141 61
	// TODO: Add extra initialization here
	r.left = 141;							//invalidation box 
	r.top = 61;
	r.right = 1046;
	r.bottom = 573;
	

	BGColorB.CreateSolidBrush(RGB(255, 255, 255));          //def white beckground
	CSliderCtrl *s = (CSliderCtrl *)GetDlgItem(IDC_SLIDER1); // NUDELMAN COMMENT
	s->EnableWindow(false);						//only if LINE RADIO is selected - slider is now in GREY
	s->SetPos(1);
	s->SetRangeMax(25);
	s->SetRangeMin(1);
	CheckRadioButton(IDC_RADIO1, IDC_RADIO4 , IDC_RADIO1);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCproject1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCproject1Dlg::OnPaint()
{

	CPaintDC dc(this);
	for (int i = 0; i < myShapes.GetSize(); ++i)
		myShapes[i]->Draw(&dc);


	CBrush brush(curColor);
	CPen pen(PS_SOLID, mythickness,curColor);				//mythickness change the pen thick
	CBrush *old = dc.SelectObject(&brush);
	CPen *oldP = dc.SelectObject(&pen);
	
	UpdateData(true);						//update the data for thick scale ! MUST !


	CRect rect;
	GetClientRect(&rect);

	float r, g, b, s, v;
	s = 1;v = 1;
	for (float h = 0;h<359;h++)						//NUDELMAN PALET
	{
		HSVtoRGB(r, g, b, h, s, v);
		for (int j = 0;j<50;j++)
			dc.SetPixel(rect.right - h, rect.top + j, RGB(r * 255, g * 255, b * 255));
	}

	dc.SelectObject(old);
	dc.SelectObject(oldP);
	CDialogEx::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCproject1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCproject1Dlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CMFCproject1Dlg::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	

	
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void CMFCproject1Dlg::OnBnClickedRadio1()
{
	futureFigKIND = RECTANGLE;
	CSliderCtrl *s = (CSliderCtrl *)GetDlgItem(IDC_SLIDER1);
	s->EnableWindow(false);
	// TODO: Add your control notification handler code here
}

//x1046 y573
//141 61
void CMFCproject1Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CPaintDC dc(this);
	UpdateData(true);
	m_XP = point.x;
	m_YP = point.y;
	UpdateData(false);

	if (isPressed)
	{
		if (point.x < r.left)
			point.x = r.left;						//border check
		else if (point.x > r.right)
			point.x = r.right;
		if (point.y < r.top)
			point.y = r.top;
		else if (point.y > r.bottom)
			point.y = r.bottom;

				myShapes[myShapes.GetSize() - 1]->setEnd(point);
				
	}
	InvalidateRect(&r);
	CDialogEx::OnMouseMove(nFlags, point);


}


void CMFCproject1Dlg::OnBnClickedRadio2()
{
	futureFigKIND = ELLIPSE;
	CSliderCtrl *s = (CSliderCtrl *)GetDlgItem(IDC_SLIDER1);
	s->EnableWindow(false);
	// TODO: Add your control notification handler code here
}


void CMFCproject1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	isPressed = true;
	if (point.x < r.left)
		point.x = r.left;
	else if (point.x > r.right)
		point.x = r.right;							//border check
	if (point.y < r.top)
		point.y = r.top;
	else if (point.y > r.bottom)
		point.y = r.bottom;
	if (Fillpressed) // fill shape
	{
		
		for (int i = myShapes.GetSize() - 1; i >= 0; i--)    // START FROM THE END !! AND GET DOWN IN THE ARRAY
		{
			if (myShapes[i]->InShape(point))
			{
				command *c = new AddColor(myShapes[i], curColor);
				c->perform(); // change the color of this shape
				commands.push(c);
				break;
			}
		}
	}
	else
	{
		if (DeleteBotton) // delete shape
		{
			for (int i = myShapes.GetSize() - 1; i >= 0; i--)
			{
				if (myShapes[i]->InShape(point))				//check which shape we want to delete
				{
					command *c = new DeleteShape(myShapes, myShapes[i]);
					c->perform();
					commands.push(c);
					InvalidateRect(&r);
					break;
				}
			}
		}
		else
		{
			Figure *s = 0;				// create the shape the user pressed
			switch (futureFigKIND) 
			{
			case LINE: s = new myLine(); break;
			case RECTANGLE: s = new myRectangle(); break;
			case ELLIPSE: s = new myEllipse(); break;
			case TRAPEZE: s = new myTrapeze(); break;
			}
			command *c = new AddShape(myShapes, s);
			c->perform(); // add shape to the array
			commands.push(c);
			s->setBg(curColor);
			s->setP(curColor);
			s->setShapePenType(0);
			s->setShapePenSize(mythickness);
			s->setStart(point);
			s->setEnd(point);

		}
	}

	
				InvalidateRect(&r);

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCproject1Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	
	if (point.x < r.left)
		point.x = r.left;
	else if (point.x > r.right)
		point.x = r.right;							//border check
	if (point.y < r.top)
		point.y = r.top;
	else if (point.y > r.bottom)
		point.y = r.bottom;


	if (!Fillpressed && !DeleteBotton) // we done to draw - not move, fill or delete!
		myShapes[myShapes.GetSize() - 1]->setEnd(point);
	isPressed = false;

	Fillpressed = false;
	DeleteBotton = false;
	InvalidateRect(&r);
	CDialogEx::OnLButtonUp(nFlags, point);
	
	
}




void CMFCproject1Dlg::OnMButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	curColor = dc.GetPixel(point);


	CDialogEx::OnMButtonDown(nFlags, point);
}


void CMFCproject1Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{

	
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMFCproject1Dlg::OnTRBNThumbPosChangingSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// This feature requires Windows Vista or greater.
	// The symbol _WIN32_WINNT must be >= 0x0600.
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	// TODO: Add your control notification handler code here

	*pResult = 0;
}


void CMFCproject1Dlg::OnBnClickedRadio3()
{
	futureFigKIND = LINE;
	CSliderCtrl *s = (CSliderCtrl *)GetDlgItem(IDC_SLIDER1);
	s->EnableWindow(true);

}


HBRUSH CMFCproject1Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	
	HBRUSH hbr = BGColorB;
	return hbr;
}


void CMFCproject1Dlg::OnBnClickedButton1()
{
	if (!(commands.empty()))
	{
		command *c = commands.top();
		c->rollback();
		undoes.push(c);
		commands.pop();
	}
	InvalidateRect(&r);
	// TODO: Add your control notification handler code here
}


void CMFCproject1Dlg::OnBnClickedButton2()
{
	if (!(undoes.empty()))
{
	command *c = undoes.top();
	c->perform();
	commands.push(c);
	undoes.pop();
}
InvalidateRect(&r);
	// TODO: Add your control notification handler code here
}


void CMFCproject1Dlg::OnBnClickedButton4()
{

	try
	{
		CFile file(L"FILE.$$", CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		myShapes.Serialize(ar);
	}
	catch (...)
	{
	}

	InvalidateRect(&r);
	// TODO: Add your control notification handler code here
}


void CMFCproject1Dlg::OnBnClickedButton5()
{
	CFile file(L"FILE.$$", CFile::modeWrite | CFile::modeCreate);
	CArchive ar(&file, CArchive::store);
	myShapes.Serialize(ar);
	InvalidateRect(&r);
	// TODO: Add your control notification handler code here
}


void CMFCproject1Dlg::OnBnClickedButton7() // fill shape in some color
{
	Fillpressed = true;
	DeleteBotton = false;
}


void CMFCproject1Dlg::OnBnClickedButton6() //delete shape
{
	DeleteBotton = true;
	Fillpressed = false;
}


void CMFCproject1Dlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	for (int i = myShapes.GetSize() - 1; i >= 0; i--)
	{
		if (myShapes[i]->InShape(point))
		{
			command *c = new AddColor(myShapes[i], curColor);
			c->perform();
			commands.push(c);
			break;
		}
	}
	InvalidateRect(&r);  
	CDialogEx::OnRButtonDown(nFlags, point);
}


void CMFCproject1Dlg::OnBnClickedRadio4()
{
	futureFigKIND = TRAPEZE;
	CSliderCtrl *s = (CSliderCtrl *)GetDlgItem(IDC_SLIDER1);
	s->EnableWindow(false);
	// TODO: Add your control notification handler code here
}




void CMFCproject1Dlg::OnBnClickedButtonNewPage()
{
	myShapes.RemoveAll();

	while (!(undoes.empty()))
	{
		undoes.pop();
	}

	while (!(commands.empty()))
	{
		commands.pop();
	}

	InvalidateRect(&r);
	
}
