#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif

const ll N=1e5+10;
vector<ll> v(N),tree(4*N);
ll n;


void make(ll n, ll s, ll e){
    if(s==e){
        tree[n]=v[e];
        return;
    }

    ll mid=(s+e)/2;
    ll l=n*2;
    ll r=(n*2)+1;
    make(l,s,mid);
    make(r,mid+1,e);

    tree[n]=__gcd(tree[l],tree[r]);
}

ll query(ll n, ll s, ll e, ll i, ll j){

    if(i>e || j<s) return 0;
    if (i<=s && e<=j) return tree[n];

    ll mid=(s+e)/2;
    ll l=n*2;
    ll r=(n*2)+1;

    return __gcd(query(l,s,mid,i,j),query(r,mid+1,e,i,j));

}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;

    for(int x=1; x<=n; x++) cin >> v[x];


    make(1,1,n);

    ll ans=INT_MAX;

    for(ll x=1; x<=n; x++){

        ll l=x, r=n, len=-1;

        while(l<=r){
            ll mid=l + (r - l) / 2;

            if(query(1,1,n,x,mid)==1){
                len=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        if(len!=-1){
            ans=min(ans,len-x+1);
        }
    }


    if(ans!=INT_MAX) cout << ans << endl;
    
    else cout << -1 << endl;

    
    
    return 0;
}