#include<stdio.h>
#define N 5

int stack[N];
int top=-1;

void push(){
    int x;
    printf("Enter data: ");
    scanf("%d",&x);
    
    if(top>=N-1){
        printf("Overflow\n");
    }else{
        top++;
        stack[top]=x;
        printf("Data is inserted!\n");
    }
}
void pop(){
    if(top==-1){
        printf("Stack is underflow!\n");
        
    }else{
        int item = stack[top];
        top--;
        printf("Poped Value: %d\n",item);
    }

}
void peek(){
    if(top==-1){
        printf("Stack is empaty\n ");
    }
    else{
        printf("Top Most Element! %d\n",stack[top]);
    }
}
void display(){
    if(top==-1){
        printf("stack is empaty!");
    }else{
        int i;
        for(i=top;i>=0;i--){
            printf("%d",stack[i]);
            
        }
        printf("\n");
    }
    
}
int main(){
    int ch;
    
    do{
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: push();
            break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 5);

    return 0;
}
