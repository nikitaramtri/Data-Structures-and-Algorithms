//
//  ds_nodesno.cpp
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

//function to count the number of leaf nodes in the binary tree
int count_leafnodes(node * ptr ){
    if(ptr == NULL)
        return 0;
    
    if(ptr -> left == NULL && ptr -> right == NULL)
        return  1;
    
    return count_leafnodes(ptr -> left) + count_leafnodes(ptr -> right);
}

//function to count the number of internal nodes in the binary tree
int count_internalnodes(node * ptr ){
    if(ptr == NULL)
        return 0;
    
    if(ptr -> left == NULL && ptr -> right == NULL)
        return  0;
    
    return count_internalnodes(ptr -> left) + count_internalnodes(ptr -> right) + 1;
}

int main(){
    
    root = enter(root, 0);
    int leaf_nodes = count_leafnodes(root);
    int internal_nodes = count_internalnodes(root);
    cout<<"No of leaf nodes = "<<leaf_nodes<<" and internal nodes = "<<internal_nodes;
    return 0;
    
}
