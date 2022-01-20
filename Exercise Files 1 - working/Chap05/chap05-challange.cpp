#include <cstdio>



unsigned long int factorial(int n)
{
if (n<2)return 1;
return n*factorial(n-1);
}

int main(void)
{
	int n= 5;
	unsigned long int fact=1;
	int i=n;

	/*for(i=n;i>1;i--)
	{
		fact*=i;
	}*/

	while(i>1)
	{
		fact*=i--;

	}


	//printf("Factorial for %d is %ld", n,factorial(n));
	printf("Factorial for %d is %ld", n,fact);
	return 0;
}





