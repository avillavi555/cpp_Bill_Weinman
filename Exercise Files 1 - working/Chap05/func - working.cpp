// func.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>
//#include "func.h"
#include <string>

/*
void func(const int &i)
{
	i= 20;
    puts("this is func()");
    printf("int i = %i\n",i);
}
*/
void func(const std::string & s)
{

    printf("string: %s\n",s.c_str());
}

int main()
{
	int i =10;
	std::string s = "Alexander Pelota";
    puts("this is main()");
    printf("Before: int i = %i\n",i);
    func(s);
    puts("this is main()");
    printf("After:  int i = %i\n",i);
    return 0;
}


