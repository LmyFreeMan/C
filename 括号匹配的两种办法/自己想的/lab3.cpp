# include<stdio.h>
int main()
{
	long s=0;
	int i,j,k;
	i=1;
	for(k=1;k<20;k++)
	{
		for(j=1;j<=k;j++)
			i=i*j;
		    s=s+i;
			i=1;
	}
	printf("%d",s);
	return 0;
}