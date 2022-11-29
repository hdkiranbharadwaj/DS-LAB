#include<stdio.h>
#include<stdlib.h>
int SIZE,N;
int* Read(int*);
void Display(int*);
int* Realloc(int*);
int* insertrear(int*);
int* insertfront(int*);
void deletefront(int*);
void deleterear(int*);
int* insertbypos(int*);
void deletebypos(int*);
int* insertbyorder(int*);
void sort(int*);
int search(int*);
void main()
{ 
  int *A,choice,index;
  system ("clear");
  printf("Enter array size\n");
  scanf("%d",&SIZE);
  A=(int*)malloc(SIZE*sizeof(int));
  if(A==NULL)
  { 
    printf("Memory full\n");
    exit(0);
  }
for(;;)
{
  printf("Enter choice\n 1.Read\n 2.Display\n 3.insertrear\n 4.insertfront\n 5.deletefront\n 6.deleterear\n 7.insertbypos\n 8.deletebypos\n 9.insertbyorder\n 10.sort\n 11.search\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:A=Read(A);break;
    case 2:Display(A);break;
    case 3:A=insertrear(A);Display(A);break;
    case 4:A=insertfront(A);Display(A);break;
    case 5:deletefront(A);Display(A);break;
    case 6:deleterear(A);Display(A);break;
    case 7:A=insertbypos(A);Display(A);break;
    case 8:deletebypos(A);Display(A);break;
    case 9:A=insertbyorder(A);Display(A);break;
    case 10:index=search(A);
            if(index==-1)
            printf("Not present\n");
            else
            printf("%d present at %d\n",A[index],index+1);
            break;
    case 11:sort(A);Display(A);break;
    default:exit(0);
  }
}
}
int* Read(int* p)
{
      int i;
	printf("Enter the value of N\n");
	scanf("%d",&N);
	if(N>SIZE)
	{
	p=Realloc(p);}
	printf("Enter the numbers\n");
	for(i=0;i<N;i++)
	{
 	 scanf("%d",p+i);
	}
	return (p);
        
}
void Display(int *p)
{   int i;
	for(i=0;i<N;i++)
	{
 	 printf("%d\n",*(p+i));
	}
}
int* Realloc(int *p)
{
	p=(int*)realloc(p,(SIZE*2)*sizeof(int));
	if (p==NULL)
	{
	printf("Memory Full\n");
	exit(0);
	}
	return(p);
}
int* insertrear(int* p)
{
	int i,item;
	if(N==SIZE)
	{
	printf("Array Full\n");
	p=Realloc(p);
 	}
	printf("Enter the item\n");
	scanf("%d",&item);
	*(p+N)=item;
	N++;
	return(p);
}
int* insertfront(int* p)
{
	int i,item;
	if(N==SIZE)
	{
	printf("Array Full\n");
	p=Realloc(p);
 	}
	printf("Enter the item\n");
	scanf("%d",&item);
	for(i=N-1;i>=0;i--)
	{
	*(p+i+1)=*(p+i);
 	}
	*(p)=item;
	N++;
	return(p);
}
void deletefront(int* p)
{
	int i;
	if(N==0)
	{
	printf("Array Empty");
	return;
	}
	printf("Deleted %d \n",*(p));
	for(i=0;i<N;i++)
	{
 	 *(p+i)=*(p+i+1);
	}
	N--;
}
void deleterear(int* p)
{
	
	if(N==0)
	{
	printf("Array Empty");
	return;
	}
	printf("Deleted %d \n",*(p+N-1));
	N--;
}
int* insertbypos(int *p)
{
	int i,pos,item;
	if(N==SIZE)
	{
	printf("Array Full\n");
	p=Realloc(p);
 	}
	L1: printf("Enter the position from 1 to %d\n",N+1);
	scanf("%d",&pos);
	if(pos<1||pos>N+1) goto L1;
	printf("Enter the item\n");
	scanf("%d",&item);
	for(i=N-1;i>=pos-1;i--)
	{
	*(p+i+1)=*(p+i);
 	}
	*(p+pos-1)=item;
	N++;
	return(p);
}
void deletebypos(int *p)
{
	int i,pos;
	if(N==0)
	{
	printf("Array Empty\n");return ;
 	}
	L1: printf("Enter the position from 1 to %d\n",N);
	scanf("%d",&pos);
	if(pos<1||pos>N) goto L1;
	for(i=pos-1;i<N;i++)
	{
	*(p+i)=*(p+i+1);
 	}
	N--;
}
int* insertbyorder(int *p)
{
       int i,item;
       if(N==SIZE)
       p=Realloc(p);
       printf("Enter the item\n");
       scanf("%d",&item);
       for(i=N-1;i>=0&&*(p+i)>item;i--)
       *(p+i+1)=*(p+i);
       *(p+i+1)=item;
       N++;
       return(p);
}
int search(int *p)
{
     if(N==0)
     return -1;
     int i,item;
     printf("Enter item to be searched\n");
     scanf("%d",&item);
     for(i=0;i<=N-1;i++)
     {
      if(*(p+i)==item)
      return i;
     }
     return -1;
}
void sort (int *p)
{
     int i,j,temp;
     for(j=0;j<N-i-1;j++)
     {
     if(*(p+j)>*(p+j+1))
     {
      temp=*(p+j);
      *(p+j)=*(p+j+1);
      *(p+j+1)=temp;
     }
     }
}
  
