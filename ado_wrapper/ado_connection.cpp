
#include "stdafx.h"
#include "ado_connection.h"


ADOConnection::ADOConnection()
{
}

ADOConnection::~ADOConnection()
{
}

void	ADOConnection::OpenX()
{
	// Define ADO object pointers.  Initialize pointers on define.
	// These are in the ADODB:: namespace
	_RecordsetPtr pRstEmployee = NULL;
	_ConnectionPtr pConnection = NULL;

	// Define string variables.
	_bstr_t strCnn("Provider='sqloledb'; Data Source='My_Data_Source'; Initial Catalog='pubs'; Integrated Security='SSPI';");

	IADORecordBinding *picRs = NULL;   // Interface Pointer declared.
	CEmployeeRs emprs;   // C++ Class object
	DBDATE varDate;

	try {
		// open connection and record set
		TESTHR(pConnection.CreateInstance(__uuidof(Connection)));
		pConnection->Open(strCnn, "", "", adConnectUnspecified);

		TESTHR(pRstEmployee.CreateInstance(__uuidof(Recordset)));
		pRstEmployee->Open("Employee", _variant_t((IDispatch *)pConnection,true), 
			adOpenKeyset, adLockOptimistic, adCmdTable);

		// Open an IADORecordBinding interface pointer for Binding Recordset to a class.
		TESTHR(pRstEmployee->QueryInterface(__uuidof(IADORecordBinding),(LPVOID*)&picRs));

		// Bind the Recordset to a C++ Class here.
		TESTHR(picRs->BindToRecordset(&emprs));

		// Assign first employee record's hire date to variable, then change hire date.
		varDate = emprs.m_sze_hiredate;
		printf("Original data\n");
		printf("\tName - Hire Date\n");
		printf("  %s  %s - %d/%d/%d\n\n",
			emprs.le_fnameStatus == adFldOK ? 
			emprs.m_sze_fname : "<NULL>",
			emprs.le_lnameStatus == adFldOK ? 
			emprs.m_sze_lname : "<NULL>",
			emprs.le_hiredateStatus == adFldOK ? 
			emprs.m_sze_hiredate.month : 0,
			emprs.le_hiredateStatus == adFldOK ? 
			emprs.m_sze_hiredate.day : 0,
			emprs.le_hiredateStatus == adFldOK ? 
			emprs.m_sze_hiredate.year : 0); 

		emprs.m_sze_hiredate.year = 1900;
		emprs.m_sze_hiredate.month = 1;
		emprs.m_sze_hiredate.day = 1;
		picRs->Update(&emprs);

		printf("\nChanged data\n");
		printf("\tName - Hire Date\n");
		printf("  %s %s - %d/%d/%d\n\n",
			emprs.le_fnameStatus == adFldOK ? 
			emprs.m_sze_fname : "<NULL>",
			emprs.le_lnameStatus == adFldOK ? 
			emprs.m_sze_lname : "<NULL>",
			emprs.le_hiredateStatus == adFldOK ? 
			emprs.m_sze_hiredate.month : 0,
			emprs.le_hiredateStatus == adFldOK ? 
			emprs.m_sze_hiredate.day : 0,
			emprs.le_hiredateStatus == adFldOK ? 
			emprs.m_sze_hiredate.year : 0); 

		// Requery Recordset and reset the hire date.
		pRstEmployee->Requery(adOptionUnspecified);

		// Open IADORecordBinding interface pointer for Binding Recordset to a class.
		TESTHR(pRstEmployee->QueryInterface(__uuidof(IADORecordBinding), (LPVOID*)&picRs));

		// Rebind the Recordset to a C++ Class here.
		TESTHR(picRs->BindToRecordset(&emprs));
		emprs.m_sze_hiredate = varDate;
		picRs->Update(&emprs);
		printf("\nData after reset\n");
		printf("\tName - Hire Date\n");
		printf("  %s %s - %d/%d/%d", emprs.le_fnameStatus == adFldOK ? 
			emprs.m_sze_fname : "<NULL>",
			emprs.le_lnameStatus == adFldOK ? 
			emprs.m_sze_lname : "<NULL>",
			emprs.le_hiredateStatus == adFldOK ? 
			emprs.m_sze_hiredate.month : 0,
			emprs.le_hiredateStatus == adFldOK ? 
			emprs.m_sze_hiredate.day : 0,
			emprs.le_hiredateStatus == adFldOK ? 
			emprs.m_sze_hiredate.year : 0); 
	}
	catch(_com_error &e) {
		// Display errors, if any. Pass a connection pointer accessed from the Connection.
		PrintProviderError(pConnection);
		PrintComError(e);
	}
}

void PrintProviderError(_ConnectionPtr pConnection)
{
	// Print Provider Errors from Connection object.
	// pErr is a record object in the Connection's Error collection.
	ErrorPtr pErr = NULL;

	if ( (pConnection->Errors->Count) > 0) {
		long nCount = pConnection->Errors->Count;
		// Collection ranges from 0 to nCount -1.
		for ( long i = 0 ; i < nCount ; i++ ) {
			pErr = pConnection->Errors->GetItem(i);
			printf("\t Error number: %x\t%s", pErr->Number, pErr->Description);
		}
	}
}

void PrintComError(_com_error &e)
{
	_bstr_t bstrSource(e.Source());
	_bstr_t bstrDescription(e.Description());

	// Print COM errors. 
	printf("Error\n");
	printf("\tCode = %08lx\n", e.Error());
	printf("\tCode meaning = %s\n", e.ErrorMessage());
	printf("\tSource = %s\n", (LPCSTR) bstrSource);
	printf("\tDescription = %s\n", (LPCSTR) bstrDescription);
}


