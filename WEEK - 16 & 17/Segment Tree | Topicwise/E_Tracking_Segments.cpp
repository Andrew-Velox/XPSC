#include <bits/stdc++.h>
#define ll long long
using namespace std;
#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif


const ll N=1e5+10;
vector<ll> tree(4*N);

void make(ll n, ll b, ll e){
    if(b==e){
        tree[n]=0;
        return;
    }

    ll mid=(b+e)/2;
    ll l=n*2;
    ll r=(n*2)+1;

    make(l,b,mid);
    make(r,mid+1,e);

    tree[n]=tree[l]+tree[r];
}
void update(ll n, ll b, ll e, ll idx, ll val){
    if(idx>e || idx<b) return;
    if(b==e){
        tree[n]=1;
        return;
    }

    ll mid=(b+e)/2;
    ll l=n*2;
    ll r=(n*2)+1;

    update(l,b,mid,idx,val);
    update(r,mid+1,e,idx,val);

    tree[n]=tree[l]+tree[r];
}

ll query(ll n, ll b, ll e, ll i, ll j){
    if(i>e || j<b) return 0;
    if(i<=b && j>=e){
        return tree[n];
    }

    ll mid=(b+e)/2;
    ll l=n*2;
    ll r=(n*2)+1;

    return query(l,b,mid,i,j)+query(r,mid+1,e,i,j);

}




void solve(){
    ll len,k; cin >> len >> k;

    vector<pair<ll,ll>> vp(k);

    for(int x=0; x<k; x++){
        cin >> vp[x].first >> vp[x].second;
    }

    ll q; cin >> q;

    vector<ll> v(q);
    for(int x=0; x<q; x++) cin >> v[x];

    
    auto ok=[&](ll mid){
        make(1,1,len);

        for(int x=0; x<=mid; x++){
            update(1,1,len,v[x],1);
        }


        bool flag=false;
        
        for(int x=0; x<k; x++){
            ll l=vp[x].first;
            ll r=vp[x].second;

            ll seg_len=(r-l+1);

            ll zero=0,one=0;
            one = query(1,1,len,l,r);
            zero=seg_len-one;

            if(one>zero){
                flag=true;
                break;
            }
        }

        return flag;
    };



    ll l=0,r=q-1,ans=-1;
    while(l<=r){
        ll mid=l+(r-l)/2;

        if(ok(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }


    if(ans==-1) cout << ans << endl;
    else cout << ++ans << endl;

    debug(vp); 
    debug(v); 


}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll t; cin >> t;
    while(t--) solve();  
    return 0;
}