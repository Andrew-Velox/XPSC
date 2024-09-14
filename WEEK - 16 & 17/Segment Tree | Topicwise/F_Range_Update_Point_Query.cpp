#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif

const ll N = 2e5+10;
ll len,q;
vector<ll> v(N);
vector<ll> tree(4*N);
void make(ll n,ll s, ll e){
    if(s==e){
        tree[n]=v[e]>9;
        return;
    }

    ll mid=(s+e)/2;
    ll l=n*2;
    ll r=(n*2)+1;
    make(l,s,mid);
    make(r,mid+1,e);

    tree[n]=tree[l] || tree[r];
}

void update(ll n,ll s,ll e,ll i, ll j){
    if(i>e || j<s || !tree[n]) return;
    if(s==e){
        ll s=0;
        while(v[e]>0){
            s+=v[e]%10;
            v[e]/=10;
        }
        v[e]=s;
        tree[n]=v[e]>9;
        return;
    }

    ll mid = (s+e)/2;
    ll l= n*2;
    ll r= (n*2)+1;

    update(l,s,mid,i,j);
    update(r,mid+1,e,i,j);
    tree[n]=tree[l] || tree[r];
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    ll t; cin >> t;
    while(t--){
        cin >> len >> q;

        for(int x=0; x<=len+1; x++) v[x]=0;
        for(int x=1; x<=len; x++) cin >> v[x];

        make(1,1,len);
        while(q--){
            ll op; cin >> op;
            if(op==1){
                ll l,r; cin >> l >> r;
                update(1,1,len,l,r);
            }
            else{
                ll idx; cin >> idx;
                cout << v[idx] << endl;
            }
        }

        
    }
    
    
    return 0;
}