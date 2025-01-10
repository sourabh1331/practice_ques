// Dividing a string into N equal parts

#include<stdio.h>

void divide(char str[],int n){
    int length=0;
    while(str[length]!='\0'){
        length++;
    }
    if (length % n!=0){
        printf("String is not Divisible into equal parts");
    }
    int parts=length/n;
    for(int i=0;i<length;i++){
        printf("%c",str[i]);

        if((i+1)%parts==0){
            printf("\n");
        }
    }
}
int main()
{
    char str[100];
    int n;
    scanf("%s",str);
    scanf("%d",&n);
    divide(str,n);

    return 0;
}