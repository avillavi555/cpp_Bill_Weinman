// stack.cpp by Bill Weinman <http://bw.org/>
// updated 2018-09-14 for CppSTL
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <string>
using namespace std;

template <typename T>
void report_stack(T & stk) {
	printf("Alex\n");
    //cout << "size: " << stk.size() << " top: " << stk.top() << endl;
	cout << "size: " << stk.size() << endl;
    if(stk.size()) cout << "top2: " << stk.top();
    cout << endl;
}

// print a simple message
void message(const char * s) { cout << s << endl; }

int main()
{
    // vector
    message("stk1");
    vector<int> v1 = {1, 2, 3, 4, 5};
    stack<int, vector<int>> stk1(v1);
    report_stack(stk1);
    message("stk1 push 42");
    stk1.push(42);
    report_stack(stk1);
    message("stk1 pop");
    stk1.pop();
    report_stack(stk1);
    
    message("pop all from stk1");
    while(!stk1.empty()){
    	cout << stk1.top() << " ";
    	stk1.pop();
    }
    cout << endl;
    report_stack(stk1);

    message("stk2 default stack (deque)");
    stack<string> stk2;
    for(string s : {"one", "two", "three", "four", "five"}) {
        stk2.push(s);
    }
    report_stack(stk2);
    message("stk2 push forty-two");
    stk2.push("forty-two");
    report_stack(stk2);
    message("stk2 pop");
    stk2.pop();
    report_stack(stk2);
    
    message("pop all from stk2");
    while(!stk2.empty()){
    	cout << stk2.top() << " ";
    	stk2.pop();
    }
    cout << endl;
    report_stack(stk2);
    //cout << "size: " << stk2.size() << endl;
    //cout << "top: " << stk2.top() << endl;


    return 0;
}
