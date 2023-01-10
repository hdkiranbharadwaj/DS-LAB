#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct Queue{
int item[SIZE];
int F,R;
};
typedef struct Queue QUE;
void Insert(QUE*);
void Delete(QUE*);
void Display(QUE);

void main()
{
	QUE Q;
	Q.F=0;
	Q.R=-1;
	for(;;)
	{
		int choice;
		printf("Enter your choice \n1.Insert\n2.Delete\n3.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:Insert(&Q);Display(Q);break;
			case 2:Delete(&Q);Display(Q);break;
			case 3:Display(Q);break;
			default:exit(0);
		}
	}
}
void Insert(QUE *PQ)
{
	int item;
	if(PQ->R==SIZE-1)
	{
		printf("Full");
		return;
	}
	printf("Enter the item\n");
	scanf("%d",&item);
	PQ->R++;
	PQ->item[PQ->R]=item;
}
void Delete(QUE *PQ)
{
	if(PQ->F>PQ->R)
	{
		printf("Empty\n");
		return;
	}
	printf("Deleted is %d",PQ->item[PQ->F]);
	PQ->F++;
	if(PQ->F>PQ->R)
	{
		PQ->F=0;
		PQ->R=-1;
	}
}

void Display(QUE Q)
{
	if(Q.F>Q.R)
	{
		printf("Empty\n");
		return;
	}
	
	printf("Data is\n");

	while(Q.F<=Q.R)
	{
		printf("%d\n",Q.item[Q.F++]);
	}
}
