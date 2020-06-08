// Complete the countSwaps function below.
void countSwaps(vector<int> a) {
    int numswap = 0, temp;
    for (int i = 0; i < a.size(); ++i){
        for (int j = 0; j < a.size()-1; ++j){
            if (a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                ++numswap;
            }
        }
    }

    cout << "Array is sorted in " << numswap << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a.back();
}