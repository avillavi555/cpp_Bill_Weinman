// struct.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

struct SA {
    int i;
    double d;
    const char * s;
};

struct {
    int i;
    double d;
    const char* s;
} s3;

int main() {
    struct SA s1 = { 3, 47.9, "string one" };
    SA s2 = { 3, 47.9, "string one" };
    s3 = { 3, 47.9, "string one" };

    printf("s1: %d, %f, %s\n", s1.i, s1.d, s1.s);
    printf("s2: %d, %f, %s\n", s2.i, s2.d, s2.s);
    printf("s3: %d, %f, %s\n", s3.i, s3.d, s3.s);

    return 0;
}
