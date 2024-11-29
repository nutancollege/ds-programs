#include<stdio.h>
#include<conio.h>
void Insert_b();
void Insert_End();
void Display();
struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};
struct Node *newnode;
struct Node *head = NULL;
int main()
{
    int ch,ans = 1,element;

    do
    {
        printf("\n OPETRATON ON Doubly LINKED LIST :");
        printf("\n 1.Insert in queue");
        printf("\n 2.Delete ");
        printf("\n 3.Display");
        printf("\n Enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
              Insert_b();
               break;
        case 2:
            Insert_End();
            break;
        case 3:
            Display();
            break;
        default:
            printf("\n WRONG CHOOICE :");
        }
        printf("\n DO YOU WANT TO CONTINUE : press 1");
        scanf("%d",&ans);

    }while(ans == 1);
}
void Insert_b()
{
    int val;
    printf("\n ENTER THE VALUE :");
    scanf("%d",&val);
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL)
    {
        printf("\n THE MEMORY IS NOT ALLOCATED :");
    }
    else{
        if(head == NULL)
        {
            newnode->data = val;
            newnode->next = NULL;
            newnode->prev = NULL;
            head = newnode;
        }
        else{
            newnode->data = val;
            newnode->next = head;
            newnode->prev = NULL;
            head->prev = newnode;
            head = newnode;
        }
        printf("\n ELEMENT IS INSERTED SUCCESSFULLY : %d",newnode->data);
    }
}
void Insert_End()
{
    int val;
    printf("\n ENTER THE VALUE :");
    scanf("%d",&val);
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL)
    {
        printf("\n THE MEMORY IS NOT ALLOCATED :");
    }
    else{
        if(head == NULL)
        {
            newnode->data = val;
            newnode->next = NULL;
            newnode->prev = NULL;
            head = newnode;
        }
        else{
           struct Node *temp;
           temp = head;
           while(temp->next != NULL)
           {
               temp = temp->next;
           }
           newnode->data = val;
           newnode->next = NULL;
           temp->next = newnode;
           newnode->prev = temp;
        }
    }
}

void Display()
{
    int i;
    struct Node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("\n THE ELEMENT ARE : %d",temp->data);
        temp = temp->next;
    }
}
