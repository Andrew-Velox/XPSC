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

void error_txt(){
    #ifdef velox
    freopen("error.txt","w",stderr);
    #endif
}



void solve(){
    ll len,k; cin >> len >> k;

    vector<ll> v(len);
    for(int x=0; x<len; x++) cin >> v[x];

    ll ans=0;
    for(int bit=30; bit>=0; bit--){
        ll miss_bits=0;

        for(auto val: v){
            // if((val&(1<<bit)) !=0 ){
            //     debug((val&(1<<bit)));
            //     debug(val,bit);
            // }
            if((val&(1<<bit))== 0){ // koyta value te amar ei(x) bit ta off acche count korbo
                miss_bits++; // arrayr koyta item ar ei bit off ache
            }
        }

        debug(bit,miss_bits);
        if(miss_bits<=k){  // missing bit ar item NO jodi K ar theke choto ba soman hoy tahole oglu ON kore dibo
            ans+=1<<bit; // sobar oi bit ta ON mane oi bit ar value ta AND korle 1 ei pabo
            k-=miss_bits; // missing thaka jet value golor bit ON korsi sejonno K operation minuse korbo
        }
    }

    cout << ans << endl;


    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}