int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Write Your Code Here
    if (n < 2)
        cout << "one" << endl;
    else if (n < 3)
        cout << "two" << endl;
    else if (n < 4)
        cout << "three" << endl;
    else if (n < 5)
        cout << "four" << endl;
    else if (n < 6)
        cout << "five" << endl;
    else if (n < 7)
        cout << "six" << endl;
    else if (n < 8)
        cout << "seven" << endl;
    else if (n < 9)
        cout << "eight" << endl;
    else if (n < 10)
        cout << "nine" << endl;
    else
        cout << "Greater than 9" << endl;
        
    return 0;
}
