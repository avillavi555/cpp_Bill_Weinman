// working.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>
#include <stdint.h>
#include <stdio.h>

void f1(int x, void (*ptrFunc)()){
	printf( "Num: %d, PtrFunc: %p\n", x,ptrFunc);
    if(ptrFunc!=NULL)
    {
    	ptrFunc();  //Usando el puntero para retrollamar
    }
}

void f2(){
    printf( "f2\n");
}

int main(){

	void (*ptr1) (int , void (*ptrAsParam)()) = NULL;
	ptr1= f1;
	ptr1(5,f2);


    puts("Hello, World!");
    return 0;
}
