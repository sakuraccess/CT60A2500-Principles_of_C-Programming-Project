//
// Created by x109649 on 19.4.2023.
//

#ifndef PRINCIPLES_OF_C_PROGRAMMING_PROJECT_WORK_LINKED_LIST_H
#define PRINCIPLES_OF_C_PROGRAMMING_PROJECT_WORK_LINKED_LIST_H

typedef struct {
    char *data;
    struct node *pNext;
} Node;

int isEmpty(Node *head);

Node *addToEnd(Node *head, char str[]);

Node *addToBeginning(Node *head, char str[]);

int size(Node *head);

Node *tail(Node *head);

Node *get_node(Node *head, int pos);

Node *deleteFirst(Node *head);

Node *deleteLast(Node *head);

int find(Node *head, char *str);

void print(Node *head);

char *toString(Node *head);

Node *reverse(Node *head);

#endif //PRINCIPLES_OF_C_PROGRAMMING_PROJECT_WORK_LINKED_LIST_H
