#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll len; cin >> len;

    vector<ll> v(len);

    for(int x=0; x<len; x++) cin >> v[x];

    int i=0,j=len-1;

    bool flag = true;
    int tmp=0;

    while(i<=j){
        if(v[i]!=v[j]){
            int ti=i;
            int tj=j;
            tmp=v[i];
            i++;
            while(i<=j){
                if(v[i]!=v[j]){
                    if(tmp!=v[i] && tmp!=v[j]){
                        flag=false;
                        break;
                    }
                    else if(tmp==v[i]) i++;
                    else if(tmp==v[j]) j--;
                    continue;
                    // cout << v[i] << " " << v[j] << " " << i << " " << j << endl;
                }
                i++;
                j--;
            }

            if(!flag){
                flag=true;
                tmp=v[tj];
                tj--;
                while(ti<=tj){
                    if(v[ti]!=v[tj]){
                        if(tmp!=v[ti] && tmp!=v[tj]){
                            flag=false;
                            // cout << v[ti] << " " << v[tj] << " " << ti << " " << tj << endl;
                            break;
                        }
                        else if(tmp==v[ti]) ti++;
                        else if(tmp==v[tj]) tj--;
                        continue;
                    }

                // cout << v[ti] << " " << v[tj]  << endl;
                ti++;
                tj--;
                }
                break;
            }
        }

        i++;
        j--;
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}