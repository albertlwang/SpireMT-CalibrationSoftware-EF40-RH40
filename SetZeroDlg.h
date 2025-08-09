/**
 * @file SetZeroDlg.h
 * @brief Declaration of the CSetZeroDlg dialog class for zero-point calibration.
 *
 * This dialog manages the user interface and logic for performing zero-point calibration
 * of meters within the calibration application. It provides controls for starting calibration,
 * collecting data, displaying results, and interacting with the database.
 *
 * Key Features:
 * - Manages serial communication with the meter for zero calibration (protocol-specific).
 * - Provides UI for setting wait/sample times and voltage levels (max, mid, low).
 * - Handles multi-threaded data collection and UI updates.
 * - Interacts with the application's database using ADO (_ConnectionPtr, _RecordsetPtr).
 * - Supports custom font and brush for consistent UI appearance.
 * - Integrates with CCollectDlg and CShowDlg for data collection and result display.
 *
 * Serial Communication Protocol Dependency:
 * - The dialog's data collection and calibration logic depend on the serial protocol
 *   used by the currently supported meter. Any changes to the meter's protocol or
 *   command set may require updates to the OnCollect, OnCalibrate, and related methods.
 * - Threaded operations and message handlers may interact with the meter via serial port.
 *
 * Maintenance Notes:
 * - Update protocol handling code if meter communication changes.
 * - Review and update UI control mappings if dialog resources change.
 * - Ensure proper cleanup of threads and COM objects to prevent resource leaks.
 *
 * Author: [Your Name or Company]
 * Date: [Date]
 */

#if !defined(AFX_SETZERODLG_H__3BE39FEE_CD8A_4D19_9449_0325FD86B85A__INCLUDED_)
#define AFX_SETZERODLG_H__3BE39FEE_CD8A_4D19_9449_0325FD86B85A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetZeroDlg.h : header file
//
#include "CollectDlg.h"
#include "ShowDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CSetZeroDlg dialog

/**
 * @class CSetZeroDlg
 * @brief Dialog for performing zero-point calibration of meters.
 *
 * Handles user interaction, serial communication, and data management for zero calibration.
 */
class CSetZeroDlg : public CDialog
{
// Construction
public:
	CSetZeroDlg(CWnd* pParent = NULL);   ///< Standard constructor
	CString str;                         ///< General-purpose string buffer
	CFont *m_Font;                       ///< Pointer to custom font
	CFont g_Font;                        ///< Custom font object
	CBrush m_brush;                      ///< Brush for custom control coloring
	_ConnectionPtr m_pAppConn;           ///< ADO connection pointer for database access
	_RecordsetPtr  m_recordset;          ///< ADO recordset pointer for database operations
	CCollectDlg collectdlg;              ///< Dialog for data collection
	int m_flag;                          ///< Status flag for calibration state
	CShowDlg *showdlg;                   ///< Pointer to dialog for showing results
	CWinThread* thread;                  ///< Thread for background operations
	CWinThread* pThread;                 ///< Additional thread pointer
	~CSetZeroDlg();                      ///< Destructor

// Dialog Data
	//{{AFX_DATA(CSetZeroDlg)
	enum { IDD = IDD_SET_ZERO };
	CTabCtrl	m_tab;                   ///< Tab control for UI navigation
	CString	m_m41;                      ///< Meter-specific data field
	CString m_wait_time, m_sample_time;  ///< Wait and sample time settings
	CString v_max, v_mid, v_low;         ///< Voltage level settings
	CString	m_show;                     ///< Display string for results
	int m_delay;                         ///< Delay setting for calibration
	float v_max_f, v_mid_f, v_low_f;     ///< Voltage levels as floats
	int dlgResult;                       ///< Dialog result code
	bool SetZeroComplete;                ///< Flag indicating if zero calibration is complete
	bool ManualSetZero;                  ///< Flag for manual zero calibration mode
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetZeroDlg)
	protected:
		int OnStart;                     ///< Internal flag for start state
		virtual void DoDataExchange(CDataExchange* pDX);    ///< DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetZeroDlg)
	virtual BOOL OnInitDialog();         ///< Initializes the dialog
	afx_msg void OnM42();                ///< Handler for M42 button
	afx_msg void OnM41();                ///< Handler for M41 button
	afx_msg void OnM42_Cal();            ///< Handler for M42 calibration
	afx_msg void OnTimer(UINT nIDEvent); ///< Timer event handler
	afx_msg void OnM_2();                ///< Handler for M_2 button
	afx_msg void OnCollect();            ///< Handler for data collection (serial protocol dependent)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor); ///< Custom control coloring
	afx_msg void OnCollect2();           ///< Handler for secondary data collection
	afx_msg void OnCollect3();           ///< Handler for tertiary data collection
	afx_msg void OnClose();              ///< Handler for dialog close event
	afx_msg void OnDestroy();            ///< Handler for dialog destroy event
	//afx_msg void PostNcDestroy();
	afx_msg void OnPaint();              ///< Paint event handler
	afx_msg void OnButtonShow();         ///< Handler for show button
	afx_msg void OnMove(int x, int y);   ///< Handler for move event
	afx_msg LRESULT OnMyMessage2(WPARAM wParam, LPARAM lParam); ///< Custom message handler
	afx_msg void OnMax();                ///< Handler for max voltage
	afx_msg void OnMid();                ///< Handler for mid voltage
	afx_msg void OnMin();                ///< Handler for min voltage
	afx_msg void OnCloseValve();         ///< Handler for closing valve
	afx_msg void OnCalibrate();          ///< Handler for calibration (serial protocol dependent)
	afx_msg void OnCalibrate_2();        ///< Handler for secondary calibration
	afx_msg void OnChangeEditWaitTime(); ///< Handler for wait time edit change
	afx_msg void OnChangeEditSampleTime(); ///< Handler for sample time edit change
	afx_msg void OnChangeVCMax();        ///< Handler for max voltage edit change
	afx_msg void OnChangeVCMid();        ///< Handler for mid voltage edit change
	afx_msg void OnChangeVCLow();        ///< Handler for low voltage edit change
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFlush();     ///< Handler for flush button
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETZERODLG_H__3BE39FEE_CD8A_4D19_9449_0325FD86B85A__INCLUDED_)
