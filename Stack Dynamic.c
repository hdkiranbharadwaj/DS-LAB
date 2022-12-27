#include<stdio.h>
#include<stdlib.h>
struct stack{
int *item;
int top;
};
typedef struct stack STK;
int SIZE;
void push(STK *);
void pop(STK *);
void peek(STK *);
void Display(STK );
int IsFull(STK *);
int IsEmpty(STK *);
void main()
{
int choice;
STK S;
S.top=-1;
printf("Enter the SIZE");
scanf("%d",&SIZE);
S.item=(int*)malloc(SIZE*sizeof(int));
for(;;)
{
printf("Enter the choice \n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY");
scanf("%d",&choice);
switch(choice)
{
case 1:push(&S);Display(S);break;
case 2:pop(&S);Display(S);break;
case 3:peek(&S);
case 4:Display(S);break;
default:exit(1);
}}}
void push (STK *pS)
{
int item;
if(IsFull(pS))
{printf("Full ");
 return;
}
printf("Enter the item \n");
scanf("%d",&item);
pS->top++;
*(pS->item+pS->top)=item;
}

void pop(STK *pS)
{
if(IsEmpty(pS))
{
printf("Empty");
return;
}
printf("Deleted %d",*(pS->item+pS->top));
pS->top--;
}
void Display(STK S)
{
if(IsEmpty (&S))
{
printf("Empty\n");
return;
}
printf("Data is \n");
while(S.top>=0)
{
printf("%d\n",*(S.item+S.top));
S.top--;
}
}
void peek(STK *pS)
{
if(IsEmpty(pS))
{
printf("Empty");
return;
}
printf("%d",*(pS->item+pS->top));
}

int IsEmpty(STK *pS)
{
if(pS->top==-1)
{
return 1;
}
return 0;
}
int IsFull(STK *pS)
{
if(pS->top==SIZE-1)
{
return 1;}
return 0;
}












