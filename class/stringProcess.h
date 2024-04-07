#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stringBlock {
    char *string;
    struct stringBlock *next;
} stringBlock;
typedef struct stringList {
    stringBlock *head;
    stringBlock *tail;
} stringList;


stringList *inputString();
void printStringList(stringList *list);


stringList *inputString() {
    stringBlock *head = (stringBlock *)malloc(sizeof(stringBlock)), *tail = head, *q;
    char *string = (char *)malloc(10 * sizeof(char)), ch, *p = string;
    while((ch = getchar()) != '\n') {
        *p++ = ch;
        if(p - string >= 10) {
            *p = '\0';
            tail->string = string;
            q = (stringBlock *)malloc(sizeof(stringBlock));
            tail->next = q;
            tail = q;
            string = (char *)malloc(10 * sizeof(char));
            p = string;
        }
    }
    *p = '\0';
    for(q = head; q != tail; q = q->next);
    // head->string = (char *)malloc((p - string + 1) * sizeof(char));
    q->string = (char *)malloc((p - string + 1) * sizeof(char));
    strcpy(q->string, string);
    free(string);
    tail->next = NULL;
    stringList *list = (stringList *)malloc(sizeof(stringList));
    list->head = head;
    list->tail = tail;
    return list;
}


void printStringList(stringList *list) {
    stringBlock *p;
    for(p = list->head; p != list->tail; p = p->next) {
        printf("%s", p->string);
    }
    printf("%s\n", p->string);
}