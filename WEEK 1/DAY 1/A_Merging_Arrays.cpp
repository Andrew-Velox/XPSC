#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;


void solve(){
    ll a,b; cin>> a>>b;

    vector<int> v1(a),v2(b);
    for(int x=0; x<a; x++) cin >> v1[x];
    for(int x=0; x<b; x++) cin >> v2[x];


    vector<int>ans;
    int l=0,r=0;
    while(l<a && r<b){
        if(v1[l]<v2[r]){
            ans.push_back(v1[l]);
            l++;
        }
        else if(v1[l]==v2[r]){
            ans.push_back(v1[l]);
            ans.push_back(v2[r]);
            l++;
            r++;
        }
        else{
            ans.push_back(v2[r]);
            r++;
        }
    }

    if(l<a){
        for(int x=l; x<a; x++){
            ans.push_back(v1[l]);
            l++;
        }
    }

    else if(r<b){
        for(int x=r; x<b; x++){
            ans.push_back(v2[r]);
            r++;
        }
    }

    for(int val: ans) cout << val << " ";

    cout << endl;
    // cout << ans.size()<< endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}