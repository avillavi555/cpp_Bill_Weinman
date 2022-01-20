// data.cpp by Bill Weinman <http://bw.org/>
// updated bw 2018-11-08
#include <cstdio>
using namespace std;

struct A1 {
    int ia;
    const char * sb = "";
    int ic;
} a3;
struct {
    int ia;
    const char * sb = "";
    int ic;
} a4;

int main() {
    A1 a;
    a.ia = 1;
    a.sb = "two";
    a.ic = 3;
    printf("ia is %d, sb is %s, ic is %d\n", a.ia, a.sb, a.ic);
    
    A1 a2 ={3,"two",1};
    A1 *ptrStr = &a2;
    printf("ia is %d, sb is %s, ic is %d\n", ptrStr->ia, ptrStr->sb, ptrStr->ic);

    a4 ={4,"two",5};
    printf("ia is %d, sb is %s, ic is %d\n", a4.ia, a4.sb, a4.ic);

    return 0;
}
