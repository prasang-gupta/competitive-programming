// Complete the minTime function below.
long minTime(vector<long> machines, long goal) {
    long minval = machines[0], maxval = machines[0];

    for (int i = 0; i < machines.size(); ++i){
        if (minval > machines[i]){
            minval = machines[i];
        }
        if (maxval < machines[i]){
            maxval = machines[i];
        }
    }

    long left = floor((goal*minval)/machines.size()), right = ceil((goal*maxval)/machines.size()), mid;
    long long curmach;

    while (left <= right){
        cout << left << " " << right << " ";
        mid = left + (right-left)/2;
        curmach = 0;
        for (int i = 0; i < machines.size(); ++i){
            curmach += mid / machines[i];
        }
        cout << mid << " " << curmach << " / " << goal << endl;
        if (curmach >= goal){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    if (curmach < goal){
        mid += 1;
    }
    return mid;
}