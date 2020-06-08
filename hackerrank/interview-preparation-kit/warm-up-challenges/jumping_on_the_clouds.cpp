// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {
    int count = 0;
    for (int i = 0; i < c.size(); ++i){
        if (i < c.size()-2 && c[i+2] == 0){
            ++count;
            i += 1;
            continue;
        }
        if (i < c.size()-1 && c[i+1] == 0){
            ++count;
            continue;
        }
    }
    return count;
}