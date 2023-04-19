//
// Created by x109649 on 19.4.2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[10];
    struct node *pNext;
} Node;

int isEmpty(Node *head) {
    if (head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

Node *addToEnd(Node *head, char str[]) {
    Node *pNew = (Node *) malloc(sizeof(Node));
    Node *pHead = head;
    strcpy(pNew->data, str);
    pNew->pNext = NULL;

    if (head == NULL) {
        pHead = pNew;
    } else {
        while (head->pNext != NULL) {
            head = head->pNext;
        }
        head->pNext = pNew;
    }

    return pHead;
}

Node *addToBeginning(Node *head, char str[]) {
    Node *pNew = (Node *) malloc(sizeof(Node));
    strcpy(pNew->data, str);
    pNew->pNext = NULL;

    if (head == NULL) {
        head = pNew;
    } else {
        pNew->pNext = head;
        head = pNew;
    }

    return head;
}

int size(Node *head) {
    int n = 0;
    while (head->pNext != NULL) {
        n++;
        head = head->pNext;
    }

    return n;
}

Node *tail(Node *head) {
    while (head->pNext != NULL) {
        head = head->pNext;
    }

    return head;
}

Node *get_node(Node *head, int pos) {
    int n = size(head);

    if (pos > n) {
        return NULL;
    }

    int i = 1;
    while (head->pNext != NULL) {
        if (i == pos) {
            return head;
        }
        head = head->pNext;
    }

    return head; //never use
}

Node *deleteFirst(Node *head) {
    if (isEmpty(head)) {
        return NULL;
    }

    if (head->pNext == NULL) {
        free(head);
        return NULL;
    }

    Node *pNewFirst = head;
    free(head);

    return pNewFirst;
}

Node *deleteLast(Node *head) {
    if (isEmpty(head)) {
        return NULL;
    }

    if (head->pNext == NULL) {
        free(head);
        return NULL;
    }

    Node *pPrev, *pFirst = head;
    while (head->pNext != NULL) {
        pPrev = head;
        head = head->pNext;
    }

    free(head);
    pPrev->pNext = NULL;
    return pFirst;
}

int find(Node *head, char *str) {
    if (isEmpty(head)) {
        return 0;
    }

    if (head->data == str) {
        return 1;
    }

    int i = 1;
    while (head->pNext != NULL) {
        head = head->pNext;
        i++;
        if (head->data == str) {
            return i;
        }
    }

    return 0;
}

void print(Node *head) {
    if (isEmpty(head)) {
        printf("List is empty.\n");
        return;
    }

    int i = 1;
    printf("Printing...\n");
    printf("Node position 1: %s.\n", head->data);

    while (head->pNext != NULL) {
        i++;
        head = head->pNext;
        printf("Node position %d: %s.\n", i, head->data);
    }
}

char *toString(Node *head) {
    if (isEmpty(head)) {
        return "List is empty.\n";
    }

    char *ans = strcat("(", head->data);
    ans = strcat(ans, ")");

    while (head->pNext != NULL) {
        head = head->pNext;
        ans = strcat(ans, " -> (");
        ans = strcat(ans, head->data);
        ans = strcat(ans, ")");
    }

    return ans;
}

Node *reverse(Node *head) {
    if (isEmpty(head)) {
        return NULL;
    }

    if (head->pNext == NULL) {
        return NULL;
    }

    Node *pPrev, *pNext = head->pNext;
    head->pNext = NULL;

    while (1) {
        pPrev = head;
        head = pNext;
//        pPrev->pNext = NULL;

        if (head->pNext == NULL) {
            head->pNext = pPrev;
            return head;
        }

        pNext = head->pNext;

        head->pNext = pPrev;

//        pPrev = head;
//        head = pNext;
//        pNext = pNext->pNext;
    }

//    return head;
}