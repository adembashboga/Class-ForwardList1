#include <iostream>
#include "ForwardList.h"
#include "List.h"
#include <list>
#include <algorithm>

int main()
{
	List list;
	list.push_back(10);
	list.push_back(1);
	list.push_back(-5);
	
	list.insert(3, 7);

	list.show();

	return 0;
}