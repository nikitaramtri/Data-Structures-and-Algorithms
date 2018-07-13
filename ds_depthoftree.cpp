//
//  ds_depthoftree.cpp
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

//function to calculate max of the two depths
int max(int depth1, int depth2){
    if(depth1 > depth2)
        return  depth1;
    else
        return depth2;
}

//function to calculate depth of the binary tree
int max_depth(node * ptr){
    if( ptr == NULL)
        return 0;
    return max(max_depth(ptr -> left), max_depth(ptr -> right)) +1;
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

int main(){
    
    root = enter(root, 0);//enter the tree whoose depth to be calculated
    cout<<"Depth of this tree = "<<max_depth(root)<<endl;
    
    return 0;
}
