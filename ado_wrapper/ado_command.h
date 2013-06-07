
#pragma once

#include "ado_base.h"

class ADOCommand
{
public:
	void	cancel();
	void	createParameter();
	void	execute();

private:
	_CommandPtr		m_command;
};
