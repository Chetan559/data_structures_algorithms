#include <stdio.h>
#include <stdlib.h>
// fifo princple is used here
struct queue
{
int front;
int back;
int size;
int *arr;
};
// emputy function
int isempty(struct queue *q)
{
if (q->back == q->front)
{
return 1;
}
else
{
return 0;
}
}
// full function
int isfull(struct queue *q)
{
if (q->back == q->size - 1)
{

return 1;
}
else
{
return 0;
}
}
// enqueue function
void enqueue(struct queue *q, int val)
{
if (isfull(q))
{
printf("The queue is full.\n");
}
else
{
q->back++;
q->arr[q->back] = val; }
}
// dequeue function
int dequeue(struct queue *q)
{
int a;
if (isempty(q))
{
printf("The queue is empty.\n");
}
else
{
q->front++;
a = q->arr[q->front];
}
return a;
}
int main()
{
struct queue q;
q.front = -1;
q.back = -1;
q.size = 400;
q.arr = (int *)malloc(q.size * sizeof(int));
int u;
int i = 2;
int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int arr[7][7] = {
{0, 1, 1, 1, 0, 0, 0},
{1, 0, 0, 0, 0, 0, 1},
{1, 1, 0, 1, 1, 0, 0},
{1, 0, 1, 0, 1, 1, 0},
{0, 0, 1, 1, 0, 1, 1},
{0, 1, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 1, 0, 0},
};
printf("%d", i);
visited[i] = 1;
enqueue(&q, i);
while (!isempty(&q))
{
int node = dequeue(&q);
for (int j = 0; j < 7; j++)
{
if (arr[node][j] == 1 && visited[j] == 0)
{
printf("%d", j);
visited[j] = 1;
enqueue(&q, j);
}
}
}
return 0;
}
