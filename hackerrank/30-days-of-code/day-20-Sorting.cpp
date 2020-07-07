    // Write Your Code Here
    int numswap = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n-1; ++j){
            if (a[j] > a[j+1]){
                numswap++;
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }