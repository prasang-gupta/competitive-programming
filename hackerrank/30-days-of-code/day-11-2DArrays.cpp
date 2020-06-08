#include <bits/stdc++.h>

using namespace std;



int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int r = arr.size(), c = arr[0].size(), sum, maxsum = - INT_MIN;

    for (int i = 0; i < r-2; ++i){
        for (int j = 0; j < c-2; ++j){
            sum = 0;
            for (int k = 0; k < 3; ++k){
                sum += arr[i][j+k];
                sum += arr[i+2][j+k];
            }
            sum += arr[i+1][j+1];
            if (maxsum < sum){
                maxsum = sum;
            }
        }
    }
    cout << maxsum << endl;
    return 0;
}
