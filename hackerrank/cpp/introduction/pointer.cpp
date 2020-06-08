void update(int *a,int *b) {
    // Complete this function
    int sum = *a + *b;
    *b = *a > *b ? *a-*b : *b-*a;
    *a = sum;
}