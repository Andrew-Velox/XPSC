//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int v[], long long int len, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

// #define ll long long
vector<long long> printFirstNegativeInteger(long long int v[], long long int len, long long int k) {
    long long i=0,j=0;

    vector<long long> vv;
    queue<int> qu;
    while(j<len){

        if(v[j]<0){
            qu.push(v[j]);
        }
        if(j-i+1==k){
            if(qu.empty()) vv.push_back(0);
            else vv.push_back(qu.front());
            if(!qu.empty() && v[i]==qu.front()){
                // cout << endl <<  "ef" << v[i] << " "  << qu.front() << endl;
                qu.pop();
                // cout <<"fro: " << qu.front() << endl;

            } 
            i++;
            j++;

        }

        else j++;
    }
    return vv;
 }