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
#define set_bits(x) __builtin_popcountll(x)
#define fst_zero(x) 63-__builtin_ctzll(x)
#define lst_zero(x) __builtin_ctzll(x)
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
    ll len,s; cin  >> len >> s;

    if(len==1){
        cout << "Yes" << endl;
        cout << s << endl;
    }
    else if(len>s ||  (len%2==0 && s%2==1)) cout << "No" << endl;
    else if(len==s){
        cout << "Yes" << endl;
        for(int x=1; x<=len; x++){
            cout << 1 << " ";
        }
        cout << endl;
    }
    else{
        if(len%2==0){
            cout << "Yes" << endl;
            for(int x=1; x<=len-2; x++){
                cout << 1 << " ";
            }
            ll get=s-(len-2);
            cout << get/2 << " " << get/2 << endl;
        }
        else{
            cout << "Yes" << endl;
            for(int x=1; x<=len-1; x++){
                cout << 1 << " ";
            }

            cout << s-(len-1) << endl;
        }
    }

    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}