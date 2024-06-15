# include<iostream>
# include<stack>
using namespace std;

void remove(stack<int>& st,int k){
    stack<int> temp;

    while(st.size()==0){
        int x=st.top();
        st.pop();
        if(st.size()!=k) temp.push(x);
    }

    while(temp.size()){
        st.push(temp.top());
        temp.pop();
    }
}

int main(){

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int k=2;
    remove(st,k);
    return 0;
}