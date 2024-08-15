#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll len;cin>>len;

    vector<ll> v(len);


    for(int x=0; x<len; x++) cin>>v[x];

    ll sm=1,cnt=1;
    sort(v.begin(),v.end());
    for(int x=0; x<len-1; x++){
        if(v[x]==v[x+1]){
            while(x<len-1 && v[x]==v[x+1]){
                cnt++;
                x++;
            }
            sm=max(sm,cnt);
            cnt=1;
        }
    }
    

    if(sm==len) cout << 0 << endl;
    else{
        ll rem=len-sm;
        ll t=rem;
        ll tmp=sm;
        ll clone=1;
        rem-=tmp;

        while(rem>0){
            tmp=tmp*2;
            rem-=tmp;
            clone++;
        }

        cout << t+clone << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}