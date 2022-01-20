// template-function.cpp by Bill Weinman <http://bw.org/>
// updated 2020-07-21
#include <iostream>
//#include <string>

template <typename T>
T maxof ( T a, T b ) {
    return ( a > b ? a : b );
}

int main() {
    std::cout << maxof<int>( 7, 9 ) << std::endl;
    std::cout << maxof<const char *>( "aaa", "bbb" ) << std::endl;
    std::cout << maxof<std::string>( "aaa", "bbb" ) << std::endl;
    std::cout << maxof( 7, 9 ) << std::endl;

    return 0;
}
