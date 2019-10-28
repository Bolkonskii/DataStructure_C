#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[40];
    int index;
    struct Node *next, *prev;
};
typedef struct Node *PNode;
PNode Head = NULL, Tail = NULL;

PNode CreateNode( char NewWord[] ){
    PNode NewNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(NewNode->word,NewWord);
    NewNode->next = NULL;
    return NewNode;
}

void AddFirst(PNode *Head, PNode *Tail,PNode NewNode){
    NewNode->next = *Head;
    NewNode->prev = NULL;
    if (*Head)
        (*Head)->prev = NewNode;
        NewNode->index = 0;
    *Head = NewNode;
    if (!(*Tail))
        *Tail = *Head;
}

void AddLast(PNode *Head,PNode *Tail, PNode NewNode){
    (*Tail)->next = NewNode;
    NewNode->prev = *Tail;
    NewNode->index = (NewNode->prev)->index + 1;
    *Tail = NewNode;
}

void PrintList(PNode *Head){
    PNode q = *Head;
    while (q) {
        printf("%d-%s ",q->index,q->word);
        q = q->next;
    }
}

int FindElement(PNode *Head, char FindWord[]){
    PNode q = *Head;
    while (q && strcmp(q->word,FindWord)){
        q = q->next;
    }
    if (q)
        return q->index;
}

void DeleteElement(PNode *Head,PNode *Tail,PNode OldElem){
    if (*Head == OldElem){
        *Head = OldElem->next;
        if (*Head){
            (*Head)->prev = NULL;
            PNode q = *Head;
            q->index = 0;
            while(q->next){
                q->next->index = q->index + 1;
                q = q->next;
            }  
        }  
        else
            *Tail = NULL;  
    }else{
        OldElem->prev->next = OldElem->next;
        if (OldElem->next){
            OldElem->next->prev = OldElem->prev;
            PNode q = OldElem->next;
            q->index = OldElem->index;
            while (q->next){
                q->next->index = q->index + 1;
                q = q->next;
            }
        }
        else
            *Tail = NULL;
        
    }
}
int main(){
    
    return 0;
}