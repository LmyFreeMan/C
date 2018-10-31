
# include<stdio.h>
# include<string.h>
int m=1;
int k=1;
int w=1;
void main()
{
	char  a[100];
	char  b[100];
	char  c[100];
	int i,j,t,r,n,d;
	printf("请输入第一个大数");
     gets(a);
	printf("请输入第二个大数\n");
    gets(b);
	i=strlen(a);
	j=strlen(b);
	if(a[0]=='9'||b[0]=='9')
		w=0;
//	printf("%d %d",i,j);
  if(i>=j)
	  t=i;
  else 
	  t=j;
  r=t;
  while((i-1>=0)&&(j-1>=0))
  {
	  if(m==0)
	  {
		   c[t-1]=a[i-1]+b[j-1]-47;
		   	if(c[t-1]>57)
			{
	     	c[t-1]=a[i-1]+b[j-1]-57;
		if(i-1==0&&i==j)
				printf("1");
	      	m=0;
			}
			else
				m=1;
	  }
      else 
	{
		  c[t-1]=a[i-1]+b[j-1]-48;
	         if(c[t-1]>57)   
			 {
	      	c[t-1]=a[i-1]+b[j-1]-58;
			m=0; 
			 }

	}
	i--;
	j--;
	t--;
  }
	if(i!=j&&i==0)
	{
             if(m==0)
			 {
				 if(b[j-1]=='9'&&w==0)
				 {
					 c[j-1]='0';
					 if(j-1==0)
						 printf("1");
					 k=0;
				 }
				 else
					  c[j-1]=b[j-1]+1;

			 }
		else
			c[j-1]=b[j-1];
         for(n=j-2;n>=0;n--)
		 {
			 if(b[n]==57&&k==0&&w==0)
			 {
				 c[n]='0';
				 	if(n==0)
				printf("1");
			 }
			 else
			 c[n]=b[n];
			 
		 }
	}
		if(i!=j&&j==0)
		{
             if(m==0)
			 {
				 if(a[i-1]=='9')
				 {
					 c[i-1]='0';
					 if(i-1==0)
						 printf("1");
					 k=0;
				 }
				 else
					  c[i-1]=a[i-1]+1;

			 }
		else
			c[i-1]=a[i-1];
         for(n=i-2;n>=0;n--)
		 {
			 if(a[n]==57&&k==0)
			 {
				 c[n]='0';
				 	if(n==0)
				printf("1");
			 }
			 else
			 c[n]=a[n];
		 }
	}
//

  for(n=0;n<r;n++)
	  printf("%c",c[n]);
}