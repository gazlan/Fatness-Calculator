#include "stdafx.h"

#include "Fatness.h"
#include "FatnessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef NDEBUG
#pragma optimize("gsy",on)
#pragma comment(linker,"/MERGE:.rdata=.text /MERGE:.data=.text /SECTION:.text,EWR")
#endif
            
BEGIN_MESSAGE_MAP(CFatnessApp, CWinApp)
   //{{AFX_MSG_MAP(CFatnessApp)
      // NOTE - the ClassWizard will add and remove mapping macros here.
      //    DO NOT EDIT what you see in these blocks of generated code!
   //}}AFX_MSG
   ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

CFatnessApp::CFatnessApp()
{
   // TODO: add construction code here,
   // Place all significant initialization in InitInstance
}

CFatnessApp    theApp;

BOOL CFatnessApp::InitInstance()
{
#ifdef _AFXDLL
   Enable3dControls();        // Call this when using MFC in a shared DLL
#else
   Enable3dControlsStatic();  // Call this when linking to MFC statically
#endif

   CFatnessDlg    dlg;

   m_pMainWnd = &dlg;

   dlg.DoModal();

   // Since the dialog has been closed, return FALSE so that we exit the
   //  application, rather than start the application's message pump.
   return FALSE;
}
