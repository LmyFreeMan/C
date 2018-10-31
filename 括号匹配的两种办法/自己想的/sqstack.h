# include<stdio.h>
typedef struct{
	int *base;
	int *top;
	int stacksize;
	int elemlength;
} sqstack;
void initstack(sqstack &s);
bool stackempty(sqstack s);
int stacklength(sqstack s);
void push(sqstack &s,int &e);
int  pop(sqstack &s,int &e);
void destroystack(sqstack &s);
void  stacktraverse(sqstack s);
void index(sqstack &s);



