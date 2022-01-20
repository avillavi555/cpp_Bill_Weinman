// shared.cpp by Bill Weinman <http://bw.org/>
// 2018-11-10

#include <cstdio>
#include <memory>
#include "strc.h"

void message(const char * s) {
    printf("\n%s\n", s);
    fflush(stdout);
}

// display object value from shared_ptr (with reference count)
void disp(const std::shared_ptr<strc> & o) {
	printf("disp(): ");
    if(o) printf("%s fx (%ld)\n", o->value(), o.use_count());
    else puts("[null]");
    fflush(stdout);
}

int main1() {
    
    message("create pointer with one");
    auto a = std::make_shared<strc>("one");
    disp(a);
    
    std::shared_ptr<strc> b(new strc("two"));
    disp(b);
    
    message("reset a to three");
    a.reset(new strc("three"));
    disp(a);
    disp(b);
    
    message("more objects:");
    auto x1 = a;
    auto x2 = a;
    auto x3 = a;
    auto x4 = a;
    auto x5 = a;
    disp(a);

    x1.reset();
    x2.reset();
    x3.reset();
    x4.reset();
    x5.reset();
    disp(a);
    disp(b);


    message("c = a");
    auto c = a;
    disp(a);
    disp(b);
    disp(c);
    
    message("end of scope");
    return 0;
    
}
