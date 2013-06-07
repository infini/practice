
#pragma once

#include "ado_base.h"


class ADOConnection
{
public:
	ADOConnection();
	~ADOConnection();

	void	cancel();
	void	open( const char* connection_string, const char* user_id, const char* password );
	void	close();
	void	execute();
	void	beginTrans();
	void	commitTrans();
	void	rollbackTrans();
	void	openSchema();

private:
	_ConnectionPtr	m_connection;
};
