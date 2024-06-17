# include<iostream>
# include<vector>
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
        // ITERATIVE
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

    stack<int> reverse(stack<int>& st){
        stack<int> temp;
        while(st.size()>0){
            temp.push(st.top());
            st.pop();
        }
        return temp;
    }
    ListNode* removeNodes(ListNode* head) {
        if(head->next==NULL) return head;
        ListNode* head2=reverseList(head);
        ListNode* temp=head2;
        stack<int> st;
        while(temp){
            if(st.size()==0 || temp->val>=st.top()) st.push(temp->val);
            temp=temp->next;
        }
        temp=reverseList(head2);
        ListNode* dummy=new ListNode(-100);
        ListNode* t=dummy;
        while(temp && st.size()>0){
            if(temp->val==st.top()){
                t->next=temp;
                t=t->next;
                st.pop();
            }
            temp=temp->next;
        }
        t->next=NULL;
        return dummy->next;
    }
};