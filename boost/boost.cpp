// boost.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "ptr_container.h"
#include "unordered_container.h"
#include "multi_index.h"

int _tmain(int argc, _TCHAR* argv[])
{
	PtrContainer kPtrContainer;
	kPtrContainer.initialize();

	UnorderedContainer kUnorderedContainer;
	kUnorderedContainer.testFunction();

	MultiIndex kMultiIndex;
	kMultiIndex.testFunction();

	return 0;
}
