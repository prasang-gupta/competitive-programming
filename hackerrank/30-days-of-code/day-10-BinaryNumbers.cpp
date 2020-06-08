#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string binary = bitset<32>(n).to_string();
    int sum = 0, maxsum = 0;
    for (int i = 0; i < binary.size(); ++i){
        if (binary[i] == '0'){
            sum = 0;
            continue;
        }
        sum += 1;
        if (sum > maxsum){
            maxsum = sum;
        }
    }
    cout << maxsum << endl;
    return 0;
}
