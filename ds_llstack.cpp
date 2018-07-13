//
//  main.cpp
//  ds_4
//
//  Created by Radhika on 22/10/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include <iostream>
using namespace std;

//creating node structure
struct node{
    int info;
    node * link;
};

//function to create a new node
node * newnode(int data){
    node * new_node = new node;
    new_node -> info = data;
    new_node -> link = NULL;
    return  new_node;
}

//function to display the stack
void display(node * top){
    node * ptr = top;
    
    //if ll is empty
    if(top == NULL){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"STACK : ";
    while(ptr != NULL){
        cout<<ptr -> info<<" -> ";
        ptr = ptr -> link;
    }
    cout<<endl;
}

//function to insert new nodes in the list
node * push(node * top, node * newnode){
    
    //ll is empty case not needed separately
   
    newnode -> link = top;
    top = newnode;
    display(top);
    return  top;
}

//function to delete node
node * pop(node * top){
    
    //if ll is empty
    if(top == NULL){
        cout<<"UNDERFLOW"<<endl;
        return top;
    }
    cout<<top -> info<<" is deleted"<<endl;
    top = top ->link;
    display(top);
    return  top;
}

int main() {

    node  * top = NULL, * new_node = NULL;
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
                            top = push(top, new_node);
                            break;
                
            case 2 :        cout<<"DELETION"<<endl;
                            top = pop(top);
                            break;
                
            default :       cout<<"Invalid entry"<<endl;
        }
        
        cout<<"Do you want to return to the menu\n";
        cin>>ch;
    }
    while(ch == 'y');
    
    return 0;
}
