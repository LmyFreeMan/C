#include "DynaSqStack.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
void main()
{
	
	bool In(char);
	char Precede(char ch1,char ch2);
	char Operate(char a,char theta,char b);
	int  i=0;
	char c,string[40];
	ElemType a,b,theta,e,x;
	printf("that is ok!\n");
	SqStack OPND,OPTR;
	InitStack(OPND);//操作数
	InitStack(OPTR);//操作符号
    Push(OPTR,'#');
	//输入表达式，例如：4+2#
			gets_s(string);
	for(c=string[i];c!='\0';i++,c=string[i]) 
	     putchar(c);
    printf("\n");
	i=0;
	c=string[i];
	while(c!='#'||GetTop(OPTR)!='#')
	{	
		if(!In(c))
		{
			Push(OPND,c);i++;c=string[i];
		}
		else
			switch(Precede(GetTop(OPTR),c))
		{
			case '<':Push(OPTR,c);i++;c=string[i];break;
			case '=':Pop(OPTR,x);i++;c=string[i];break;
			case '>':Pop(OPTR,theta);Pop(OPND,b);Pop(OPND,a);
				     Push(OPND,Operate(a,theta,b));
					 break;
		}
	}
	
	printf("%d\n",GetTop(OPND)-'0');
}
bool In(char ch)
{
	char OP[7]={'#','+','-','*','/','(',')'};
	int i,flag=0;
	for(i=0;i<=6;i++)
		if (ch==OP[i]) {flag=1;break;}
	if(flag==1)
		return true;
	else
		return false;
}
char Precede(char ch1,char ch2)
{
	char result;
	switch(ch1)
	{
	case '+': switch(ch2)
			  { 
	              case '#':
				  case '+':
                  case '-':result='>';break;
	              case '*':
	              case '/':result='<';break;
			  };break;
	case '-':switch(ch2)
			 {
				 case '#':
				 case '+':
                  case '-':result='>';break;
	              case '*':
	              case '/':result='<';break;
			 };break;
	case '*':switch(ch2)
			 {
		          case '#':
				 case '+':
                  case '-':
	              case '*':
	              case '/':result='>';break;
			 }break;
    case '/':switch(ch2)
			 {
		          case '#':
				 case '+':
                  case '-':
	              case '*':
	              case '/':result='>';break;
			 }break;
	case '#':switch(ch2)
			 {
		          case '#':
				  case '+':
                  case '-':
	              case '*':
	              case '/':result='<';break;
			 }break;
	}
	return result;
}
char Operate(char a,char theta,char b)
{
	int inta,intb,intc;
	inta=a-'0';intb=b-'0';
//	printf("inta=%d,intb=%d,theta=%c\n",inta,intb,theta);
    switch(theta)
	{
	    case '+':intc=inta+intb;break;
		case '-':intc=inta-intb;break;
        case '*':intc=inta*intb;break;
        case '/':intc=inta/intb;break;
	}
//	printf("intc=%d\n",intc);
	return intc+'0';

}





				


			