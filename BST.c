#include<stdio.h>
#include<stdlib.h>
struct node
{
  int info;
  struct node *llink;
  struct node *rlink;
};
  typedef struct node *NODE;
  NODE Construct(NODE);
  void Disp(NODE);
  NODE Search(NODE, int, NODE*);
  void Inorder(NODE);
  void Preorder(NODE);
  void Postorder(NODE);
  NODE Delete(NODE);
  int Count(NODE);

void main()
{
    int ch, key;
    NODE Root = NULL, NS=NULL, PN=NULL ;
    clrscr();
   
    for(;;)
      {
	printf("enter choice:1: Construction\n:\n2:Disp\n3:Search\n4:Delete\n");
	scanf("%d", &ch);
	 switch(ch)
	 {
	    case 1:  Root =Construct(Root);  break;
	    case 2:  Disp(Root);  break;
	    case 3:  printf("enter the key of node to be searched\n");
		     scanf("%d", &key);
		     if(Root->info == key)
		     {
		      printf("Searching node info = %d and No parent for the root n",Root->info);
		     }
		     else
		     {
		       NS=Search(Root,key, &PN);
		       if(NS==NULL)
		         printf("Node doens't exist\n");
		       else
		         printf("Searching node info = %d and its parent is:%d \n",NS->info, PN->info);
		     }
		     break;
	    case 4: Root =Delete(Root); Disp(Root); break;
	    
	    default: exit(0);
	 }
      }
}
NODE createnode()
{
	return ((NODE)malloc(sizeof(struct node)));
}
NODE Construct(NODE R)
{
     NODE NN, TP, PN;
     int ch;
     for(;;)
     {
       printf("enter 1 to continue inerting nodes, otherwise -1\n");
       scanf("%d", &ch);
       if(ch!=-1)
       {
          NN = createnode();
	  printf("enter info:");
	  scanf("%d", &NN->info);
	  NN->llink=NN->rlink=NULL;
	  if(R==NULL)  return NN;

		TP = R;
		PN = NULL;
	  while(TP!=NULL)
	  {
	   PN = TP;
	   if(NN->info<TP->info)
		TP = TP->llink;
	   else
	        TP = TP->rlink;
	  }
          if(NN->info<PN->info)
                PN->llink = NN;
          else
                PN->rlink = NN;
      } 
       else break;
     }
     return R;
} 
void Disp(NODE R)
{   
    int ch;
    if(R==NULL)
    {
      printf("Tree empty\n");
      return;
    }
    printf("\nInorder Traversal is: ");
    Inorder(R);
    printf("\nPreorder Traversal is: ");
    Preorder(R);
    printf("\nPostorder Traversal is: ");
    Postorder(R);
}
void Inorder(NODE R)
{
  if(R==NULL) return;
  Inorder(R->llink);
  printf("%d  ", R->info);
  Inorder(R->rlink);
}
void Preorder(NODE R)
{
  if(R==NULL) return;
   printf("%d  ", R->info);
  Preorder(R->llink);
  Preorder(R->rlink);
}
void Postorder(NODE R)
{
  if(R==NULL) return;
  Postorder(R->llink);
  Postorder(R->rlink);
  printf("%d  ", R->info);
}



int Count(NODE R)
{
	if(R==NULL) return 0;
	int count=0;
	count++;
	count=count+Count(R->llink);
	count=count+Count(R->rlink);
	return count;
}

