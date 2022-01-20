// template-variable.cpp by Bill Weinman <http://bw.org/>
// created 2018-09-08
#include <iostream>
using namespace std;

template<typename T>
T pi = T(3.1415926535897932385L);


template<typename T>
T areaCircle(const T & r){
	return r*r*pi<T>;
}

int main()
{

    cout.precision(20);
    cout << pi<double> << endl;
    cout << pi<float> << endl;
    cout << pi<long double> << endl;

    cout << "area: " << areaCircle<long double>(3);


    return 0;
}
