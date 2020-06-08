// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    map <int, int> elem;
    map <int, int> freq;
    vector <int> ans;

    for (int i = 0; i < queries.size(); ++i){
        if (queries[i][0] == 1){
            freq[elem[queries[i][1]]]--;
            freq[++elem[queries[i][1]]]++;
        }
        else if (queries[i][0] == 2){
            if (elem[queries[i][1]] > 0){
                freq[elem[queries[i][1]]--]--;
                freq[elem[queries[i][1]]]++;
            }
        }
        else{
            ans.push_back((freq[queries[i][1]]) ? 1 : 0);
        }
    }
    return ans;
}