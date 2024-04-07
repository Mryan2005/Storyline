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
        printf("[add] add a node\n[read] read list\n[exit] exit\n");
        printf("Enter command: ");
        scanf("%s", command);
        if(strcmp(command, "add") == 0) {
            system("cls");
            addANode(&List);
            system("pause");
        } else if(strcmp(command, "read") == 0) {
            system("cls");
            readLinkList(&List);
            printf("wether read a node? if you went input the number of lens and the number of camera, or input 0 to exit\n");
            do {
                scanf("%d", &lens);
                if(lens != 0) {
                    scanf("%d", &camera);
                    findNodeThroughID(&List, lens, camera);
                    printf("wether read a node? if you went input the number of lens and the number of camera, or input 0 to exit\n");
                }
            } while(lens != 0);
            system("pause");
		}
    } while(strcmp(command, "exit") != 0);
}
