// template-function.cpp by Bill Weinman <http://bw.org/>
// updated 2018-08-18
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
T maxof ( const T & a, const T & b ) {
    return ( a > b ? a : b );
}
template <class T>
T maxofc ( const T & a, const T & b ) {
    return ( a > b ? a : b );
}

template<typename T>
void printv(const vector<T> & v){
	if(v.empty()) return;
	for(const T & i : v) cout << i << " ";
	cout << endl;
}



int main() {
    cout << " //////// " << endl;
    int a = 7;
    int b = 9;
    cout << "max is " << maxof<int>( a, b ) << endl;
    cout << "max is: " << maxof( a, b ) << endl;

    cout << " //////// " << endl;
    string sa = "alex";
    string sb = "lau";
    cout << "max is " << maxof<string>( sa, sb ) << endl;


    cout << " //////// " << endl;
    const char * spa = "alex";
    const char * spb = "lau";
    cout << "max is " << maxof<const char *>( spa, spb ) << endl;
    
    vector<int> v1= {1,2,3,4,5};
    printv<int>(v1);
    printv(v1);

    vector<string> s1= {"uno", "dos","tres"};
    printv<string>(s1);
    printv(s1);


    
    return 0;
}
