// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    map <long, long> right, left;
    long count = 0;

    for (int i = 0; i < arr.size(); ++i){
        right[arr[i]]++;
    }

    for (int i = 0; i < arr.size(); ++i){
        right[arr[i]]--;
        if (arr[i]%r == 0){
            count += left[arr[i]/r]*right[arr[i]*r];
        }
        left[arr[i]]++;
    }
    return count;
}