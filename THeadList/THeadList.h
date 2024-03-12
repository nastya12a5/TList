#pragma once
#include<iostream>
#include <algorithm>
#include "../TList/TList.h"
using namespace std;
struct TMonom {
	double Coeff;
	int index;
	TMonom(float cval = 1, int ival = 0) :Coeff(cval), index(ival) {}
	virtual ~TMonom() {}
	void SetCoeff(double cval) { Coeff = cval; }
	double GetCoeff() {
		return Coeff;
	}
	void SetIndex(int ival) { index = ival; }
	int GetIndex() {
		return index;
	}
	bool operator==(const TMonom& other) const {
		return (Coeff == other.Coeff && index == other.index);
	}
	
	bool operator!=(const TMonom& other) const {
		return !(*this == other);
	}
	
	bool operator<(const TMonom& other) const {
		if (index < other.index)
		{
			return true;
		}
		else
		{
			if (index == other.index)
			{
				return Coeff < other.Coeff;
			}
			else
			{
				return false;
			}
		}
	}
	
	bool operator>(const TMonom& other) const {
		return !(*this < other);
	}

	
	friend istream& operator>>(istream& cin, TMonom& monom) {
		cin >> monom.Coeff >> monom.index;
		return cin;
	}

	
	friend ostream& operator<<(ostream& cout, const TMonom& monom) {
		int degx = monom.index / 100;
		int degy = monom.index / 10;
		int degz = monom.index % 10;
		cout << monom.Coeff << "*X^(" << degx << ")Y^(" << degy << ")Z^(" << degz << ")";
		return cout;
	}
};
template <class T>
class THeadList :public TList <T>
{
protected:
	TNode<T>* pHead;
public:
	THeadList() {
		pHead = new TNode<T>;
		pHead->pNext = pHead;
		pLast = pStop = pFirst = pPr = pCurr = pHead;
		pos = -1; len = 0;
	}
	~THeadList() {
		TList<T>::DelList();
		delete pHead;
	}
	THeadList(const THeadList<T>& list_object)
	{
		TNode<T>* tmp = list_object.pFirst, * curr;

		while (tmp != list_object.pStop)
		{
			curr = new TNode<T>;
			curr->val = tmp->val;
			if (pFirst == pStop)
			{
				pFirst = curr;
				pLast = curr;
			}
			else
			{
				pLast->pNext = curr;
				pLast = curr;
			}

			tmp = tmp->pNext;
		}
		pHead = new TNode<T>;
		pHead->pNext = pFirst;
		len = list_object.len;
		TList<T>::Reset();
	}
	void InsFirst(T _val) 
	{
		TList<T>::InsFirst(_val);
		pHead->pNext = pFirst;
	}
	void DelFirst() override {
		TList<T>::DelFirst();
		pHead->pNext = pFirst;
	}

};

