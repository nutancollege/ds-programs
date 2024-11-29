#include<stdio.h>
#include<conio.h>
#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insert(int key )
{
    int index;
    index = hashFunction(key);
    int oriindex = index;

    while(hashTable[index] != EMPTY)
    {
        index = (index+1)%TABLE_SIZE;
        if(index  == oriindex)
        {
            printf("\n hash table is full cannot inserted %d",key);
            return;
        }

    }

    hashTable[index] = key;
    printf("\n the %d is inserted at %d",key,index);
}

void Search(int key)
{
    int index = hashFunction(key);
    int real = index;

    while(hashTable[index] != EMPTY)
    {
        if(hashTable[index] == key)
        {
            printf("\n %d is found at %d index",key,index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if(index == real)
        {
            break;
        }
    }
    printf("\n %d is not found ",key);
}
void Display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("Index %d: EMPTY\n", i);
        else
            printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main()
{
    int ch,i;
    for(i = 0 ;i<TABLE_SIZE;i++)
    {
        hashTable[i] = EMPTY;
    }

    int data;

    while(1)
    {
        printf("\n 1.insert");
        printf("\n 2.search");
        printf("\n 3.display");
        printf("\n 4.exit");
        printf("\n Enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {

        case 1:
            printf("\n Enter the data :");
            scanf("%d",&data);
            insert(data);
            break;
        case 2:
            printf("\n Enter the data that you want to search :");
            scanf("%d",&data);
            Search(data);
            break;
        case 3:
            printf("\n DISPLAY HASH TABLE :");
            Display();
            break;
        case 4:
            return 0 ;
        default:
             printf("\n you enter wrong choice :");
        }
    }
}
