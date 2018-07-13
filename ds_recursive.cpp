//
//  main.cpp
//  ds_5
//
//  Created by Radhika on 28/10/17.
//  Copyright © 2017 Nikita. All rights reserved.
//


#include <iostream>
using namespace std;

//creating node structure
struct node{
    int info;
    node * left;
    node * right;
} * root = NULL;

//function to create a new node
node * newnode(int data){
    node * new_node = new node;
    new_node -> info = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

//function for preorder traversal of tree
void preorder(node * ptr){
    if(ptr == NULL)
        return ;
    
    cout<<ptr -> info<<" ";
    preorder(ptr -> left);
    preorder(ptr -> right);
}

//function for inorder traversal of tree
void inorder(node * ptr){
    if(ptr == NULL)
        return ;
    
    inorder(ptr -> left);
    cout<<ptr -> info<<" ";
    inorder(ptr -> right);
}

//function for postorder traversal of tree
void postorder(node * ptr){
    if(ptr == NULL)
        return ;
    
    postorder(ptr -> left);
    postorder(ptr -> right);
    cout<<ptr -> info<<" ";
}

//function to input tree
node * enter(node * ptr, int level){
    int data;
    node * new_node;
    int ch;
    
    cout<<"Enter data at level "<<level<<endl;
    cin>>data;
    
    new_node = newnode(data);
    ptr = new_node;
    level ++;
    cout<<"Do you want to enter left child(1/0)"<<endl;
    cin>>ch;
    
    if(ch){
        ptr -> left = enter(ptr -> left, level);
    }
    
    cout<<"Do you want to enter right child(1/0)"<<endl;
    cin>>ch;
    if(ch){
        ptr -> right = enter(ptr -> right, level);
    }
    
    return ptr;
}

int main() {
    int level = 0;
    root = enter(root, level);
    cout<<"Preorder traversal : ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder traversal : ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder traversal : ";
    postorder(root);
    cout<<endl;
    return 0;
}
