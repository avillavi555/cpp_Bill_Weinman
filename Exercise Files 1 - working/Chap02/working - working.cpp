// working.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

int main()
{
    int i;
    i = 7;
    int j = 5;
    const int m = 7;

    //m = 5;

    printf("value is %d\n", i);
    puts("Hello, World!");


    char s[] = "String1";
    printf("s is %s\n",s);
    for (int i = 0; s[i] != 0; i++) {
        printf("char is %c\n",s[i]);
    }

    char s1[] = { 'S','t','r','i','n','g','2',0};
    for (int i = 0; s1[i] != 0; i++) {
        printf("char is %c\n", s1[i]);
    }

    char s3[] = "String3";
    for (char* p = s3; *p != 0; ++p) {
        printf("char is %c\n", *p);
    }



    return 0;
}
