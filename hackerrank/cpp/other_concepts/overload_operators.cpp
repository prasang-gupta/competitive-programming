//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

Complex & operator + (const Complex &a, const Complex &b) {
    Complex* ans = new Complex;
    ans->a = a.a + b.a;
    ans->b = a.b + b.b;
    return *ans;
}

ostream & operator << (ostream &out, const Complex &a) {
    out << a.a << "+i" << a.b;
    return out;
}