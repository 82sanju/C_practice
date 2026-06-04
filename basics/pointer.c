// #include <stdio.h>

// int main() {
//     int x = 10;
//     int *p;

//     p = &x;

//     printf("%p\n", p);   // prints address
//     printf("%d\n", *p);  // prints value stored at that address

//     return 0;
// }

#include <stdio.h>

int main() {
    int house1 = 100;
    int house2 = 200;
    
    int *p = &house1; // 'p' points to house1
    
    printf("BEFORE CHANGING POINTER:\n");
    printf("Value of p : %p\n", (void*)p);
    printf("Value of &p: %p\n\n", (void*)&p);
    
    p = &house2; // 'p' now points to house2 instead
    
    printf("AFTER CHANGING POINTER:\n");
    printf("Value of p : %p\n", (void*)p);
    printf("Value of &p: %p\n", (void*)&p);
    
    return 0;
}
