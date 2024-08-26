#include <bits/stdc++.h>
#define ll long long
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl "\n"
using namespace std;

void solve(){
    ll len;
    cin >> len;
    string s; cin >> s;

    string sml_s="";

    bool othr_let=false;

    for(int x=0; x<len; x++){
        sml_s+=tolower(s[x]);
        if(sml_s[x]!='m' && sml_s[x]!='e' && sml_s[x]!='o' && sml_s[x]!='w'){
            othr_let=true;
            cout << "NO" << endl;
            return;

        }
    }

    string m="meow";

    string dupli="";
    dupli+=sml_s[0];
    int i=0;

    for(int x=1; x<len; x++){
        if(dupli[i]!=sml_s[x]){
            dupli+=sml_s[x];
            i++;
        }
    }

    // cout << dupli << endl;
    
    if(dupli==m) YES;
    else NO;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}