#ifndef _FITNESSDLG_H_
#define _FITNESSDLG_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum PARAM
{
   PRM_NONE,
   PRM_AGE,
   PRM_HEIGHT,
   PRM_WEIGHT
};

class CFatnessDlg : public CDialog
{
   // Construction
   public:

      CFatnessDlg(CWnd* pParent = NULL);  // standard constructor

      // Dialog Data
      //{{AFX_DATA(CFatnessDlg)
      enum { IDD = IDD_FATNESS };
      CSpinButtonCtrl   m_SpinWeight;
      CSpinButtonCtrl   m_SpinHeight;
      CSpinButtonCtrl   m_SpinAge;
      //}}AFX_DATA

   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(CFatnessDlg)
   protected:
      virtual void DoDataExchange(CDataExchange* pDX);   // DDX/DDV support
   //}}AFX_VIRTUAL

   // Implementation
   protected:
   
      HICON m_hIcon;

   // Generated message map functions
   //{{AFX_MSG(CFatnessDlg)
      virtual BOOL OnInitDialog();
      afx_msg void OnPaint();
      afx_msg HCURSOR OnQueryDragIcon();
      afx_msg void OnRbMale();
      afx_msg void OnRbFemale();
      afx_msg void OnChangeEdtAge();
      afx_msg void OnChangeEdtHeight();
      afx_msg void OnChangeEdtWeight();
   afx_msg void OnKillfocusEdtAge();
   afx_msg void OnKillfocusEdtHeight();
   afx_msg void OnKillfocusEdtWeight();
   //}}AFX_MSG
   DECLARE_MESSAGE_MAP()

   private:
      
      bool bRefresh;
      bool bGender;

      float fWeight;
      float fHeight;
      float fAge;
   
   private:
      
      void Refresh(PARAM Prm = PRM_NONE);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif
