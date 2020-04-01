/*
 * =====================================================================================
 *
 *       Filename:  circular.c
 *
 *    Description:  queue implementation based on circlar array
 *
 *        Version:  1.0
 *        Created:  03/28/2020 11:27:29 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karan Raval (), karanraval72@yahoo.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<malloc.h>
typedef struct queue {
    int capacity;
    int front;
    int rear;
    int *array;
}QUEUE;

void Enqueue(QUEUE *hdr, int data);
int Dequeue(QUEUE *hdr);
void Print_queue(QUEUE *hdr);
unsigned int IsFull(QUEUE *hdr);
unsigned int IsEmpty(QUEUE *hdr);
unsigned int Capacity(QUEUE *hdr);
void Delete_queue(QUEUE *hdr);

int main()
{
    unsigned int option;
    int temp, data;
    char ch;
    QUEUE *head;
    head = malloc(sizeof(QUEUE));
    if(!head){
        printf("head is NULL\n");
        return 0;
    }
    printf("Enter the capacity of queue\n");
    scanf("%d",&(head->capacity));
    head->front = -1;
    head->rear = -1;
    head->array = malloc(head->capacity * sizeof(int));
    if(!(head->array)){
        printf("head->array is NULL\n");
        return 0;
    }
    do {
        printf("Enter the option\n1)Enqueue\n2)Dequeue\n3)Print\n4)Capacity\n5)Delete queue\n");
        scanf("%u", &option);
        switch(option){
            case 1 :
                printf("enter the data\n");
                scanf("%d",&data);
                Enqueue(head, data);
                break;
            case 2 :
                temp = Dequeue(head);
                printf("Number : %d\n",temp);
                break;
            case 3 :
                Print_queue(head);
                break;
            case 4 :
                printf("Capacity of queue is %d\n",Capacity(head));
                break;
            case 5 :
                printf("You are deleting queue\n");
                Delete_queue(head);
                break;
            default :
                printf("Invalid option\n");
                break;
        }
        printf("Do you want to continue...(y/n)?\n");
        scanf(" %c", &ch);
    }
    while(ch =='y' || ch =='Y');
    return 0;
}
unsigned int IsFull(QUEUE *hdr)
{
    return ((hdr->rear + 1) % (hdr->capacity) == hdr->front);
}
unsigned int Capacity(QUEUE *hdr)
{
    int temp;
    temp = (hdr->capacity - (hdr->front + hdr->rear + 1)) % hdr->capacity;
    printf("temp = %d\n",temp);
    return temp;
}
unsigned int IsEmpty(QUEUE *hdr)
{
    if(hdr->front == -1)
        return 1;
    else
        return 0;
}
void Print_queue(QUEUE *hdr)
{
    if(IsEmpty(hdr)){
        printf("Queue is empty\n");
        return;
    }
    int i,j;
    i = hdr->front;
    j = hdr->rear;
    for( ; i<=j;i++)
        printf("%d ",hdr->array[i]);
    printf("\n");
}
void Enqueue(QUEUE *hdr, int data)
{
    if(IsFull(hdr)){
        printf("Queue is Full\n");
        return;
    }
    hdr->rear = (hdr->rear+1) % (hdr->capacity);
    hdr->array[hdr->rear] = data;
    if(hdr->front == -1)
        hdr->front = hdr->rear;
}
int Dequeue(QUEUE *hdr)
{
    int temp;
    if(IsEmpty(hdr)){
        printf("Queue is empty\n");
        return 0;
    }
    temp = hdr->array[hdr->front] ;
    if(hdr->front == hdr->rear)
        hdr->front = hdr->rear = -1;
    else
        hdr->front = (hdr->front+1) % hdr->capacity;
    return temp;
}
void Delete_queue(QUEUE *hdr)
{
    if(hdr){
        if(hdr->array)
            free(hdr->array);
        free(hdr);
    }
}
