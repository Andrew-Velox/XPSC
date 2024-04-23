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





void solve(){
    string s; cin >> s;


    // STORE positons
    vector<ll> mp[28];
    for(int x=1; x<s.size()-1; x++){
        ll val = (s[x]-'a');
        val++;
        mp[val].push_back(x+1);
    }


    // SORT
    string sml="",big="";
    for(int x=1; x<s.size()-1; x++){
        if(s[0]>=s[x]) sml+=s[x];
        else big+=s[x];
    }
    grtsrt(sml);
    srt(big);
    string tm=s;
    s=tm[0];
    s+=sml;
    s+=big;
    s+=tm[tm.size()-1];


    ll prev_sum = 0;
    vector<ll> pth;
    pth.push_back(1);


    ll p_dig = ((s[0]-'a')+1);
    ll lst_dig = ((s[s.size()-1] - 'a') +1);
    ll ans = abs( p_dig-lst_dig);
    ll tmp = ans;

    // cout << s << endl;

    for(int x=1; x<s.size()-1; x++){

        ll b = (s[x]-'a')+1;
        // cout << mp[b] << " ";

        ll get = prev_sum + abs(p_dig-b) + abs(lst_dig - b);

        
        if(get <= tmp){
            tmp=min(tmp,get);

            prev_sum += abs(p_dig-b);

            if(mp[b][0]!=-1){
                for(auto kk: mp[b]){
                    pth.push_back(kk);
                }
                mp[b]={-1};
            }

            p_dig=b;
        }
    }
    ans = tmp;
    pth.push_back(s.size());
    cout << ans << " " << pth.size() << endl;
    for(auto vv: pth) cout << vv << " ";
    cout << endl;


    // debug(pth);

    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}