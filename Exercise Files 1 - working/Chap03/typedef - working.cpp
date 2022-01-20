// typedef.cpp by Bill Weinman <http://bw.org/>
// updated 2020-08-05
#include <cstdio>

typedef unsigned char points_t;
typedef unsigned char rank_t;
typedef char str_t;

struct score {
    points_t p;
    rank_t r;
    str_t t;
};

int main()
{
    score s = { 5, 1 , 'A'};
    printf("score s had %d points and a rank of %d, and char:%c\n", s.p, s.r, s.t);
    
    return 0;
}
