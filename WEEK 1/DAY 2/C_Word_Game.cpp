#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll n;cin >> n;

    map<string,ll> mp;
    vector<string> v;
    for(int x=0; x<3; x++){
        for(int y=0; y<n; y++){
            string s; cin >> s;
            v.push_back(s);
            mp[s]++;
        }
    }

    ll row1=0,row2=0,row3=0;
    int i=0;
    for(int x=0; x<3; x++){
        for(int y=0; y<n; y++){
            if(x==0){
                if(mp[v[i]]==1) row1+=3;
                else if(mp[v[i]]==2) row1+=1;
            }
            else if(x==1){
                if(mp[v[i]]==1) row2+=3;
                else if(mp[v[i]]==2) row2+=1;
            }
            else{
                if(mp[v[i]]==1) row3+=3;
                else if(mp[v[i]]==2) row3+=1;
            }
            i++;
        }
    }

    cout << row1 << " " << row2 << " " << row3 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}