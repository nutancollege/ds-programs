#include<stdio.h>
#include<conio.h>
struct Node{
   int data;
   struct Node *next;
};
struct Node *head = NULL;
struct Node *newnode,*temp;
void Insert_b();

void Delete_end();

void Display();
//void Insert_pos();
int val,pos;
int main()
{
    int ch,ans = 1;

    do{
    system("cls");
    printf("\n THE OPERATION ON LINK LIST");
    printf("\n 1.Insert_b");

    printf("\n 2.deleter ending");

    printf("\n 3.Display");
    printf("\n 4.exit ");
    printf("\n Enter your choice :");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        Insert_b();
        break;


    case 2:
        Delete_end();

    case 3:
        Display();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("\n you enter wrong choooice :");
    }
    printf("\n do you want to continue press 1 ");
    scanf("%d",&ans);
    }while(ans == 1);
}
void Insert_b()
{
      printf("\n Enter the data :");
           scanf("%d",&val);
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL)
    {
        printf("\n memory is not allocated :");
    }
    else
    {

        if(head  == NULL)
        {

           newnode->data = val;
           newnode->next = NULL;
           head = newnode;
        }
        else{
            newnode->data = val;
            newnode->next = head;
            head = newnode;
        }
        printf("\n THE DATA IS ENSERTED SUCCESSFULLY : %d",newnode->data);
    }

}


void Delete_end()
{
    struct Node *t;
    t = head;
    while(t->next != NULL)
    {
        t = t->next;
    }
    printf("THE DELETE DATA IS %d",t->data);
    t->next = NULL;
    free(temp);
}
void Display()
{
    int i;
    temp = head;
    while(temp != NULL)
    {
        printf("\n THE ELEMENT ARE : %d",temp->data);
        temp = temp->next;
    }
}
