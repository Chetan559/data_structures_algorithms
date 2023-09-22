// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *arr;
};
int null(struct stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int full(struct stack *st)
{
    if (st->top == st->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *st, int data)
{
    if (full(st) == 0)
    {
        st->top++;
        st->arr[st->top] = data;
    }
    else
    {
        printf("Stack Overflow");
    }
}

void pop(struct stack *st)
{
    int *ptr;
    ptr = (int *)malloc(sizeof(int));
    if (null(st) == 0)
    {
        *(ptr) = st->arr[st->top];
        st->top--;
        free(ptr);
    }
    else
    {
        printf("stack empty");
    }
}
void display(struct stack *st)
{
    printf("%d", st->arr[st->top]);
}

int main()
{
    // Write C code here
    int n;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 100;
    s->arr = (int *)malloc(s->size * sizeof(int));
    // if (null(s) == 1)
    // {
    //     printf("empty");
    // }
    push(s, 5);
    display(s);

    return 0;
}