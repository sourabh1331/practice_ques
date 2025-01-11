#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int max(int a, int b) {
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int maxSubarraySum(int arr[], int size) {
    int maxSum =0;
    for (int st = 0; st < size; st++) { 
        int currSum = 0;
        for (int end = st; end < size; end++) {
            currSum = currSum + arr[end];
            maxSum=max(currSum,maxSum);
        }
    }
    return maxSum;
}


int main(){
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    //print all subarray
    /*for(int st =0;st<n;st++){
        for(int end=st;end<n;end++){
            for(int i=st;i<=end;i++){
                printf("%d\n",arr[i]);
            }
            printf("\n");
        }
    }*/
    int max_sum = maxSubarraySum(arr, n);
    printf("%d\n", max_sum);
    free(arr);
    return 0;
} 