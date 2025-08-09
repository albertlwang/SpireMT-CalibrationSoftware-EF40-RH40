/**
 * @file SetDlg.h
 * @brief Declaration of the CSetDlg dialog class for meter parameter configuration.
 *
 * This dialog is used for setting and editing various parameters related to meter calibration and configuration.
 * It provides UI controls for entering and modifying meter settings, supports batch operations, and interacts
 * with the application's database using ADO. The dialog also manages serial communication with the meter device.
 *
 * Dependencies:
 * - Serial communication protocol: Some dialog actions (such as parameter setting, quick set, and batch operations)
 *   depend on the current meter's serial protocol. If the protocol changes, methods that send commands to the meter
 *   (e.g., OnM11, OnM12, OnQuickSet, OnMulset, etc.) may require updates to match the new protocol's command structure.
 * - Database: Uses ADO (_ConnectionPtr, _RecordsetPtr) for reading and writing meter configuration data.
 *
 * Note for future developers:
 * - If supporting a new meter or protocol, review all message handlers that interact with the meter via serial port.
 *   Update command formats and parsing logic as needed.
 * - UI control variables (e.g., m_m11, m_m12, etc.) are mapped to dialog fields for user input.
 */

#if !defined(AFX_SETDLG_H__03D8720A_111E_40CD_8344_5DA8359FBB17__INCLUDED_)
#define AFX_SETDLG_H__03D8720A_111E_40CD_8344_5DA8359FBB17__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetDlg.h : header file
//
#include "LineArrayDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CSetDlg dialog

/**
 * @class CSetDlg
 * @brief Dialog for configuring meter parameters and sending commands to the meter.
 *
 * Provides UI and logic for setting individual and batch meter parameters, interacting with the database,
 * and communicating with the meter device over a serial connection.
 */
class CSetDlg : public CDialog
{
// Construction
public:
	CFont g_font;                ///< Font used for dialog controls
	CString m_meterno;           ///< Meter number
	CString str;                 ///< General-purpose string buffer
	CString str1;                ///< General-purpose string buffer
	CLineArrayDlg line_array;    ///< Dialog for line array operations

	_ConnectionPtr m_pAppConn;   ///< ADO connection pointer for database access
	_RecordsetPtr  m_recordset;  ///< ADO recordset pointer for database operations

	int leixing;                 ///< Meter type
	CString jiaodu;              ///< Angle parameter
	CString shengsu;             ///< Speed parameter
	CString juli;                ///< Distance parameter
	CString shijian;             ///< Time parameter
	int pinlv;                   ///< Frequency parameter
	int fangfa;                  ///< Method parameter
	CString xishu;               ///< Coefficient parameter

	CSetDlg(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CSetDlg)
	enum { IDD = IDD_SET };
	CString	m_m11;
	CString	m_m12;
	CString	m_m13;
	CString	m_m18;
	CString	m_m40;
	CString	m_m45;
	CString	m_m231;
	CString	m_m232;
	CString	m_m233;
	CString	m_m234;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnM11();
	afx_msg void OnM30();
	afx_msg void OnM12();
	afx_msg void OnM13();
	afx_msg void OnUpdateM14();
	afx_msg void OnM14();
	afx_msg void OnUpdateM16();
	afx_msg void OnM16();
	afx_msg void OnM18();
	afx_msg void OnUpdateM20();
	afx_msg void OnM20();
	afx_msg void OnUpdateM31();
	afx_msg void OnM31();
	afx_msg void OnUpdateM32();
	afx_msg void OnM32();
	afx_msg void OnUpdateM33();
	afx_msg void OnM33();
	afx_msg void OnM34();
	afx_msg void OnM35();
	afx_msg void OnM36();
	afx_msg void OnM37();
	afx_msg void OnOk();
	afx_msg void OnUpdateM39();
	afx_msg void OnM39();
	afx_msg void OnM40();
	afx_msg void OnUpdateM79();
	afx_msg void OnM79();
	afx_msg void OnSelchangeComboMeter();
	afx_msg void OnUpdateM24();
	afx_msg void OnUpdateM26();
	afx_msg void OnM25();
	afx_msg void OnM26();
	afx_msg void OnM45();
	afx_msg void OnM23();
	afx_msg void OnQuickSet2();
	afx_msg void OnQuickSet();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg void OnM24();
	afx_msg void OnM48();
	afx_msg void OnM231();
	afx_msg void OnM232();
	afx_msg void OnM233();
	afx_msg void OnM234();
	afx_msg void OnCopy();
	afx_msg void OnChangeEditM11();
	afx_msg void OnChangeEditM12();
	afx_msg void OnMulset();
	afx_msg void OnPaste();
	afx_msg void OnSelchangeComboM23();
	afx_msg void OnSelchangeComboM24();
	afx_msg void OnChangeEditM231();
	afx_msg void OnChangeEditM232();
	afx_msg void OnChangeEditM233();
	afx_msg void OnChangeEditM234();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnSelchangeComboM16();
	afx_msg void OnRadio9();
	afx_msg void OnRadio10();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETDLG_H__03D8720A_111E_40CD_8344_5DA8359FBB17__INCLUDED_)
