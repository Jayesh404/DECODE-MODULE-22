# include<iostream>
# include<stack>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n,-1);

        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && st.top()<=nums[i]) st.pop();
            if(st.size()==0){
                if(i==n-1){
                    for(int j=0;j<n-1;j++){
                        if(nums[j]>nums[i]){
                            arr[i]=nums[j];
                            break;
                        }
                    }
                }
                else{
                    bool flag=false;
                    for(int k=i+1;k<n;k++){
                        if(nums[k]>nums[i]){
                            arr[i]=nums[k];
                            flag=true;
                            break;
                        }
                    }
                    if(flag==false){
                        for(int l=0;l<i;l++){
                            if(nums[l]>nums[i]){
                                arr[i]=nums[l];
                                break;
                            }
                        }
                    }
                }
            }
            else arr[i]=st.top();

            st.push(nums[i]);
        }

        return arr;
    }
};