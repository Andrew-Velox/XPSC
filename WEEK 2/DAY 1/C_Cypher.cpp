#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll len; cin>>len;
    vector<ll> v(len);

    for(int x=0; x<len; x++) cin >> v[x];

    for(int x=0; x<len; x++){
        int n;
        string s;
        cin >> n >> s;
        for(int y=0; y<n; y++){
            if(s[y]=='D'){
                v[x]++;
                if(v[x]>9) v[x]=0;
            }
            else if(s[y]=='U'){
                v[x]--;
                if(v[x]<0) v[x]=9;
            }
        }
    }

    for(int x=0; x<len; x++) cout << v[x] << " ";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}