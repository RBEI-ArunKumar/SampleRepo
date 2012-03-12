// BytDlgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BytDlg.h"
#include "BytDlgDlg.h"
#include ".\bytdlgdlg.h"
#include <Winsock2.h>
#include <string>
#include "CServicer.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CBytDlgDlg dialog



CBytDlgDlg::CBytDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBytDlgDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_oExlApplication = NULL;
}

void CBytDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBytDlgDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
END_MESSAGE_MAP()

//structures
struct SPGN
{
	BYTE by1:8;
	BYTE by2:8;
	BYTE by3:1;
	BYTE by4:1;
};

union PGN
{
	UINT unPGN:18;
	struct SPGN sPGN;
};

struct ST_ID
{
	BYTE bySrc:8;
	union PGN uPGN;
	BYTE byPriority:3;
};

union J19_ID
{
	UINT unID:29;
	struct ST_ID sID;
};	

struct BITS
{
	BYTE b1: 1;
	BYTE b2: 1;
	BYTE b3: 1;
	BYTE b4: 1;
	BYTE b5: 1;
	BYTE b6: 1;
	BYTE b7: 1;
	BYTE b8: 1;
	BYTE b9: 1;
	BYTE b10: 1;
	BYTE b11: 1;
	BYTE b12: 1;
	BYTE b13: 1;
	BYTE b14: 1;
	BYTE b15: 1;
	BYTE b16: 1;
	BYTE b17: 1;
	BYTE b18: 1;
	BYTE b19: 1;
	BYTE b20: 1;
	BYTE b21: 1;
	BYTE b22: 1;
	BYTE b23: 1;
	BYTE b24: 1;
	BYTE b25: 1;
	BYTE b26: 1;
	BYTE b27: 1;
	BYTE b28: 1;
	BYTE b29: 1;
};

// Stop watch class.
class CStopWatch
{
public:
    // Constructor.
    CStopWatch()
    {
        // Ticks per second.
        QueryPerformanceFrequency( &liPerfFreq );
    }

    // Start counter.
    void Start()
    {
        liStart.QuadPart = 0;
        QueryPerformanceCounter( &liStart );
    }

    // Stop counter.
    void Stop()
    {
        liEnd.QuadPart = 0;
        QueryPerformanceCounter( &liEnd );
    }

    // Get duration.
    long double GetDuration()
    {
        return ( liEnd.QuadPart - liStart.QuadPart) /
                long double( liPerfFreq.QuadPart );
    }

private:
    LARGE_INTEGER liStart;
    LARGE_INTEGER liEnd;
    LARGE_INTEGER liPerfFreq;
};


// CBytDlgDlg message handlers

BOOL CBytDlgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

		// The file, which is to be hidden.
	CString csFile = _T("D:\\ppapp1.pdf");

	// Hide the file.
	::SetFileAttributes( csFile, FILE_ATTRIBUTE_ENCRYPTED );

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

	// TODO: Add extra initialization here
	if(m_oExlApplication == NULL)
	{
		if(!m_oExlApplication.CreateDispatch("Excel.Application"))
		{	
			MessageBox(_T("EXCEL NOT FOUND"),MB_OK);			
		}
		else
		{
			USES_CONVERSION;
			VARIANT var;
			CString strExp;
			double dblResult;
			strExp = _T("5*(0.1+10)");
			string tExp;
			tExp = strExp.GetBuffer();
			VariantInit(&var);
			var.vt  = VT_BSTR;
			var.bstrVal = SysAllocString(A2W(tExp.c_str() )); 
			var = m_oExlApplication.Evaluate(var);			
			
			if(var.vt!= VT_ERROR)
			{
				dblResult = var.dblVal; 
				CString strResult;
				strResult.Format(_T("Result = %lf"), dblResult);
				//AfxMessageBox(strResult);
			}
			else
				AfxMessageBox(_T("Error evaluating the formula"));
		}
	}

	union J19_ID objJ19ID;
	BITS b;	
	
	objJ19ID.unID = 255;
	b = * (BITS*) (&objJ19ID);
	objJ19ID.sID.bySrc = 128;
	b = * (BITS*) (&objJ19ID);
	objJ19ID.sID.byPriority = 7;	
	b = * (BITS*) (&objJ19ID);
	objJ19ID.sID.uPGN.unPGN = 262144;
	b = * (BITS*) (&objJ19ID);
	objJ19ID.sID.uPGN.sPGN.by1 = 255;
	b = * (BITS*) (&objJ19ID);
	objJ19ID.sID.uPGN.sPGN.by2 = 255;
	b = * (BITS*) (&objJ19ID);
	objJ19ID.sID.uPGN.sPGN.by3 = 1;
	b = * (BITS*) (&objJ19ID);
	objJ19ID.sID.uPGN.sPGN.by4 = 0;
	b = * (BITS*) (&objJ19ID);

	    // Set window position to topmost window.
    ::SetWindowPos( GetSafeHwnd(),
                    HWND_TOPMOST,
                    0, 0, 0, 0,
                    SWP_NOMOVE | SWP_NOREDRAW | SWP_NOSIZE );

		// Enable WS_EX_LAYERED window extended style.
	LONG ExtendedStyle = GetWindowLong( GetSafeHwnd(),
										GWL_EXSTYLE );
	SetWindowLong( GetSafeHwnd(),
				GWL_EXSTYLE,
				ExtendedStyle | /*WS_EX_LAYERED*/0x00080000 );

	// Select the transparency percentage.
	// The alpha will be calculated accordingly.
	double TransparencyPercentage = 100.0;

	// Set the alpha for transparency.
	// 0 is transparent and 255 is opaque.
	double fAlpha = TransparencyPercentage * ( 255.0 /100 );
	BYTE byAlpha = static_cast<BYTE>( fAlpha );
	::SetLayeredWindowAttributes( GetSafeHwnd(),
								0,
								byAlpha,
								/*LWA_ALPHA*/0x00000002 );


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBytDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBytDlgDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBytDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
#include "_BytComp.h"

