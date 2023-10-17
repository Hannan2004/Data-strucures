#include<stdio.h>
#include<malloc.h>

struct node
{
    struct node *next;
    int data;
    struct node *prev;
};
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

int main()
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
        printf("\n 9. Delete before node");
        printf("\n 10. Delete after a node");
        printf("\n 11. Delete entire list");
        printf("\n 12. Exit");
        printf("\n \n Enter your option");
        scanf("%d",&option);
        switch(option)
        {
            case 1: start = create_ll(start);
                    printf("\n Double Linked list created"); 
                  break;
            case 2: start = display(start);
                  break;
            case 3: start = insert_beg(start);
                  break;
            case 4: start = insert_end(start);
                  break;
            case 5: start = insert_before(start);
                  break;
            case 6: start = insert_after(start);
                  break;
            case 7: start = delete_beg(start);
                  break; 
            case 8: start = delete_end(start);
                  break;
            case 9: start = delete_before(start);
                  break;
            case 10: start = delete_after(start);
                  break;
            case 11: start = delete_list(start);
                  printf("\n doubly linked list created");
                  break;                                                                                                                                                                           
        }
    } while (option!=12);      
    return 0;
}

struct node *create_ll(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("\n enter -1 to end");
    printf("\n enter data");
    scanf("%d",&num);
    while(num != -1)
    {
        if(start == NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->prev = NULL;
            new_node->next = NULL;
            new_node->data = num;
            start = new_node;
        }
        else
        {
            ptr=start;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = num;
            while(ptr->next != NULL)
            ptr=ptr->next;
            ptr->next=new_node;
            new_node->prev=ptr;
            new_node->next=NULL;
        }
        printf("\n enter the data");
        scanf("%d",&num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr != NULL)
    {
        printf("\n %d", ptr->data);
        ptr=ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n enter number");
    scanf("%d",&num);
    new_node= (struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    start->prev=new_node;
    new_node->next=start;
    new_node->prev=NULL;
    start=new_node;
    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *new_node,*ptr;
    int num,val;
    printf("\n enter the data ");
    scanf("%d",&num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while(ptr != NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->prev=ptr;
    new_node->next=NULL;
    return start;
}

/* struct node *insert_beg(struct node *start)
{
    struct node *new_node,*ptr;
    int num,val;
    printf("\n enter data");
    scanf("%d",&num);
    printf("\n enter the data of node before which you want to enter a new node");
    scanf("%d",&val);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while(ptr->data != val)
    {
        ptr=ptr->next;
    }
    new_node->next=ptr;
    new_node->prev=ptr->prev;
    ptr->prev=new_node;
    return start;
} */

struct node *insert_after(struct node *start)
{
    struct node *new_node,*ptr;
    int num,val;
    printf("\n enter data");
    scanf("%d",&num);
    printf("\n enter the data of node after which you want to enter a new node");
    scanf("%d",&val);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    ptr=start;
    while(ptr->data != val)
    {
        ptr=ptr->next;
    }
    new_node->prev=ptr;
    new_node->next=ptr->next;
    ptr->next=new_node;
    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    start->prev=NULL;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    return start;
}

struct node *delete_after(struct node *start)
{
    struct node *ptr,*temp;
    int val;
    printf("\n enter the value after which the node has to be deleted");
    scanf("%d",&val);
    ptr = start;
    while(ptr->data != val)
    {
        ptr=ptr->next;
    }
    temp = ptr->next;
    ptr->next=temp->next;
    temp->next->prev=ptr;
    free(temp);
    return start;
}

struct node *delete_before(struct node *start)
{
    struct node *ptr,*temp;
    int val;
    printf("\n enter the value before which the node has to be deleted");
    scanf("%d",&val);
    ptr = start;
    while(ptr->data != val)
    {
        ptr=ptr->next;
    }
    temp = ptr->prev;
    if(temp == start)
    {
        start=delete_beg(start);
    }
    else{
    ptr->prev=temp->prev;
    temp->prev->next=ptr;
    }
    free(temp);
    return start;
}

struct node *delete_list(struct node *start)
{
    while(start != NULL)
    {
        start = delete_beg(start);
    }
    return start;
}











