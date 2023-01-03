#include<stdio.h>
#include<string.h>
int size 20
struct stk1
{
  char item[size];
  int top;
};
typedef struct stk1  Oprstk;
struct stk2
{
  char item[10][size];
  int top;
};

typedef struct stk2  Opndstk;

void push1(char c, Oprstk *s)
{
  if(s->top ==size-1)
   printf("stack full\n");
  else
 s->top++;
  s->item[s->top] = c;
}

char pop1(Oprstk *s)
 {
    char c;
   if(s->top ==-1)
   printf("stack empty\n");
  else
   c = s->item[s->top];
    s->top--;
 return c;
}
void push2(char c[], Opndstk *s)
{
  if(s->top ==size-1)
   printf("stack full\n");
  else
 s->top++;
  strcpy(s->item[s->top], c);
}

char* pop2(Opndstk *s)  //   char[]
 {
    char *c; //    char c[10]
   if(s->top ==-1)
   {
   printf("stack empty\n");
	}
  else

   c = s->item[s->top];   // strcpy(c, s->item[s->top])
    s->top--;
 return c;   // return c;

}
void par(Oprstk *oprtr, Opndstk *opnd)
{
  char *op1, *op2, opr, t[2], pexp[20];
   opr = pop1(oprtr); 
   t[0] = opr;
   t[1]='\0';
    op2=pop2(opnd);
    op1=pop2(opnd);
    strcpy(pexp,t);
    strcat(pexp,op1);
    strcat(pexp,op2);
    push2(pexp, opnd);
}




int isoperand(char c)
{
   switch(c)
{
  case '+':
   case '-':
   case '*':
   case '/':
   case '(':
    case ')':
    case '$':
    case '^': return 0;
     default : return 1;
}
}

int stkprc(char c)
{
   switch(c)
{
   case '+':
  case '-': return 2;
   case '*':
   case '/':  return 4;
  case '$':
  case '^': return 6;
  case '(': return 0;
 }
}

int inprc(char c)
{
 switch(c)
{
   case '+':
  case '-': return 1;
   case '*':
   case '/':  return 3;
  case '$':
  case '^': return 7;
  case '(': return 8;
   case ')': return 0;
 }
}

void inpre(char in[], char pre[])
{
  Oprstk s1;
  Opndstk s2; 
 char c,temp[2];
  int i=0;
  s1.top = -1;
  s2.top=-1;
  while((c =in[i++]) !='\0')
{
  if(isoperand(c))   
   {
     temp[0]= c;    //  pos[j++]= c
     temp[1]='\0';
      push2(temp,&s2);
  }


    else
     {
      while(s1.top != -1 && stkprc(s1.item[s1.top]) > inprc(c))
	{
	   if(c ==')')
	    {
		while(s1.item[s1.top] !='(')
		       par(&s1,&s2);   // po[j++] = pop1(&s1);
			pop1(&s1);// s.top--
			break;
	     }
	  else
	    par(&s1,&s2); // po[j++] = pop(&s);

	}

    if(c!=')')
 push1(c,&s1);

     }

 }


  while(s1.top !=-1)
    par(&s1,&s2);   //po[j++] = pop(&s);
   
   strcpy(pre, s2.item[s2.top]);

}


main()
{
 char in[30],pre[30];
 // system("clear");
  clrscr();
  for(;;)
  {
  printf("enter exp and 0 to terminate\n");
  scanf("%s", in);
  if(strcmp(in, "0") == 0) break;
  inpre(in, pre);
  printf("given infix expressionn is %s\n", in);
  printf(" converted Prefix expression: %s\n", pre);
  }
  getch();
}
