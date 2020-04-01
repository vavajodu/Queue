/*
 * =====================================================================================
 *
 *       Filename:  ll_queue.c
 *
 *    Description:  Queue implementation using linked list.
 *
 *        Version:  1.0
 *        Created:  04/01/2020 08:43:56 AM
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
#include "ll_queue.h"

int main()
{
    QUEUE *head = NULL;
    unsigned int choice;
    char ch;
    int temp, data;
    CreateQueue(&head);
    do {
        printf("Enter option\n1)Enqueue\n2)Dequeue\n3)Print\n4)Reverse\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
                printf("enter the number\n");
                scanf("%d",&data);
                Enqueue(head,data);
                break;
            case 2 :
                temp = Dequeue(head);
                printf("Data : %d\n", temp);
                break;
            case 3:
                Print(head);
                break;
            case 4:
                Reverse_queue(head);
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

