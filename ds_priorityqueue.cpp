//
//  ds_priorityqueue.cpp
//  ds_4
//
//  Created by Radhika on 23/10/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include<iostream>
using namespace std;

//creating node structure
struct node{
    int info;
    int priority;
    node * link;
} * start;

//function to create a new node
node * newnode(int data, int pri){
    node * new_node = new node;
    new_node -> info = data;
    new_node -> priority = pri;
    new_node -> link = NULL;
    return  new_node;
}

//function to display
void display(){
    node * ptr = start;
    
    //if list is empty
    if(start == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Priority Queue : ";
    while(ptr != NULL){
        cout<<ptr -> info<<"["<<ptr -> priority<<"]"<<" -> ";
        ptr = ptr -> link;
    }
    cout<<endl;
}

//function to insert a node
void insertion(node * newnode){
    node * ptr = start;
    
    // if ll is empty
    if(start == NULL){
        start = newnode;
    }
    else{
        if(newnode -> priority < start -> priority){
            newnode -> link = start;
            start = newnode;
        }
        else{
            while(ptr -> link != NULL && !(ptr -> link -> priority > newnode -> priority)){
                ptr = ptr -> link;
            }
            newnode -> link = ptr -> link;
            ptr-> link = newnode;
        }
    }
    display();
}

//function to delete a node
void deletion(){
    //if list is empty
    if(start == NULL){
        cout<<"Priority Queue is empty"<<endl;
        return;
    }
    cout<<start-> info<<"["<<start -> priority<<"]"<<" is finished"<<endl;
    start = start -> link;
    display();
}

int main() {
    
    start = NULL;
    node * new_node = NULL;
    int choice;//choice of operation
    int data;// info part of the new node to be inserted
    int pri; // priority part of new node to be inserted
    char ch;//do while variable
    
    do{
        cout<<"Choose: 1 = Insertion and 2 = Deletion"<<endl;
        cin>>choice;
        
        switch (choice) {
                
            case  1 :       cout<<"INSERTION \nEnter data and priority"<<endl;
                            cin>>data>>pri;
                            new_node = newnode(data, pri);
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
