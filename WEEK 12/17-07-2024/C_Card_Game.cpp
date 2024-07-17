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
// template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// Define the pbds template with a custom comparator
template <typename T, typename Compare = less<T>> using pbds = tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;


class cmp{
    public:
        bool operator()(pair<int,int> a,pair<int,int> b){
            return a.first > b.first;
        }
};

void solve(){
    ll len; cin >> len;
    vector<ll> v(len+1);


    for(int x=1; x<=len; x++) cin >> v[x];

    ll ans=0;
    for(int x=3; x<=len; x++){
        if(v[x]>0) ans+=v[x]; 
    }

    ll get = 0;
    if(v[1]>=0) get=v[1];
    if(len>=2) get = max(get,v[1]+v[2]);

    cout << ans+get << endl;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}