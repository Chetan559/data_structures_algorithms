// Online C compiler to run C program online
#include <stdio.h>

int stack[100];
int top = -1;

void push(){
    if(top==99){
        printf("OVERFLOW\n");
        return;
    }
    else{
        top++;
        printf("ENTER NUMBER:- \n");
        scanf("%d", &stack[top]);
    }
}
void pop(){
    if(top==-1){
        printf("UNDERFLOW\n");
        return;
    }
    else{
        int temp;
        temp = stack[top];
        top--;
        printf("%d deleted\n",temp);
    }
}
void peep(){
    if(top==-1){
        printf("UNDERFLOW\n");
        return;
    }
    else {
        printf("top element is %d\n", stack[top]);
    }
    
}
void dispaly(){
    if(top==-1){
        printf("UNDERFLOW\n");
        return;
    }
    else{
        for(int i=top; i>-1;i--){
            printf("%d ",stack[i]);
        }
        printf("\n ");
    }
}

int main() {
    // Write C code here
    int choice;
    do{
    printf("1. push \n2. pop \n3. peep \n4. dispaly \n0. exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        peep();
        break;
        case 4:
        dispaly();
        break;
        default:
        printf("invaild choice\n");
    }
        
    }while(choice!=0);

    return 0;
}