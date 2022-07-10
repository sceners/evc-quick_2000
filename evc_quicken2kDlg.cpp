// evc_quicken2kDlg.cpp : implementation file
//

#include "stdafx.h"
#include "evc_quicken2k.h"
#include "evc_quicken2kDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// Some Globals .....

int stupidity_counter = 0;


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEvc_quicken2kDlg dialog

CEvc_quicken2kDlg::CEvc_quicken2kDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEvc_quicken2kDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEvc_quicken2kDlg)
	m_sSerial = _T("");
	m_sUcode = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEvc_quicken2kDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEvc_quicken2kDlg)
	DDX_Control(pDX, IDC_unused, m_cUnused);
	DDX_Control(pDX, IDC_Ucode, m_cUcode);
	DDX_Control(pDX, IDC_Serial, m_cSerial);
	DDX_Text(pDX, IDC_Serial, m_sSerial);
	DDV_MaxChars(pDX, m_sSerial, 5);
	DDX_Text(pDX, IDC_Ucode, m_sUcode);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEvc_quicken2kDlg, CDialog)
	//{{AFX_MSG_MAP(CEvc_quicken2kDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDGO, OnGo)
	ON_BN_CLICKED(IDAbout, OnAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEvc_quicken2kDlg message handlers

BOOL CEvc_quicken2kDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEvc_quicken2kDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEvc_quicken2kDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEvc_quicken2kDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEvc_quicken2kDlg::OnGo()
{
		CString Serial, UnlockCode,
//          *~THE MATRIX*~
			_0 = "20769",
		    _1 = "39658",
			_2 = "02981",
			_3 = "11870",
			_4 = "64323",
			_5 = "73212",
			_6 = "46545",
			_7 = "55434",
			_8 = "42981",
			_9 = "51870";
//          EnD oF thE MATRIX*~

	char buffer[5];
	int i;
	// Get that string
	GetDlgItemText(IDC_Serial,buffer,6);
	Serial=buffer;
	UnlockCode = ""; // empty var

	if (Serial.GetLength()!= 5) goto no_char; // not enough chars entered? jump around
	for (i = 0; i!=5;i++)
	{
		// Yeah this pretty thing builds the UnlockCode
		// Just a fact:
		// atoi(blah bleh); converts a String 0-9 into a value .. in case the param is a-z the return value = 0
		// so I need to check at the end of the switch {} if the UnlockCode = 20769 is Serial = 00000 ?

		switch (atoi(Serial.Mid(i,1)))
		{
			case 0: UnlockCode += _0.Mid(i,1);
			break;

			case 1: UnlockCode += _1.Mid(i,1);
			break;

			case 2: UnlockCode += _2.Mid(i,1);
			break;

			case 3: UnlockCode += _3.Mid(i,1);
			break;

			case 4: UnlockCode += _4.Mid(i,1);
			break;

			case 5: UnlockCode += _5.Mid(i,1);
			break;

			case 6: UnlockCode += _6.Mid(i,1);
			break;

			case 7: UnlockCode += _7.Mid(i,1);
			break;

			case 8: UnlockCode += _8.Mid(i,1);
			break;

			case 9: UnlockCode += _9.Mid(i,1);
			break;

			default: goto bad_char;
		} // switch
	}// for

	// First the check .. non digits stuff
	if ((UnlockCode == "20769") && (Serial !="00000")) goto bad_char;

	/////////////////////////////////////////////////////////////
	///     A Professional Programmar would kill me now !!!   ///
	/////////////////////////////////////////////////////////////

	goto good_boy; // well if we're here then everything worked fine - so jump to good_boy

bad_char:	// if we're landing here we typed in some fucking non-digit
			MessageBox("Sorry dude only digits are possible to enter","Aargh",MB_ICONINFORMATION);
			goto fuck_off;
no_char:
			MessageBox("You need to enter your Serial Number\nRead evc.nfo!!","Oops",MB_ICONINFORMATION);

fuck_off:	UnlockCode="!";	// well display a ! in editbox UnlockCode:
			stupidity_counter++;  // increase the stupidity counter


			// if you're very very stupid you'll get these messages! ..
			if (stupidity_counter >= 10) // don't take this too personal ( I just like to piss off newbies - and old people )
			{
				MessageBox("Hey #3! Exit the program right now!!! You're too stupid to use it :)","Oh my ghod!",MB_ICONSTOP);
				MessageBox("Hey #2! Exit the program right now!!! You're too stupid to use it :)","Oh my ghod!",MB_ICONSTOP);
				MessageBox("Hey #1! Exit the program right now!!! You're too stupid to use it :)","Oh my ghod!",MB_ICONSTOP);
				MessageBox("Hey !!! Exit the program right now!!! You're too stupid to use it :)","Oh my ghod!",MB_ICONSTOP);
				stupidity_counter = 0; // reset the counter

				// this would reboot the computer without asking .. arg that's not nice
				// ExitWindowsEx(EWX_REBOOT,0);
			}

good_boy:
		SetDlgItemText(IDC_Ucode,UnlockCode);

}// call

void CEvc_quicken2kDlg::OnAbout()
{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();

}
