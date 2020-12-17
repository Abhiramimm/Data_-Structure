#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
  int info;
  struct node *next;
};
struct node *head;
int item;
void insertf();
void insertend();
void insertinbt();
void delef();
void delend();
void delebt();
void search();
void display();

void main()
{
   int ch=0;
   clrscr();
   while(ch!=9)
   {
      printf("\nLINKED LIST OPERATIONS");
      printf("\n*********************\n");
      printf("\n1.Insertf \n2.Insertend \n3.insertinbt \n4.delef \n5.delend \n6.delebt \n7.search \n8.Display \n9.Exit");

       printf("\n\nEnter your choice:");
       scanf("%d",&ch);
       switch(ch)
       {
	   case 1:
		    insertf();
		    break;
	   case 2:
		    insertend();
		    break;
	   case 3:
		    insertinbt();
		    break;
	   case 4:
		    delef();
		    break;
	   case 5:
		    delend();
		    break;
	   case 6:
		    delebt();
		    break;
           case 7:
                    search();
                    break;
	   case 8:
		    display();
		    break;
	   case 9:
		   break;

	   default:
		    printf("\nInvalid choice");
       }

   }
getch();

}
void insertf()
{
 struct node *ptr;
 int item;
 ptr=(struct node*)malloc(sizeof(struct node*));
 if(ptr==NULL)
 {
    printf("\nOverflow");
 }
 else
 {
   printf("\nEnter new item:");
   scanf("%d",&item);
   ptr->info=item;
   ptr->next=head;
   head=ptr;
   printf("\nsuccessfully inserted\n");
 }


}

void insertend()
{
 struct node *ptr,*temp;
 int item;
 ptr=(struct node*)malloc(sizeof(struct node*));
 if(ptr==NULL)
 {
    printf("\nOverflow");
 }
 else
 {
   printf("\nEnter new item:");
   scanf("%d",&item);
   ptr->info=item;
   if(head==NULL)
    {

       ptr->next=NULL;
       head=ptr;
       printf("\nsuccessfully inserted\n");
    }
    else
    {
       temp=head;
       while(temp->next!=NULL)
       {
	   temp=temp->next;
       }
	temp->next=ptr;
	ptr->next=NULL;
	printf("\nsuccessfully inserted\n");
    }
 }



}

void insertinbt()
{
 int i,loc,item;
 struct node *ptr,*temp;
 ptr=(struct node*)malloc(sizeof(struct node*));
 if(ptr==NULL)
 {
    printf("\nOverflow");
 }
  else
  {
     printf("\nEnter new item:");
     scanf("%d",&item);
     ptr->info=item;
     printf("\nEnter the location after which you want to insert:");
     scanf("%d",&loc);
     temp=head;
     for(i=0;i<loc;i++)
     {
	temp=temp->next;
	if(temp==NULL)
	{
	   printf("\ncan't insert");
	}
      }
       ptr->next=temp->next;
       temp->next=ptr;
       printf("\nsuccessfully inserted\n");
      }

}
void delef()
{
 struct node *ptr;

 if(head==NULL)
 {
    printf("\nList is empty");
 }
 else
 {
   ptr=head;
   head=ptr->next;
   free(ptr);
   printf("\nsuccessfully deletedted\n");
 }
}
void delend()
{
 struct node *ptr,*prev;

 if(head==NULL)
 {
    printf("\nList is empty");
 }
 else if(head->next==NULL)
 {
   head=NULL;
   free(head);
   printf("\nsuccessfully deleted\n");
 }
 else
 {
    ptr=head;
    while(ptr->next!=NULL)
    {
	prev=ptr;
	ptr=ptr->next;
    }
    prev->next=NULL;
    free(ptr);
     printf("\nsuccessfully deleted\n");
 }
}

void delebt()
{
   struct node *ptr,*prev;
   int loc,i;
   printf("\nEnter the location of the node after which you want to perform deletion\n");
   scanf("%d",&loc);
   ptr=head;
   for(i=0;i<loc;i++)
   {
      prev=ptr;
      ptr=ptr->next;
      if(ptr==NULL)
      {
	 printf("\ncan't delete");
      }
   }
   prev->next=ptr->next;
    free(ptr);
   printf("\nsuccessfully deleted",loc+1);
}

void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->info == item)  
            {  
                printf("item found at location %d ",i+1);  
                flag=0;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}  
  

void display()
{
   struct node*ptr;
   ptr=head;
   if(ptr==NULL)
   {
      printf("\nList is empty");
   }
   else
   {
     printf("\ncurrent list is:");
     while(ptr!=NULL)
     {
	printf("\t%d->",ptr->info);
	ptr=ptr->next;
     }
   }
}

     