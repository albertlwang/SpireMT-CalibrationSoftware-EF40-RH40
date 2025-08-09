// CalibrationDlg.h : header file
//
// This file declares the CCalibrationDlg class, which implements the main dialog for the CALIBRATION application.
// The dialog manages user interaction for meter calibration, including serial communication setup, meter installation,
// zero setting, analysis, and reminders. It integrates with several sub-dialogs for specific calibration tasks.
// The dialog also supports multi-language UI and database connectivity for meter data management.
//
// Serial communication protocol dependencies:
// - Uses the CnComm class for serial port communication with meters.
// - Handles COM port selection, baud rate auto-detection, and meter search via serial protocol.
// - All meter data exchange and calibration commands are sent/received using the protocol supported by CnComm.
//
// For further details, see Calibration.h and Calibration.cpp.

#if !defined(AFX_CALIBRATIONDLG_H__81E1239B_4B66_4E4F_ADF4_6558B2026620__INCLUDED_)
#define AFX_CALIBRATIONDLG_H__81E1239B_4B66_4E4F_ADF4_6558B2026620__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CnComm.h"         // Serial communication helper
#include "SetDlg.h"         // Meter settings dialog
#include "InstallDlg.h"     // Meter installation dialog
#include "SetZeroDlg.h"     // Zero setting dialog
#include "AnalysisDlg.h"    // Data analysis dialog
#include "ShowDlg.h"        // Data display dialog
#include "ReminderDlg.h"    // Reminder dialog

/////////////////////////////////////////////////////////////////////////////
// CCalibrationDlg dialog
/**
 * @class CCalibrationDlg
 * @brief Main dialog class for the CALIBRATION application.
 *
 * Handles user interface for meter calibration, including serial communication, meter setup,
 * installation, zeroing, analysis, and reminders. Integrates with sub-dialogs for each task.
 * Supports multi-language UI and database operations for meter data.
 */
class CCalibrationDlg : public CDialog
{
// Construction
public:
	CString str;                ///< General-purpose string for dialog operations
	CFont g_Font;               ///< Font used in the dialog
	int res;                    ///< Result/status code for dialog operations
	CCalibrationDlg(CWnd* pParent = NULL);	// standard constructor
	CSetDlg setdlg;             ///< Meter settings dialog instance
	CInstallDlg installdlg;     ///< Meter installation dialog instance
	CSetZeroDlg setzerodlg;     ///< Zero setting dialog instance
	CAnalysisDlg analysisdlg;   ///< Data analysis dialog instance
	CReminderDlg reminderDlg;   ///< Reminder dialog instance

	_ConnectionPtr m_pAppConn;  ///< Database connection pointer
	_RecordsetPtr  m_recordset; ///< Database recordset pointer

// Dialog Data
	//{{AFX_DATA(CCalibrationDlg)
	enum { IDD = IDD_CALIBRATION_DIALOG };
	CString	m_meterrange;       ///< Meter range string for display
	//}}AFX_DATA
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalibrationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;              ///< Dialog icon handle

	// Generated message map functions
	//{{AFX_MSG(CCalibrationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenComm();
	afx_msg void OnSet();
	afx_msg void OnInstall();
	afx_msg void OnBaudAuto();
	afx_msg void CloseBaudAuto();
	afx_msg void OnSearchMeter();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSetZero();
	afx_msg void OnAnalysis();
	afx_msg void OnClose();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeLanguage();
	afx_msg void OnCheck();
	afx_msg void OnSelchangeComboComm();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALIBRATIONDLG_H__81E1239B_4B66_4E4F_ADF4_6558B2026620__INCLUDED_)
