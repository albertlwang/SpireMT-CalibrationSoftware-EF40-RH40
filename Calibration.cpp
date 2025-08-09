// Calibration.cpp : Defines the class behaviors for the application.
//
// This file implements the main entry point and application logic for the CALIBRATION tool.
// It initializes the application, sets up OLE and MFC controls, and launches the main dialog.
// The application is designed to calibrate up to 20 meters, communicating with them via serial port
// using the protocol supported by the CnComm class. The dialog (CalibrationDlg) handles user interaction
// and calibration workflow. Logging and date/time utilities are present but commented out.
//
// Serial communication protocol dependencies:
// - The application expects meters to be connected via a serial port and to support the protocol
//   implemented in CnComm (see Calibration.h for details).
// - The COM port is selected and managed in the application state.
// - Meter data is exchanged using the Meter_Info and nowflux structures.
//
// For further details, see Calibration.h and CalibrationDlg.h/.cpp.

#include "stdafx.h"
#include "Calibration.h"
#include "CalibrationDlg.h"
#include "Log.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalibrationApp
// Main application class for the CALIBRATION tool.

BEGIN_MESSAGE_MAP(CCalibrationApp, CWinApp)
	//{{AFX_MSG_MAP(CCalibrationApp)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalibrationApp construction
// Constructor for the main application class.

CCalibrationApp::CCalibrationApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCalibrationApp object
// Global instance of the application.

CCalibrationApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCalibrationApp initialization
// Initializes OLE, MFC controls, and launches the main dialog.

BOOL CCalibrationApp::InitInstance()
{
	AfxEnableControlContainer();

	AfxOleInit();
	CoInitialize(NULL);
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CCalibrationDlg dlg;
	m_pMainWnd = &dlg;

	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	if (!AfxOleInit())  
	{  
		return FALSE;  
	}
	//memset(liuliang, 0, sizeof(liuliang));
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

//
//inline CString getCurrentDateTime(CString s) {
//	time_t now = time(0);
//	struct tm  tstruct;
//	char  buf[80];
//	tstruct = *localtime(&now);
//	if (s == "now")
//		strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
//	else if (s == "date")
//		strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
//	return CString(buf);
//};
//inline void Logger(CString logMsg) {
//
//	std::string filePath = "/LogDir/log_" + getCurrentDateTime("date") + ".txt";
//	std::string now = getCurrentDateTime("now");
//	std::ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app);
//	CString csOFS(ofs.c .c_str());
//	ofs << now << '\t' << logMsg << '\n';
//	ofs.close();
//}
//
