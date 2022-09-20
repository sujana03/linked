#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;
void insertion();
void ins_at_beg();
void ins_at_pos();
void ins_at_end();
void del_at_beg();
void del_at_pos();
void del_at_end();
void deletion();
void display();
void create();
int count();
void sort();
void search();
void sort_inc();
void sort_dec();
int main()
{
    int ch;
    while(1)
    {
        printf("\n Enter the position to be performed ");
        printf("\n 1 : insertion \n 2 : deletion \n 3 : display \n 4 : create new node \n 5 : count no.of nodes \n 6 : sort \n 7 : searching \n 8 : exit");
        printf("\n Your choice :  ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : insertion();
                     break;
            case 2 : deletion();
                     break;
            case 3 : display();
                     break;
            case 4 : create();
                     break;
            case 5 : count();
                     break;
            case 6 : sort();
                     break;
            case 7 : search();
                     break;
            case 8 : exit(0);
            default: printf("\n Invalid choice");
        }
    }
    return 0;
}
int count()
{
    struct node *temp=head;
    int c=1;
    if(head==NULL)
        printf("\n No nodes are present");
    else
    {
     while(temp->next!=NULL)
     {
         temp=temp->next;
         c++;
     }
     printf("\n No.of nodes = %d\n",c);
    }
    return c;
}
void create()
{
    struct node *nn,*temp=head;
    int val;
    nn=(struct node*)malloc(sizeof(struct node));
    if(nn==NULL)
        printf("\n Node cannot be created");
    else
    {
        printf("\n Enter an element : ");
        scanf("%d",&val);
        nn->data=val;
        nn->next=NULL;
        if(head==NULL)
            head=nn;
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nn;
            printf("\n Node created Successfully\n");
        }
    }
}
void insertion()
{
    int ch;
    printf("\n Enter the operation : ");
    printf("\n 1 : Insertion at begining \n 2 : Insertion at position \n 3 : Insertion at end ");
    printf("\n Your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : ins_at_beg();
                 break;
        case 2 : ins_at_pos();
                 break;
        case 3 : ins_at_end();
                 break;
        default:printf("\n Invalid choice");
    }
}
void display()
{
    struct node *temp=head;
    if(head==NULL)
        printf("\n No elements to display");
    else
    {
        while(temp!=NULL)
        {
            printf(" %d ->",temp->data);
            temp=temp->next;
        }
    }
    printf("\n Displayed Successfully\n");
}
void ins_at_beg()
{
    struct node *nn;
    int val;
    nn=(struct node*)malloc(sizeof(struct node));
    if(nn==NULL)
        printf("\n Node cannot be created");
    else
    {
        printf("\n Enter an element : ");
        scanf("%d",&val);
        nn->data=val;
        nn->next=NULL;
        if(head==NULL)
            head=nn;
        else
        {
            nn->next=head;
            head=nn;
            printf("\n Node inserted successfully\n");
        }
    }
}
void ins_at_pos()
{
    struct node *nn,*temp=head;
    int val,pos,i;
    nn=(struct node*)malloc(sizeof(struct node));
    if(nn==NULL)
        printf("\n Node cannot be created");
    else
    {
        printf("\n Enter an element : ");
        scanf("%d",&val);
        printf("\n Enter position of the element to be inserted : ");
        scanf("%d",&pos);
        nn->data=val;
        nn->next=NULL;
        if(head==NULL)
            head=nn;
        else
        {
            for(i=1;i<pos-1;i++)
                temp=temp->next;
            nn->next=temp->next;
            temp->next=nn;
            printf("\n Node inserted successfully\n");
        }
    }
}
void ins_at_end()
{
    struct node *nn, *temp=head;
    int val;
    nn=(struct node*)malloc(sizeof(struct node));
    if(nn==NULL)
        printf("\n Node cannot be created");
    else
    {
        printf("\n Enter an element : ");
        scanf("%d",&val);
        nn->data=val;
        if(head==NULL)
            head=nn;
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nn;
            printf("\n Node inserted successfully\n");
        }
    }
}
void deletion()
{
    int ch;
    printf("\n Enter the operation : ");
    printf("\n 1 : Deletion at begining \n 2 : Deletion at position \n 3 : Deletion at end ");
    printf("\n Your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : del_at_beg();
                 break;
        case 2 : del_at_pos();
                 break;
        case 3 : del_at_end();
                 break;
        default:printf("\n Invalid choice");
    }
}
void del_at_beg()
{
    struct node *temp=head;
    if(head==NULL)
            printf("\n No nodes to delete");
    else
    {
        head=head->next;
        temp->next=NULL;
        printf("\n Value to be deleted : %d",temp->data);
        free(temp);
        printf("\n Node deleted successfully\n");
    }
}
void del_at_pos()
{
    struct node *temp1=head,*temp2=head;
    int i,pos;
    if(head==NULL)
            printf("\n No nodes to delete");
    else
    {
        printf("\n Enter the position of the node to be deleted : ");
        scanf("%d",&pos);
        for(i=0;i<pos-1;i++)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=temp1->next;
        temp1->next=NULL;
        printf("\n Value to be deleted : %d",temp1->data);
        free(temp1);
        printf("\n Node deleted successfully\n");
    }
}
void del_at_end()
{
    struct node *temp1=head,*temp2=head;
    if(head==NULL)
           printf("\n No nodes to delete");
    else
    {
        while(temp1->next!=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next=NULL;
        printf("\n Value to be deleted : %d",temp1->data);
        free(temp1);
        printf("\n Node deleted successfully\n");
    }
}
void sort()
{
    int ch;
    printf("\n Enter the operation : ");
    printf("\n 1 : Sorting in ascending order \n 2 : Sorting in decending order" );
    printf("\n Your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : sort_inc();
                 break;
        case 2 : sort_dec();
                 break;
        default:printf("\n Invalid choice");
    }
}
void sort_inc()
{
   struct node *temp1=head,*temp2=head->next;
   int i,n,temp3;
   n=count();
   for(i=0;i<n-1;i++)
   {
       while(temp1->next!=NULL&&temp2!=NULL)
       {
           if(temp1->data>temp2->data)
           {
               temp3=temp2->data;
               temp2->data=temp1->data;
               temp1->data=temp3;
           }
           temp1=temp1->next;
           temp2=temp2->next;
       }
       temp1=head;
       temp2=head->next;
   }
}
void sort_dec()
{
   struct node *temp1=head,*temp2=head->next;
   int i,n,temp3;
   n=count();
   for(i=0;i<n-1;i++)
   {
       while(temp1->next!=NULL&&temp2!=NULL)
       {
           if(temp1->data<temp2->data)
           {
               temp3=temp2->data;
               temp2->data=temp1->data;
               temp1->data=temp3;
           }
           temp1=temp1->next;
           temp2=temp2->next;
       }
       temp1=head;
       temp2=head->next;
   }
}
void search()
{
    int index,a,key;
    printf("\n Enter element to be searched : ");
    scanf("%d",&key);
    struct node *temp;
    index = 0;
    temp = head;
    while(temp!= NULL && temp->data != key)
    {
        index++;
        temp = temp->next;
    }
    if(temp != NULL)
    {
        a=index;
    }
    else
     a=-1;
    if(a==-1)
        printf("\n Element not found\n");
    else
        printf("\n Element found\n");
}
   