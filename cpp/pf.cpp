#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << ":" << (x) << " | "

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in", "r", stdin);
    double pf_bal = 0.0;
    double pf_int = 0.007;
    double pf_amt = 13000.0;
    double pf_inc = 0.10;
    int num_years = 30;
    cout << std::setprecision(10);
    for (int year = 1; year <= num_years; ++year) {
        for (int month = 1; month <= 12; ++month) {
            pf_bal += pf_bal * pf_int + pf_amt;
        }
        pf_amt += pf_amt * pf_inc;
        cout << "closing balace in pf account after " << year << " year: Rs. " << pf_bal << "\n";
    }
    /*for (int i = 0; i < 5; ++i) {
        pf_bal += pf_bal * pf_int + 13000.0;
    }
    cout << "Closing balance in 2020: Rs. " << pf_bal << "\n";
    for (int i = 0; i < 12; ++i) {
        pf_bal += pf_bal * pf_int + 14036.0;
    }
    cout << "Closing balance in 2021: Rs. " << pf_bal << "\n"; */
    return 0;
}

