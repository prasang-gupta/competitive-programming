class Matrix {
    public:
        vector < vector <int>> a;

        Matrix & operator + (const Matrix &b) {
            for (int i = 0; i < b.a.size(); ++i){
                for (int j = 0; j < b.a[0].size(); ++j){
                    a[i][j] += b.a[i][j];
                }
            }
            return *this;
        }
};