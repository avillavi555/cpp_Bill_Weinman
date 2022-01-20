// working.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>


int& f(int& i) {
    ++i;
    return i;
}

int main()
{
    int i = 7;
    f(i)=89;

    printf("i=%d\n",f(i));

    puts("Hello, World!");
    return 0;
}
