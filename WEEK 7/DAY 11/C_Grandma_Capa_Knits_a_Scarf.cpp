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
    ll len; cin >> len;
    string s; cin >>s;

    bool pal=true;
    char a,b;
    for(int x=0; x<len/2; x++){
        if(s[x]!=s[len-x-1]){
            a=s[x];
            b=s[len-x-1];
            pal=false;
            break;
        }
    }

    if(pal){
        cout << 0 << endl;
        return;
    }

    // check for (a)
    ll ans=0;
    bool flag_a=false;
    ll l=0,r=len-1,cnt=0;
    while(l<=r){
        if(s[l]!=s[r]){
            if(s[l]==a){
                l++;
                cnt++;
            }
            else if(s[r]==a){
                cnt++;
                r--;
            }
            else{
                flag_a=true;
                break;
            }
        }
        else{
            l++;
            r--;
        }
    }

    bool flag_b=false;
    l=0,r=len-1;
    ll cnt2=0;
    while(l<=r){
        if(s[l]!=s[r]){
            if(s[l]==b){
                l++;
                cnt2++;
            }
            else if(s[r]==b){
                cnt2++;
                r--;
            }
            else{
                flag_b=true;
                break;
            }
        }
        else{
            l++;
            r--;
        }
    }

    if(flag_a && flag_b) cout << -1 << endl;
    else if(!flag_a && !flag_b) cout << min(cnt,cnt2) << endl;
    else if(!flag_a && flag_b) cout << cnt << endl;
    else cout << cnt2 << endl;

    debug(cnt);

    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}