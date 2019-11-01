#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *next, *prev;
};
typedef struct Node *PNode;

typedef struct {
    PNode Head, Tail;
}Stack;

void Push(Stack *S, char x){
    PNode NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = x;
    NewNode->next = S->Head;
    NewNode->prev = NULL;

    if (S->Head)
        S->Head = NewNode;
    if(!S->Tail)
        S->Tail = S->Head;
}

char Pop(Stack *S){
    PNode TopNode = S->Head;
    char x;
    if (!TopNode)
        return '&';
    x = TopNode->data;
    S->Head = TopNode->next;
    if (S->Head) S->Head->prev = NULL;
    else S->Tail = NULL;
    free(TopNode);
    return x;
}

int main() {
    
    return 0;
}