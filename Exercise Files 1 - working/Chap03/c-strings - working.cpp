// c-strings.cpp by Bill Weinman <http://bw.org/>
// updated 2020-07-05
#include <cstdio>

int main() {

    char cstring0[] = "String0";
    const char * cstring1 = "String1"; // better


    char cstring2[] = 
        "String2" 
        "Str2";
    const char* cstring3 = 
        "String3" 
        "Str3"; 


    //cstring1 = NULL;

    puts(cstring0);
    puts(cstring1);
    //printf("cstring1 = %s", cstring1);
    puts(cstring2);
    puts(cstring3);
    
    for(int i = 0; cstring0[i]; i++) {
        printf("%d: %c\n", i, cstring0[i]);
    }
    return 0;
}
