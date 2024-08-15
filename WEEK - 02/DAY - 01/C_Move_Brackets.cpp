#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll len; cin>> len;
    string s; cin >> s;

    stack<char> ch;

    for(auto c: s){
        if(ch.empty()){
            ch.push(c);
            continue;
        }

        if(c==')' && ch.top()=='('){
            ch.pop();
        }
        else ch.push(c);

    }

    cout << ch.size()/2 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}