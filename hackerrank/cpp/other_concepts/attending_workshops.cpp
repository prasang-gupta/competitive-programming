//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop {
    int start_time, duration, end_time;
};

struct Available_Workshops {
    int n;
    Workshop *a = new Workshop[n];
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops *ptr = new Available_Workshops;
    ptr->n = n;
    for (int i = 0; i < n; ++i){
        ptr->a[i].start_time = start_time[i];
        ptr->a[i].duration = duration[i];
        ptr->a[i].end_time = start_time[i] + duration[i];
    }
    return ptr;
}

bool sorthelp(Workshop a, Workshop b) {
    return a.end_time < b.end_time;
}

int CalculateMaxWorkshops(Available_Workshops *ptr) {
    int count = 1;
    sort(ptr->a, ptr->a + ptr->n, sorthelp);
    int last_end = ptr->a[0].end_time;
    for (int i = 1; i < ptr->n; ++i){
        if (ptr->a[i].start_time >= last_end){
            count++;
            last_end = ptr->a[i].end_time;
        }
    }
    return count;
}