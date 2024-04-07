#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkList.h"
#include "stringProcess.h"


typedef struct itemHead{
    int id;
    char *chartName;
    struct itemHead *next;
} itemHead;
typedef itemHead *itemHeadPtr;


void readFile(FILE *fp) {
    itemHeadPtr head = NULL, p = NULL;
    head = (itemHeadPtr)malloc(sizeof(itemHead));
    p = head->next = (itemHeadPtr)malloc(sizeof(itemHead));
    char ch, temp[256];
    int i = 0, curId = 0;
    while((ch = fgetc(fp)) != '\n') {
        if(ch == ' ') {
            temp[i] = '\0';
            i = 0;
            p->id = ++curId;
            p->chartName = (char *)malloc(strlen(temp) + 1);
            strcpy(p->chartName, temp);
            p->next = (itemHeadPtr)malloc(sizeof(itemHead));
            p = p->next;
        }
        temp[i++] = ch;
    }
}