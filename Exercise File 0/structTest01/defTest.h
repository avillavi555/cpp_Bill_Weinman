// class.cpp by Bill Weinman <http://bw.org/>
// updated bw 2018-10-03
#include <cstdio>
using namespace std;


class c11 {
    int i = 0;
public:
    void setvalue( const int & value ) { i = value; }
    int getvalue() const { return i; }
};

class c12 {
private:
	int i = 0;
public:
    void setvalue( const int & value ) { i = value; }
    int getvalue() const { return i; }
};

class c13 {
private:
	int i = 0;
public:
    void setvalue( const int & );
    int getvalue() const;
};



