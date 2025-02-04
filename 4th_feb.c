#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    char str[10];
    struct Node *next;
} Node;

typedef struct Dir {
    Node *head;
    Node *tail;
} Dir;

void initDir(Dir *d) {
    d->head = NULL;
    d->tail = NULL;
}

void addDir(Dir *d, char str[]) {
    Node *newdir = (Node *)malloc(sizeof(Node));
    strcpy(newdir->str, str);
    newdir->next = NULL;
    if (d->head == NULL) {
        d->head = d->tail = newdir;
    } else {
        d->tail->next = newdir;
        d->tail = newdir;
    }
}

void popback(Dir *d) {
    if (d->head == NULL) return;
    if (d->head == d->tail) {
        free(d->head);
        d->head = d->tail = NULL;
        return;
    }
    Node *temp = d->head;
    while (temp->next != d->tail) temp = temp->next;
    free(d->tail);
    temp->next = NULL;
    d->tail = temp;
}

void printDir(Dir *d) {
    Node *temp = d->head;
    printf("/");
    while (temp != NULL) {
        printf("%s/", temp->str);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Dir d;
    initDir(&d);
    
    char input[MAX], *token;
    
    printf("Enter commands (space-separated): ");
    fgets(input, MAX, stdin);
    
    token = strtok(input, " ");
    while (token != NULL) {
        if (strcmp(token, "cd") == 0) {
            token = strtok(NULL, " ");
            if (token == NULL) break;

            if (strcmp(token, "../") == 0) {
                popback(&d);
            } else if (strcmp(token, "./") == 0) {
                continue;
            } else {
                addDir(&d, token);
            }
        }
        token = strtok(NULL, " ");
    }

    printDir(&d);
    return 0;
}
