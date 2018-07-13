//
//  ds_bstdeletion.cpp
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
node * insert(node * ptr, node * newnode){
    if(ptr == NULL)
        return newnode;
    if(newnode -> info < ptr -> info)
        ptr -> left = insert(ptr -> left, newnode);
    else
        ptr -> right = insert(ptr -> right, newnode);
    return ptr;
}

//function to find min node
node * find_min_node(node * ptr){
    while(ptr -> left != NULL){
        ptr = ptr -> left;
    }
    return ptr;
}
//function for deleting a node with info part equal to key
node * delnode(node * ptr, int key){
    
    node * temp = NULL;
    
    //if bst is empty
    if(ptr == NULL)
        return ptr;
    
    if(key < ptr -> info)
        ptr -> left = delnode(ptr -> left, key);
    
    else if(key > ptr -> info)
        ptr -> right = delnode(ptr -> right, key);
    
    else{
        if(ptr -> left ==  NULL){
            temp = ptr -> right;
            delete(ptr);
            return temp;
        }
        else if(ptr -> right == NULL){
            temp = ptr -> left;
            delete(ptr);
            return temp;
        }
        else{
            temp = find_min_node(ptr -> right);
            ptr -> info = temp -> info;
            ptr -> right = delnode(ptr -> right, temp -> info);
        }
    }
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
    int data, choice;
    
    do{
        cout<<"Choose: 1 = insert & 2 = search"<<endl;
        cin>>choice;
        
        switch(choice){
            case 1 :        cout<<"Insertion :"<<endl;
                            cout<<"Enter data"<<endl;
                            cin>>data;
                            new_node = newnode(data);
                            root = insert(root, new_node);
                            inorder(root);
                            break;
                
            case 2 :        cout<<"Deletion :"<<endl;
                            cout<<"Enter data"<<endl;
                            cin>>data;
                            root = delnode(root,data);
                            inorder(root);
                            break;
                
            default :       cout<<"invalid argument "<<endl;
        }
        
        
        cout<<"\nDo you want to return to the menu(y/n)"<<endl;
        cin>>ch;
    }
    while(ch == 'y');
    
    return 0;
}
