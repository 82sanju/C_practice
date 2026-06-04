#include<stdio.h>
#include<stdlib.h>
int main(){
    int rows,col;
    int **arr;
    printf("enter rows and columns:");
    scanf("%d %d",&rows,&col);

    
    //array creation
    arr=(int **)malloc(rows * sizeof(int *));
    if(arr==NULL){
        printf("mem alloc failed\n");
        return 1;
    }

    for(int i=0;i<rows;i++){
        arr[i]=(int *)malloc(col * sizeof(int));
        if(arr==NULL){
            printf("mem alloc failed\n");
            return 1;
        }
    }

    printf("enter elements of array:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<rows;i++){
        free(arr[i]);
    }
    free(arr);
    arr=NULL;
    return 0;


}