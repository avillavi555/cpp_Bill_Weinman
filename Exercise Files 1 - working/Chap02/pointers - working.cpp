// pointers.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

int main()
{
    int x = 7;
    int y = 42;
    int * ip = &x;
    const int& g = x;

    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of *ip is %d\n", *ip);

    printf("La direccion de x is %p\n", &x);
    printf("The value of ip is %p\n", ip);

    x = 77;
    printf("The value of x is %d\n", x);
    printf("The value of g is %d\n", g);

    




    return 0;
}
