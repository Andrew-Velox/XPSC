// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
vector<long long> printFirstNegativeInteger(long long int A[],
        long long int N, long long int K) {
            
        long long i=0,j=0;

        vector<long long> vv;
        queue<int> qu;
        
        while(j<N){
             if(A[j]<0){
                qu.push(A[j]);
            }
            
            if(j-i+1==K){
            if(qu.empty()) vv.push_back(0);
            else vv.push_back(qu.front());
            if(!qu.empty() && A[i]==qu.front()){
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
