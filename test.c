//除了注释部分，其他地方不能有中文 
#include <stdio.h>

void mySwap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;	
}

int main()
{
	int a, b;
	a = 1;
	b = 2;
	
	printf("before swap:\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	
	mySwap(&a, &b);
	
	printf("after swap:\n"); 
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	
	return 0;
}
