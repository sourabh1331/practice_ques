#include<stdio.h>
#include<stdlib.h>

int** convertTo2DArray(int*arr,int row,int cols){
    int** twoDArray=(int**)malloc(row*sizeof(int*));
    for (int i = 0; i < row; i++) {
        twoDArray[i] = (int*)malloc(cols * sizeof(int));//allocating memory for each row
        
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<cols;j++){
            twoDArray[i][j]=arr[i*cols+j];
        }

    }
    return twoDArray;
}
void print2DArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int totalelement,row,cols;
    printf("Enter the total Element: ");
    scanf("%d",&totalelement);

    printf("Enter the row and cols: ");
    scanf("%d %d",&row,&cols);

    if(row*cols!=totalelement){
        return 1;
    }
    int* arr=(int*)malloc(totalelement*sizeof(int));
    for(int i=0;i<totalelement;i++){
        scanf("%d", &arr[i]);
    }
    
    int** twoDArray=convertTo2DArray(arr,row,cols);

    printf("2D array\n");
    print2DArray(twoDArray, row, cols);

    free(arr);
    for (int i = 0; i < row; i++) {
        free(twoDArray[i]);
    }
    free(twoDArray);

    return 0;

}