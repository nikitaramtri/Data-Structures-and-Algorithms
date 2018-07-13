//
//  ds_circularll.cpp
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
    node * link;
} * start;

//function to create a new node
node * newnode(int data){
    node * new_node = new node;
    new_node -> info = data;
    new_node -> link = NULL;
    return new_node;
}

//function to display ll
void display(node * start){
    node * ptr = start;
    
    //if ll is empty
    if(start == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"LIST: ";
    while(ptr -> link != start){
        cout<<ptr -> info<<" -> ";
        ptr = ptr -> link;
    }
    cout<<ptr -> info<<endl;
}

//function to insert new node
void insertion(node * newnode){
    node * ptr = start;
    //if ll is empty
    if(start == NULL){
        start = newnode;
        newnode -> link = start;
    }
    else{
        while(ptr -> link != start){
            ptr = ptr -> link;
        }
        ptr -> link = newnode;
        newnode -> link = start;
    }
    display(start);
}

//function to delete a node
void deletion(){
    node * ptr = start;
    
    //if ll is empty
    if(start == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    
    
    //if ll has one node
    if(start -> link == start){
        cout<<start -> info<<" is deleted"<<endl;
        start = NULL;
    }
    else{
        while(ptr -> link -> link!= start){
            ptr = ptr -> link;
        }
        cout<<ptr -> link -> info<< " is deleted"<<endl;
        ptr -> link = start;
    }
    
    display(start);
}

int main(){
    node  * new_node = NULL;
    int choice;//choice of operation
    int data;// info part of the new node to be inserted
    char ch;//do while variable
    
    do{
        cout<<"Choose: 1 = Insertion and 2 = Deletion"<<endl;
        cin>>choice;
        
        switch (choice) {
                
            case  1 :       cout<<"INSERTION \nEnter data"<<endl;
                            cin>>data;
                            new_node = newnode(data);
                            insertion(new_node);
                            break;
                
            case 2 :        cout<<"DELETION"<<endl;
                            deletion();
                            break;
                
            default :       cout<<"Invalid entry"<<endl;
        }
        
        cout<<"Do you want to return to the menu\n";
        cin>>ch;
    }
    while(ch == 'y');
    return 0;
 }
