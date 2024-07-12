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
    string s; cin >> s;


    set<ll> need;
    vector<ll> mp(len+1,0);

    for(int x=1; x<=len; x++){
        if(s[x-1]=='0'){
            need.insert(x);
        }
        else mp[x]=2;
    }

    if(need.size()==0){
        cout << 0 << endl;
        return;
    }
    if(need.size()==len){
        cout << len << endl;
        return;
    }

    ll ans=0;
    for(ll x=1; x<=len; x++){
        for(ll y=x; y<=len; y+=x){
            if(mp[y]==0){
                mp[y]=1;
                ans+=x;
            }
            else if(mp[y]==2){
                break;
            }
        }
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