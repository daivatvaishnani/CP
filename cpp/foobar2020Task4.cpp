/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

class Fraction {
public:
    ll num, den;
    void normalize() {
        ll gcdnd = gcd(num, den);
        while(gcdnd != 1) {
            num /= gcdnd;
            den /= gcdnd;
            gcdnd = gcd(num, den);
        }
    }
    Fraction() {
        num = 1, den = 1;
    }
    Fraction(ll nval) {
        num = nval, den = 1;
    }
    Fraction(ll nval, ll dval) {
        num = nval, den = dval;
        normalize();
    }
    Fraction add(Fraction f) {
        ll nden = den * f.den;
        ll nnum = num * f.den + f.num * den;
        return Fraction(nnum, nden);
    }
    Fraction sub(Fraction f) {
        ll nden = den * f.den;
        ll nnum = num * f.den - f.num * den;
        return Fraction(nnum, nden);
    }
    Fraction mul(Fraction f) {
        ll nden = den * f.den;
        ll nnum = num * f.num;
        return Fraction(nnum, nden);
    }
};

void printFractionMatrix(vector<vector<Fraction>> &matrix) {
    for(auto row : matrix) {
        for(Fraction f : row) {
            cout << "(" << f.num << "/" << f.den << ") ";
        }
        cout << "\n";
    }
    cout << "\n";
}

Fraction getProbability(ll i, ll j, vector<vector<ll>> &arr) {
    ll num = arr[i][j], den = 0;
    for(ll k = 0; k < arr[i].size(); ++k) {
        den += arr[i][k];
    }
    return Fraction(num, den);
}

vector<bool> findTerminalStates(vector<vector<ll>> &arr) {
    ll nstates = arr.size();
    vector<bool> isTerminal(nstates);
    for(ll i = 0; i < nstates; ++i) {
        bool transitioned = 0;
        for(ll j = 0; j < nstates; ++j) {
            if(arr[i][j] > 0) {
                transitioned = 1;
                break;
            }
        }
        isTerminal[i] = !transitioned;
    }
    return isTerminal;
}

vector<vector<Fraction>> computeMarkovMatrix(vector<vector<ll>> &arr, vector<bool> &isTerminal) {
    ll nstates = arr.size();
    vector<ll> order;
    for(ll i = 0; i < nstates; ++i) {
        if(isTerminal[i]) {
            order.push_back(i);
            arr[i][i] = 1;
        }
    }
    for(ll i = 0; i < nstates; ++i) {
        if(!isTerminal[i]) {
            order.push_back(i);
        }
    }
    vector<vector<Fraction>> markovMatrix(nstates, vector<Fraction>(nstates));
    for(ll i = 0; i < nstates; ++i) {
        for(ll j = 0; j < nstates; ++j) {
            markovMatrix[i][j] = getProbability(order[i], order[j], arr);
        }
    }
    return markovMatrix;
}

vector<vector<Fraction>> computeFMatrix(vector<vector<Fraction>> &RMatrix, vector<vector<Fraction>> &QMatrix) {
    vector<vector<Fraction>> FMatrix;
    vector<vector<Fraction>> IQMatrix = QMatrix;
    for(ll i = 0; i < QMatrix.size(); ++i) {
        for(ll j = 0; j < QMatrix.size(); ++j) {
            if(i != j) {
                IQMatrix[i][j] = IQMatrix[i][j].mul(Fraction(-1));
            } else {
                IQMatrix[i][j] = Fraction(1).sub(IQMatrix[i][j]);
            }
        }
    }
    printFractionMatrix(IQMatrix);
    return FMatrix;
}

vector<vector<Fraction>> computeLimitingMatrix(vector<vector<Fraction>> &markovMatrix, vector<bool> &isTerminal) {
    ll nstates = markovMatrix.size();
    ll ntstates = 0;
    for(bool b : isTerminal) {
        ntstates += b;
    }
    vector<vector<Fraction>> limitingMatrix(nstates, vector<Fraction>(nstates));
    vector<vector<Fraction>> RMatrix(nstates-ntstates, vector<Fraction>(ntstates));
    for(ll i = ntstates; i < nstates; ++i) {
        for(ll j = 0; j < ntstates; ++j) {
            RMatrix[i-ntstates][j] = markovMatrix[i][j];
        }
    }
    vector<vector<Fraction>> QMatrix(nstates-ntstates, vector<Fraction>(nstates-ntstates));
    for(ll i = ntstates; i < nstates; ++i) {
        for(ll j = ntstates; j < nstates; ++j) {
            QMatrix[i-ntstates][j-ntstates] = markovMatrix[i][j];
        }
    }
    printFractionMatrix(markovMatrix);
    printFractionMatrix(RMatrix);
    printFractionMatrix(QMatrix);
    vector<vector<Fraction>> FMatrix = computeFMatrix(RMatrix, QMatrix);
    return limitingMatrix;
}

vector<ll> solve(vector<vector<ll>> &arr) {
    ll nstates = arr.size();
    vector<ll> ans;
    vector<ll> cnt(nstates);
    vector<bool> isTerminal = findTerminalStates(arr);
    vector<vector<Fraction>> markovMatrix = computeMarkovMatrix(arr, isTerminal);
    vector<vector<Fraction>> limitingMatrix = computeLimitingMatrix(markovMatrix, isTerminal);
    return cnt;
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<ll>> arr = {
        {0, 1, 0, 0, 0, 1}, 
        {4, 0, 0, 3, 2, 0}, 
        {0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0}
    };
    vector<ll> ans = solve(arr);
    for(ll i : ans) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}