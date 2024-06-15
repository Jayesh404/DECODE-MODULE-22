# include<iostream>
# include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                ans.push(s[i]);
            }
            else if(s[i]==')'){
                if(ans.empty()) return false;
                if(ans.top()=='(') ans.pop();
                else return false;
            }
            else if(s[i]=='}'){
                if(ans.empty()) return false;
                if(ans.top()=='{') ans.pop();
                else return false;
            }
            else if(s[i]==']'){
                if(ans.empty()) return false;
                if(ans.top()=='[') ans.pop();
                else return false;
            }
        }
        if(ans.empty()) return true;
        else return false;
    }
};