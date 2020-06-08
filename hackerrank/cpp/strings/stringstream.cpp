vector<int> parseInts(string str) {
	// Complete this function
    vector <int> result;
    int i;
    char c;

    stringstream ss(str);
    while (ss){
        ss >> i >> c;
        result.push_back(i);
    }
    return result;
}