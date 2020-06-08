int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;

		/* Enter your code here. */
        try {
            cout << Server::compute(A,B) << endl;
        }
        catch (std::bad_alloc &e){
            cout << "Not enough memory" << endl;
        }
        catch (exception &e){
            cout << "Exception: " << e.what() << endl;
        }
        catch (...){
            cout << "Other Exception" << endl;
        }
	}