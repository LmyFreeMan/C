# include<stdio.h>
# include<stdlib.h>
# include"sqstack.h"
void main()
{
	int elem,e;
	int a;
	sqstack l;
	initstack(l);
	printf("������'('����'[',���س�������\n");
	while(1)
	{
	  e=getchar();
	  if(e=='#')
		break;
	 push(l,e);
	}
    printf("������')'����']',��#�ż�����'\n");
	getchar();
	while(1)
	{ 
      elem=getchar();
      switch(elem)
	  {
	  case ')':if (pop(l,a) == '(') break;
			   else { printf("ƥ��ʧ��");exit(0); }
	  case ']':if(pop(l,a) == '[') break;
			   else {
				   printf("ƥ��ʧ��");exit(0);
			   }
	  case '#':break;
	  }
	  break;
	}
	printf("ƥ��ɹ�");
	while (1)
	{
		getchar();
	}
}
