int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    constexpr unsigned exponent = 31;
    constexpr unsigned two_to_exponent = 1u << exponent;

    unsigned int n, s, p, q;
    cin >> n >> s >> p >> q;

    if (p % 2 == 0){
        if (p == 0){
            if (s == q){
                cout <<  1 << endl;
                return 0;
            }
            cout <<  2 << endl;
            return 0;
        }
        if (s == 0 && q == 0){
            cout <<  1 << endl;
            return 0;
        }

        unsigned a1_minus_a0 = (p-1) * s + q;
        unsigned num = exponent - __builtin_popcount((a1_minus_a0 & -a1_minus_a0) - 1);
        unsigned den = __builtin_popcount((p & -p) - 1);
        unsigned m = num / den + (num % den == 0 ? 1 : 2);
        cout << min(n, m) << endl;
    }
    else{
        if (p == 1){
            if (q == 0){
                cout << 1 << endl;
                return 0;
            }
            else{
                cout << min(n, two_to_exponent / (q & -q)) << endl;
                return 0;
            }
        }
        if (s == 0 && q == 0){
            cout << 1 << endl;
            return 0;
        }

        unsigned m = 1;
        unsigned long long p_minus_1 = p-1;
        unsigned long long a1_minus_a0 = p_minus_1 * s + q;
        unsigned long long p_to_m = p;
        unsigned long long mask = (two_to_exponent * (p_minus_1 & -p_minus_1) / (a1_minus_a0 & -a1_minus_a0)) - 1;

        while (m < n && (p_to_m & mask) != 1){
            p_to_m = p_to_m * p_to_m;
            m = m * 2;
        }
        cout << min(n, m) << endl;
    }
    return 0;
}
