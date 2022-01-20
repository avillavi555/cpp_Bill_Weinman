// working.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

template <typename T>
T factorial (T n){
	T rc=n;
	while(n>1){
	rc *= --n;
	}
	return rc;
}



int main()
{
	unsigned long int nl=5;
	printf("factorial de %ld es: %ld\n",nl,factorial(nl));

	unsigned int nui=5;
	printf("factorial de %d es: %d\n",nui,factorial(nui));

	int ni=5;
	printf("factorial de %d es: %d\n",ni,factorial(ni));

	long long unsigned int nll=15;
	printf("factorial de %lld es: %lld\n",nll,factorial(nll));

	long double nld=25;
	printf("factorial de %Lf ! es: %-4.10Lg\n",nld,factorial(nld));

    return 0;
}
