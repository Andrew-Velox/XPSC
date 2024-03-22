#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll len,item;
    cin>>len>>item;

    vector<ll> v(len),ans;

    for(int x=0; x<len; x++) cin >> v[x];


    for(int x=0; x<len; x++){
        if(v[x]!=item) ans.push_back(v[x]);
    }

    for(int x=0; x<ans.size(); x++) cout << ans[x]<< " ";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1; //cin >> t;
    while(t--) solve();
    return 0;
}