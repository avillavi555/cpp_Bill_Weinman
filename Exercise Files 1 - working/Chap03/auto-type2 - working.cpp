// auto-type2.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>
#include <vector>

int main() {
    std::vector<int> vi = { 1, 2, 3, 4, 5 };
    for(std::vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) {
        printf("int is %d\n", *it);
    }

    std::vector<int> vi1 = { 1, 2, 3, 4, 5, 6 };
    for (auto it = vi1.begin(); it != vi1.end(); ++it) {
        printf("int is %d\n", *it);
    }




    return 0;
}
