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

#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define unq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define set_bits(x) __builtin_popcountll(x)
#define fst_zero(x) 63-__builtin_ctzll(x)
#define lst_zero(x) __builtin_ctzll(x)
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) ((x/gcd(x,y))*y)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define ll long long
#define pb push_back
#define endl '\n'
#define fx(x) fixed<<setprecision(x)
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll MOD = 1e9+7;

void error_txt(){
    #ifdef velox
    freopen("error.txt","w",stderr);
    #endif
}


void solve(){
    ll len,vac_no,vac_tm,wt_t;
    cin >> len >> vac_no >> vac_tm >> wt_t;

    vector<ll> v(len);
    for(int x=0; x<len; x++) cin >> v[x];

    ll get =v[0]+wt_t+vac_tm;
    // ll open_t=v[0];
    // ll wt=0;
    ll ans=0,cnt=0;

    for(int x=0;x<len;x++){
        if(x==0 || get<v[x] || cnt>vac_no){
            ans++;
            cnt=1;
            get=v[x]+vac_tm+wt_t;
        }
        cnt++;
    }

    cout << ans << endl;


    // for(int x=1; x<len; x++){
    //     if(v[x-1]>=v[x]){

    //         debug(v[x],cnt);
    //         if(cnt<vac_no){
    //             v[x] = v[x-1];
    //             cnt++;
    //             wt=1;
    //         }
    //         else{
    //             ans++;
    //             v[x]+=wt_t+vac_tm;
    //             open_t=v[x];
    //             cnt=1;
    //         }
    //     }
    //     else if(v[x-1]<v[x]){
    //         if(cnt<vac_no){
    //             cnt++;
    //             // debug(v[x],cnt);
    //             // v[x]=v[x-1];
    //         }
    //         else{
    //             v[x]+=wt_t+vac_tm;
    //             open_t=v[x];
    //             cnt=1;
    //             ans++;

    //         }
    //     }
    // }


    // cout << ans << endl;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}