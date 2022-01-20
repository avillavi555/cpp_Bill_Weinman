// class.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

// a very simple class
class C1 {
    int i = 0;
public:
    void setvalue( int value );
    //int getvalue();
    int getvalue()const;
};

void C1::setvalue( int value )
{ i = value; }
/*
int C1::getvalue()
{
	puts("non-const function");
	return i; }
*/
int C1::getvalue()const
{
	puts("const function");
	return i; }




int main() {
    int i = 47;
    C1 o1;

    o1.setvalue(i);
    const C1 o2=o1;

    printf("value is %d\n", o1.getvalue());
    printf("value is %d\n", o2.getvalue());
    return 0;
}
