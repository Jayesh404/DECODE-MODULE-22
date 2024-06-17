# include<iostream>
# include<algorithm>
# include<vector>
# include<stack>
using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int> nsi(n);
        vector<int> psi(n);

        stack<int> st1;
        nsi[n-1]=n;
        st1.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st1.size()>0 && arr[i]<=arr[st1.top()]){
                st1.pop();
            }
            if(st1.size()==0) nsi[i]=n;
            else nsi[i]=st1.top();
            st1.push(i);
        }
        stack<int> st2;
        psi[0]=-1;
        st2.push(0);
        for(int i=1;i<n;i++){
            while(st2.size()>0 && arr[i]<=arr[st2.top()]){
                st2.pop();
            }
            if(st2.size()==0) psi[i]=-1;
            else psi[i]=st2.top();
            st2.push(i);
        }

        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int width=nsi[i]-psi[i]-1;
            int area=arr[i]* width;
            if(area>maxi) maxi=area;
        }

        return maxi;


    }
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> row(m , 0);
        int maxArea = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] == '1')row[j] += 1;
                else row[j] = 0;
            }
            maxArea = max(maxArea , largestRectangleArea(row));
        }
        return maxArea;
    }
};