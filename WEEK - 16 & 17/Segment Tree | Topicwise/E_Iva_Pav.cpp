#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif

const ll N=2e5+10;
vector<ll> t(4*N);
vector<ll> v(N);

void make(ll n, ll b, ll e){
    if(b==e){
        t[n]=v[e];
        return;
    }

    ll mid=(b+e)/2;
    ll l=(n*2);
    ll r=(n*2)+1;

    make(l,b,mid);
    make(r,mid+1,e);

    t[n]=(t[l]&t[r]);
}

ll query(ll n, ll b, ll e,ll i, ll j){
    if(i>e || j<b) return -1;

    if(i<=b && j>=e){
        return t[n];
    }

    ll mid=(b+e)/2;
    ll l=(n*2);
    ll r=(n*2)+1;

    return ( query(l,b,mid,i,j) & query(r,mid+1,e,i,j) );

}




void solve(){
    ll len; cin >> len;
    for(int x=1; x<=len; x++) cin >> v[x];


    make(1,1,len);
    ll q; cin >> q;

    while(q--){
        ll i,k; cin >> i >> k;

        ll l=i,r=len, ans=-1;
        while(l<=r){
            ll mid=l+(r-l)/2;
            if(query(1,1,len,i,mid)>=k){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        cout << ans << " ";
    }

    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    ll t; cin >> t;
    while(t--) solve();
    
    return 0;
}