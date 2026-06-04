#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4;
    
    
    int **arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL) {
        printf("Memory allocation failed for row pointers\n");
        return 1;
    }
//allocate mem for rows
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed %d\n", i);
            return 1;
        }
    }
// assign values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * 10 + j;
        }
    }

    //Print values + addresses
    printf("\nArray values and address:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d pointer address: %p\n", i, (void *)arr[i]);
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = %d (addr: %p)\n",
                   i, j, arr[i][j], (void *)&arr[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < rows; i++) {
        // free each row
        free(arr[i]);
    }
    free(arr);          

    return 0;

}
 