#ifndef  _FATNESS_H_
#define  _FATNESS_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
   #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"      // main symbols

class CFatnessApp : public CWinApp
{
   public:
   
      CFatnessApp();

   // Overrides
   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(CFatnessApp)
   public:
      virtual BOOL InitInstance();
   //}}AFX_VIRTUAL

   // Implementation

   //{{AFX_MSG(CFatnessApp)
      // NOTE - the ClassWizard will add and remove member functions here.
      //    DO NOT EDIT what you see in these blocks of generated code !
   //}}AFX_MSG
   DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
