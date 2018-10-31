# include<stdio.h>
# include<string.h>

void main()
{
	 
	char i,j,k;
	char LA[4]={3,5,8,11};
	char LB[7]={2,6,8,9,11,15,20};
	char LC[11];
	i=j=k=0;
    while((i<4)&&(j<7))	
	{
		if(LA[i]>=LB[j])
		{
			LC[k]=LB[j];
			k++;
			j++;
		}
		else
		{
			LC[k]=LA[i];
			i++;
			k++;
		}
	}
    while(i<4)
	{
		LC[k]=LA[i];
		i++;
		k++;
	}
	 while(j<7)
	{
		LC[k]=LB[j];
		j++;
		k++;
	}
	 printf("LC={");
	 for(i=0;i<10;i++)
	 {
	 printf("%d,",LC[i]);
	 }
	 printf("%d}",LC[10]);
}
