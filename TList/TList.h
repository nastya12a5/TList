#pragma once
#include<iostream>
#include <algorithm>

template <class T>
struct TNode
{
	T val;
	TNode<T>* pNext;
	TNode() { pNext = nullptr; }
};
template <class T>
class TList
{
protected:
	TNode<T>* pFirst, * pLast, * pStop, * pCurr, * pPr;
	int pos, len;
public:
	 TList()
	{
		pStop = nullptr;
		pFirst = pStop; pLast = pStop;
		len = 0; pos = -1; pCurr = pStop; pPr = pStop;
	}
	virtual void DelList() {
		TNode<T>* tmp = pFirst;
		while (pFirst != pStop)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
			
		}
		//pFirst = pLast = pPr = pCurr = pStop;
		len = 0; pos = -1;
	}
	  ~TList() { DelList(); }
	 TList(const TList<T>& obj)
	{
		TNode<T>* tmp = obj.pFirst;
		
		while (tmp != pStop)
		{
			InsLast(tmp->val);
			tmp = tmp->pNext;

		}
	}
	virtual void Reset()
	{
		pCurr = pFirst; pPr = pStop; pos = 0;
	}
	virtual void GoNext()
	{
		if (pCurr == pStop) { throw "Error"; }
		if (pCurr != pStop)
		{
			pPr = pCurr; pCurr = pCurr->pNext; pos++;
		}
	}
	virtual bool IsEnd()
	{
		return (pStop == pCurr);
	}
	virtual void InsFirst(T _val)
	{
		TNode <T>* tmp = new TNode<T>;
		tmp->val = _val;
		if (pFirst == pStop) {
			pLast = tmp;
			tmp->pNext = pStop;
		}
		else {
			tmp->pNext = pFirst;
		}
	    
		pFirst = tmp;
		len++; 

	}
	virtual void InsCurr(T _val)
	{
		if (len == 0)
		{
			throw std::exception();
		}
		
		
		else
		{
			TNode <T>* tmp = new TNode<T>;
			tmp->val = _val;
			pPr->pNext = tmp;
			tmp->pNext = pCurr;
			pPr = tmp;
			len++; pos++;
		}
	}
	virtual void InsLast(T _val)
	{
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		tmp->pNext = pStop;
		if (pLast==pStop)
		{
			pFirst = tmp;
			
		}
		else
		{
			pLast->pNext = tmp;
			
		}
		pLast = tmp; len++; pos++;
	}
	virtual void DelFirst()
	{
		if (len==0)
		{
			throw std::exception();
		}
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		len--;
	}
	virtual void DelCurr()
	{
		if (pCurr==pStop) { throw "Error"; }
		if (pCurr != pStop)
		{
			if (pCurr == pFirst)
			{
				DelFirst();
				pCurr = pFirst;
				pos = 0;
			}
			else
			{
				TNode<T>* tmp = pCurr;
				pCurr = pCurr->pNext;
				pPr->pNext = pCurr;
				delete tmp;
				len--;
			}
		}
	}
	virtual T & getCurrent() const
	{
		return pCurr->val;
	}
	virtual void SetPos(int _pos)
	{
		if (_pos < 0 || _pos >= len)
		{
			throw std::out_of_range("Invalid position");
	    }
		Reset();
		for (int i = 0; i < _pos; i++)
		{
			GoNext();
		}
	}

};

