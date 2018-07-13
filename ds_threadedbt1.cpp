//
//  ds_threadedbt1.cpp
//  ds_7
//
//  Created by Radhika on 05/11/17.
//  Copyright © 2017 Nikita. All rights reserved.
//


#include <iostream>
#include<stack>
using namespace std;

//creating node structure
struct node{
    int info;
    bool tag;
    node * left;
    node * right;
} * root = NULL;

//function to create a new node
node * newnode(int data){
    node * new_node = new node;
    new_node -> info = data;
    new_node -> tag = 0;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

//function for traversal of threaded bt
void display(node * ptr){
    node * parent = ptr;
    // if tree is empty
    if(ptr == NULL)
        return;
    
    while(ptr -> right != NULL){
        while(ptr -> left != NULL){
            parent = ptr;
            ptr = ptr -> left;
        }
 
        if(ptr -> tag == 1){
            cout<<ptr -> info<<" ";
            parent = ptr -> right;
            ptr = parent -> right;
            cout<<parent -> info;
        }
        else
            ptr = ptr -> right;
    }
}


int find(node * parent, node * ptr){

    if (parent == NULL)
        return 0;
    if(parent == ptr)
        return 1;
    if(parent -> left == NULL && parent -> right == NULL)
        return  0;
    if(find(parent -> left, ptr)==1 || find(parent ->right, ptr)==1)
        return 1;

        return 0;
    
    
}
node * get_successor(node * parent, node * ptr){
 if(parent == NULL)
 return parent;

    if(find(parent -> left, ptr)){//if ptr present in left subtree
   
        if(get_successor(parent -> left, ptr) == NULL)
            return parent;
        else
            return get_successor(parent -> left, ptr);    }
    else{
        return get_successor(parent -> right, ptr);
    }
 }

 //function to create threaded bt
void create(node * ptr){
    if(ptr == NULL)
        return;
    while(ptr != NULL){
        while(ptr -> left != NULL)
            ptr = ptr -> left;
       
        while(ptr -> right == NULL){
            ptr -> tag = 1;
            ptr -> right = get_successor(root, ptr);
            ptr = ptr -> right ;
        }
        ptr = ptr -> right;
    }
}
int main() {
    //create root
    root = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->left->left  = newnode(4);
    root -> left -> left -> right = newnode(5);
    root ->left -> right = newnode(6);
    root ->left -> right -> left = newnode(7);
    root ->left -> right -> right= newnode(8);
    root -> right -> left =newnode(9);
    root -> right -> right =newnode(10);

    create(root);
    display(root);
    return 0;
}


//function to get the inorder succesor of node ptr
/*node * get_successor(node * parent, node * ptr){
 if(parent == NULL)
 return parent;
 //if(parent -> left == NULL && parent -> right == NULL)
 //return  NULL;
 if(parent -> left == ptr)
 return parent;
 //if(parent -> right == ptr)
 //return get_successor(root, parent);
 // cout<<ptr -> info<<endl;
 node * parentl = NULL, * parentr = NULL;
 parentl = get_successor(parent -> left, ptr);
 if(parentl)
 {
 return parentl;
 }
 parentr = get_successor(parent -> right, ptr);
 return parentr;
 }
 */
