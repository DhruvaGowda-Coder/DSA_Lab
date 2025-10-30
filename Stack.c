# include<stdio.h>
# define N 5
int stack[N];
int top = -1;

void Push(){
    int x;
    printf("Enter the Data:");
    scanf("%d",&x);
    if (top == N-1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top] = x;

    }
}

void Pop(){
    if (top == -1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Deleted element is %d\n",stack[top]);
        top--;
    }
}

void Top(){
    if (top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Top element is %d\n",stack[top]);
    }
}

void Display(){
    if (top == -1){
        printf("Stack is empty\n");
    }
    else{
        for (int i = top; i >= 0; i--){
            printf("%d\n",stack[i]);
        }
    }
}


void main(){
    int ch;
    do{
        printf("1.Push\n2.Pop\n3.Top\n4.Display\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: Push(); break;
            case 2: Pop(); break;
            case 3: Top(); break;
            case 4: Display(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        
        }
    }
    while(ch!=0);
    getch();
    
}



