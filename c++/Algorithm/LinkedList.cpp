#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void list_pushback(Node* root,int data){
    Node* temp;
    Node* ptr;
    temp = new Node;
    ptr = root;
    temp->data = data;
    temp->next = NULL;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void print_list(Node* root){
    while(root!=NULL){
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}

void list_pushfront(Node* root,int data){
    Node* ptr;
    ptr = new Node;
    ptr->data = root->data;
    ptr->next = root->next;
    root->data = data;
    root->next = ptr;
}
void list_rf(Node* root){
    Node* ptr;
    ptr = root->next;
    root = ptr;
    cout << endl;
}

void list_removeback(Node* root){
    Node* ptr;
    ptr = root;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = NULL;
}

void list_makeCircle(Node* root){
    Node* ptr;
    ptr = root;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = root;
}

void list_join(Node* root,Node* newList){
    Node* ptr;
    ptr = root;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newList;
}

int getLastElem(Node* root){
    Node* ptr;
    ptr = root;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    return ptr->data;
}

int getElem(int index,Node* root){
    Node* ptr;
    ptr = root;
    while(index--){
        ptr = ptr->next;
    }
    return ptr->data;
}

void list_insert(int index, Node* root,int data){
    Node* ptr;
    ptr = root;
    Node* temp;
    temp = new Node;
    if(index == 0){
        temp->data = ptr->data;
        temp->next = ptr->next;
        root->data = data;
        root->next = temp;
    }
    else{
        index--;
        while(index--){
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        temp->data = data;
        ptr->next = temp;
    }
}

int main(){
    Node* Start;
    Start = new Node;
    Start->data = 10;
    Start->next = NULL;
    Node* Happy;
    Happy = new Node;
    Happy->data = 15559;
    Happy->next = NULL;
    list_pushback(Start,20);
    list_pushback(Start,40);
    list_pushback(Start,50);
    list_pushback(Start,30);
    list_removeback(Start);
    print_list(Start);
    list_pushback(Start,30);
    list_pushback(Happy,15556);
    list_pushback(Happy,15551);
    list_join(Start,Happy);
    print_list(Start);
    cout << getLastElem(Start) << endl;
    cout << getElem(0,Start) << endl;
    list_insert(0,Happy,1991);
    list_insert(0,Happy,1100100101);
    list_insert(3,Start,1000001);
    print_list(Start);
    print_list(Happy);
    list_pushfront(Start,1);
    list_pushfront(Start,0);
    list_pushfront(Start,0);
    list_rf(Start);
    print_list(Start);
}