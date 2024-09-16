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
    string s; cin >> s;
    ll bread_ache,sause_ache,chees_ache;
    cin >> bread_ache >> sause_ache >> chees_ache;
    
    ll bread_price,sause_price,chees_price;
    cin >> bread_price >> sause_price >> chees_price;
    ll taka; cin >> taka;

    ll cnt_b=0,cnt_s=0,cnt_c=0;
    for(int x=0; x<s.size(); x++){
        if(s[x]=='B') cnt_b++;
        else if(s[x]=='S') cnt_s++;
        else cnt_c++;
    }

    auto ok=[&](ll Hamburgers){

        ll make_b,make_s,make_c;

        make_b= max(0ll,((cnt_b*Hamburgers)-bread_ache)*bread_price);
        make_s= max(0ll,((cnt_s*Hamburgers)-sause_ache)*sause_price);
        make_c= max(0ll,((cnt_c*Hamburgers)-chees_ache)*chees_price);

        ll total_taka=(make_b+make_s+make_c);

        return total_taka<= taka;

    };


    ll l=0,r=1e13+10,ans=0;

    while(l<=r){
        ll Hamburgers=l+(r-l)/2;

        if(ok(Hamburgers)){
            ans=Hamburgers;
            l=Hamburgers+1;
        }
        else r=Hamburgers-1;
    }


    cout << ans << endl;
   
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}