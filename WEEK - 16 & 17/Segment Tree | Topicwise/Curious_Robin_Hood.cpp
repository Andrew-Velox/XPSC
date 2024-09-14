#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif

const ll N=1e5+10;

vector<ll> v(N),t(N*4);

void make(ll n, ll b, ll e){
    if(b==e){
        t[n]=v[e];
        return;
    }

    ll mid=(b+e)/2;
    ll l=n*2;
    ll r=(n*2)+1;
    
    make(l,b,mid);
    make(r,mid+1,e);

    t[n]=t[l]+t[r];

}

void update(ll n, ll b, ll e, ll idx, ll val){
    if(idx>e || idx<b) return;
    if(b==e){
        t[n]+=val;
        return;
    }

    ll mid=(b+e)/2;
    ll l=n*2;
    ll r=(n*2)+1;
    
    update(l,b,mid,idx,val);
    update(r,mid+1,e,idx,val);

    t[n]=t[l]+t[r];

}
void delet(ll n, ll b, ll e, ll idx){
    if(idx>e || idx<b) return;
    if(b==e){
        cout << t[n] << endl;
        t[n]=0;
        return;
    }

    ll mid=(b+e)/2;
    ll l=n*2;
    ll r=(n*2)+1;
    
    delet(l,b,mid,idx);
    delet(r,mid+1,e,idx);

    t[n]=t[l]+t[r];

}

ll query(ll n, ll b, ll e, ll i, ll j){
    if(i>e || j<b) return 0;
    if(i<=b && j>=e){
        return t[n];
    }

    ll mid=(b+e)/2;
    ll l=n*2;
    ll r=(n*2)+1;
    
    return query(l,b,mid,i,j)+query(r,mid+1,e,i,j);

}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll t; cin >> t;

    for(int x=1; x<=t; x++){
        ll len,q; cin >> len >> q;
        for(int x=1; x<=len; x++) cin >> v[x];
        make(1,1,len);

        cout << "Case " << x <<":"<< endl;
        while(q--){
            ll op; cin >> op;
            if(op==1){
                ll idx; cin >> idx;
                delet(1,1,len,idx+1);
            }
            else if(op==2){
                ll idx, val;
                cin>> idx >> val;
                update(1,1,len,idx+1,val);
            }
            else{
                ll l,r;
                cin >> l >> r;
                
                cout << query(1,1,len,l+1,r+1) << endl;
            }
        }

        
    }    
    
    
    return 0;
}