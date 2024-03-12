#include <iostream>
#include "THeadList.h"
#include <locale.h>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	THeadList<int> list;
	list.InsFirst(3);
	list.InsLast(2);
	list.InsLast(1);
	cout << "Cоздание кольцевого списка " << endl;
	for (list.Reset(); !list.IsEnd(); list.GoNext()) { cout << list.getCurrent() << endl; }
	list.SetPos(1);
	list.InsCurr(5);
	cout << "Ввод элемента 5 на вторую позицию " << endl;
	for (list.Reset(); !list.IsEnd(); list.GoNext()) { cout << list.getCurrent() << endl; }
	list.~THeadList();
	THeadList<int> list1;
	list1.InsFirst(3);
	list1.InsLast(4);
	list1.InsFirst(5);
	
	cout << "Удаление списка" << endl << "Ввод после удаления" << endl;
	for (list1.Reset(); !list1.IsEnd(); list1.GoNext()) { cout << list1.getCurrent() << endl; }
	THeadList<int> l(list1);
	//cout << "Копирование списка " << endl;
	for (l.Reset(); !l.IsEnd(); l.GoNext()) { cout << l.getCurrent() << endl; }
}

