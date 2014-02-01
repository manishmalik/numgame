#include<stdio.h>
#include<conio.h>
int main()
{
	long long int i,j;
	long int c=0;
	for(i=0;i<1000000000000000;i++)
		{
			if(i%35==0)
			{
				j=i;
				while(j!=0)
				{
					if(j%10==5||j%10==7)
						j=j/10;
					else
						break;
				}
				if(j==0)
					c++;
				else 
					continue;
			}
		 }
	printf("%ld",c);
	getch();
	return 0;
}