
#pragma once

#include "ado_base.h"

class ADOCollection
{
public:
	void	append();
	void	deletes();
	void	refresh();


private:
	_CollectionPtr	m_collection;

};
