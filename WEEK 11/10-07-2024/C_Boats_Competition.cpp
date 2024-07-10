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
    vector<ll> v(len);

    for(int x=0; x<len; x++) cin >> v[x];
    set<ll> st;
    for(auto val: v) st.insert(val);
    map<ll,ll> itm;
    for(auto val: v) itm[val]++;
    debug(st);
    map<ll,ll> mp;

    for(auto x=st.begin(); x!=st.end(); x++){
        for(auto i = x; i!=st.end(); i++){
            if(*i==*x && itm[*x]<2) continue;
            ll get = *i+*x;
            ll cnt=itm[*x]/2;
            if(*i!=*x) cnt=min(itm[*x],itm[*i]);
            
            if(mp[get]==0) mp[get]=cnt;
            else mp[get]+=cnt;
            debug(*x, *i, get,cnt);
        }
        debug(endl);
        
    }

    ll ans=0;

    for(auto val: mp){
        ans=max(ans,val.second);
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