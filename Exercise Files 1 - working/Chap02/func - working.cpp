// func.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

void func()
{
    puts("this is func()");
}

void func1(int i, const char * p)
{
    printf("int %d, const char* %s", i , p);
}


int main()
{
    puts("this is main()");
    func();
    char c[] = "Alexander";
    const char* m = c;
    func1(34,m);
    return 0;
}

