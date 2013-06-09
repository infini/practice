
#pragma once

#import "C:\Program Files\Common Files\System\ado\msado60_Backcompat.tlb" no_namespace rename( "EOF", "adoEOF" )


class ADOCollection
{
public:
	void	append();
	void	_delete();
	void	refresh();


private:
	_CollectionPtr	m_collection;

};

/************************************************************************/
/* property
long GetCount( ); __declspec(property(get=GetCount)) long Count;
PropertyPtr GetItem( const _variant_t & Index ); __declspec(property(get=GetItem)) PropertyPtr Item[];
*/
/************************************************************************/