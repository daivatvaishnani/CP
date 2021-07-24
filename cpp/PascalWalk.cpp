/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll max_rows = 200;

vector<vector<ll>> triangle;
vector<vector<ll>> row_sum;
vector<ll> c_off = {1, 0};

void print_triangle(ll n) {
    for(ll row = 0; row < n; ++row) {
        for(ll i = 0; i < row+1; ++i) {
            cout << "(" << triangle[row][i] << ", " << row_sum[row][i] << ") ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void preprocess(ll n_rows) {
    triangle.push_back({1LL});
    row_sum.push_back({1});
    for(ll row = 1; row < n_rows; ++row) {
        vector<ll> t_row;
        vector<ll> r_sum;
        for(ll k = 0; k < row + 1; ++k) {
            ll sum = 0;
            if(k == 0 || k == row) {
                t_row.push_back(1LL);
                sum = 1LL; 
            } else {
                ll num = triangle[row-1][k] + triangle[row-1][k-1];
                t_row.push_back(num);
                sum = num;
            }
            if(r_sum.size() > 0) {
                sum += r_sum[r_sum.size()-1];
            }
            r_sum.push_back(sum);
        }
        triangle.push_back(t_row);
        row_sum.push_back(r_sum);
    }
}

bool isPascalPathWithSum(ll sum, vector<pair<ll,ll>> &path) {
    assert(path.size() <= 500);
    ll path_sum = 0;
    for(pair<ll,ll> position: path) {
        assert(position.first < 500);
        assert(position.second >= 0 && position.second <= position.first);
        path_sum += triangle[position.first][position.second];
    }
    assert(path_sum == sum);
    return true;
}

vector<pair<ll,ll>> findPascalPath(ll sum) {
    vector<pair<ll,ll>> pascal_path;
    ll sum_till = 1;
    ll row = 0, col = 0;
    bool done = 0;
    while(1) {
        // cout << "currently at " << row << " " << col << " " << sum_till << "\n";
        pascal_path.push_back({row, col});
        if(sum_till == sum) {
            done = 1;
            break;
        }
        ll n_row = row+1, n_col;
        bool found = 0;
        for(ll off : c_off) {
            if(!(row & 1) && off == 1) {
                continue;
            }
            if(col + off >= 0) {
                n_col = col + off;
                // cout << "considering " << n_row+1 << " " << n_col+1 << " " << triangle[n_row][n_col] << "\n";
                if(triangle[n_row][n_col] + sum_till == sum) {
                    found = 1;
                    sum_till += triangle[n_row][n_col];
                    row = n_row, col = n_col;
                    break;
                } else if(row_sum[n_row][n_col] + sum_till <= sum) {
                    found = 1;
                    sum_till += triangle[n_row][n_col];
                    row = n_row, col = n_col;
                    break;
                }
            }
        }
        if(!found) {
            col = col - 1;
            if(col >= 0) {
                sum_till += triangle[row][col];
            } else {
                break;
            }
        }
    }
    return pascal_path;
}

void test_case(ll case_no) {
    ll sum;
    cin >> sum;
    vector<pair<ll, ll>> pascal_walk = findPascalPath(sum);
    assert(isPascalPathWithSum(sum, pascal_walk) == true);
    cout << "Case #" << case_no << ":\n";
    for(pair<ll,ll> position: pascal_walk) {
        cout << position.first+1 << " " << position.second+1 << "\n";
    }
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    preprocess(max_rows);
    // print_triangle(15);
    for(ll i = 1; i <= t; ++i) {
        test_case(i);
    }
    return 0;
}