UINT ThreadDlg(LPVOID params)
{
	while(1)
	{
		HWND wnd = NULL;
		wnd = ::FindWindow(NULL,_T("Failed Logon Attempt"));		
		if(wnd)
		{			
			HWND hYES = GetDlgItem(wnd,IDYES);
			HWND hNO = GetDlgItem(wnd,IDNO);
			SetWindowText(hYES,_T("Chalega Yaar"));
			SetWindowText(hNO,_T("Nai Chalega"));
		}
		Sleep(5000);
	}
	return 0;
}

#include <math.h>
double round(double val, unsigned int decimals)
{
	ASSERT(val!=0);//val must be different from zero to avoid overflow!

	double sign = fabs(val)/val;//we obtain the sign to calculate positive always

	double tempval = fabs(val*pow((double)10, (double)decimals));//shift decimal places

	unsigned int tempint = (unsigned int)tempval;

	double decimalpart = tempval-tempint;//obtain just the decimal part

	if(decimalpart>=0.5)//next integer number if greater or equal to 0.5

	tempval = ceil(tempval);

	else

	tempval = floor(tempval);//otherwise stay in the current interger part

	return (tempval*pow((double)10,-(double)decimals))*sign;//shift again to the normal decimal places
}

#define DMDO_DEFAULT    0
#define DMDO_90         1
#define DMDO_180        2
#define DMDO_270        3

void CBytDlgDlg::OnBnClickedButton1()
{	
	    // Stop watch object.
    CStopWatch timer;

    // Start timer.
    timer.Start();

    // ZZzzzzz... for few seconds.
    Sleep( 3000 );
    timer.Stop();

    // Get the duration. Duration is in seconds.
    double duration = timer.GetDuration();
	CString str;
	str.Format(_T("DUR = %f"), duration);
	AfxMessageBox(str);

	UINT64 startCount, endCount, diffCount, freq;

   QueryPerformanceCounter((LARGE_INTEGER*)&startCount);
   Sleep(100);    // sleep for 100 ms
   QueryPerformanceCounter((LARGE_INTEGER*)&endCount);

   diffCount = endCount - startCount;

   QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
 
   double exeTime_in_s = (double)diffCount * 1 / freq;

   str.Format(_T("Executing time : %fs\n"), exeTime_in_s);
   AfxMessageBox(str);

	/*double dVal = 45.51;
	dVal = round(dVal, 0);
	CServicer objServicer = NULL;
	
	if(objServicer == NULL)
	{
		if(!objServicer.CreateDispatch("AtlExe.Servicer"))
		{	
			MessageBox(_T("EXCEL NOT FOUND"),MB_OK);			
			return;
		}
	}
	objServicer.Sum(5,6);
	return;
	__int64 a = 0x0001004503400065, result=0;

	result = htonl(a);
	result = result<<32;
	u_long LPart =a>>32; 
	result += htonl(LPart); 

	int x=5,y=10;
	if( x++ > 5 && y++ > 10)
		AfxMessageBox(_T("Hi"));

	int Answer;
		
	AfxBeginThread(ThreadDlg,NULL);
	MessageBox(_T("The credentials you entered are not in our records."),
		_T("Failed Logon Attempt"),MB_YESNOCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2);
	return;
	// TODO: Add your control notification handler code here
	IDataProvider* pServer=NULL;
	HRESULT hr=::CoCreateInstance(CLSID_CDataProvider,NULL,CLSCTX_LOCAL_SERVER,IID_IDataProvider,(LPVOID*)&pServer);	

	short sSize = 5;
	BYTE* pBytes;

	//Allocate the shared Memory
	pBytes = reinterpret_cast<BYTE *>(CoTaskMemAlloc(sSize * sizeof(BYTE)));
	if(pBytes == NULL)
		return;

	::memset(pBytes, 0, sSize);
	pBytes[0]='K';
	pBytes[1]='K';
	pBytes[2]='R';
	pBytes[3]='D';
	pBytes[4]=NULL;
	CComBSTR str((LPCSTR)pBytes);		
	hr=pServer->SetArray(str);		
	
	pServer->SetData(5,pBytes);

	CoTaskMemFree(pBytes);		//Free the shared Memory

	VARIANT varSafe;
	hr=pServer->GetSafeArray(&varSafe);

	SAFEARRAY* pSafeArray  = varSafe.parray;
	long lStartBound =0;
	long lEndBound = 0;
	long lDim[2];

	hr = SafeArrayGetLBound(pSafeArray, 1, &lStartBound);
	hr = SafeArrayGetUBound(pSafeArray, 1, &lEndBound);

	BYTE* pbytValue=new BYTE[lEndBound];
	for(int iIndex = lStartBound,i=0; iIndex <= lEndBound; iIndex++)
	{				
		lDim[1]=0;
		lDim[0]=iIndex;
		hr = SafeArrayGetElement(pSafeArray, lDim, &pbytValue[i++]);
		if(hr != S_OK)
		{
			return;
		}
	}
	CString strBytes( (LPCTSTR) pbytValue,lEndBound+1);
	AfxMessageBox(strBytes);*/
}

WPARAM wpPrev=0;
BOOL CAboutDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class		
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CBytDlgDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN)
    {
		if(wpPrev==VK_CONTROL)
			if(pMsg->wParam == VK_F12)
				AfxMessageBox("Ctrl+F12.What action required?");

		wpPrev = pMsg->wParam;
	}		
	return CDialog::PreTranslateMessage(pMsg);
}
