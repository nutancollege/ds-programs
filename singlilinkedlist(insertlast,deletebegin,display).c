#include<stdio.h>
#include<conio.h>
struct Node{
   int data;
   struct Node *next;
};
struct Node *head = NULL;
struct Node *newnode,*temp;

void Insert_End();

void Delete_b();


void Display();
//void Insert_pos();
int val,pos;
int main()
{
    int ch,ans = 1;

    do{
    system("cls");
    printf("\n THE OPERATION ON LINK LIST");

    printf("\n 1.Insert_End");

    printf("\n 2.DELETE BEGINING");


    printf("\n 3.Display");
    printf("\n 4.exit ");
    printf("\n Enter your choice :");
    scanf("%d",&ch);

    switch(ch)
    {

    case 1:
        Insert_End();
        break;

    case 2:
        Delete_b();
        break;

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

void Insert_End()
{
    printf("\n Enter the data to Insert at end :");
    scanf("%d",&val);
    newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL)
    {
        printf("\n THE MEMORY IS NOT AVALIABLE :");
    }
    else {
        if(head == NULL)
        {
            newnode->data = val;
            newnode->next = NULL;
            head = newnode;
        }
        else{
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            newnode->data = val;
            newnode->next = NULL;
            temp->next = newnode;
        }
        printf("\n successfull ");
    }
}

void Delete_b()
{
    if(head == NULL)
    {
        printf("\n THE MEMORY IS NOT AVALIABLE :");
    }
    else{
        temp = head;
        printf("the deleter Item is %d",temp->data);
        head = temp->next;
        temp->next = NULL;
        free(temp);
    }
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
