#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringProcess.h"


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


void removeNodeThroughID(linkList *list, int lensSerialNumber, int cameraSerialNumber) {
    node *p, *q;
    for(p = list->head, q = list->head->next; q != NULL; p = q, q = q->next) {
        if(q->lensSerialNumber == lensSerialNumber && q->cameraSerialNumber == cameraSerialNumber) {
            p->next = q->next;
            free(q);
            return;
        }
    }
    printf("No such node found.\n");
}


void changeNodeThroughID(linkList *list, int lensSerialNumber, int cameraSerialNumber) {
    node *p;
    int command;
    for(p = list->head->next; p != NULL; p = p->next) {
        if(p->lensSerialNumber == lensSerialNumber && p->cameraSerialNumber == cameraSerialNumber) {
            while(1) {
                printf("which one do you want to change?\n");
                printf("[0] exit\n[1] lensSerialNumber\n[2] cameraSerialNumber\n[3] shots\n[4] shootAction\n[5] duration\n[6] shotContent\n[7] lines\n[8] effectSound\n[9] music\n[10] transition\n[11] other\n");
                scanf("%d", &command);
                getchar();
                switch(command) {
                    case 0:
                        return;
                    case 1:
                        printf("Please input the lens serial number: ");
                        scanf("%d", &p->lensSerialNumber);
                        break;
                    case 2:
                        printf("Please input the camera serial number: ");
                        scanf("%d", &p->cameraSerialNumber);
                        break;
                    case 3:
                        printf("Please input the shots: ");
                        stringList *temp = inputString();
                        p->shots = temp;
                        break;
                    case 4:
                        printf("Please input the shoot action: ");
                        temp = inputString();
                        p->shootAction = temp;
                        break;
                    case 5:
                        printf("Please input the duration(int): ");
                        scanf("%d", &p->duration);
                        break;
                    case 6:
                        printf("Please input the shot content: ");
                        temp = inputString();
                        p->shotContent = temp;
                        break;
                    case 7:
                        printf("Please input the lines: ");
                        temp = inputString();
                        p->lines = temp;
                        break;
                    case 8:
                        printf("Please input the effect sound: ");
                        temp = inputString();
                        p->effectSound = temp;
                        break;
                    case 9:
                        printf("Please input the music: ");
                        temp = inputString();
                        p->music = temp;
                        break;
                    case 10:
                        printf("Please input the transition: ");
                        temp = inputString();
                        p->transition = temp;
                        break;
                    case 11:
                        printf("Please input the other: ");
                        temp = inputString();
                        p->other = temp;
                        break;
                    default:
                        printf("Invalid command.\n");
                        break;
                }
            }
        }
    }
    printf("No such node found.\n");
}