#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[40];
    int count;
    int index;
    struct Node *next;
};

typedef struct Node *PNode;
PNode Head = NULL;

PNode CreateNode ( char NewWord[] ) {
    PNode NewNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(NewNode->word,NewWord);
    NewNode->count = 1;
    NewNode->next = NULL;
    return NewNode;
}

void AddFirst(PNode *Head,PNode NewNode){
    NewNode->next = *Head;
    NewNode->index = 0;
    *Head = NewNode;

}
void AddAfter(PNode NewNode,PNode p){
    NewNode->next = p->next;
    p->next = NewNode;
    NewNode->index = p->index + 1;
    PNode q = NewNode->next;
    if (q)
        q->index = NewNode->index + 1;
    while (q->next){
        (q->next)->index = q->index + 1;
        q = q->next;
    }
}

void AddBefore(PNode *Head,PNode p,PNode NewNode){
    PNode q = *Head;
    if (*Head == p){
        AddFirst(Head,NewNode);
        return;
    }
    while (q && q->next != p)
        q = q->next;
    if (q)
        AddAfter(NewNode,q);
}

void AddLast(PNode *Head,PNode NewNode){
    PNode q = *Head;
    if (*Head == NULL){
        NewNode->index = 0;
        *Head = NewNode;
        return;
    }
    while (q && q->next != NULL){
        q = q->next;
    }
    if (q)
        q->next = NewNode;
        NewNode->index = q->index + 1;

}

int FindIndex(PNode Head, char NewWord[]){
    PNode q = Head;
    while (q && strcmp(q->word,NewWord)){
        q = q->next;
    }
    return q->index;
}

void PrintList(PNode Head) {
    PNode p = Head;
    while(p != NULL){
        printf("%d-%s ",p->index,p->word);
        p = p->next;
    }
}

void DeleteNode(PNode *Head, PNode OldNode){
    PNode q = *Head;
    if (*Head == OldNode){
        *Head = OldNode->next;
    }else{
        while (q && q->next != OldNode)
            q = q->next;
        if (q == NULL) return;
        q->next = OldNode->next;
        while (q->next){
            (q->next)->index = q->index + 1;
            q = q->next;
        }

    }
    free(OldNode);
}

int main(){

    return 0;
}