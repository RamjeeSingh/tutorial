#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    int max = 0;    
    vector<int> result;

    public:
    int maxLen(vector<int>&A, int n)
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
            if (cnt > max) {
                cout<<"\n\n Display result \n\n\n";   
                display(result);
                cout<<"\n\n Update cnt = "<< cnt <<endl;
                max = cnt;
            }            
        }    

        if( offset >= n) {        
            return max;
        }
        for(int i = offset; i < n ; i++) {
           // cout<< " \n Check sum with "<< A[i] << endl;
            result.push_back(A[i]);
            //display(result);
            maxLenUtil(A, n, i+1, sum + A[i], cnt + 1);
            result.pop_back();
        }
        return max;
    }
};


int main() {
    Solution s;
    clock_t start, end;
    vector<int> A = {15, -2, 2, -8, 1, 7, 10, 23};

    start = clock(); 
    s.maxLen(A, A.size());
    cout <<"\n Max sum 0 is = "<< s.maxLen(A, A.size())<< " \n\n";
    end = clock(); 
    cout<< "\n\n time taken  = " << (double)(end - start)/(CLOCKS_PER_SEC)<<setprecision(5);

}

