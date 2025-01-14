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
    if (head == NULL) {
        return 0;
    }

    int n = 1;
    while (head->pNext != NULL) {
        n++;
        head = head->pNext;
    }

    return n;
}

Node *tail(Node *head) {
    if (isEmpty(head)) {
        return NULL;
    }

    while (head->pNext != NULL) {
        head = head->pNext;
    }

//    printf("head : %s\n", head->data);

    return head;
}

Node *get_node(Node *head, int pos) {
    int n = size(head);

    if (pos > n) {
        return NULL;
    }

    int i = 1;
    while (head->pNext != NULL) {
        if (pos == i++) {
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

    Node *pNewFirst = head->pNext;
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

    if (strcmp(head->data, str) == 0) {
        return 1;
    }

    int i = 1;
    while (head->pNext != NULL) {
        head = head->pNext;
        i++;
        if (strcmp(head->data, str) == 0) {
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

    char *ans = (char *) calloc(1, 5000 * sizeof(char));
    strcat(ans, "(");
    strcat(ans, head->data);
    strcat(ans, ")");

//    printf("%s\n", ans);

    while (head->pNext != NULL) {
        head = head->pNext;
        strcat(ans, " -> (");
        strcat(ans, head->data);
        strcat(ans, ")");
    }

    return ans;
}

Node *reverse(Node *head) {
    if (isEmpty(head) || head->pNext == NULL) {
        return head;
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