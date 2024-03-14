// Implementation of all operations of Linklist 05-11-22 D8
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node CreateList()
{
    if (head == NULL)
    {
        int n, data;
        printf("Enter the number of nodes:");
        scanf("%d", &n);
        struct node *newNode, *ptr;
        newNode = (struct node *)malloc(sizeof(struct node));
        head = newNode;
        ptr = head;
        printf("Enter the data:");
        scanf("%d", &data);
        head->data = data;
        for (int i = 2; i <= n; i++)
        {
            newNode = malloc(sizeof(struct node));
            ptr->next = newNode;
            printf("Enter the data:");
            scanf("%d", &data);
            newNode->data = data;
            ptr = ptr->next;
            ptr->next = NULL;
        }
    }
    else
        printf("List all ready created.\n");
}
void Travase()
{
    struct node *ptr;
    if (head == NULL)
        printf("\nList is empty.\n");
    else
    {
        printf("\n displaying the list-------->");
        ptr = head;
        while (ptr != NULL)
        {
            printf("\t%d", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
void insertAtbeginning()
{
    struct node *newNode;
    int data;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("\t NODE INSERTED AT THE BEGINING IS DONE----------->");
}
void insertAtposition()
{
    struct node *newNode, *ptr;
    int data, v;
    if(head == NULL)
    {
        printf("\nList is empty.\n");
    }
    else
    {
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d", &data);
    newNode->data = data;
    printf("Enter the value  insert after:");
    scanf("%d", &v);
    printf("\t NODE INSERTED AFTER %d IS DONE----------->",v);
    ptr = head;
    while (ptr->data != v)
    {
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    }
}
void insertAtindex()
{
    struct node *newNode, *ptr;
    int data, cunt = 1, pos;
    if(head == NULL){
        printf("\nList is empty.\n");
    }else{
    printf("Enter the position:");
    scanf("%d", &pos);
    int c=count();
    ptr = head;
    if(pos==1)
    { 
         insertAtbeginning();

     }
     else if(pos<=c)
     {
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d", &data);
    newNode->data = data;
   
    while (cunt < pos - 1)
    {
        ptr = ptr->next;
        cunt++;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
     }else{
        printf("\n index out of bound\n");
     }
    }
}
void insertAtend()
{
    struct node *newNode, *ptr;
    int data;
    if(head == NULL){
        printf("\nList is empty.\n");
    }else{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d", &data);
    newNode->data = data;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = NULL;
    }
}
void deleteAtbegining()
{
    struct node *ptr;
    if (head == NULL)
        printf("List is empty.\n");
    else
    {
        ptr = head;
        head = head->next;
        free(ptr);
    }
}
void deleteAtposition()
{
    struct node *ptr, *prevptr;
    ptr = head;
    int data;
    if (head == NULL)
        printf("\nList is empty.\n");
    else{
    printf("Enter the index to delete the data :");
    scanf("%d", &data);
    ptr = head;
    while (ptr->data != data || ptr == NULL)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Can't delete-----YOU HAVE INSERTED AN WRONG INPUT----`^`\n");
        return;
    }
    prevptr->next = ptr->next;
    free(ptr);
    }
}
void deleteAtindex()
{
    struct node *ptr, *prevptr;
    int cunt = 1, pos;
    if (head == NULL)
        printf("\nList is empty.\n");
    else{
    printf("Enter the position  delete :");
    scanf("%d", &pos);
    int c=count();
    if(pos==1)
    {
         deleteAtbegining();
    }
    else if(pos<=c)
    {
        ptr = head;
        while (cunt <= pos - 1)
        {
            prevptr = ptr;
            ptr = ptr->next;
            cunt++;
            if (ptr == NULL)
             {
                printf("Can't delete.\n");
                return;
            }
        }
        prevptr->next = ptr->next;
        free(ptr);
    }
    else{
       printf("\n index out of bound -_-\n\n");
    }
    }
}
void deleteAtend()
{
    struct node *ptr, *prevptr;
    if (head == NULL)
        printf("List is empty.\n");
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            prevptr = ptr;
            ptr = ptr->next;
        }
        prevptr->next = NULL;
        free(ptr);
    }
}
void search()
{
    struct node *ptr;
    ptr = head;
    int v, count = 1;
    if (head == NULL)
        printf("\nList is empty.\n");
    else{
    printf("Enter the value to search:");
    scanf("%d", &v);
    if (ptr == NULL)
        printf("List is empty.\n");
    else
    {
        while (ptr->data != v)
        {
            count++;
            ptr = ptr->next;
        }
        if (ptr == NULL)
            printf("Value is not present in the list.\n");
        else
            printf("the position is:%d\n", count);
    }
    }
}
int count()
{
    struct node *ptr;
    ptr = head;
    int cont = 0;
    if (ptr == NULL)
        printf("List is empty.\n\n\n");
    else
    {
        while (ptr != NULL)
        {
            cont++;
            ptr = ptr->next;
        }
        printf("the number of element:%d\n", cont);
    }
    return cont;
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n\n");
        printf("press1:\tTo Create list.\n");
        printf("press2:\tFor display.\n");
        printf("press3:\tFor Insert at beginning.\n");
        printf("press4:\tFor Insert at any index.\n");
        printf("press5:\tFor Insert after a value.\n");
        printf("press6:\tFor Insert at end.\n");
        printf("press7:\tFor Delete at beginning.\n");
        printf("press8:\tFor Delete at any index.\n");
        printf("press9:\tFor Delete after a value.\n");
        printf("press10: For Delete at end.\n");
        printf("press11: To Count.\n");
        printf("press12: To Search.\n");
        printf("press13: For Exit.\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            CreateList();
            break;
        case 2:
            Travase();
            break;
        case 3:
            insertAtbeginning();
            break;
        case 4:
            insertAtindex();
            break;
        case 5:
            insertAtposition();
            break;
        case 6:
            insertAtend();
            break;
        case 7:
            deleteAtbegining();
            break;
        case 8:
            deleteAtindex();
            break;
        case 9:
            deleteAtposition();
            break;
        case 10:
            deleteAtend();
            break;
        case 11:
            count();
            break;
        case 12:
            search();
            break;
        case 13:
            exit(0);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}