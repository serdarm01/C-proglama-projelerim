#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Turkish");
	int i,j,ha=3,hb=3,hc=3,k,x=1,h=1,c=1,z=0,w=0;
	char m[10][4],mt[4][10];
    printf("Oyun hakkında bilgiler:\n1.kırılabilir camlar K ile gösterilmiştir\n2.Kırılıp kullanılamaz olan camlar D ile gösterilmiştir\n3.Sağlam camlar S ile gösterilmiştir\n4.Oyuncu sırası A,B,C şeklindedir\n\n");
	srand(time(NULL));
for(i=0;i<10;i++)
{
	k=rand()%4;
    for(j=0;j<4;j++)
	 {
	 	m[i][j]='S';
	 	m[i][k]='K';
	 }
}
 for(i=0;i<10;i++)
    {
        for(j=0;j<4;j++)
		{
            mt[j][i]=m[i][j];
        }
    }
    for(i=0;i<4;i++)
	{
        for(j=0;j<10;j++)
		{
            printf("%c ", mt[i][j]);
        }
        printf("\n");
    }
    printf("\nOyun başlamıştır:\n\n");
    aoyuncusu:
    	 	if(ha==0&&hb==0&&hc==0)
	{
	goto elenme;
	}
     while(x<11)
    {
    	if(ha==0)
    	{
    		goto boyuncusu;
		}
    	z++;
    	ayeniden:
        k=rand()%4;
        if(mt[k][x-1]=='D')
        {
        	goto ayeniden;
		}
    	printf("A oyuncus %d.sütun %d.basamağındadır\n",x,k+1);
		mt[k][x-1]='A';
    	for(i=0;i<4;i++)
    	{
    		for(j=0;j<x;j++)
    		{
    			 printf("%c ",mt[i][j]);
			}
			printf("\n");
		}
		 mt[k][x-1]=m[x-1][k];
         if(mt[k][x-1]=='K')
         {
         	mt[k][x-1]='D';
         	ha=ha-1;
         	printf("Basamak kırıldı\n");
         	x=1;
         	z=z+4;
         	goto boyuncusu;
		 }
		  if(x==10)
		 {
		 	goto asonuc;
		 }
		 if(z==3)
		 {
		 	x++;
		 	goto boyuncusu;
		 }
		 if(z>3)
		 {
		 	x++;
		 	goto boyuncusu;
		 }
		 x++;
    }
		boyuncusu:
	  	while(h<11)
		{
			if(hb==0)
    	{
    		goto coyuncusu;
		}
		w++;
		byeniden:
        k=rand()%4;
        if(mt[k][x-1]=='D')
        {
        	goto byeniden;
		}
    	printf("B oyuncus %d.sütun %d.basamağındadır\n",h,k+1);
		mt[k][h-1]='B';
    	for(i=0;i<4;i++)
    	{
    		for(j=0;j<h;j++)
    		{
    			 printf("%c ",mt[i][j]);
			}
			printf("\n")
		}
		 mt[k][h-1]=m[h-1][k];
         if(mt[k][h-1]=='K')
         {
         	mt[k][h-1]='D';
         	hb=hb-1;
         	printf("Basamak kırıldı\n");
         	h=1;
         	w=w+3;
         	goto coyuncusu;
		 }
		  if(h==10)
		 {
		 	goto bsonuc;
		 }
		  if(w==2)
		 {
		 	h++;
		 	goto coyuncusu;
		 }
          if(w>=3)
		 {
		 	h++;
		 	goto coyuncusu;
		 }
		 h++;		 
	}
	coyuncusu:
	while(c<11)
	 {
		if(hc==0)
    	{
    		goto aoyuncusu;
		}
		cyeniden:
        k=rand()%4;
        if(mt[k][c-1]=='D')
        {
        	goto cyeniden;
		}
    	printf("C oyuncus %d.sütun %d.basamağındadır\n",c,k+1);
		mt[k][c-1]='C';
    	for(i=0;i<4;i++)
    	{
    		for(j=0;j<c;j++)
    		{
    			printf("%c ",mt[i][j]);
			}
			printf("\n");
		}
		 mt[k][c-1]=m[c-1][k];
         if(mt[k][c-1]=='K')
         {
         	mt[k][c-1]='D';
         	hc=hc-1;
         	printf("Basamak kırıldı\n");
         	c=1;
         	goto aoyuncusu;
		 }
		  if(c==10)
		 {
		 	goto csonuc;
		 }
		 c++;
		 if(x==h&&h==c)
		 {
		 if(ha>0&&hb>0&&hc>0)
		 	{
		 	printf("Tüm oyuncular aynı sütündadır A B C sırasıyla oyuna devam edecektir\n");
		    }
		 	if(x==9)
		 	{
		 	x++;
		    }
		    c;
		    x+2;
		    h++;
		    w+3;
	    	goto devam;
		 }
	 	if(x==h||h==x)
	 	{
	 		if(ha>0&&hb>0)
	 		{
	 		printf("A ile B oyuncuları çakışmıştır A oyuncusu bir sonraki basamağa atlamıştır\n");
	 		x++;
	 		if(x==c)
	 		{
	 			printf("A bir sonraki basamakda C ile çakışmıştır\n");
	 			x++;
			 }
			 goto devam;
	 	    }
		 }
		 if(x==c||c==x)
		 {
		 	if(ha>0&&hc>0)
		 	{
		 printf("A ile C oyuncuları çakışmıştır A oyuncusu bir sonraki basamağa atlamıştır\n");
		 x++;
		 z+3;
		 if(x==h)
		 {
		 	printf("A oyuncusu B nin olduğu sütuna geçmiştir bu nedenle A B nin önünden başlar\n");
		 	x++;
		 }
	        }
		 }
		 if(h==c||c==h)
		 {
		 	if(hb>0&&hc>0)
		 	{
		 	printf("B ve C oyuncusu çakışmıştır B oyuncusu bir sonraki satıra atlamıştır\n");
		 	h++;
		    }
		 }
		 devam:
		 goto aoyuncusu;
	 }
	 
	    asonuc:
		if(x==10)
		{
		    printf("A=%d B=%d C=%d\n",ha,hb,hc);
		   if(ha==0)
    	 {
         printf("A oyuncusu elenmiştir\n");
         }
		if(hb==0)
    	{
    	printf("B oyuncusu elenmiştir\n");
		}
		if(hc==0)
    	{
    		printf("C oyuncusu elenmiştir\n");
		}
			printf("A oyuncusu kazanmıştır");
		}
		bsonuc:
		if(h==10)
		{
			printf("A=%d B=%d C=%d\n",ha,hb,hc);
			 if(ha==0)
    	{
    	printf("A oyuncusu elenmiştir\n");
        }
		if(hb==0)
    	{
    	printf("B oyuncusu elenmiştir\n");
		}
		if(hc==0)
    	{
    		printf("C oyuncusu elenmiştir\n");
		}
			printf("B oyuncusu kazanmıştır");
		}
		csonuc:
		if(c==10)
		{
		 printf("A=%d B=%d C=%d\n",ha,hb,hc);
		  if(ha==0)
    	{
    	printf("A oyuncusu elenmiştir\n");
        }
		if(hb==0)
    	{
    	printf("B oyuncusu elenmiştir\n");
		}
		if(hc==0)
    	{
    		printf("C oyuncusu elenmiştir\n");
		}
		 printf("C oyuncusu kazanmıştır");
		}
		elenme:
			if(ha==0&&hb==0&&hc==0)
	{
		printf("\nTüm oyuncular elenmiştir\n");
	}
    return 0;
}
