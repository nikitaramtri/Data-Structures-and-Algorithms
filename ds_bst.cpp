//
//  ds_bst.cpp
//  ds_5
//
//  Created by Radhika on 29/10/17.
//  Copyright © 2017 Nikita. All rights reserved.
//


#include<iostream>
using namespace std;


//creating node structure
struct node{
    int info;
    node * left;
    node * right;
}*root = NULL;

//function to create a new node
node * newnode(int data){
    node * new_node = new node;
    new_node -> info = data;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

//function for bst creation
node * enter(node * ptr, node * newnode){
    if(ptr == NULL)
        return newnode;
    if(newnode -> info < ptr -> info)
        ptr -> left = enter(ptr -> left, newnode);
    else
        ptr -> right = enter(ptr -> right, newnode);
    return ptr;
}

//function for preorder traversal of tree since inorder traversal of bst gives nodes in sorted order
void inorder(node * ptr){
    if(ptr == NULL)
        return ;
    
    inorder(ptr -> left);
    cout<<ptr -> info<<" ";
    inorder(ptr -> right);
}

int main(){
    node * new_node = NULL;
    char ch;
    int data;
    
    do{
        cout<<"Enter data"<<endl;
        cin>>data;
        new_node = newnode(data);
        root = enter(root, new_node);
        
        cout<<"Do you want to enter more nodes(y/n)"<<endl;
        cin>>ch;
    }
    while(ch == 'y');
 
    inorder(root);
    return 0;
}
