	// Add your code here

    Difference (vector <int> v) : elements (v) {}

    void computeDifference () {
        int minval = elements[0], maxval = elements[0];
        for (int i = 0; i < elements.size(); ++i){
            if (minval > elements[i])
                minval = elements[i];
            if (maxval < elements[i])
                maxval = elements[i];
        }
        maximumDifference = (maxval - minval);
    }