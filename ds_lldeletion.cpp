//
//  ds_lldeletion.cpp
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
void insertion(node ** start, int pos, node * newnode){
    
    node * ptr = * start;
    //if ll is empty
    if(*start == NULL){
        *start = newnode;
    }
    
    //if ll ids not empty
    else{
        
        if(pos == 0){
            //insertion at beginning
            newnode ->link = * start;
            * start = newnode;
        }
        else{
            int index = 0;//current node pos
            
            while(index != pos - 1){
                ptr = ptr ->link;
                index ++;
            }
            newnode -> link = ptr -> link;
            ptr -> link = newnode;
        }    }
    display(*start);
}

//function to delete a node from the linked list
int deletion(node ** start, int pos){
    node * ptr = * start;
    //if ll is empty
    if(*start == NULL){
        cout<<"Linked list is empty"<<endl;
        return 0;
    }
    
    //if ll ids not empty
    else{
        
        if(pos == 0){
            //deletion at beginning
            *start = (*start) -> link;
        }
        else{
            int index = 0;//current node pos
            
            while(index != pos - 1){
                ptr = ptr ->link;
                index ++;
            }
            ptr -> link = ptr -> link -> link;
        }
    }
    display(*start);
    return  1;
}
int main(){
    
    node * start = NULL, *new_node = NULL;
    int data;//info part of the new node to be inserted
    int nnodes = 0;//no.of nodes
    int pos;//position at which node is to be inserted
    int choice;//choice of operation variable
    char ch;//do while variable
    int status;//stores the status of deletion
    
    do{
        
        cout<<"Choose: 1 = Insertion and 2 = Deletion"<<endl;
        cin>>choice;
        
        switch(choice){
                
            case 1:      cout<<"Enter the position at which node is to be inserted when no. of nodes in the list are "<<nnodes ++<<endl;
                        cin>>pos;
                
                        cout<<"Enter data for the node"<<endl;
                        cin>>data;
                        new_node = newnode(data);
                        insertion(&start, pos, new_node);
                        break;
                
            case 2:     cout<<"Enter the position at which node is to be deleted when no. of nodes in the list are "<<nnodes <<endl;
                        cin>>pos;
                        status = deletion(&start, pos);
                        if(status)
                            nnodes --;
                        break;
                
            default:    cout<<"Invalid entry"<<endl;
                
        }
       
        
        cout<<"Do you want to insert more nodes"<<endl;
        cin>>ch;
    }
    while(ch == 'y');
    
    
    return 0;
}
