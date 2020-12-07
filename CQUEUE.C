#include<stdio.h>
#include<conio.h>


int q[25],front=0,rear=0,n,item,i;
void insert();
void delet();
void display();

int main()
{

   int ch;
   clrscr();
   printf("\nEnter the size of queue:");
   scanf("%d",&n);
   printf("\nCIRCULAR QUEUE OPERATION");
   printf("\n************************");
   printf("\n1.Insert \n2.delete\n3.Display \n4.Exit");
   do
   {
       printf("\n\nEnter your choice:");
       scanf("%d",&ch);
       switch(ch)
       {
	   case 1:
		    insert();
		    break;
	   case 2:
		    delet();
		    break;
	   case 3:
		   display();
		   break;
	   case 4:
		    break;
	   default:
		    printf("\nInvalid choice");
       }
    }while(ch!=4);
    getch();
    return 0;
}
void insert()
{

  if((front==1 && rear==n)||(front==rear+1))
  {
     printf("\nOverflow");
  }
  else
  {
     if(front==0)
     {
	front=1;
	rear=1;
     }
      else if(rear==n)
      {
	 rear=1;
      }
      else
      {
	 rear=rear+1;
      }
      printf("\nEnter an item:");
      scanf("%d",&item);
      q[rear]=item;
      printf("\nsuccessfully innserted");
  }

}

void delet()
{

   if(front==0)
   {
      printf("\n\nUnderflow");
   }
   else
   {
       item=q[front];
       if(front==rear)
       {
	   front=0;
	   rear=0;
       }
       else if(front==n)
       {
	   front=1;
       }
       else
       {
	 front=front+1;
       }
       printf("\ndeleted successfully");
   }
}

void display()
{
   if(front==0)
   {
      printf("\nqueue is empty");
   }
   else
   {
      printf("\ncurrent queue is :");
      if(front>rear)
      {
	       for(i=front;i<=n;i++)
	       printf("\t%d",q[i]);
	       for(i=1;i<=rear;i++)
	       printf("\t%d",q[i]);

       }
       else
       {
	  for(i=front;i<=rear;i++)
	  printf("\t%d",q[i]);

       }

   }
}