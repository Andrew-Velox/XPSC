#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif

const ll N=2e5;

vector<ll> v(N),tree(4*N);

ll marge(ll length, ll a, ll b){

    ll pw=__lg(length); // get msb on bit
    
    
    if(pw%2) return a|b;
    else return a^b;
}


void make(ll n,ll st,ll end){
    
    if(st==end){
        tree[n]=v[st];
        return;
    }

    ll mid=(st+end)/2;
    ll l=n*2;
    ll r=(n*2)+1;

    make(l,st,mid);
    make(r,mid+1,end);

    tree[n]=marge(end-st+1,tree[l],tree[r]);

}


void update(ll n,ll st, ll end, ll idx, ll val){
    
    if(idx>end || idx<st) return;


    if(st==end){
        tree[n]=val;
        return;
    }
    ll mid=(st+end)/2;
    ll l=n*2;
    ll r=(n*2)+1;

    update(l,st,mid,idx,val);
    update(r,mid+1,end, idx, val);

    tree[n]=marge(end-st+1,tree[l],tree[r]);
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    ll n,q; cin >> n >> q;

    for(int x=1; x<=(1<<n); x++) cin >> v[x];
    
    n=(1<<n);

    make(1,1,n);

    while(q--){
        ll idx,val;
        cin >> idx >> val;

        update(1,1,n,idx,val);

        cout << tree[1] << endl;
    }
    
    return 0;
}