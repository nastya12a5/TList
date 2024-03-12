#pragma once                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
# ifndef __POLINOM_H__ 
 
#define __POLINOM_H__  
#include "../TList/THeadList.h "
#include <math.h>
using namespace std;
class TPolinom : THeadList<TMonom>
{
public:
	TPolinom(int monoms[][2], int km)
	{
		TMonom tmp(0, -1);
		pHead->val = tmp;
		for (int i = 0; i < km; i++)
		{
			TMonom monom((double)monoms[i][0], monoms[i][1]);
			InsLast(monom);
		}
	}
	TPolinom(TPolinom& q)
	{
		TMonom h(0, -1);
		pHead->val = h;
		for (q.Reset(); !q.IsEnd(); q.GoNext())
		{
			TMonom monom = q.getCurrent();
			InsLast(monom);
		}
	}
	friend TPolinom& operator + (TPolinom& p,TPolinom& Q)
	{
		
		TPolinom result(0, -1);
		p.Reset();
		Q.Reset();
		while (1)
		{
			
			if (p.pCurr->val.index > Q.pCurr->val.index) p.GoNext();
			else
				if (p.pCurr->val.index < Q.pCurr->val.index)
				{

					p.InsCurr(Q.pCurr->val);
					Q.GoNext();

				}
				else
				{
					if (p.pCurr->val.index == -1) break;
					p.pCurr->val.Coeff=p.pCurr->val.Coeff + Q.pCurr->val.Coeff;
					if (p.pCurr->val.Coeff == 0)
					{
						 
							p.DelCurr();

					}
					else {
						if (p.pCurr->val.Coeff != 0)
						{
							p.GoNext();
							Q.GoNext();
						}
					}
				}
		}
		return p;
	}
	TPolinom& operator+=(TPolinom& Q)
	{
		
		Reset();
		Q.Reset();
		while (1)
		{
			
			if (pCurr->val.index > Q.pCurr->val.index) GoNext();
			else
				if (pCurr->val.index < Q.pCurr->val.index)
				{
					
					InsCurr(Q.pCurr->val);
					Q.GoNext();
					
				}
				else
				{
					if (pCurr->val.index == -1) break;
					pCurr->val.Coeff += Q.pCurr->val.Coeff;
					if (pCurr->val.Coeff == 0)
					{
						if (pCurr == pFirst) {
							DelCurr();
							pCurr = pFirst;
							
						}
						else
							DelCurr();
						Q.GoNext();
					}
					else {
						if (pCurr->val.Coeff != 0)
						{
							GoNext();
							Q.GoNext();
						}
					}
					
				}
		}
		return *this;
	}
	TPolinom& operator -=(TPolinom& q)
	{
		TPolinom n=q.operator*(-1);
		operator+=(n);
		return *this;


	}
	void AddMonom(TMonom m)
	{
		pCurr = pFirst;
		while (m.index < pCurr->val.index)
		{
			GoNext();

		}
		if (pCurr->val.index == m.GetIndex())
		{
			if (m.Coeff + pCurr->val.Coeff == 0)
				DelCurr();
			else pCurr->val.Coeff = m.GetCoeff() + pCurr->val.Coeff;
		}
		else
		{
			InsCurr(m);
		}

	}
	TPolinom& operator*(double c)
	{
		for (Reset(); !IsEnd(); GoNext())
		{
			pCurr->val.Coeff = pCurr->val.Coeff * c;
		}
		return *this;
	}
	TPolinom& operator =(TPolinom& Q)
	{
		while (pHead->pNext != pStop) DelFirst();
		for (Q.Reset(); !Q.IsEnd(); Q.GoNext())
		{
			TMonom tmp = Q.pCurr->val;
			InsLast(tmp);
		}
		return *this;
	}
	friend ostream& operator<<(ostream & os, TPolinom& q)
	{
		for (q.Reset(); !q.IsEnd(); q.GoNext())
			 os<< q.pCurr->val.Coeff <<" " << q.pCurr->val.index << ' ';
		return os;
	}
	

};
#endif   