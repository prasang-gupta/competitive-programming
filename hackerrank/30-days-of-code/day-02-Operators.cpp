// Complete the solve function below.
void solve(double meal_cost, int tip_percent, int tax_percent) {
    double tip, tax, ans;
    tip = (meal_cost * tip_percent) / 100.0;
    tax = (meal_cost * tax_percent) / 100.0;
    ans = meal_cost + tip + tax;
    if (ans - (int)ans >= 0.5){
        cout << (int)ans + 1;
    }
    else{
        cout << (int)ans;
    }
}