#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int marks;
    int roll_number;
    struct Student* next;
} Student;

Student* createStudent(char name[], int marks, int roll_number) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->roll_number = roll_number;
    newStudent->next = NULL;
    return newStudent;
}

void insertStudent(Student** head, char name[], int marks, int roll_number) {
    Student* newStudent = createStudent(name, marks, roll_number);
    if (*head == NULL) {
        *head = newStudent;
        return;
    }
    Student* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newStudent;
}

Student* getMiddle(Student* head) {
    if (head == NULL) return NULL;
    Student* slow = head;
    Student* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Student* merge(Student* left, Student* right) {
    if (!left) return right;
    if (!right) return left;

    Student* result = NULL;
    if (left->marks > right->marks || (left->marks == right->marks && left->roll_number < right->roll_number)) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

Student* mergeSort(Student* head) {
    if (!head || !head->next) return head;

    Student* middle = getMiddle(head);
    Student* nextToMiddle = middle->next;
    middle->next = NULL;

    Student* left = mergeSort(head);
    Student* right = mergeSort(nextToMiddle);

    return merge(left, right);
}

void printList(Student* head) {
    while (head) {
        printf("%s %d %d\n", head->name, head->marks, head->roll_number);
        head = head->next;
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student* head = NULL;
    char name[50];
    int marks, roll_number;

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", name, &marks, &roll_number);
        insertStudent(&head, name, marks, roll_number);
    }

    head = mergeSort(head);

    printf("\nSorted Student List:\n");
    printList(head);

    return 0;
}
