# include<stdio.h>
typedef struct{
	int *base;
	int *top;
	int stacksize;
} sqstack;
void initstack(sqstack &s);
void push(sqstack &s,int &e);
int pop(sqstack &s,int &e);
void destroystack(sqstack &s);
void index(sqstack &s);



