#include "class/stringProcess.h"
#include "class/linkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    linkList List;
    initList(&List);
    char command[100];
	int lens, camera;
    do {
        system("cls");
        printf("[add] add a node\n");
        printf("[read] read the link list\n");
        printf("[rm] remove a node\n");
        printf("[change] change a node\n");
        printf("[exit] exit the program\n");
        printf("Enter command: ");
        scanf("%s", command);
        if(strcmp(command, "add") == 0) {
            system("cls");
            addANode(&List);
            system("pause");
        } else if(strcmp(command, "read") == 0) {
            system("cls");
            printf("wether read a node? if you went input the number of lens and the number of camera, or input 0 to exit\n");
			readLinkList(&List);
            printf("Please input the lens serial number and the camera serial number and the camera serial number: ");
            do {
                scanf("%d", &lens);
                if(lens != 0) {
                    scanf("%d", &camera);
                    findNodeThroughID(&List, lens, camera);
                    printf("wether read a node? if you went input the number of lens and the number of camera, or input 0 to exit\n");
					readLinkList(&List);
                    printf("Please input the lens serial number and the camera serial number: ");
                }
            } while(lens != 0);
            system("pause");
		} else if(strcmp(command, "rm") == 0) {
            system("cls");
            printf("wether remove a node? if you went input the number of lens and the number of camera, or input 0 to exit\n");
			readLinkList(&List);
            printf("Please input the lens serial number and the camera serial number: ");
            do {
                scanf("%d", &lens);
                if(lens != 0) {
                    scanf("%d", &camera);
                    removeNodeThroughID(&List, lens, camera);
                    printf("wether remove a node? if you went input the number of lens and the number of camera, or input 0 to exit\n");
					readLinkList(&List);
                    printf("Please input the lens serial number and the camera serial number: ");
                }
            } while(lens != 0);
            system("pause");
        } else if(strcmp(command, "change") == 0) {
            system("cls");
            printf("wether change a node? if you went input the number of lens and the number of camera, or input 0 to exit\n");
			readLinkList(&List);
            printf("Please input the lens serial number and the camera serial number: ");
            do {
                scanf("%d", &lens);
                if(lens != 0) {
                    scanf("%d", &camera);
                    changeNodeThroughID(&List, lens, camera);
                    printf("wether change a node? if you went input the number of lens and the number of camera, or input 0 to exit\n");
					readLinkList(&List);
                    printf("Please input the lens serial number and the camera serial number: ");
                }
            } while(lens != 0);
            system("pause");
        }
    } while(strcmp(command, "exit") != 0);
}
