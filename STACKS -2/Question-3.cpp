# include<iostream>
# include<vector>
# include<stack>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> arr(n);
        arr[n-1]=prices[n-1];

        stack<int> st;
        st.push(prices[n-1]);

        for(int i=n-2;i>=0;i--){

            while(st.size()>0 && st.top()>prices[i]) st.pop();
            if(st.size()==0) arr[i]=prices[i];
            else arr[i]=prices[i]-st.top();

            st.push(prices[i]);
        }

        return arr;
    }
};