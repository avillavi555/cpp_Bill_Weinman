// jump.cpp by Bill Weinman <http://bw.org/>
// a simple jump table
// updated 2020-08-27
#include <cstdio>

void fa() { puts("this is fa()"); }
void fb() { puts("this is fb()"); }
void fc() { puts("this is fc()"); }
void fd() { puts("this is fd()"); }
void fe() { puts("this is fe()"); }

void (*funcs[])() = { fa, fb, fc, fd, fe };

// prompt and return string
const char * prompt() {
    puts("Choose an option:");
    puts("1. Function fa()");
    puts("2. Function fb()");
    puts("3. Function fc()");
    puts("4. Function fd()");
    puts("5. Function fe()");
    puts("Q. Quit.");
    printf(">> ");
    fflush(stdout);                 // flush after prompt
    
    const int buffsz = 16;          // constant for buffer size
    static char response[buffsz];   // static storage for response buffer
    fgets(response, buffsz, stdin); // get response from console
    
    printf("response_1: %c\n",response[0]);
    printf("response_2: %c\n",response[1]);
    printf("response: %s\n",response);
    //printf("response*: %s\n",*response);
    printf("buffsz: %d\n",buffsz);
    printf("stdin: %d\n",stdin);

    return response;
}

// jump table
int jump( const char * rs ) {

    char code = rs[0];
    char code1 = rs[1];
    char code2 = rs[2];
    char code3 = rs[3];
    char code4 = rs[4];

    printf("code: %c\n",code);
    printf("code_h: %h\n",code);

    printf("code1: %c\n",code1);
    printf("code2: %c\n",code2);
    printf("code3: %c\n",code3);
    printf("code4: %c\n",code4);

    if(code == 'q' || code == 'Q') return 0;
    
    // get the length of the funcs array
    size_t func_length = sizeof(funcs);
    printf("func_length: %d\n",func_length);

    func_length = sizeof(funcs[0]);
    printf("func_length: %d\n",func_length);

    func_length = sizeof(funcs) / sizeof(funcs[0]);
    printf("func_length: %d\n",func_length);
    
    puts("*************");

    size_t i = code;   // convert ASCII numeral to int
    printf("i: %d\n",i);

    i = (size_t) code;   // convert ASCII numeral to int
    printf("i: %d\n",i);

    i = (size_t) code - '0';   // convert ASCII numeral to int
    printf("i: %d\n",i);

    if( i < 1 || i > func_length ) {
        puts("invalid choice");
        return 1;
    } else {
    	puts("Alex!!!");
        funcs[i - 1]();         // array is zero-based

    	puts("Alexander!!!");
        (*funcs[i - 1])();         // array is zero-based

        return 1;
    }
    
}

int main() {
    while(jump(prompt())) ;
    puts("\nDone.");
    return 0;
}

