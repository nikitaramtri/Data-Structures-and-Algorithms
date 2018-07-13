//
//  ds_iterative.cpp
//  ds_5
//
//  Created by Radhika on 30/10/17.
//  Copyright © 2017 Nikita. All rights reserved.
//


#include <iostream>
#include<stack>
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
    //base case
    if(ptr == NULL)
        return ;
    
    stack<node *> tree; //stack named tree created to be used for preorder traversal of tree
    tree.push(ptr);// push root node
    while(!tree.empty()){
        node * temp = tree.top();
        cout<<temp -> info<<" ";
        tree.pop();
        if(temp -> right)
            tree.push(temp -> right);
        if(temp ->left)
            tree.push(temp ->left);
    }
}

//function for inrder traversal of tree
void inorder(node * ptr){
    //base case
    if(ptr == NULL)
        return ;
 
    int status = 0;
    
    stack<node *> tree; //stack named tree created to be used for preorder traversal of tree
    //tree.push(ptr);// push root node
    while(!status){
        while(ptr != NULL){
            tree.push(ptr);
            ptr = ptr -> left;
        }
        if(!tree.empty()){
            ptr = tree.top();
            cout<<ptr -> info<<" ";
            tree.pop();
            ptr = ptr -> right;
        }
        else
            status = 1;
        
    }
}

//function for postorder traversal of tree
void postorder(node * ptr){
   	if(ptr == NULL)
        return;
    
    stack<node*> tree;
    int status = 0;
    node * prev = ptr;
    
    while(!status){
        while(ptr != NULL){
            tree.push(ptr);
            ptr = ptr -> left;
        }
        
        if(!tree.empty()){
            
            ptr = tree.top();
            //if both left and rigt sub trees of the ptr are processed i.e. prev is same as rt pointer of ptr
            if (prev == ptr -> right ){
                cout<<ptr -> info<<" ";
                tree.pop();
                prev = ptr;
               
                if(tree.empty()){   // if stack is empty
                    break;
                }
                
                ptr = NULL;
            }
            else{
                if(ptr -> right == NULL ){
                    cout<<ptr -> info<<" ";
                    tree.pop();
                }
                prev = ptr ;
                ptr = ptr -> right;
            }
            
        }
        else    //if tree is empty
            status = 1;
    }//end of while loop
}


int main() {
    /*create root*/
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
    
    cout<<"Preorder traversal : ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder traversal : ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder traversal : ";
    postorder(root);
    
    return 0;
}
