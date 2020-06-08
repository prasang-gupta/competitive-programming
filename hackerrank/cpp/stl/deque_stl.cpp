void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque <int> a;
    int curmax = arr[0];
    for (int i = 0; i < k; ++i){
        if (curmax < arr[i]){
            curmax = arr[i];
        }
        a.push_back(arr[i]);
    }

    cout << curmax << " ";
    for (int i = k; i < n; ++i){
        if (curmax < arr[i]){
            curmax = arr[i];
        }

        if (arr[i-k] == curmax){
            int getmax = arr[i];
            for (int j = i; j > i-k; --j){
                if (getmax < arr[j]){
                    getmax = arr[j];
                }
            }
            curmax = getmax;
        }

        a.pop_front();
        a.push_back(arr[i]);
        cout << curmax << " ";
    }
    cout << endl;
}