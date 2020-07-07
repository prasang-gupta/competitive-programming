int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int d1,m1,y1,d2,m2,y2;
    cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
    int nofine = 0;
    if (y1 > y2){
        cout << 10000 << endl;
        return 0;
    }
    else if (y1 == y2){
        if (m1 > m2){
            cout << 500 * (m1 - m2) << endl;
            return 0;
        }
        else if (m1 == m2){
            if (d1 > d2){
                cout << 15 * (d1 - d2) << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
