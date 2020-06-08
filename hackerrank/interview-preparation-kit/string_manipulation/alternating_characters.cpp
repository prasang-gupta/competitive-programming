// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int count = 0, j = 0;
    for (int i = 1; i < s.size(); ++i){
        if (s[i] == s[j]){
            ++count;
        }
        else{
            j = i;
        }
    }
    return count;
}