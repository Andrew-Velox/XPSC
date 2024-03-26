#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll len,s;
    cin >> len >> s;

    vector<ll> v(len);
    for(int x=0; x<len; x++) cin >> v[x];



    ll l=0,r=0,sum=0,ans=0;

    while(r<len){
        sum+=v[r];

        if(sum>=s){
            ans+=len-r;

            // cout << len-r << " ";
            while(sum>=s && l<len){
                sum-=v[l];
                l++;
                if(sum>=s) ans+=len-r;
            }
        }
   
        r++;
    }
    // cout << endl;

    cout << ans << endl;
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}