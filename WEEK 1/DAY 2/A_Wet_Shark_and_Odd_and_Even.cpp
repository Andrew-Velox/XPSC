#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll len; cin >> len;

    vector<ll> v(len);
    ll sml_odd=INT_MAX;
    ll t_sum=0;

    for(int x=0; x<len; x++){
        cin>>v[x];
        if(v[x]%2==1) sml_odd=min(sml_odd,v[x]);
        t_sum+=v[x];
    }

    if(t_sum%2==0) cout << t_sum << endl;
    else cout<<t_sum-sml_odd<< endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}