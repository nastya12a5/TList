

#include <iostream>
#include "TList.h"
using namespace std;
int main()
{
	TList<int> list;
	list.InsFirst(3);
	list.InsLast(2);
	list.InsLast(1);
	for (list.Reset(); !list.IsEnd(); list.GoNext()) { cout << list.getCurrent() << endl; }
	list.SetPos(1);
	list.InsCurr(5);
	for (list.Reset(); !list.IsEnd(); list.GoNext()) { cout << list.getCurrent() << endl; }
	list.~TList();
	list.InsFirst(3);
	for (list.Reset(); !list.IsEnd(); list.GoNext()) { cout << list.getCurrent() << endl; }
	TList<int> l(list);
	for (l.Reset(); !l.IsEnd(); l.GoNext()) { cout << l.getCurrent() << endl; }
}

