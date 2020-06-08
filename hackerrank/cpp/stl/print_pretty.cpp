int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
        cout << hex << left << showbase << nouppercase << (long long int)A << endl;
        cout << right << showpos << setprecision(2) << setw(15) << setfill('_') << fixed << B << endl;
        cout << left << setprecision(9) << scientific << uppercase << noshowpos << C << endl;
	}
	return 0;

}