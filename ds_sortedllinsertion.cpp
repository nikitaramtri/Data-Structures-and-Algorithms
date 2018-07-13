//
//  ds_sortedllinsertion.cpp
//  ds_3
//
//  Created by Radhika on 22/10/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include<iostream>
using namespace std;

//creating node structure
struct node{
    int info;
    node * link;
};

//function to create new node
node * newnode(int data){
    node * new_node = new node;
    new_node -> info = data;
    new_node -> link = NULL;
    return  new_node;
}

//function to display linked list
void display(node * start){
    node * ptr =  start;
    
    cout<<"LINKED LIST : "<<endl;
    while(ptr != NULL){
        cout<<ptr -> info<<" -> ";
        ptr = ptr -> link;
    }
    cout<<endl;
}
//function to insert node in a linked list
void insertion(node ** start, node * newnode){
    
    node * ptr = * start;
    //if ll is empty
    if(*start == NULL){
        *start = newnode;
    }
    
    //if ll ids not empty
    else{
        
        if(newnode -> info < (*start) -> info){
            newnode -> link = ptr;
            (*start) = newnode;
        }
        
        else{
                while( (ptr -> link != NULL) && (ptr ->link -> info < newnode -> info )){
                ptr = ptr -> link;
            }
            newnode -> link = ptr -> link;
            ptr -> link = newnode;
        }
    }
    display(*start);
    
}
int main(){
    
    node * start = NULL, *new_node = NULL;
    int data;//info part of the new node to be inserted
    char ch;//do while variable
    
    do{
        cout<<"Enter data for the node"<<endl;
        cin>>data;
        new_node = newnode(data);
        insertion(&start, new_node);
        
        cout<<"Do you want to insert more nodes"<<endl;
        cin>>ch;
    }
    while(ch == 'y');
    
    
    return 0;
}
