// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long size = s.size(), result = 0;
    long firstbound = n%size, multiplier = n/size;
    for (int i = 0; i < size; ++i){
        if (s[i] == 'a'){
            if (i < firstbound){
                result += multiplier+1;
            }
            else{
                if (multiplier == 0){
                    break;
                }
                result += multiplier;
            }
        }
    }
    return result;
}