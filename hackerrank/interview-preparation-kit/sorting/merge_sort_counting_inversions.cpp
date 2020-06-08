long merge(vector <int> &arr, long left, long mid, long right){
    long i, j, count = 0;
    i = left;
    j = mid + 1;

    vector <int> temp;
    while ((i <= mid) && (j <= right)){
        if (arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }
        else {
            count += mid+1-i;
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid){
        temp.push_back(arr[i++]);
    }
    while (j <= right){
        temp.push_back(arr[j++]);
    }

    for (i = left; i <= right; ++i){
        arr[i] = temp[i-left];
    }
    return count;
}

long mergeSort(vector <int> &arr, long left, long right){
    long mid, count = 0;
    if (right > left){
        mid = left + (right-left)/2;

        count += mergeSort(arr, left, mid);
        count += mergeSort(arr, mid+1, right);

        count += merge(arr, left, mid, right);
    }
    return count;
}
// Complete the countInversions function below.
long countInversions(vector<int> arr) {
    return mergeSort(arr, 0, arr.size()-1);
}