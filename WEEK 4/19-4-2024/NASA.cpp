#include <bits/stdc++.h>
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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl '\n'
#define fx(x) fixed<<setprecision(x)

void error_txt(){
    #ifdef velox
    freopen("error.txt","w",stderr);
    #endif
}

const int N = (1<<15); // 2^15
vector<ll> palindromes;

void generate_palindrome(){
    for(int x=0; x<N; x++){
        string s = to_string(x);
        ll len = s.size();

        bool f=true;
        for(int y=0; y<len/2; y++){
            if(s[y]!=s[len-y-1]){
                f=false;
                break;
            }
        }
        if(f) palindromes.push_back(x);
    }
}



void solve(){
    ll len; cin >> len;
    vector<ll> v(len);

    vector<ll> cnt(N); // map not works here :(
    for(int x=0; x<len; x++){
        cin >> v[x];
        cnt[v[x]]++;
    }

    ll ans=len;
    for(int x=0; x<len; x++){
        for(int y=0; y<palindromes.size(); y++){
            ll get = (v[x] ^ palindromes[y]);
            ans+= cnt[get];
            
            // if(cnt[get]!=0){
                // cout << v[x] << " " << palindromes[y] << " " << get << endl;
            //    cout << cnt[get] << endl;
            // }
        }
    }
    
    // cout << ans << endl;
    
    cout << ans/2 << endl;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    generate_palindrome();
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}