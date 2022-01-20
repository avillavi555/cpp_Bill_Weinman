// transform.cpp by Bill Weinman <http://bw.org/>
// 2018-09-19 for CppSTL
#include <iostream>
#include <vector>
#include <algorithm>
#include "rational.h"
using namespace std;

template <typename T>
class accum {
    T _acc = 0;
    accum(){}
public:
    accum(T n) : _acc(n){}
    T operator() (T y) { _acc += y; return _acc; }
};

template <typename T>
void disp_v(vector<T> & v) {
    if(!v.size()) return;
    for(T e :  v) { cout << e << " "; }
    cout << endl;
}


ostream & operator << (ostream & o, const Rational & r){
	return o << string(r);
}

int main()
{
    accum<int> x(7);
    cout << x(7) << endl;
    
    vector<int> v1 = { 1, 2, 3, 4, 5};
    disp_v(v1);
    
    vector<int> v2(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), x);

    disp_v(v2);
    
    /*****************************/

    accum<Rational> rx(Rational(3,5));
    cout << rx(7) << endl;

    vector<Rational> rv1 = { 1, 2, 3, 4, 5};
    disp_v(v1);

    vector<Rational> rv2(v1.size());
    transform(rv1.begin(), rv1.end(), rv2.begin(), rx);

    disp_v(rv2);




    return 0;
}
