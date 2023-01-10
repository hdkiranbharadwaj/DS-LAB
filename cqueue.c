 #include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct cQueue{
int item[SIZE];
int F,R,cnt;
};
typedef struct cQueue cQUE;
void Insert(cQUE*);
void Delete(cQUE*);
void Display(cQUE*);

void main()
{
	int choice;
	cQUE cQ;
	cQ.F=0;
	cQ.R=-1;
	cQ.cnt=0;
	for(;;)
	{
		
		printf("Enter your choice \n1.Insert\n2.Delete\n3.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:Insert(&cQ);Display(&cQ);break;
			case 2:Delete(&cQ);Display(&cQ);break;
			case 3:Display(&cQ);break;
			default:exit(0);
		}
	}
}
void Insert(cQUE *PQ)
{
	int item;
	if(PQ->cnt==SIZE)
	{
		printf("Full");
		return;
	}
	printf("Enter the item\n");
	scanf("%d",&item);
	PQ->R=(PQ->R+1)%SIZE;
	PQ->item[PQ->R]=item;
	PQ->cnt++;
}
void Delete(cQUE *PQ)
{
	if(PQ->cnt==0)
	{
		printf("Empty\n");
		return;
	}
	printf("Deleted is %d",PQ->item[PQ->F]);
	PQ->F=(PQ->F+1)%SIZE;
	PQ->cnt--;
	if(PQ->cnt==0)
	{
		PQ->F=0;
		PQ->R=-1;
	}
}

void Display(cQUE *Q)
{
	int i,j=Q->F;	
	if(Q->cnt==0)
	{
		printf("Empty\n");
		return;
	}
	printf("DATA IS\n");
	for(i=1;i<=Q->cnt;i++)
	{
		printf("%d\n",*(Q->item+j));
		j=(j+1)%SIZE;
	}
}
