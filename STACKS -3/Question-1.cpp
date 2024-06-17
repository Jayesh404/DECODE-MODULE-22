# include<iostream>
# include<vector>
# include<stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& s) {
        int n=s.size();
        stack<int> st;

        for(int i=0;i<n;i++){
            if(st.size()==0) st.push(stoi(s[i]));
            else if(s[i]=="+"){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.push(x);
                st.push(x+y);
            }
            else if(s[i]=="D"){
                int x=st.top();
                st.push(2*x);
            }
            else if(s[i]=="C"){
                st.pop();
            }
            else{
                st.push(stoi(s[i]));
            }
        }
        int sum=0;
        while(st.size()>0){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};