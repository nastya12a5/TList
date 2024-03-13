

#include <iostream>
#include "TPolinom.h"

using namespace std;
int main()
{
    
    int ms1[][2] = { {-2,643},{-1,543},{9,100} };
    int mn1 = sizeof(ms1) / (2 * sizeof(int));
    TPolinom p(ms1, mn1);
   cout << "Polinom 1= " << p << endl;
   int ms2[][2] = { {2,643},{3,543},{9,101} };
   int mn2 = sizeof(ms2) / (2 * sizeof(int));
   TPolinom p1(ms2, mn2);
   
   cout << "Polinom 2= " << p1 << endl;
   TPolinom p2 = p + p1;
   //p += p1;
   cout << "1+2= " << p2 << endl;
   int ms3[][2] = { {-2,643},{-1,543},{9,100} };
   int mn3 = sizeof(ms1) / (2 * sizeof(int));
   
   TPolinom p3(ms3, mn3);
   cout << "Polinom 3= " << p3 << endl;
   TMonom m(4, 443);
   p3.AddMonom(m);
   cout << "AddMonom " << p3 << endl;
   p3 -= p1;
   cout << "3-2= " << p3 << endl;
   TPolinom p4(p3);
   cout << p4<<endl;
   TPolinom p5 = p4 - p1;
   cout << p5;
}

