/*
 * =====================================================================================
 *
 *       Filename:  head_tail_queue.h
 *
 *    Description: Header file for head_tail_queue.c, contains function definations. 
 *
 *        Version:  1.0
 *        Created:  04/12/2020 11:15:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karan Raval (), karanraval72@yahoo.com
 *   Organization:  
 *
 * =====================================================================================
 */

typedef struct queue{
    struct queue *prev;
    int data;
    struct queue *next;
}QUEUE;

//Function declarations
void EnqueueBack(QUEUE **hdr, int data);
void EnqueueFront(QUEUE **hdr, int data);
int DequeueBack(QUEUE **hdr);
int DequeueFront(QUEUE **hdr);
void Print(QUEUE *hdr);

void EnqueueBack(QUEUE **hdr, int data)
{
    QUEUE *new_node = NULL;
    new_node = malloc(sizeof(QUEUE));
    if(!new_node){
        printf("EnqueueBack : memory allocation failed\n");
        return;
    }
    new_node->data = data;
    if((*hdr) == NULL){
        *hdr = new_node;
        (*hdr)->prev = *hdr;
        (*hdr)->next = *hdr;
    }
    else{
        new_node->next = *hdr;
        new_node->prev = (*hdr)->prev;
        (*hdr)->prev->next = new_node;
        (*hdr)->prev = new_node;
    }
    return;
}
void EnqueueFront(QUEUE **hdr, int data)
{
    EnqueueBack(hdr,data);
    (*hdr) = (*hdr)->prev;
    return;
}
void Print(QUEUE *hdr)
{
    if(hdr == NULL){
        printf("Queue is empty\n");
        return;
    }
    char flag = 0;
    QUEUE *temp = hdr;
    while(flag ==0){
        printf("%d ",temp->data);
        temp = temp->next;
        if(temp == hdr)
            flag = 1;
    }
    printf("\n");
}
int DequeueBack(QUEUE **hdr)
{
    if((*hdr) == NULL){
        printf("Queue is empty\n");
        return 0;
    }
    QUEUE *temp;
    int data;
    if((*hdr)->prev == (*hdr)){
        data = (*hdr)->data;
        free(*hdr);
        *hdr = NULL;
    }
    else{
        temp = (*hdr)->prev->prev;
        data = temp->next->data;
        temp->next = (*hdr);
        free((*hdr)->prev);
        (*hdr)->prev = temp;
    }
    return data;
}
int DequeueFront(QUEUE **hdr)
{
    if((*hdr) == NULL){
        printf("Queue is empty\n");
        return 0;
    }
    int data;
    (*hdr) = (*hdr)->next;
    data = DequeueBack(hdr);
    return data;
}
