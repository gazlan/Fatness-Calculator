#include "stdafx.h"

#include "math.h"
#include "Fatness.h"
#include "FatnessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define BEFORE2(P)   BEFORE(P,__LINE__)
#define BEFORE(P1,P2) static void P1##P2(); 


BEFORE2(TEST2)

// PRT_MODULE("FATNESS");

//#define PRT_MODULE_NAME    "FATNESS"  

//PROTECT@@BEFORE("CFatnessDlg::OnInitDialog",ENCRYPT,"CFatnessDlg::Refresh",METHOD_1);

//PRT_BEFORE(DECRYPT
//PRT_BEFORE(HASH

/*
PRT_AFTER(
PRT_INSTEAD(
*/

CFatnessDlg::CFatnessDlg(CWnd* pParent /*=NULL*/)
   : CDialog(CFatnessDlg::IDD, pParent)
{
   //{{AFX_DATA_INIT(CFatnessDlg)
      // NOTE: the ClassWizard will add member initialization here
   //}}AFX_DATA_INIT
   // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
   m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

   bGender  = true;
   bRefresh = false;

   fAge    = 0.0;
   fHeight = 0.0;
   fWeight = 0.0;
}

void CFatnessDlg::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);

   //{{AFX_DATA_MAP(CFatnessDlg)
   DDX_Control(pDX, IDC_SPN_WEIGHT, m_SpinWeight);
   DDX_Control(pDX, IDC_SPN_HEIGHT, m_SpinHeight);
   DDX_Control(pDX, IDC_SPN_AGE, m_SpinAge);
   //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFatnessDlg, CDialog)
   //{{AFX_MSG_MAP(CFatnessDlg)
   ON_WM_PAINT()
   ON_WM_QUERYDRAGICON()
   ON_BN_CLICKED(IDC_RB_MALE, OnRbMale)
   ON_BN_CLICKED(IDC_RB_FEMALE, OnRbFemale)
   ON_EN_CHANGE(IDC_EDT_AGE, OnChangeEdtAge)
   ON_EN_CHANGE(IDC_EDT_HEIGHT, OnChangeEdtHeight)
   ON_EN_CHANGE(IDC_EDT_WEIGHT, OnChangeEdtWeight)
   ON_EN_KILLFOCUS(IDC_EDT_AGE, OnKillfocusEdtAge)
   ON_EN_KILLFOCUS(IDC_EDT_HEIGHT, OnKillfocusEdtHeight)
   ON_EN_KILLFOCUS(IDC_EDT_WEIGHT, OnKillfocusEdtWeight)
   //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFatnessDlg message handlers

