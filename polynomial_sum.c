//polynomial arithmeatic.implement a function to add polynomial together represented as sll it contain two field 1-coeff,2-power
// create two ll and return a ll that give resust

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coeff;
    int power;
    struct Node* next;
}Node;

Node*createNode(int c,int p){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->coeff =c;
    newnode->power=p;
    newnode->next=NULL;

    return newnode;
}

void insert_at_head(Node** head_ref, int coeff,int power) {
    Node* newnode = createNode(coeff,power);
    newnode->next = *head_ref;
    *head_ref = newnode;
}

void printPolynomial(Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->power);
        if (poly->next != NULL)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

Node*addPolynomials(Node* poly1,Node*poly2){
    Node* result = NULL;
    Node** temp = &result;
    while(poly1!=NULL || poly2!=NULL){
        int coeff,power;
        if (poly1 == NULL) {
            coeff = poly2->coeff;
            power = poly2->power;
            poly2 = poly2->next;

        }else if(poly2== NULL){
            coeff=poly1->coeff;
            power=poly1->power;
            poly1=poly1->next;
        }else if (poly1->power > poly2->power) {
            coeff = poly1->coeff;
            power = poly1->power;
            poly1 = poly1->next;
        }else if (poly1->power < poly2->power) {
            coeff = poly2->coeff;
            power = poly2->power;
            poly2 = poly2->next;
        }else{
            coeff=poly1->coeff+poly2->coeff;
            power =poly1->power;
            poly1 = poly1->next;
            poly2 = poly2->next;

        }
        if (coeff != 0) {
            *temp = createNode(coeff, power);
            temp = &((*temp)->next);
        }
    }
    return result;
}
int main() {
    Node* exp1 = NULL;
    Node* exp2 = NULL;
    int n, coeff, power;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    printf("Enter terms in format (coefficient power):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &power);
        insert_at_head(&exp1, coeff, power);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter terms in format (coefficient power):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &power);
        insert_at_head(&exp2, coeff, power);
    }

    printf("First Polynomial: ");
    printPolynomial(exp1);
    printf("Second Polynomial: ");
    printPolynomial(exp2);

    Node* sum = addPolynomials(exp1, exp2);
    printf("Sum of Polynomials: ");
    printPolynomial(sum);

    return 0;
}
