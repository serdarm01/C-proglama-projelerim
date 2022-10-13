#include <stdio.h>
int main ()
{
	char s[]="deneme";
	int a[5]={1,2,3,4,5};
	int x=10;
	int *ptr;
	putchar(*s);
	printf("\n%d\n",*a);
	*&x=20;
	printf("x=%d\n",x);
	ptr=&x;
	*ptr=30;
    printf("x=%d\n",x);
	return 0;
}
