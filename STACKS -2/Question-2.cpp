# include<iostream>
# include<vector>
# include <algorithm>
# include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        //ITERATIVE
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        ListNode* left=NULL;
        ListNode* right=head->next;
        while(right!=NULL){
            temp->next=left;
            left=temp;
            temp=right;
            right=right->next;
        }
        temp->next=left;
        return temp;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        

        int n=1;
        ListNode* t=head;
        while(t){
            n++;
            t=t->next;
        }
        vector<int> arr(n,0);
        ListNode* temp=reverseList(head);

        stack<int> st;
        st.push(temp->val);
        temp=temp->next;
        int i=n-2;
        while(temp ){

            while(st.size()>0 && st.top()<=temp->val) st.pop();
            if(st.size()==0) arr[i]=0;
            else arr[i]=st.top();

            st.push(temp->val);
            i--;
            temp=temp->next;
        }
        reverse(arr.begin(),arr.end());
        arr.pop_back();
        reverse(arr.begin(),arr.end());


        return arr;

    }
};