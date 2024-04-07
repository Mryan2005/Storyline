#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkList.h"
#include "stringProcess.h"

typedef struct step {
	node *data;
	char *command;
	struct step *next;
} step;
typedef step* stepStack;


void initStepStack(stepStack *stack);
void PushUndo(stepStack *undoStack, step *step_);
void PushRedo(stepStack *redoStack, step *step_);
void redo(stepStack *undoStack, stepStack *redoStack, linkList *List);


void createAStep(node *p, step *step_, char *command) {
	step_->data = p;
	step_->command = (char *)malloc(10 * sizeof(char));
	strcpy(step_->command, command);
	step_->next = NULL;
}


void initStepStack(stepStack *stack) {
	*stack = NULL;
}


void PushUndo(stepStack *undoStack, step *step_, char *command) {
	step_->command = (char *)malloc(10 * sizeof(char));
	strcpy(step_->command, command);
	step_->next = *undoStack;
	*undoStack = step_;
}


void PushRedo(stepStack *redoStack, step *step_, char *command) {
	step_->command = (char *)malloc(10 * sizeof(char));
	strcpy(step_->command, command);
	step_->next = *redoStack;
	*redoStack = step_;
}


void undo(stepStack *undoStack, stepStack *redoStack, linkList *List) {
	node *p = List->head;
	if(*undoStack == NULL) {
		printf("No more undo\n");
		return;
	}
	step *step_ = *undoStack;
	*undoStack = step_->next;
	if(strcmp(step_->command, "add") == 0) {
		for(p = List->head; step_->data->next != p; p = p->next);
		p->next = step_->data->next;
		PushRedo(redoStack, step_, "delete");
	} else if(strcmp(step_->command, "delete") == 0) {
		p = List->head;
		while(p->next != step_->data) {
			p = p->next;
		}
		p->next = step_->data->next;
		PushRedo(redoStack, step_, "add");
	} else if(strcmp(step_->command, "modify") == 0) {
		for(p = List->head; step_->data->next != p; p = p->next);
		step_->data->next = p->next;
		p->next = step_->data;
		PushRedo(redoStack, step_, "modify");
	}
}


void redo(stepStack *undoStack, stepStack *redoStack, linkList *List) {
	node *p = List->head;
	if(*undoStack == NULL) {
		printf("No more redo\n");
		return;
	}
	step *step_ = *undoStack;
	*undoStack = step_->next;
	if(strcmp(step_->command, "add") == 0) {
		for(p = List->head; step_->data->next != p; p = p->next);
		p->next = step_->data->next;
		PushUndo(redoStack, step_, "delete");
	} else if(strcmp(step_->command, "delete") == 0) {
		p = List->head;
		while(p->next != step_->data) {
			p = p->next;
		}
		p->next = step_->data->next;
		PushUndo(redoStack, step_, "add");
	} else if(strcmp(step_->command, "modify") == 0) {
		for(p = List->head; step_->data->next != p; p = p->next);
		step_->data->next = p->next;
		p->next = step_->data;
		PushUndo(redoStack, step_, "modify");
	}
}
