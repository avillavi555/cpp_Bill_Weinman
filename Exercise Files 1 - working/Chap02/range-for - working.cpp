// range-for.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

int main()
{
    int array[] = { 1, 2, 3, 4, 5 };
    for(int i : array) {
        printf("i is %d\n", i);
    }

    puts("**********");
    char array2[] = "Alexander";
    for (int i : array2) {
        printf("i is %c\n", i);
    }

    puts("**********");
    char array3[] = "Alexander";
    for (char i : array3) {
        printf("i is %c\n", i);
    }


    puts("**********");
    char array4[] = "Alexander";
    for (char i : array4) {
        if (i == NULL) break;
        printf("i is %c\n", i);
    }


    return 0;
}
