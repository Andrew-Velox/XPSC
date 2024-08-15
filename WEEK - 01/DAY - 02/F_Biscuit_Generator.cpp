#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll a,b,t;
    cin>>a>>b>>t;

    ll ans=0;
    ll ck=a;
    while(ck<=t){
        ans+=b;
        ck+=a;
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}