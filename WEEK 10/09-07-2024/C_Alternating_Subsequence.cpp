#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif

#define ll long long
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define unq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) ((x/gcd(x,y))*y)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl '\n'
#define fx(x) fixed<<setprecision(x)
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void error_txt(){
    #ifdef velox
    freopen("error.txt","w",stderr);
    #endif
}



void solve(){
    ll len; cin >> len;
    vector<ll> v(len),neg,pos;
    ll ans=INT_MIN;
    for(int x=0; x<len; x++){
        cin >> v[x];
        if(v[x]<0)neg.push_back(v[x]);
        else pos.push_back(v[x]);
        ans=max(ans,v[x]);
    }
;

    if(pos.size()==0 || neg.size()==0){
        cout << ans << endl;
        return;
    }
    else ans=INT_MIN;

    ll l=0,r=0,get=v[0];
    vector<ll> mk;
    while(r<len){
        if(v[l]<0){
            get=v[l];

            while(v[r]<0 && r<len){
                get=max(get,v[r]);
                r++;
            }
            mk.push_back(get);
            l=r;
        }
        else if(v[l]>0){
            get=v[l];
            while(v[r]>0 && r<len){
                get=max(get,v[r]);
                r++;
            }
            mk.push_back(get);
            l=r;
        }
    }
    // debug(mk);
    ans=0;
    for(auto val: mk){
        ans+=val;
    }

    cout << ans << endl;
    

    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}