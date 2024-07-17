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
    ll r,c; cin >> r >> c;

    vector<vector<ll>> ar(r,vector<ll>(c));

    for(int x=0; x<r; x++){
        for(int y=0; y<c; y++){
            cin >> ar[x][y];
        }
        srt(ar[x]);
        
    }



    vector<vector<ll>> ans(r,vector<ll>(c));
    for(int x=0; x<c; x++){
        

        ll mn = INT_MAX;
        ll in=-1;

        for(int y=0; y<r; y++){
            if(ar[y][0]<mn){
                mn=ar[y][0];
                in=y;
            }
        }

        for(int y=0; y<r; y++){
            if(in==y){
                ans[y][x]=ar[y][0];
                ar[y].erase(ar[y].begin());
            }
            else{
                ans[y][x]=ar[y].back();
                ar[y].pop_back();
            }
        }
    }

    for(int x=0; x<r; x++){
        for(int y=0; y<c; y++){
            cout <<  ans[x][y] << " ";
        }
        cout << endl;
        
    }

    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}