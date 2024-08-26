#include <bits/stdc++.h>
#define ll long long
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl "\n"
using namespace std;

void solve(){
    ll len,q;
    cin >> len >> q;

    vector<ll> v(len+1),p_sum(len+1);

    ll sum=0;
    for(int x=0; x<len; x++){
        cin >> v[x];
        sum+=v[x];
        p_sum[x+1]=sum;
    }

    while(q--){
        ll i,j,k;
        cin >> i >> j >> k;

        // cout << p_sum[i-1]<< " " << ((j-i+1)*k) << " " << (p_sum[len]-p_sum[j]) << endl;
        ll get=p_sum[i-1]+((j-i+1)*k)+(p_sum[len]-p_sum[j]);
        // cout << get << endl;
        if(get%2==1) YES;
        else NO;

    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}