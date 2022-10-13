#include <stdio.h>
int main()
{
	int i,j,a,b,c;
	printf("satir sayisini giriniz:");
	scanf("%d",&a);
	printf("sutun sayisini giriniz:");
	scanf("%d",&b);
	int m[a][b];
	
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			printf("satir %d sutun %d degerini girniz:",i+1,j+1);
			scanf("%d",&m[i][j]);
		}
		
	}
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			if(m[i][j]==1)
			{
				for(c=0;c<a;c++)
				m[c][j]=1;
			}
		}
	}
	printf("\nolusan matris sekli:\n");
	
  	for(i=0;i<a;i++)
 	{
		for(j=0;j<b;j++)
		{
			printf("%d ",m[i][j]);
		}
		printf("\n");
 	}
	return 0;
}
