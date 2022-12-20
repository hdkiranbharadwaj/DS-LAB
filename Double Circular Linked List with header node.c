#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node * RL;
struct node * LL;
};
typedef struct node* NODE;


NODE createnode();
void Display(NODE);
void insertrear(NODE);
void insertfront(NODE);
void deletefront(NODE);
void deleterear(NODE);
void insertbypos(NODE);
void deletebypos(NODE);
void deletebykey(NODE);
void insertbyorder(NODE);
NODE searchbykey(NODE);
void reverse(NODE);
NODE Copy(NODE);
void main()
{ 
  NODE Head=createnode();
  Head->info=0;
  Head->RL=Head; 
  Head->LL=Head; 
  NODE SN,copy;
  int choice;
  system ("clear");
for(;;)
{
  printf("Enter choice\n 1.insertfront\n 2.Display\n 3.insertrear\n 4.deletefront\n 5.deleterear\n 6.search\n 7.insertbypos\n 8.insertbyorder\n 9.deletebykey\n 10.deletebypos\n 11.reverse\n 12.copy\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:insertfront(Head);Display(Head);break;
    case 2:Display(Head);break;
    case 3:insertrear(Head);Display(Head);break;
    case 4:deletefront(Head);Display(Head);break;
    case 5:deleterear(Head);Display(Head);break;
    case 6:SN =searchbykey(Head);
            if(SN==NULL)
            printf("Not present\n");
            else
            printf("Node info is  %d\n",SN->info);
            break;
    case 7:insertbypos(Head);Display(Head);break;
    case 8:insertbyorder(Head);Display(Head);break;
    case 9:deletebykey(Head);Display(Head);break;
    case 10:deletebypos(Head);Display(Head);break;
    case 11:reverse(Head);Display(Head);break;
    /*case 12: copy=Copy(Head);Display(copy);break;*/
    
    default:exit(0);
  }
}
}
NODE createnode()
{
  NODE NN =(NODE)malloc(sizeof(struct node));
  return NN;
}
void Display(NODE PH)
{
	if(PH->info==0)
	{
		printf("Empty\n");
		return;	
	}
	NODE TP=PH->RL;
	while(TP!=PH)
	{
	printf("%d\n",TP->info);
	TP=TP->RL;
	}
}
void insertrear(NODE PH)
{
	NODE NN=createnode();
	printf("Enter the data\n");
	scanf("%d",&NN->info);
	NN->LL=PH->LL;
	NN->RL=PH;
	NN->LL->RL=NN;
	NN->RL->LL=NN;
	PH->info++;
}

void insertfront(NODE PH)
{	NODE NN;
	NN=createnode();
	printf("Enter the data\n");
	scanf("%d",&NN->info);
	NN->LL=PH;
	NN->RL=PH->RL;
	PH->RL=NN;
	NN->RL->LL=NN;
	PH->info++;
}
void deleterear(NODE PH)
{
	if(PH->info==0)
	{
	printf("Empty");
	return;
	}        
	NODE LN=PH->LL;
	PH->LL=LN->LL;
	LN->LL->RL=PH;
	printf("Deleted info is %d \n",LN->info);
	free(LN);
	PH->info--;
}
void deletefront(NODE PH)
{
	NODE FN;
	if(PH->info==0)
	{
		printf("Empty\n");
		return;
	}
	FN=PH->RL;
	PH->RL=FN->RL;
	FN->RL->LL=PH;
	printf("Deleted info is %d\n",FN->info);
	free (FN);
	PH->info--;
}
void insertbypos(NODE PH)
{
	NODE NN,TP;
 	int pos,cnt=1;
 	NN=createnode();
        printf("Enter the data\n");
 	scanf("%d",&NN->info);
	L1:printf("Enter position between 1 to %d",(PH->info+1));
   	scanf("%d",&pos);
 	 if(pos<1 || pos>PH->info+1)  goto L1;
	TP=PH->RL;
	
	while(cnt!=pos)
	{
	TP=TP->RL;
	cnt++;
	}
	NN->LL=TP->LL;
	NN->RL=TP;
	NN->LL->RL=NN;
	TP->LL=NN;
	PH->info++;
}
void insertbyorder(NODE PH)
{
	NODE TP=PH->RL;
	NODE NN=createnode();
	printf("Enter the number\n");
	scanf("%d",&NN->info);
	while(TP!=PH&&NN->info>TP->info)
	{
	TP=TP->RL;
	}
	NN->LL=TP->LL;
	NN->RL=TP;
	NN->LL->RL=NN;
	TP->LL=NN;
	PH->info++;
}
NODE searchbykey(NODE PH)
{	if(PH->info==0)
	  {return NULL;}
	int key;
	printf("Enter key");
	scanf("%d",&key);
	NODE TP=PH->RL;
	while(TP!=PH)
	{
		if(TP->info==key)
		{
		  return(TP);
		}
	TP=TP->RL;
	}
	return NULL;
}
void deletebykey(NODE PH)
{
	NODE TP;
 	int key;
	if(PH->info==0)
	{
	printf("Empty");
	return;
	} 
	printf("Enter the key");
	scanf("%d",&key);
	TP=PH->RL;
	while(TP!=PH&&TP->info!=key)
	{
	TP=TP->RL;}
	if(TP==PH)
	{
	printf("Not found");
	return;
	}
	TP->LL->RL=TP->RL;
	TP->RL->LL=TP->LL;
	printf("Deleted info is %d\n",PH->info);
	free(TP);
	PH->info--;
}
void deletebypos(NODE PH)
{
	NODE NN,TP;
	int pos,cnt;
	if(PH->info == 0)
	{
	printf("Empty List \n");
	return;
	}
	l1:printf("Enter The Position between 1 to %d\n",PH->info);
	scanf("%d",&pos);
	if(pos<1 || pos > PH->info) goto l1;
	cnt = 1;
	
	TP = PH->RL;
	while(cnt!=pos)
	{
	TP = TP->RL;
	cnt++;
	}
	TP->LL->RL = TP->RL;
	TP->RL->LL = TP->LL;
	printf("%d is Deleted\n",TP->info);
	free(TP);
	PH->info--;
}
void reverse(NODE PH)
{
	NODE temp = PH;
	NODE prev = NULL;
	NODE curr = NULL;
	while(temp != NULL)
	{
	curr = temp->RL;
	temp->RL = prev;
	temp->LL = curr;
	prev = temp;
	temp = curr;
	}
	PH = prev;
}


	
	

