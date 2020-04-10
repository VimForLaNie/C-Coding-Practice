#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

struct Node* newNode(int data){
    Node* temp;
    temp = new Node;
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
stack<Node*> st;
void dfs(Node* root){
    st.push(root);
    while(!st.empty()){
        Node* top;
        top = st.top();
        st.pop();
        cout << top->data << " ";
        if(top->left != NULL){
            st.push(top->left);
        }
        if(top->right != NULL){
            st.push(top->right);
        }  
    }
    cout << endl;
}

int main(){
    Node* root;
    root = newNode(1991);
    root->right = newNode(5);
    root->left = newNode(0);
    root->left->right = newNode(777);
    root->left->left = newNode(666);
    root->left->left->left = newNode(555);
    root->right->right = newNode(10);
    cout << "Hello" << endl;
    dfs(root);
}