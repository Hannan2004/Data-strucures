// in this program we will be implementing singly linked list in C
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *creatll(struct node *);
struct node *display(struct node *);
struct node *insertBeg(struct node *);
struct node *insertEnd(struct node *);
struct node *insertBefore(struct node *);
struct node *insertAfter(struct node *);
struct node *deleteBeg(struct node *);
struct node *deleteEnd(struct node *);
struct node *deleteNode(struct node *);
struct node *deleteAfter(struct node *);
struct node *deleteList(struct node *);
struct node *sortList(struct node *);

int main(int argc, char *argv[])
{
    int option;
    do
    {
        printf("\n \n MAIN MENU ");
        printf("\n 1. Create a list");
        printf("\n 2. Display the list");
        printf("\n 3. Add at beginning");
        printf("\n 4. Add at end");
        printf("\n 5. Add before");
        printf("\n 6. Add after");
        printf("\n 7. Delete at beginning");
        printf("\n 8. Delete at end");
        printf("\n 9. Delete a given node");
        printf("\n 10. Delete after a node");
        printf("\n 11. Delete entire list");
        printf("\n 12. Sort the list");
        printf("\n 13. Exit");
        printf("\n \n Enter your option");
        scanf("%d",&option);
        switch(option)
        {
            case 1: start = creatll(start);
                    printf("\n Linked list created"); 
                  break;
            case 2: start = display(start);
                  break;
            case 3: start = insertBeg(start);
                  break;
            case 4: start = insertEnd(start);
                  break;
            case 5: start = insertBefore(start);
                  break;
            case 6: start = insertAfter(start);
                  break;
            case 7: start = deleteBeg(start);
                  break; 
            case 8: start = deleteEnd(start);
                  break;
            case 9: start = deleteNode(start);
                  break;
            case 10: start = deleteAfter(start);
                  break;
            case 11: start = deleteList(start);
                  break;
            case 12: start = sortList(start);
                  break;                                                                                                                                                                                   
        }
    } while (option != 13);
    return 0;
}

struct node *creatll(struct node *start)
{
    struct node*new_node, *ptr;
    int num;
    printf("\n enter -1 to end ");
    printf("\n enter the data : ");
    scanf("%d",&num);
    while(num!=-1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data = num;
        if(start==NULL)
        {
            new_node -> next =NULL;
            start = new_node;
        }
        else
        {
            ptr =start;
            while(ptr->next != NULL)
            {
                ptr=ptr->next;
            }
            ptr->next= new_node;
            new_node->next=NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d",&num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("\t %d",ptr->data);
        ptr=ptr->next;
    }
    return start;
}

struct node *insertBeg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n enter the data ");
    scanf("%d", &num);
    new_node= (struct node *)malloc(sizeof(struct node *));
    new_node->data=num;
    new_node->next=start;
    start=new_node;
    return start;
}

struct node *insertEnd(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("\n enter the data ");
    scanf("%d", &num);
    new_node=(struct node *)malloc(sizeof(struct node *));
    new_node->data=num;
    new_node->next=NULL;
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;
    return start;
}

struct node *insertBefore(struct node *start)
{
    struct node *new_node,*ptr,*preptr;
    int num,val;
    printf("\n enter the data ");
    scanf("%d", &num);
    printf("\n enter the data of the node before which you want to insert a node ");
    scanf("%d", &val);
    new_node=(struct node *)malloc(sizeof(struct node *));
    new_node->data=num;
    ptr=start;
    while(ptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;
    return start;
}

struct node *insertAfter(struct node *start)
{
    struct node *new_node,*ptr,*preptr;
    int num,val;
    printf("\n enter the data ");
    scanf("%d", &num);
    printf("\n enter the data of the node after which you want to insert a node ");
    scanf("%d", &val);
    new_node=(struct node *)malloc(sizeof(struct node *));
    new_node->data=num;
    ptr=start;
    while(preptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;
    return start;
}

struct node *deleteBeg(struct node *start)
{
    struct node*ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}

struct node *deleteEnd(struct node *start)
{
    struct node *ptr,*preptr;
    ptr=start;
    while(ptr->next != NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    return start;
}

struct node *deleteNode(struct node *start)
{
    struct node *ptr,*preptr;
    int val;
    printf("\n enter the data of the node which has to be deleted : ");
    scanf("%d",&val);
    ptr=start;
    if(ptr->data==val)
    {
        start= deleteBeg(start);
        return start;
    }
    else{
        while(ptr->data !=val)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr -> next=ptr -> next;
        free(ptr);
        return start;
    }
}

struct node *deleteAfter(struct node *start)
{
    struct node *ptr,*preptr;
    int val;
    printf("\n enter the data of the node after which you want to perform deletion");
    scanf("%d",&val);
    ptr=start;
    preptr=ptr;
    while(preptr -> data != val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}

struct node *deleteList(struct node *start)
{
    struct node*ptr;
    if(start!=NULL)
    {
        ptr=start;
        while(ptr!=NULL)
        {
            printf("\n %d is to be deleted next",ptr->data);
            start=deleteBeg(start);
            ptr=start;
        }
    }
    return 0;
}

struct node *sortList(struct node *start)
{
    struct node *ptr1,*ptr2;
    int temp;
    ptr1=start;
        while(ptr1 -> next != NULL)
        {
            ptr2=ptr1->next;
            while(ptr2!=NULL)
            {
                if(ptr1->data > ptr2->data)
                {
                    temp =ptr1->data;
                    ptr1->data=ptr2->data;
                    ptr2->data=temp;
                }
                ptr2=ptr2->next;
            }
            ptr1=ptr1->next;
        }   
    return start;
}