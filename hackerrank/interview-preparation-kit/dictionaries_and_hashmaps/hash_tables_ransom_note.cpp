// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map <string, int> m;
    for (int i = 0; i < magazine.size(); ++i){
        auto node = m.find(magazine[i]);
        if (node == m.end()){
            m.insert({magazine[i], 1});
        }
        else{
            node->second += 1;
        }
    }

    for (int i = 0; i < note.size(); ++i){
        auto node = m.find(note[i]);
        if (node == m.end()){
            cout << "No" << endl;
            return;
        }
        else{
            node->second -= 1;
            if (node->second < 0){
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << "Yes" << endl;
}