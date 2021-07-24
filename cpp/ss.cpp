#include <bits/stdc++.h>
using namespace std;

vector<int> parseInts(string str) {
   vector<int> pi;
   stringstream ss;
   ss << str;
   char ch;
   int parsed;
   while(ss >> parsed) {
      pi.push_back(parsed);
   }
   return pi;
}
int main() {
    freopen("in","r",stdin); freopen("out","w",stdout);
    string str;
    getline(cin,str);
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
