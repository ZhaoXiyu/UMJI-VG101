#include <stdio.h>
#include <stdlib.h>
#define opmpow
#ifdef opmpow
#include "ex2_mpow.h"
#endif
#ifdef opprod
#include "ex2_prod.h"
#endif
#ifdef opquo
#include "ex2_quo.h"
#endif
#ifdef opsum
#include "ex2_sum.h"
#endif
#ifdef oprem
#include "ex2_rem.h"
#endif

int main(){
	int a, b;
	printf("Enter two integers: ");
	scanf("%d %d",&a, &b);
	#ifdef opquo
		printf("Quotient: %d\n",quo(a,b));
	#endif
	#ifdef oprem
		printf("Remainder: %d\n",rem(a,b));
	#endif
	#ifdef opsum
		printf("Sum: %d\n",sum(a,b));
	#endif
	#ifdef opprod
		printf("Product: %d\n",prod(a,b));
	#endif
	#ifdef opmpow
		printf("Exponent: %ld\n",mpow(a,b));
	#endif
	return 0;
}