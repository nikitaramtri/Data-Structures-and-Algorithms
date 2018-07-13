//
//  ds_llqueue.cpp
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

//function to display the queue
void display(node * front){
    node * ptr = front;
    
    //if queue is empty
    if(front == NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"QUEUE : ";
    while(ptr != NULL){
        cout<<ptr -> info<<" -> ";
        ptr = ptr -> link;
    }
    cout<<endl;
}

//function to insert new nodes in the queue
void insertion(node ** front, node ** rear, node * newnode){
    
    //if queue is empty
    if(*rear == NULL){
        *rear = *front = newnode;
    }
    //when queue is not empty
    else{
        (*rear) -> link = newnode;
        *rear = newnode;
    }
  
    display(*front);
   
}

//function to delete node
void deletion(node ** front, node ** rear){
    
    //if queue is empty
    if(*front == NULL){
        cout<<"UNDERFLOW"<<endl;
        return;
    }
    
    cout<<(*front) -> info<<" is deleted"<<endl;
    
    //if queue has only 1 node
    if(*front == *rear){
        *front = *rear = NULL;
        return;
    }
    *front = (*front) -> link;
    display(*front);
  
}

int main() {
    
    node  * front = NULL,* rear = NULL, * new_node = NULL;
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
                            insertion(&front, &rear, new_node);
                            break;
                
            case 2 :        cout<<"DELETION"<<endl;
                            deletion(&front, &rear);
                            break;
                
            default :       cout<<"Invalid entry"<<endl;
        }
        
        cout<<"Do you want to return to the menu\n";
        cin>>ch;
    }
    while(ch == 'y');
    
    return 0;
}
