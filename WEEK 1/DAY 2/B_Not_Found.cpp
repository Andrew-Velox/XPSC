#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    string s; cin>>s;

    char ans;
    bool flag=false;

    sort(s.begin(),s.end());
    string alpha="abcdefghijklmnopqrstuvwxyz";

    int i=0;


    for(int x=0; x<26; x++){
        if(alpha[x]==s[i]){
            // cout << alpha[i]<< " " <<s[x]<<endl;
            while(alpha[x]==s[i]) i++;
        }
        else{
            flag=true;
            ans=alpha[x];
            break;
        }
    }

    if(flag) cout << ans << endl;
    else cout << "None" << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}