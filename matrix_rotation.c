// Rotate matrix by 90°
//dynamic mameory allocation
#include<stdio.h>
#include<stdlib.h>
void rotate90(int **mat,int n){

    for (int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp=mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i]=temp;
        }
    }

    for (int i=0;i<n;i++){
        int start=0,end=n-1;
        while(start<end){
            int temp=mat[i][start];
            mat[i][start]=mat[i][end];
            mat[i][end]=temp;
            start++;
            end--;
        }
    }

}
int main(){
    int n;
    scanf("%d", &n);
    int **mat=(int **)malloc(n*sizeof(int*));
    for (int i =0;i<n;i++){
        mat[i]=(int *)malloc(n*sizeof(int));
    }
    printf("Enter the elements of the %d x %d matrix:\n", n, n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    rotate90(mat, n);
    printf("Rotated matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    for (int i=0;i<n;i++){
        free(mat[i]);
    }
    free(mat);
    return 0;
}