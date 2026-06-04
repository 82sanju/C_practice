int main() {
    int a = 10, b = 20;

    const int *p = &a;
    //*p = 30;

    p = &b;
    printf("*p = %d\n", *p);

    return 0;
}