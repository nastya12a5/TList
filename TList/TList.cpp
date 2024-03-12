

#include <iostream>
#include "TList.h"
#include "THeadList.h"
#include <locale.h>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	TList<int> list;
	list.InsFirst(3);
	list.InsLast(2);
	list.InsLast(1);
	cout << "Cоздание списка " << endl;
	for (list.Reset(); !list.IsEnd(); list.GoNext()) { cout << list.getCurrent() << endl; }
	list.SetPos(1);
	list.InsCurr(5);
	
	cout << "Ввод элемента 5 на вторую позицию " << endl;
	for (list.Reset(); !list.IsEnd(); list.GoNext()) { cout  <<list.getCurrent() << endl; }
	list.~TList();
	list.InsFirst(3);
	list.InsLast(4);
	list.InsFirst(5);
	list.DelFirst();
	list.SetPos(1);
	list.DelCurr();
	cout << "Удаление списка" << endl << "Ввод после удаления" << endl;
	for (list.Reset(); !list.IsEnd(); list.GoNext()) { cout << list.getCurrent() << endl; }
	TList<int> l(list);
	cout << "Копирование списка " << endl;
	for (l.Reset(); !l.IsEnd(); l.GoNext()) { cout << l.getCurrent() << endl; }
	THeadList<int> list2;
	list2.InsFirst(3);
	list2.InsLast(2);
	list2.InsLast(1);
	cout << "Cоздание кольцевого списка " << endl;
	for (list2.Reset(); !list2.IsEnd(); list2.GoNext()) { cout << list2.getCurrent() << endl; }
	list2.SetPos(0);
	list2.InsCurr(5);
	cout << "Ввод элемента 5 на вторую позицию " << endl;
	for (list2.Reset(); !list2.IsEnd(); list2.GoNext()) { cout << list2.getCurrent() << endl; }
	list2.DelList();
	THeadList<int> list1;
	list1.InsFirst(3);
	list1.InsLast(4);
	list1.InsFirst(5);

	cout << "Удаление списка" << endl << "Ввод после удаления" << endl;
	for (list1.Reset(); !list1.IsEnd(); list1.GoNext()) { cout << list1.getCurrent() << endl; }
	THeadList<int> l2(list1);
	cout << "Копирование списка " << endl;
	for (l2.Reset(); !l2.IsEnd(); l2.GoNext()) { cout << l2.getCurrent() << endl; }
}

