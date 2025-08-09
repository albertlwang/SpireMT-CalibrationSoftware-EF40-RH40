// Calibration.h : main header file for the CALIBRATION application
//
// This file defines the main application class and supporting structures for the CALIBRATION tool.
// The application is designed to calibrate up to 20 meters, supporting serial communication with meters
// via the CnComm helper class. The application manages meter information, calibration factors, and
// instantaneous flow data. It also supports multi-language UI and unit conversions.
//
// Serial communication protocol dependencies:
// - The CnComm class (g_com) is used for all serial-port interactions with the meters.
// - The commm field stores the selected COM-port number for communication.
// - The application expects the connected meters to support the protocol implemented in CnComm.
// - Meter_Info and nowflux structures are used to store and process data received from the meters.
//
// For more details on the implementation, see Calibration.cpp.

#if !defined(AFX_CALIBRATION_H__AAE3103C_76FA_489D_AA50_797C06CE0516__INCLUDED_)
#define AFX_CALIBRATION_H__AAE3103C_76FA_489D_AA50_797C06CE0516__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "CnComm.h"         // Serial communication helper class
#include "Afxmt.h"          // MFC multithreading support
#include "Meter_Information.h" // Meter information structure

#include <fstream> 

/////////////////////////////////////////////////////////////////////////////
// CCalibrationApp:
// See Calibration.cpp for the implementation of this class
//

/**
 * @struct NOWFLUX
 * @brief Stores instantaneous flow data for a meter.
 * 
 * Contains meter identifier, flow rate, speed, and other calibration-related values.
 * Units for flow and speed are stored as strings.
 */
typedef struct NOWFLUX 
{
	CString mmeter;      ///< Meter identifier
	float mflux;         ///< Measured flow rate
	float mspeed;        ///< Measured speed
	float S_UPf;         ///< Upstream signal value
	float S_DNf;         ///< Downstream signal value
	float Qf;            ///< Q value (application-specific)
	float Rf;            ///< R value (application-specific)
	float posTotalf;     ///< Totalized positive flow
	CString unflux;      ///< Unit of flow rate
	CString unspeed;     ///< Unit of flow speed
	CString S;           ///< S value (application-specific)
	CString Q;           ///< Q value (application-specific)
	CString R;           ///< R value (application-specific)
}nowflux;

/**
 * @class CCalibrationApp
 * @brief Main application class for the CALIBRATION tool.
 * 
 * Manages application state, meter information, calibration factors, and serial communication.
 * Supports up to 20 meters, multi-language UI, and unit conversions.
 */
class CCalibrationApp : public CWinApp
{
public:
	CCalibrationApp();

	CString biaohao;         ///< Meter serial number / identifier
	CString xs;              ///< Current calibration factor
	CString yxs;             ///< Original calibration factor
	CString flux;            ///< Current flow total or rate
	CRect g_rc;              ///< Main window's client rectangle
	nowflux liuliang[20];    ///< Instantaneous flow snapshots for up to 20 meters
	int no;                  ///< Number of meters that could be calibrated
	CnComm g_com;            ///< Serial-port helper (CnComm wrapper)
	CEvent g_event;          ///< Thread-sync event
	int p;                   ///< Reserved/unspecified
	int commm;               ///< Selected COM-port number (serial communication)
	int language;            ///< UI language index
	int unit_volume;         ///< Unit of volume of current meter
	int unit_time;           ///< Unit of time of the meters
	int biaoleixing;         ///< Meter type: 0 = 1M, 1 = 2M
	Meter_Info Meters[20];   ///< Info blobs for each attached meter
	int Global_Sampling_Total; ///< For each sampling, how many times it polls the reference meter at 1s gap

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalibrationApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCalibrationApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALIBRATION_H__AAE3103C_76FA_489D_AA50_797C06CE0516__INCLUDED_)
