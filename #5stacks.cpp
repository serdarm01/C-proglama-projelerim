#include <stdio.h>
#define BOYUT 10

int dizi[BOYUT],top;

 
 void push(int veri)
 {
 
	 	top = top + 1;
	 	dizi[top]= veri;
	 		
 }
 void full()
 {
 		if(top + 1 == BOYUT)
 	{
 		printf("Stack doludur !! \n");
	 }
 }
 void empty()
 {
 	if(top == -1)
 	{
 		printf("Stack zaten bos");
	}
 }
 void pop()
 {
	   top=top-1;
 }
 int peek()
 {
 	return dizi[top];
 }
 void yazdir()
 {
 	int i;
 	
 	for(i=0;i<top+1;i++)
 	{
 	   printf("%d ", dizi[i]);
	}
	printf("==> TOP DEGER ");
 }
int main()
{	
    int secim,sayi;
    top=-1;
    while(1==1)
    {
	
	printf("\n1-push");
	printf("\n2-pop");
	printf("\n3-peek");
	printf("\n4-islem sonlandirma");
	printf("\nSecimini girin;");
	scanf("%d",&secim);
	
	switch(secim)
	{
		case 1:
			printf("\n bir sayi giriniz: ");
			scanf("%d",&sayi);
			push(sayi);
			if(top + 1 == BOYUT)
 	         {
			full();
		    }
			yazdir();
			break;
		case 2:	
		    full();
			if(top == -1)
 	        {
 		     pop();
	        }
			yazdir();
			break;
	   case 3:
           printf("islemler sona ermistir.");
      	break;
	}
      
    }
	return 0;
}
