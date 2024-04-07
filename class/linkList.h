#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringProcess.h"
#include "linkStack.h"


typedef struct node {
    int lensSerialNumber;
    int cameraSerialNumber;
    stringList *shots;
    stringList *shootAction;
    int duration;
    stringList *shotContent;
    stringList *lines;
    stringList *effectSound;
    stringList *music;
    stringList *transition;
    stringList *other;
    struct node *next;
} node;
typedef struct linkList {
    node *head;
    node *tail;
} linkList;


void initList(linkList *list);
void addANode(linkList *list);
void findNodeThroughID(linkList *list, int lensSerialNumber, int cameraSerialNumber);
void readLinkNode(node *p);
void readLinkList(linkList *list);


void initList(linkList *list) {
    list->head = (node *)malloc(sizeof(node));
    list->head->next = NULL;
    list->tail = list->head;
}


void addANode(linkList *list) {
    node *p = (node *)malloc(sizeof(node));
    list->tail->next = p;
    list->tail = p;
    p->next = NULL;
    printf("Please input the lens serial number: ");
    scanf("%d", &p->lensSerialNumber);
    printf("Please input the camera serial number: ");
    scanf("%d", &p->cameraSerialNumber);
    getchar();
    printf("Please input the shots: ");
    stringList *temp = inputString();
    p->shots = temp;
    printf("Please input the shoot action: ");
    temp = inputString();
    p->shootAction = temp;
    printf("Please input the duration(int): ");
    scanf("%d", &p->duration);
    getchar();
    printf("Please input the shot content: ");
    temp = inputString();
    p->shotContent = temp;
    printf("Please input the lines: ");
    temp = inputString();
    p->lines = temp;
    printf("Please input the effect sound: ");
    temp = inputString();
    p->effectSound = temp;
    printf("Please input the music: ");
    temp = inputString();
    p->music = temp;
    printf("Please input the transition: ");
    temp = inputString();
    p->transition = temp;
    printf("Please input the other: ");
    temp = inputString();
    p->other = temp;
}


void findNodeThroughID(linkList *list, int lensSerialNumber, int cameraSerialNumber) {
    node *p;
    for(p = list->head->next; p != NULL; p = p->next) {
        if(p->lensSerialNumber == lensSerialNumber && p->cameraSerialNumber == cameraSerialNumber) {
            readLinkNode(p);
            return;
        }
    }
    printf("No such node found.\n");
}


void readLinkNode(node *p) {
    printf("Lens serial number: %d\n", p->lensSerialNumber);
    printf("Camera serial number: %d\n", p->cameraSerialNumber);
    printf("Shots: ");
    printStringList(p->shots);
    printf("Shoot action: ");
    printStringList(p->shootAction);
    printf("Duration: %d\n", p->duration);
    printf("Shot content: ");
    printStringList(p->shotContent);
    printf("Lines: ");
    printStringList(p->lines);
    printf("Effect sound: ");
    printStringList(p->effectSound);
    printf("Music: ");
    printStringList(p->music);
    printf("Transition: ");
    printStringList(p->transition);
    printf("Other: ");
    printStringList(p->other);
}


void readLinkList(linkList *list) {
    node *p;
    for(p = list->head->next; p != NULL; p = p->next) {
        printf("[%d][%d] ", p->lensSerialNumber, p->cameraSerialNumber);
        printStringList(p->shotContent);
    }
}


void deleteNode(linkList *list, int lensSerialNumber, int cameraSerialNumber) {
    node *p = list->head, *q;
    while(p->next != NULL) {
        if(p->next->lensSerialNumber == lensSerialNumber && p->next->cameraSerialNumber == cameraSerialNumber) {
            q = p->next;
            p->next = q->next;
            
            return;
        }
        p = p->next;
    }
    printf("No such node found.\n");
}


void changeNode(linkList *list, int lensSerialNumber, int cameraSerialNumber) {
    node *p;
    for(p = list->head->next; p != NULL; p = p->next) {
        if(p->lensSerialNumber == lensSerialNumber && p->cameraSerialNumber == cameraSerialNumber) {
            printf("Please input the lens serial number: ");
            scanf("%d", &p->lensSerialNumber);
            printf("Please input the camera serial number: ");
            scanf("%d", &p->cameraSerialNumber);
            getchar();
            printf("Please input the shots: ");
            stringList *temp = inputString();
            p->shots = temp;
            printf("Please input the shoot action: ");
            temp = inputString();
            p->shootAction = temp;
            printf("Please input the duration(int): ");
            scanf("%d", &p->duration);
            getchar();
            printf("Please input the shot content: ");
            temp = inputString();
            p->shotContent = temp;
            printf("Please input the lines: ");
            temp = inputString();
            p->lines = temp;
            printf("Please input the effect sound: ");
            temp = inputString();
            p->effectSound = temp;
            printf("Please input the music: ");
            temp = inputString();
            p->music = temp;
            printf("Please input the transition: ");
            temp = inputString();
            p->transition = temp;
            printf("Please input the other: ");
            temp = inputString();
            p->other = temp;
            return;
        }
    }
    printf("No such node found.\n");
}