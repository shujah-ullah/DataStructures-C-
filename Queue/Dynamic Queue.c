#include<stdio.h>


struct Queue
{
	int front;
	int rear;
	int size;
	int *Q;
};
void create(struct Queue *q, int size)
{
	q->size = size;
	q->front = q->rear = -1;
	q->Q = (int*)malloc(q->size*sizeof(int));
};
void enqueue(struct Queue *q, int x)
{
	if(q->rear == q->size-1)
		printf("queue is FULL: \n");
	else if(q->rear == -1 && q->front == -1)
		{
			q->rear = 0;
			q->front = 0;
			q->Q [q->rear] = x;
		}
	else
		{
			q->rear++;
			q->Q [q->rear] = x;
		}
};
void dequeue(struct Queue *q)
{
	if(q->front == -1 && q->rear == -1)
		printf("Attempt to dequeue empty queue\n");
	else if(q->front == q->rear)
		{
			q->front = -1;
			q->rear = -1;
		}
	else
		{
			q->front++;
			printf("%d dequeued\n",q->Q[q->front] );
		}
		
	}
void display(struct Queue q)
{
	if(q.front == -1 && q.rear == -1)
	{
		printf("queue is empty:\n");
	}
	else
	{
		for(int i = q.front ; i<=q.rear; i++)
		{
			printf("%d, ",q.Q[i]);
		}
		printf("\n");
	}
}
int main()
{
	
	struct Queue q; //object to struct queue
	create(&q, 4);
	enqueue(&q, 10);
	enqueue(&q, 20);
	display(q);
	dequeue(&q);
	display(q);
	dequeue(&q);
	display(q);
	
	
	
	
	
	
}