/**
 * @file AnalysisDlg.h
 * @brief Declaration of the CAnalysisDlg dialog class for meter data analysis.
 *
 * This dialog provides the user interface and logic for analyzing meter calibration data.
 * It displays results in a list control, manages error dialogs, and interacts with the application's
 * database using ADO.
 */

#if !defined(AFX_ANALYSISDLG_H__A2D01BE2_9FFB_47E5_991E_7003490AB631__INCLUDED_)
#define AFX_ANALYSISDLG_H__A2D01BE2_9FFB_47E5_991E_7003490AB631__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnalysisDlg.h : header file
#include "ErrorDlg.h"
//

/////////////////////////////////////////////////////////////////////////////
// CAnalysisDlg dialog

/**
 * @class CAnalysisDlg
 * @brief Dialog for analyzing and displaying meter calibration data.
 *
 * Provides UI and logic for analyzing meter data, displaying results, and handling errors.
 * Interacts with the database and manages analysis-specific data structures.
 */
class CAnalysisDlg : public CDialog
{
// Construction
public:
	CAnalysisDlg(CWnd* pParent = NULL);   ///< Standard constructor
	_ConnectionPtr m_pAppConn;            ///< ADO connection pointer for database access
	_RecordsetPtr  m_recordset;           ///< ADO recordset pointer for database operations
	CString m_str;                        ///< General-purpose string buffer
	CFont g_font;                         ///< Font used for dialog controls
	CErrorDlg errordlg;                   ///< Error dialog for displaying error information
	float fdata[3][6];                    ///< Analysis data array
	float wucha[3][3];                    ///< Error data array
	float xzwucha[3][3];                  ///< Additional error data array
	float xishu[20];                      ///< Coefficient array
	float xzxishu[20];                    ///< Additional coefficient array
	int check[20];                        ///< Check array for analysis status

// Dialog Data
	//{{AFX_DATA(CAnalysisDlg)
	enum { IDD = IDD_ANALYSIS };
	CListCtrl	m_list;                   ///< List control for displaying analysis results
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnalysisDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    ///< DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAnalysisDlg)
	virtual BOOL OnInitDialog();                         ///< Initializes the dialog
	afx_msg void OnCheckout();                           ///< Handles checkout action
	afx_msg void OnClose();                              ///< Handles dialog close event
	afx_msg void OnDblclkListAnalysis(NMHDR* pNMHDR, LRESULT* pResult); ///< Handles double-click on list
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANALYSISDLG_H__A2D01BE2_9FFB_47E5_991E_7003490AB631__INCLUDED_)
