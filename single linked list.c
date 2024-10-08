#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node * link;
};
typedef struct node* NODE;

int N=0;
NODE createnode();
void Display(NODE);
NODE insertrear(NODE);
NODE insertfront(NODE);
NODE deletefront(NODE);
NODE deleterear(NODE);
NODE insertbypos(NODE);
NODE deletebypos(NODE);
NODE deletebykey(NODE);
NODE insertbyorder(NODE);
NODE sort(NODE);
NODE search(NODE);
NODE reverse(NODE);
NODE cpyu(NODE);
void main()
{ 
  NODE First=NULL;
  NODE SN,copy,rev;
  int choice;
  system ("clear");
for(;;)
{
  printf("Enter choice\n 1.insertfront\n 2.Display\n 3.insertrear\n 4.deletefront\n 5.deleterear\n 6.search\n 7.insertbypos\n 8.insertbyorder\n 9.deletebykey\n 10.deletebypos\n 11.sort\n 12.copy\n 13.reverse\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:First=insertfront(First);Display(First);break;
    case 2:Display(First);break;
    case 3:First=insertrear(First);Display(First);break;
    case 4:First=deletefront(First);Display(First);break;
    case 5:First=deleterear(First);Display(First);break;
    case 6:SN =search(First);
            if(SN==NULL)
            printf("Not present\n");
            else
            printf("Node info is  %d\n",SN->info);
            break;
    case 7:First=insertbypos(First);Display(First);break;
    case 8:First=insertbyorder(First);Display(First);break;
    case 9:First=deletebykey(First);Display(First);break;
    case 10:First=deletebypos(First);Display(First);break;
    case 11:First=sort(First);Display(First);break;
    case 12: copy=cpyu(First);Display(copy);break;
    case 13:rev=reverse(First);Display(rev);break;
    default:exit(0);
  }
}
}

NODE insertfront(NODE pf)
{
	NODE NN;
	NN=createnode();
	printf("Enter the data\n");
	scanf("%d",&NN->info);
	NN->link=pf;
	pf=NN;
	N++;
	return pf;
}

void Display(NODE pf)
{       
	if(pf==NULL)
	{
	printf("Empty");
	return;
	}
        printf("DATA is\n");
	while(pf!=NULL)
	{
	printf("%d\n",pf->info);
	pf=pf->link;
	}
}

NODE createnode()
{
	NODE NN;
	NN=(NODE)malloc(sizeof(struct node));
	return NN;
}

NODE insertrear(NODE pf)
{
	NODE NN,LN;
	NN=createnode();
	printf("Enter the data\n");
	scanf("%d",&NN->info);
	LN=pf;
	if(LN==NULL)
	return NN;
	
	while(LN->link!=NULL)
	{LN=LN->link;}
	LN->link=NN;
	N++;
	return pf;
}


NODE deletefront(NODE pf)
{
	NODE FN;
	if(pf==NULL)
	{
	printf("Empty");
	return NULL;
	}
	FN=pf;
	pf=pf->link;
	printf("Deleted item is %d",FN->info);
	free(FN);
	N--;
	return pf;
}

NODE deleterear(NODE pf)
{
	NODE LN;
	NODE pLN=NULL;
	if(pf==NULL)
	{
	printf("Empty");
	return NULL;
	}
	LN=pf;
	while(LN->link!=NULL)
	{pLN=LN;
	LN=LN->link;
	}
	printf("Deleted item is %d",LN->info);
	N--;
	free(LN);
	if(pLN!=NULL)
	{
	pLN->link=NULL;
	}
	else
	{return NULL;}
	return pf;
}

NODE search(NODE pf)
{
	int key;
	printf("Enter key");
	scanf("%d",&key);
	while(pf!=NULL)
	{
	if(pf->info=key)
	{return pf;
	}
	pf=pf->link;
	}
	return NULL;
}

NODE insertbypos(NODE pF)
{
 	NODE NN,TP,PN;
 	int pos,cnt;
 	NN=createnode();
        printf("Enter the data\n");
 	scanf("%d",&NN->info);
  	NN->link=NULL;
	L1:printf("Enter position between 1 to %d",N+1);
   	scanf("%d",&pos);
 	 if(pos<1 || pos>N+1)  goto L1;
        TP=pF; PN=NULL; cnt=1;
  	while(cnt!=pos && TP!=NULL)
   	{
    	PN=TP;
    	TP=TP->link;
    	cnt++;
        }
  	if(PN==NULL)
  	{
   	NN->link=TP;
   	return NN;
  	} 
   	NN->link=TP;
  	PN->link=NN;
  	N++;
  	return pF;
}

NODE insertbyorder(NODE pF)
{
 	NODE NN,TP,PN;
	NN=createnode();
        printf("Enter the data\n");
	scanf("%d",&NN->info);
	NN->link=NULL;
	TP=pF; PN=NULL;
	while(TP!=NULL && TP->info<NN->info)
	  {
	   PN=TP;
	   TP=TP->link;
	  }
	if(PN==NULL)
	  {
	   NN->link=TP;
           return NN;
	  }
	NN->link=TP;
	PN->link=NN;
	N++;
	return pF;
}

NODE deletebykey(NODE pf)
{
	NODE ND,PN;
	int key;	
	if(pf==NULL)
	{
	printf("Empty");
	return NULL;
	}
	printf("Enter key");
	scanf("%d",&key);
	ND=pf;
	PN=NULL;
	while(ND!=NULL&&ND->info!=key)
	{PN=ND;
	ND=ND->link;
	}
	if(ND==NULL)
	printf("Not found");
	else if(PN==NULL)
	pf=pf->link;
	else 
	PN->link=ND->link;
	printf("Deleted item is %d",ND->info);
	N--;
	free(ND);
	return pf;
}


NODE deletebypos(NODE pf)
{
	NODE ND,PN;
	int pos,cnt;
	if(pf==NULL)
	{
	printf("Empty");
	return NULL;
	}
	L1:printf("Enter position between 1 to %d",N);
	scanf("%d",&pos);
	if(pos<1||pos>N) goto L1;
	ND=pf;
	PN=NULL;
	cnt=1;
	while(cnt!=pos)
	{PN=ND;
	ND=ND->link;
	cnt++;
	}
	if(PN==NULL)
	pf=pf->link;
	else 
	PN->link=ND->link;
	printf("Deleted item is %d",ND->info);
	N--;
	free(ND);
	return pf;
}

NODE sort(NODE pf)
{
	NODE TP;
	int i,j,temp;
	for(i=0;i<N-1;i++)
	{TP=pf;
	for(j=0;j<N-1-i;j++)
	{if(TP->info>TP->link->info)
	{temp=TP->info;
	TP->info=TP->link->info;
	TP->link->info=temp;
	}
	TP=TP->link;
	}
	}
	return pf;
}


NODE cpyu(NODE pf)
{       NODE NN,cpy,ccpy;
        NN=createnode();
        ccpy=cpy=NN;
        cpy->info=pf->info;
        pf=pf->link;
 while (pf!=NULL)
 {
   NN=createnode();
   cpy->link=NN;
   cpy=cpy->link;
   cpy->info=pf->info;
   pf=pf->link;
 }
      cpy->link=NULL;
      return ccpy;
 }

NODE reverse(NODE pf)
{NODE NN,rev;
 NN=createnode();
 rev=NN;
 rev->info=pf->info;
 rev->link=NULL;
 pf=pf->link;
 while (pf!=NULL)
{NN=createnode();
 NN->link=rev;
 rev=NN;
 rev->info=pf->info;
 pf=pf->link;
 }
return rev;
 }
