// data.cpp by Bill Weinman <http://bw.org/>
// updated bw 2018-11-08
#include <cstdio>
using namespace std;

struct punto {
	int x;
	int y;
} pto = {3,4}, *ptr = &pto, arsp[10];
/*
struct {
	int x1;
	char *str;
	float *arr[10];
	struct punto pto;
} strA, *ptrA=&strA;
*/
class {
public:
	int x1;
	char *str;
	float *arr[10];
	struct punto pto;
} strA, *ptrA=&strA;

int main() {
    
	printf("x is %d, y is %d\n", ptr->x, ptr->y);
	(*ptr).x = 5;
	(*ptr).y = 6;
	printf("x is %d, y is %d\n", ptr->x, ptr->y);
	ptr->x = 7;
	ptr->y = 8;
	printf("x is %d, y is %d\n", ptr->x, ptr->y);

	float pi1 = 1.14159, pi2 = 2.14159;
	(*ptrA).x1 = 5;
	(*ptrA).str = "Alex";
	(*ptrA).arr[0] = &pi1;
	(*ptrA).arr[1] = &pi2;
	(*ptrA).arr[2] = nullptr;
	printf("x1 is %d, str is %s\n", ptrA->x1, ptrA->str);
	printf("x1 is %d, str is %s\n", (*ptrA).x1, (*ptrA).str);
	printf("arr[0] is %f \n",*(ptrA->arr[0]));
	printf("arr[1] is %f \n",*(ptrA->arr[1]));
	printf("arr[0] is %f \n",*(*ptrA).arr[0]);
	printf("arr[1] is %f \n",*(*ptrA).arr[1]);
	//printf("arr[2] is %f \n",*(ptrA->arr[2]));
	printf("arr[0] is %f \n",*strA.arr[0]);
	printf("arr[1] is %f \n",*strA.arr[1]);

	ptrA->str="AlexVillavicencio";
	printf("str is %s\n", ptrA->str);
	printf("str is %s\n", ptrA->str);
	printf("Letra \"%c\"\n",  *ptrA->str);
	//printf("Letra \"%c\"\n",  (*ptrA->str)++);
	//printf("Letra \"%c\"\n",  *ptrA++->str);
	printf("Letra \"%c\"\n",  *++ptrA->str);
	printf("Letra \"%c\"\n",  *++ptrA->str);
	printf("Letra \"%c\"\n",  *++ptrA->str);
	printf("Letra \"%c\"\n",  *ptrA->str++);

    return 0;
}
