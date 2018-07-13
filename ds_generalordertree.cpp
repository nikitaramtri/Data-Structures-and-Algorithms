//
//  ds_generalordertree.cpp
//  ds_5
//
//  Created by Radhika on 30/10/17.
//  Copyright © 2017 Nikita. All rights reserved.
//


#include<iostream>
using namespace std;

//creating node structure for a general ordered tree
struct node{
    char info;
    node * son;
    node * next;
}* root = NULL;

//function to create a new node
node * newnode(char data){
    node * new_node = new node;
    new_node -> info = data;
    new_node -> son = NULL;
    new_node -> next = NULL;
    return  new_node;
}

//function to count the number of leaf nodes
int count_leaf_nodes(node * ptr){
    int sum = 0;
    if(ptr == NULL)
        return 0;
    if(ptr -> son == NULL)
        return 1;
    ptr = ptr -> son;
    while(ptr != NULL){
        sum += count_leaf_nodes(ptr);
        ptr = ptr -> next;
    }
    return sum;
}


int main(){
    root = newnode('A');
    root ->  son = newnode('B');
    root -> son -> next = newnode('C');
    root ->son -> next -> next = newnode('D');
    root -> son -> son = newnode('E');
    root -> son -> son -> next = newnode('F');
    root -> son -> next -> son = newnode('G');
    root -> son -> next -> son -> next = newnode('H');
    root ->son -> next -> next -> son = newnode('I');
    /*
            A
          /
         B  -  C   -  D
        /      /      /
       E - F  G - H  I
     */
    
    cout<<"No of leaf nodes :"<<count_leaf_nodes(root)<<endl;
    return 0;
}


