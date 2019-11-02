#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node *next, *prev;
};

typedef struct Node * PNode;

typedef struct {
    PNode head, tail;
}Queue;

Queue CreateQueue(){
    Queue NewNode;
    NewNode.head = NULL;
    NewNode.tail = NULL;
    return NewNode;
}

void PushTail(Queue *Q, int x){
    PNode NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = x;
    NewNode->prev = Q->tail;
    NewNode->next = NULL;

    if (Q->tail) 
        Q->tail->next = NewNode;
    Q->tail = NewNode;

    if ( ! Q->head) Q->head = Q->tail;
}

int PopTail(Queue *Q){
    if (!Q->head){
        printf("\nQueue is empty\n");
        return 101;
    }
    int x = Q->head->data;
    if (Q->head->next){
        Q->head = Q->head->next;
        Q->head->prev = NULL;
    }else{
        Q->head = NULL;
        Q->tail = NULL;
    }
    return x;

}
int main() {
    
    return 0;
}