int Height(NODE R)
{
	if(R==NULL) return -1;
	return(1+max(Height(R->llink),Height(R->rlink));
}
NODE Copy(NODE R)
{
	if(R==NULL)return NULL;
	NODE TN;
	TN=CreateNode();
	TN->info=R->info;
	TN->llink=Copy(R->llink);
	TN->rlink=Copy(R->rlink);
	return TN;
}
int Max(NODE R)
{
	NODE TP=R;
	while(TP->rlink!=NULL)
	 TP=TP->rlink;
	return TP->info;
}
int Min(NODE R)
{
	NODE TP=R;
	while(TP->llink!=NULL)
	 TP=TP->llink;
	return TP->info;
}





NODE Search(NODE R,int key, NODE *PN) 
{  
   NODE NS=NULL;
   if(R==NULL) return NULL;
   if(R->info==key)
   {
     NS = R;
   }
   if(NS==NULL)
   {
    *PN = R;
     if(key<R->info)
     	NS = Search(R->llink, key,PN);
     else
	NS = Search(R->rlink, key, PN);
   }
  return NS;
}

NODE Delete(NODE R)
{  
   int key;
   NODE  ND=NULL, PN=NULL, IS, ISP;
   NODE TP; 
   if(R==NULL)
    {
       printf("tree empty\n"); return NULL;
    }
   printf("enter key of the node to be deleted:\n");
   scanf("%d", &key);
   if(R->info==key && R->llink==NULL && R->rlink==NULL)
    {
      printf("deleted: %d\n", R->info);
      free(R);
      return NULL;

   }
   ND = Search(R, key, &PN);
   if(ND==NULL)
   {
      printf("Node doesn't exist\n");
      return R;
   }#include<stdio.h>
#include<stdlib.h>

struct node{

int info;
struct node *Llink,*Rlink;
};

typedef struct node *NODE;

NODE BST_Construction(NODE);
int Max(NODE);
int Min(NODE);

NODE Search(NODE R,int key);
NODE Delete(NODE R,int key);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
NODE CreateNode();
int Count(NODE);
int CountLeafNode(NODE);
int Height(NODE);
int NonLeafNode(NODE);
NODE Copy(NODE);
int Maxi(int, int);

void main()
{

	NODE SN = NULL;
	int key,res;
	NODE Root = NULL;
	int ch = 0;
	for(;;)
	{
		printf("Enter Your Choice : \n1.Tree Construction\n2.Search\n3.Delete\n4.Inorder Traversal\n5.PreOrder Traversal\n6.PostOrder Traversal\n7.Find Min\n8.Find Max \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0: exit(0);
			case 1 : Root = BST_Construction(Root);break;
			case 2 : printf("Enter the Value : ");
					scanf("%d",&key);
					SN = Search(Root, key);
					if(SN!=NULL)
					 printf("Element is Found.. ");
					 else
					 printf("NOT Found ");
					 break;
			case 3 : printf("Enetr the Value : ");
			scanf("%d",&key);
			Root = Delete(Root,key);
			break;
			case 4 : inorder(Root);break;
			case 5 : preorder(Root);break;
			case 6 : postorder(Root);break;
			case 7 : printf("Minimum Value : %d\n",Min(Root));break;
			case 8 : printf("Maximum Value : %d\n",Max(Root));break;
			default : printf("Invalid choice ..");break;
					 
		
		}
	}

}

void preorder(NODE R)
{
	if(R==NULL) return;
	printf("%d\t",R->info);
	preorder(R->Llink);
	preorder(R->Rlink);
}

void inorder(NODE R)
{
	if(R==NULL) return;
	inorder(R->Llink);
	printf("%d\t",R->info);
	inorder(R->Rlink);
}

void postorder(NODE R)
{
	if(R==NULL) return;
	postorder(R->Llink);
	postorder(R->Rlink);
	printf("%d\t",R->info);
}

int Count(NODE R)
{
	if(R == NULL) return 0;
	int count = 0;
	count ++;
	count = c    ount + Count(R->Llink);
	count = count + Count(R->Rlink);
	return count; 
}

NODE CreateNode()
{
	NODE NN = (NODE)malloc(sizeof(struct node));
	return NN;
}
NODE BST_Construction(NODE R)
{
	NODE PN,NN,TP;
	int ch;
	for(;;)
	{
	printf("Enter The Info(-1 for Termination) : ");
	scanf("%d",&ch);
	if(ch == -1) break;
	
	NN = CreateNode();
	NN->info = ch;
	NN->Llink = NN->Rlink = NULL;
	if(R == NULL) return NN;
	
	TP = R;
	while(TP != NULL)
	{
	PN = TP;
	if(NN->info<TP->info)
		TP = TP->Llink;
		else
		TP = TP->Rlink;
	
	}
	if(NN->info < PN->info)
	
		PN->Llink = NN;
		else
		PN->Rlink = NN;
		
	}
	return R;
	}



int Max(NODE R)
{
	NODE TP = R;
	while(TP ->Rlink != NULL)
		TP = TP->Rlink;
	return TP->info;
	
}

int Min(NODE R)
{
	NODE TP = R;
	while(TP ->Llink != NULL)
		TP = TP->Llink;
	return TP->info;
}

NODE Search(NODE R,int key)
{
	NODE SN = NULL;
	if(R == NULL) return NULL;
	if(R->info == key) SN = R;
	if(SN == NULL)
	{
		if(key<R->info)
			SN = Search(R->Llink,key);
			else
			SN = Search(R->Rlink,key);
		
	}
	return SN;
}


NODE Delete(NODE R,int key)
{
}


int CountLeafNode(NODE R)
{
	if(R == NULL) return 0;
	int count = 0;
	if(R->Rlink == NULL && R->Llink == NULL)
	count ++;
	count = count + CountLeafNode(R->Llink);
	count = count + CountLeafNode(R->Rlink);
	return count; 
}

int Height(NODE R)
{
	if(R == NULL) return -1;
	return (1+Maxi(Height(R->Llink),Height(R->Rlink));
}
int Maxi(int a , int b)
{
	return a>b?a:b;
}
int NonLeafNode(NODE R)
{
	return (Count(R)-CountLeafNode(R));
}
NODE Copy(NODE R);


















   printf("node to be deleted is %d and ites parent is:%d\n", ND->info, PN->info);
   if(ND->llink==NULL && ND->rlink==NULL)
   {
     if(ND==PN->llink)
       PN->llink=NULL;
     else
       PN->rlink=NULL;
       printf("deleted:%d\n", ND->info);
       free(ND);
     return R;
   }
   else 
   if(ND->llink!=NULL && ND->rlink==NULL || ND->llink==NULL && ND->rlink!=NULL)
   {
     if(ND->rlink==NULL)
      TP = ND->llink;
	else
      TP = ND->rlink;
       if(ND==PN->rlink)
	  PN->rlink= TP;
       else
	    PN->llink=TP;

      printf("deleted:%d\n", ND->info);
       free(ND);
       return R;
 }
 else  
 {
   IS=ND->rlink;  ISP = ND;
   while(IS->llink !=NULL)  
   {
     ISP = IS;
     IS = IS->llink;
   }
   printf("deleted:%d \n",ND->info);
   ND->info = IS->info;
   if(IS->llink==NULL && IS->rlink==NULL) 
   {
     if( IS == ISP->llink)
	 ISP->llink = NULL;
     else
	  ISP->rlink=NULL;
   }
   else  
   {
     if( IS == ISP->llink)
	 ISP->llink = IS->rlink;
     else
	  ISP->rlink=IS->rlink;
   }
   free(IS);
    return R;
 } 

 }
