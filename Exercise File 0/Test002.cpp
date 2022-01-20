// working.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>
#include <stdint.h>
#include <stdio.h>


int main(){

    char arrCh[5];
    float *ptrF;
    int arrInt[4];
    char *ptrCh;
    int *ptrInt;

    ptrF=arrCh[4];
    ptrInt=ptrF;
    ptrCh=++ptrF;
    arrCh[3]=*(++ptrF);



    puts("Hello, World!");
    return 0;
}
