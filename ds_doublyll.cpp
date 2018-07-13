//
//  ds_doublyll.cpp
//  ds_4
//
//  Created by Radhika on 22/10/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include<iostream>
using namespace std;

//creating node structure
struct node{
    int info;
    node * prev;//pointer to the previous node
    node * next;//pointer to the next node
} * beg, * last;//pointers pointing to the beginning and end respectively of the doubly linked list

//function to create a new node
node * newnode(int data){
    node * new_node = new node;
    new_node -> info = data;
    new_node -> prev = NULL;
    new_node -> next = NULL;
    return  new_node;
}

//function to display ll
void display(node * beg){
    
    // if ll is empty
    if(beg == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    node * ptr = beg;
    
    cout<<"LIST: ";
    while(ptr != NULL){
        cout<<ptr -> info<<" <-> ";
        ptr = ptr -> next;
    }
    cout<<endl;
    
}
//function to insert new nodes
void insertion(node * newnode, int position, int nnodes){
    node * ptr = beg;
    // if ll is empty
    if(beg == NULL){
        beg = last = newnode;
    }
    else{
        if(position == 1){
            newnode -> next = beg;
            beg -> prev = newnode;
            beg = newnode;
        }
        else if(position > nnodes){
            last -> next = newnode;
            newnode ->prev = last;
            last = newnode;
        }
        else{
            
            while(-- position) {
                ptr = ptr -> next;
            }
            newnode -> next = ptr;
            newnode -> prev = ptr ->prev;
            ptr -> prev -> next = newnode;
            ptr -> prev = newnode;
        }
        
    }
    display(beg);
}

//function to delete a node
int deletion(int position, int nnodes){
    node * ptr = beg;
    
    //if ll is empty
    if(beg == NULL){
        cout<<"List is empty"<<endl;
        return 0;
    }
    //if ll contains only one node
    if(beg == last){
        beg = last = NULL;
        
    }
    else{
        if(position == 1){
            beg = beg -> next;
            beg -> prev = NULL;
        }
        else if(position == nnodes){
            last = last -> prev;
            last -> next = NULL;
        }
        else{
            while(-- position){
                ptr = ptr -> next;
            }
            ptr -> prev -> next = ptr -> next;
            ptr -> next -> prev = ptr -> prev;
        }
    }
    display(beg);
    return 1;
}
int main(){
    
    beg = NULL;
    last = NULL;
    node * new_node = NULL;//new node to be inserted
    int choice;//choice of operation
    int data;// info part of the new node to be inserted
    char ch;//do while variable
    int nnodes = 0;//number of nodes
    int pos;//position for insertion or deletion
    int status;//status of deletion
    
    do{
        cout<<"Choose: 1 = Insertion and 2 = Deletion"<<endl;
        cin>>choice;
        
        switch (choice) {
                
            case  1 :       cout<<"INSERTION \nEnter position for insertion when no. of nodes = "<<nnodes<<endl;
                            cin>>pos;
                            cout<<"Enter data\n";
                            cin>>data;
                            new_node = newnode(data);
                            insertion(new_node, pos, nnodes);
                            nnodes ++;
                            break;
                
            case 2 :        cout<<"DELETION \nEnter position for deletion when no. of nodes = "<<nnodes<<endl;
                            cin>>pos;
                            status = deletion(pos, nnodes);
                            if(status)
                            nnodes --;
                            break;
                
            default :       cout<<"Invalid entry"<<endl;
        }
        
        cout<<"Do you want to return to the menu\n";
        cin>>ch;
    }
    while(ch == 'y');
    return 0;
}
