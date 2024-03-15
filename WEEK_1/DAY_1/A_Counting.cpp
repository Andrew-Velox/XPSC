#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll a,b;
    cin>> a >>b;
    ll ans=(b-a)+1;
    
    cout << (ans>=0 ? ans:0) << endl; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}
