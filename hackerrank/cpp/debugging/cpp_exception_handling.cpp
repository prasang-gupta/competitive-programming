void process_input(int n) {
    int d;
    try {
        d = largest_proper_divisor(n);
    }
    catch (invalid_argument e) {
        cout << e.what() << endl;
        cout << "returning control flow to caller" << endl;
        return;
    }
    cout << "result=" << d << endl;
    cout << "returning control flow to caller" << endl;
}