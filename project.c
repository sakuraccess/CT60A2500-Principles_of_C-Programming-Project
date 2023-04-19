/* You may use this file as a model for writing a testing program for your project work */
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *filePointer;
    char lineBuffer[20];

    // Create an empty list
    Node *pFirst = NULL;

    // Testing if the list is empty
    printf("Is empty?: %d\n", isEmpty(pFirst));

    pFirst = addToBeginning(pFirst, "Kimi");

    print(pFirst);

    // Reading the file and adding the elements
    filePointer = fopen("..\\names.txt", "r");

    if (filePointer == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }

    while (fgets(lineBuffer, 20, filePointer)) {
        lineBuffer[strcspn(lineBuffer, "\n")] = '\0';
        pFirst = addToEnd(pFirst, lineBuffer);
    }

    fclose(filePointer);

    // Testing if the list is empty again
    printf("Is empty?: %d\n", isEmpty(pFirst));

    // printing the list
    print(pFirst);

    // printing the size of the list
    printf("Size is: %d\n", size(pFirst));

    // Fetching the last not
    Node *nodePtr = tail(pFirst);
    printf("Last name: %s\n", nodePtr->data);

    // Fetching the 10th node
    nodePtr = get_node(pFirst, 2);
    printf("Name in position %d: %s\n", 2, nodePtr->data);

    // Fetching element outside the list 
    nodePtr = get_node(pFirst, 31);
    if (nodePtr == NULL) {
        printf("Not found!\n");
    }

    // Delete the first element
    printf("Deleting first...\n");
    pFirst = deleteFirst(pFirst);

    // printing the list
    print(pFirst);

    // Add a new first
    printf("Adding \"Sirkka\" to the beginning...\n");
    pFirst = addToBeginning(pFirst, "Sirkka");
    // Remove the last
    printf("Deleting last...\n");
    pFirst = deleteLast(pFirst);

    // Print the modified list
    print(pFirst);

    // test whether some names are present
    printf("The position of %s is: %d\n", "Teppo", find(pFirst, "Teppo"));
    printf("The position of %s is: %d\n", "Maija", find(pFirst, "Maija"));

    // reverse the list and print it
    printf("Reversing the list...\n");
    pFirst = reverse(pFirst);
//    print(pFirst);

    printf("%s\n", toString(pFirst));

    return 0;
}