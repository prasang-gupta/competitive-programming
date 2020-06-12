function getMaxLessThanK (n, k) {
    var maxval = 0;
    for (let i = 0; i <= n; ++i){
        for (let j = i+1; j <= n; ++j){
            let temp = (i & j);
            if (temp < k && temp > maxval){
                maxval = temp;
            }
        }
    }
    return maxval;
}