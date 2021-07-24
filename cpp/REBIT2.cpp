/**
* Problem Link: https://www.codechef.com/APRIL20B/problems/REBIT
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

#define one Rational(1)

ll add(ll a, ll b) {
	return (a % mod + b % mod) % mod;
}

ll sub(ll a, ll b) {
    return (mod + a % mod - b % mod) % mod;
}

ll mul(ll a, ll b) {
	return (a % mod * b % mod) % mod;
}

ll modpow(ll x, ll n, ll m) {
    if(n == 0) {
    	return 1 % m;
    }
    long long u = modpow(x, n/2, m);
    u = (u * u) % m;
    if(n % 2 == 1) {
    	u = (u * x) % m;
    }
	return u; 
}

ll modinv(ll x, ll m) {
	return modpow(x, m-2, m);
}

ll gcd(ll a, ll b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return (a * b) / gcd(a, b);
}

class Rational {
	ll p, q;
	void normalize() {
		ll gcdpq = gcd(p, q);
		p /= gcdpq;
		q /= gcdpq;
	}
public:
	Rational() {
		this->p = 1;
		this->q = 1;
	}

	Rational(ll p) {
		this->p = p;
		this->q = 1;
	}

	Rational(ll p, ll q) {
		assert(q != 0);
		this->p = p;
		this->q = q;
		normalize();
	}

	Rational operator+(Rational r) {
		// ll nq = lcm(this->q, r.q);
		// ll np = this->p * (nq / this->q) + r.p * (nq / r.q);
        ll nq = 1;
        ll np = add(this->p, r.p);
		return Rational(np, nq);
	}

	Rational operator-(Rational r) {
		// ll nq = lcm(this->q, r.q);
		// ll np = this->p * (nq / this->q) - r.p * (nq / r.q);
        ll nq = 1;
        ll np = sub(this->p, r.p);
		return Rational(np, nq);
	}

	Rational operator*(Rational r) {
		// ll nq = this->q * r.q;
		// ll np = this->p * r.p;
        ll nq = 1;
        ll np = mul(this->p, r.p);
		return Rational(np, nq);
	}

	string toString() {
		string s = to_string(this->p) + "/" + to_string(this->q);
		return s;
	}

	string get(int n) {
		ll val = (p % mod * modinv(modpow(4, n, mod), mod) % mod) % mod;
		return to_string(val); 
		// return this->toString();
	}
};

class Expression {
	string s;
	unordered_map<char, Rational> r;

	void executeAND(Expression &exp) {
		auto x1 = this->r;
		auto x2 = exp.getr();
		assert(x1.size() == 4);
		assert(x2.size() == 4);
		this->r['1'] = x1['1'] * x2['1'];
		this->r['a'] = x1['1'] * x2['a'] + x1['a'] * x2['1']
						+ x1['a'] * x2['a'];
		this->r['A'] = x1['1'] * x2['A'] + x1['A'] * x2['1']
						+ x1['A'] * x2['A'];
		this->r['0'] = x1['1'] * x2['0'] + x1['0'] * x2['1']
						+ x1['0'] * x2['0']
						+ x1['0'] * x2['a'] + x1['a'] * x2['0']
						+ x1['0'] * x2['A'] + x1['A'] * x2['0']
						+ x1['a'] * x2['A'] + x1['A'] * x2['a'];
	}
	void executeOR(Expression &exp) {
		auto x1 = this->r;
		auto x2 = exp.getr();
		assert(x1.size() == 4);
		assert(x2.size() == 4);
		this->r['a'] = x1['0'] * x2['a'] + x1['a'] * x2['0']
						+ x1['a'] * x2['a'];
		this->r['A'] = x1['0'] * x2['A'] + x1['A'] * x2['0']
						+ x1['A'] * x2['A'];
		this->r['0'] = x1['0'] * x2['0'];
		this->r['1'] = x1['1'] * x2['1']
						+ x1['1'] * x2['0'] + x1['0'] * x2['1']
						+ x1['1'] * x2['a'] + x1['a'] * x2['1']
						+ x1['1'] * x2['A'] + x1['A'] * x2['1']
						+ x1['a'] * x2['A'] + x1['A'] * x2['a'];
	}
	void executeXOR(Expression &exp) {
		auto x1 = this->r;
		auto x2 = exp.getr();
		assert(x1.size() == 4);
		assert(x2.size() == 4);
		this->r['1'] = x1['1'] * x2['0'] + x1['0'] * x2['1']
						+ x1['a'] * x2['A'] + x1['A'] * x2['a'];
		this->r['a'] = x1['0'] * x2['a'] + x1['a'] * x2['0']
						+ x1['1'] * x2['A'] + x1['A'] * x2['1'];
		this->r['A'] = x1['0'] * x2['A'] + x1['A'] * x2['0']
						+ x1['1'] * x2['a'] + x1['a'] * x2['1'];
		this->r['0'] = x1['1'] * x2['1'] 
						+ x1['0'] * x2['0']
						+ x1['a'] * x2['a']
						+ x1['A'] * x2['A'];
	}
public:
	Expression(string s) {
		this->s = s;
		if(s == "#") {
			r.clear();
			r['1'] = Rational(1, 1);
			r['0'] = Rational(1, 1);
			r['a'] = Rational(1, 1);
			r['A'] = Rational(1, 1);
		}
	}

	void evaluate(Expression &exp, char operand) {
		// cout << "evaluating : ";
		this->s = '(' + this->get() + operand + exp.get() + ')';
		switch(operand) {
			case '&':
				executeAND(exp);
				break;
			case '|':
				executeOR(exp);
				break;
			case '^':
				executeXOR(exp);
				break;
			default:
				break;
		}
		// cout << s << "\n";
	}

	string get() {
		return this->s;
	}

	string getR(int n) {
		string ans = "";
		ans += this->r['0'].get(n) + " ";
		ans += this->r['1'].get(n) + " ";
		ans += this->r['a'].get(n) + " ";
		ans += this->r['A'].get(n);
		return ans;
	}

	unordered_map<char, Rational> getr() {
		return this->r;
	}
};

void test_case() {
    string l, expression;
    cin >> l;
    stack<char> st;
    stack<Expression> stx;
    ll cnt = 0;
    for(char c : l) {
    	if(c == '(') {
 			continue;
    	} else if(c == ')') {
    		if(stx.size() >= 2 && st.size() >= 1) {
    			Expression ex2 = stx.top();
    			stx.pop();
    			Expression ex1 = stx.top();
    			stx.pop();
    			char operand = st.top();
    			st.pop();
    			ex1.evaluate(ex2, operand);
    			stx.push(ex1);
    		} 
    	} else if(c == '#') {
            cnt++;
    		stx.push(Expression("#"));
    	} else {
    		// operands
    		st.push(c);
    	}
    }
    // cout << cnt << "\n";
    // cout << stx.size() << "\n";
    assert(stx.size() == 1);
    Expression final_expression = stx.top();
    assert(final_expression.get() == l);
    // cout << "Final Expression: " << final_expression.get() << "\n";
    cout << final_expression.getR(cnt) << "\n";
    // cout << "---------------------------------------\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        test_case();
    }
    return 0;
}
