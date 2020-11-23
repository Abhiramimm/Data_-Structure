#include<stdio.h>
#include<conio.h>
int a[50],ch,item,top,n,i;
void push();
void pop();
void display();

int main()
{
   clrscr();
   top=0;
   printf("\nEnter the size of stack:");
   scanf("%d",&n);
   printf("\nSTACK OPERATION");
   printf("\n***************");
   printf("\n1.Push \n2.Pop\n3.Display \n4.Exit");
   do
   {
       printf("\n\nEnter your choice:");
       scanf("%d",&ch);
       switch(ch)
       {
	   case 1:
		    push();
		    break;
	   case 2:
		    pop();
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
void push()
{
  int item;
  if(top==n)
  {
     printf("\nOverflow");
  }
  else
  {
     printf("\nEnter new element:");
     scanf("%d",&item);
     top=top+1;
     a[top]=item;
     printf("\nSuccessfully inserted");
   }
}

void pop()
{

   if(top==0)
   {
      printf("\n\nUnderflow");
   }
   else
   {
       item=a[top];
       top=top-1;
       printf("\nSuccessfully deleted");
    }
}

void display()
{
   if(top==0)
   {
      printf("\nStack is empty");
   }
   else
   {
      printf("\ncurrent stack is :");
      for(i=top;i>=1;i--)
      {
	 printf("\n%d",a[i]);
      }
   }
}




