#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll a,b,c;
    cin>>a>>b>>c;

    ll ans=-1;

    ll i=a/c;
    while(c*i<=b){
        if(c*i>=a && c*i<=b){
            ans=c*i;
            break;
        }
        i++;
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