BOOL CFatnessDlg::OnInitDialog()
{
   CDialog::OnInitDialog();

   // Set the icon for this dialog.  The framework does this automatically
   //  when the application's main window is not a dialog
   SetIcon(m_hIcon,TRUE);       // Set big icon
   SetIcon(m_hIcon,FALSE);      // Set small icon

   CenterWindow();

   CheckRadioButton(IDC_RB_MALE,IDC_RB_FEMALE,bGender  ?  IDC_RB_MALE  :  IDC_RB_FEMALE);

   m_SpinAge.SetRange(0,100);
   m_SpinHeight.SetRange(0,250);
   m_SpinWeight.SetRange(0,200);

   fAge    = 20.5;
   fHeight = 185;
   fWeight = 90;

   m_SpinAge.   SetPos((int)fAge);
   m_SpinHeight.SetPos((int)fHeight);
   m_SpinWeight.SetPos((int)fWeight);

   Refresh();

   return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFatnessDlg::OnPaint()
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
HCURSOR CFatnessDlg::OnQueryDragIcon()
{
   return (HCURSOR) m_hIcon;
}

void CFatnessDlg::OnChangeEdtAge()
{
   if (bRefresh)
      return;

   CString     sAge;

   GetDlgItemText(IDC_EDT_AGE,sAge);

   fAge = (float)atof((LPCTSTR)sAge);

   Refresh(PRM_AGE);
}

void CFatnessDlg::OnChangeEdtHeight()
{
   if (bRefresh)
      return;

   CString     sHeight;

   GetDlgItemText(IDC_EDT_HEIGHT,sHeight);

   fHeight = (float)atof((LPCTSTR)sHeight);

   Refresh(PRM_HEIGHT);
}

void CFatnessDlg::OnChangeEdtWeight()
{
   if (bRefresh)
      return;

   CString     sWeight;

   GetDlgItemText(IDC_EDT_WEIGHT,sWeight);

   fWeight = (float)atof((LPCTSTR)sWeight);

   Refresh(PRM_WEIGHT);
}

void CFatnessDlg::OnRbMale()
{
   if (bRefresh)
      return;

   bGender = true;

   CheckRadioButton(IDC_RB_MALE,IDC_RB_FEMALE,bGender  ?  IDC_RB_MALE  :  IDC_RB_FEMALE);

   Refresh();
}

void CFatnessDlg::OnRbFemale()
{
   if (bRefresh)
      return;

   bGender = false;

   CheckRadioButton(IDC_RB_MALE,IDC_RB_FEMALE,bGender  ?  IDC_RB_MALE  :  IDC_RB_FEMALE);

   Refresh();
}

void CFatnessDlg::Refresh(PARAM Prm)
{
   bRefresh = true;

   CString     sAge;
   CString     sHeight;
   CString     sWeight;

   sAge.Format   ("%4.2f",fAge);
   sHeight.Format("%4.2f",fHeight);
   sWeight.Format("%4.2f",fWeight);

   if (Prm != PRM_AGE)
      SetDlgItemText(IDC_EDT_AGE,sAge);

   if (Prm != PRM_HEIGHT)
      SetDlgItemText(IDC_EDT_HEIGHT,sHeight);

   if (Prm != PRM_WEIGHT)
      SetDlgItemText(IDC_EDT_WEIGHT,sWeight);

   float    fIdealWeight = fHeight * 3.0F - 450.0F + fAge;

   if (bGender)      // Men
   {
      fIdealWeight *= 0.25;
      fIdealWeight += 45.0F;
   }
   else              // Women
   {
      fIdealWeight *= 0.225F;
      fIdealWeight += 40.4F;
   }

   CString     sIdealWeight;

   sIdealWeight.Format("%3.1f",fIdealWeight);

   float    fDifferent = fWeight - fIdealWeight;

   sWeight.Format("%3.1f",fDifferent);

   float    fFatness = 100.0F * (fDifferent / fWeight);

   if (bGender)
   {
      fFatness += 15.0F;   // Men
   }
   else
   {
      fFatness += 22.0F;   // Women
   }

   CString     sFatness;

   sFatness.Format("%5.2f",fFatness);

   float    fDensity = (float)(0.001 *(8.9 * fFatness + 11.0F * (100.0F - fFatness)));

   CString     sDensity;

   sDensity.Format("%5.3f",fDensity);

   float    fCapacity = fWeight / fDensity;

   CString     sCapacity;

   sCapacity.Format("%4.2f",fCapacity);

   float    fArea = (float)((pow(fWeight * 1000.0F,(log10(1.0F / fWeight) + 35.75) / 53.2) * pow(fHeight,0.3)) / 3118.2);

   CString     sArea;

   sArea.Format("%4.2f",fArea);

   SetDlgItemText(IDC_EDT_IDEALWEIGHT,sIdealWeight);
   SetDlgItemText(IDC_EDT_EXCESS,sWeight);
   SetDlgItemText(IDC_EDT_FATNESS,sFatness);
   SetDlgItemText(IDC_EDT_DENSITY,sDensity);
   SetDlgItemText(IDC_EDT_CAPASITY,sCapacity);
   SetDlgItemText(IDC_EDT_AREA,sArea);

   bRefresh = false;
}

void CFatnessDlg::OnKillfocusEdtAge() 
{
   Refresh();
}

void CFatnessDlg::OnKillfocusEdtHeight() 
{
   Refresh();
}

void CFatnessDlg::OnKillfocusEdtWeight() 
{
   Refresh();
}
