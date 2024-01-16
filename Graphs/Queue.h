#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
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

	if(q->rear == -1 && q->front == -1)
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
int dequeue(struct Queue *q)
{
	
	if(q->front == q->rear)
		{
			return q->Q[q->front] ;
			q->front = -1;
			q->rear = -1;
		}
	else
		{
			q->front++;
			return q->Q[q->front] ;
		}
		
	}
bool isEmpty(struct Queue *q) {
    if (q->front == q->rear && q->front != 0 && q->rear != 0 ){
		return true;
    }
    return false;
}
