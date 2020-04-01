/*
 * =====================================================================================
 *
 *       Filename:  ll_queue.h
 *
 *    Description: Header file for queue implementation using link list.
 *                 You need to clone stack code as well to execute reverse functinality.
 *                 Please check C/datastruct/stack 
 *
 *        Version:  1.0
 *        Created:  04/01/2020 11:15:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karan Raval (), karanraval72@yahoo.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "../stack/ll_stack.h"

typedef struct list{
    int data;
    struct list *next;
}LIST;
typedef struct queue{
    LIST *front;
    LIST *rear;
}QUEUE;

void CreateQueue(QUEUE **hdr);
void Enqueue(QUEUE *hdr,int data);
int Dequeue(QUEUE *hdr);
int IsEmptyqueue(QUEUE *hdr);
void Print(QUEUE *hdr);
void Reverse_queue(QUEUE *hdr);

void CreateQueue(QUEUE **hdr)
{
    *hdr = malloc (sizeof(QUEUE));
    if(!hdr){
        printf("CreateQueue : memory allocation failed\n");
        return;
    }
    (*hdr)->front = (*hdr)->rear = NULL;
    return;
}
void Enqueue(QUEUE *hdr,int data)
{
    LIST *temp;
    temp = malloc( sizeof(LIST));
    if(!temp){
        printf("Enqueue : memory allocation failed\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;
    if(hdr->rear)
        hdr->rear->next = temp;
    hdr->rear = temp;
    if(hdr->front == NULL)
        hdr->front = hdr->rear;
    return;
}
void Print(QUEUE *hdr)
{
    if(IsEmptyqueue(hdr)){
        printf("Queue is empty\n");
        return;
    }
    LIST *temp;
    temp = hdr->front;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int IsEmptyqueue(QUEUE *hdr)
{
    if(hdr->front == NULL)
        return 1;
    else
        return 0;
}
int Dequeue(QUEUE *hdr)
{
    if(IsEmptyqueue(hdr)){
        printf("Queue is empty\n");
        return 0;
    }
    int data;
    LIST *temp;
    temp = hdr->front;
    hdr->front = hdr->front->next;
    data = temp->data;
    free(temp);
    return data;
}
void Reverse_queue(QUEUE *hdr)
{
    if(IsEmptyqueue(hdr)){
        printf("Queue is empty\n");
        return;
    }
    LL_STACK *temp = NULL;
    int data;
    while(!(IsEmptyqueue(hdr))){
        data = Dequeue(hdr);
        push(&temp,data);
    }
    while(!(IsEmpty(temp))){
        data = pop(&temp);
        Enqueue(hdr, data);
    }
    return;
}

