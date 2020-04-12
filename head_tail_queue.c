/*
 * =====================================================================================
 *
 *       Filename: head_tail_queue.c 
 *
 *    Description: head and tail queue. you can enqueue and dequeue at end and front. 
 *
 *        Version:  1.0
 *        Created:  04/12/2020 08:43:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karan Raval (), karanraval72@yahoo.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include<stdio.h>
#include<stdlib.h>
#include "head_tail_queue.h"

int main()
{
    QUEUE *head = NULL;
    unsigned int choice;
    char ch;
    int data;
    do {
        printf("Enter option\n1)EnqueueBack\n2)EnqueueFront\n3)DequeueBack\n4)DequeueFront\n5)Print\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
                printf("enter the number\n");
                scanf("%d",&data);
                EnqueueBack(&head,data);
                break;
            case 2 :
                printf("enter the number\n");
                scanf("%d",&data);
                EnqueueFront(&head,data);
                break;
            case 3:
                data = DequeueBack(&head);
                printf("Data : %d\n",data);
                break;
            case 4:
                data = DequeueBack(&head);
                printf("Data : %d\n",data);
                break;
            case 5:
                Print(head);
                break;
            default :
                printf("Invalid option\n");
                break;
        }
        printf("Do you want to continue(y/n)?\n");
        scanf(" %c",&ch);
    }
    while(ch =='y' || ch =='Y');
    return 0;   
}
