#include <bits/stdc++.h>

using namespace std;

class Solution {
    
    vector<int> result;

    public:
    int maxlen = 0;
    int maxLenRec(vector<int>&A, int n)
    {           
	return maxLenUtil(A, n, 0, 0, 0);
    }    
    void display(vector<int> result) {
        cout << endl;
        for(auto i = result.begin(); i != result.end(); ++i) {
	    cout<< "   " << *i;
        }
        cout << endl;
    }
    int maxLenUtil(vector<int> &A, int n, int offset, int sum, int cnt) { 

        if (sum == 0 && cnt != 0) {
            if (cnt > maxlen) {                
                //display(result);                
                maxlen = cnt;
            }            
        }    

        if( offset >= n) {        
            return maxlen;
        }
        for(int i = offset; i < n ; i++) {
           // cout<< " \n Check sum with "<< A[i] << endl;
            result.push_back(A[i]);
            //display(result);
            maxLenUtil(A, n, i+1, sum + A[i], cnt + 1);
            result.pop_back();
        }
        return maxlen;
    }
    int max(int a , int b) {
        return a > b ? a: b;
    }
    int maxLenIter(vector<int>&A, int n)
    {           
        unordered_map<int, int> map;
        int sum = 0;
        int max_len = 0;
        for(int i = 0; i < A.size(); i++) {
            sum = sum + A[i]; 
            if(map.find(sum) != map.end()) {
             //   cout<< " \n found 0 sum " << i - map[sum]<< endl ;
                max_len = max(i - map[sum], max_len);               
            } else {
                 map[sum] = i;
            }
        }
        return max_len;
    }
};


int main() {
    Solution s;
    clock_t start, end;
    vector<int> A = {15, -2, 2, -8, 1, 7, 10, 23};
    int recresult ;
    int iterresult;
    double timetaken = 0.0;
    int loopcnt = 100000;

    start = clock(); 
    for(int cnt = loopcnt; cnt > 0; cnt--) {
        s.maxlen = 0;
        recresult = s.maxLenRec(A, A.size());
    }
    end = clock();
    timetaken = ((double)end - start	)/ CLOCKS_PER_SEC;    
    cout <<"\n Max sum 0 is = "<< recresult << " \n\n";
    cout<< "\n\n time taken  = " << timetaken <<setprecision(5)<< endl;

    start = clock(); 
    for(int cnt = loopcnt; cnt > 0; cnt--) {
        iterresult = s.maxLenIter(A, A.size());
    }
    end = clock();
    timetaken = ((double)end - start	)/ CLOCKS_PER_SEC;
    cout <<"\n Max sum 0 is = "<< iterresult << " \n\n";
    cout<< "\n\n time taken  = " << timetaken << setprecision(5)<< endl;

}

