#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

void interchangeDiagonals(int matrix[max][max],int n){
    for(int i=0;i<n;i++){
        int temp=matrix[i][i];
        matrix[i][i]=matrix[i][n-i-1];
        matrix[i][n-i-1]=temp;
    }
}

int sumDiagonals(int matrix[max][max],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=matrix[i][i];
        if(i!=n-i-1){
            sum+=matrix[i][n-i-1];
        }
    }
    return sum;
}


int main(){
    int n,matrix[max][max];
    char input[max];
    printf("Enter the size of Matix\n");
    scanf("%d",&n);
    getchar();
    printf("Enter the element in the matrix\n");
    for(int i=0;i<n;i++){
        fgets(input,max,stdin);
        input[strcspn(input,"\n")]='\0';
        // this for if we eneter single digit
        /*if(strlen(input)!=n){ 
            printf("Invalid input. Each row must have exactly %d characters.\n", n);
            return 1;
        }*/
        int num;
        int j = 0;
        char *token = strtok(input, " "); 
        while (token != NULL) {
            num = atoi(token); 
            matrix[i][j] = num;
            j++;
            token = strtok(NULL, " ");
        }
    }
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    int diagonalSum = sumDiagonals(matrix, n);
    interchangeDiagonals(matrix, n);

    printf("\nMatrix after interchanging diagonals:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of diagonals: %d\n", diagonalSum);

    return 0;
}