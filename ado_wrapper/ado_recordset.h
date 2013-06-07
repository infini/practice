
#pragma once

#include "ado_base.h"

class ADORecordset
{
public:
	void	open( const char* source, _ConnectionPtr connection );
	void	move_next();
	bool	move_prev();

private:
	_RecordsetPtr	m_recordset;
};
