//
//  ds_circularqueue.cpp
//  ds_3
//
//  Created by Radhika on 19/10/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include<iostream>
using namespace std;
int max_size = 5;

//insertion in a circular linked list
void insertion(int queue[], int &front, int &rear, int element){
    
    if( (front == 0 && rear == max_size -1) ||  (front == rear + 1)){
        cout<<"OVERFLOW"<<endl;
        return;
    }
    else if(front == -1)
        front = rear = 0;
    else if(rear == max_size - 1)
        rear = 0;
    else
        rear ++;
    
    queue[rear] = element;
}

//deletion in a circular linked list
void deletion(int queue[], int &front, int &rear){
    
    if(front == -1){
        cout<<"UNDERFLOW"<<endl;
        return;
    }
    else if(front == rear)
        front = rear = -1;
    else if(front == max_size - 1)
        front = 0;
    else
        front ++;
    
}

//displaying a circular queue
void display(int queue[], int front, int rear){
    
    int index; //looping variable
    cout<<front<<rear<<endl;
    if(front <= rear){
        cout<<"1"<<endl;
        for(index = front; index <= rear; index ++)
            cout<<queue[index]<<" ";
    }
    else{
        cout<<"2 "<<endl;
        for(index = front; index < max_size; index ++)
            cout<<queue[index]<<" ";
        for(index = 0; index <= rear; index ++)
            cout<<queue[index]<<" ";
    }
}

int main(){
    
    int queue[max_size];
    int element;
    int front = -1, rear = -1;
    
    int choice;//choice of operation to be performed
    char ch;// do while variable
    
    cout<<"Choose :"<<endl;
    cout<<"1 = insert"<<endl;
    cout<<"2 = delete"<<endl;
    cout<<"3 = display"<<endl;
    
    do{
        
        cout<<"enter (1/2/3)"<<endl;
        cin>>choice;
        
        switch(choice){
                
            case 1  :   cout<<"ENQUE"<<endl;
                        cout<<"Enter element to be inserted"<<endl;
                        cin>>element;
                        insertion(queue, front, rear, element);
                        break;
                
                
            case 2 :    cout<<"DEQUE"<<endl;
                        deletion(queue, front, rear);
                        break;
                
            case 3 :    cout<<"DISPLAY"<<endl;
                        display(queue, front, rear);
                        break;
                
            default :   cout<<"Invalid entry"<<endl;
        }
        
        cout<<"Do you want to make another operation?(y/n)"<<endl;
        cin>>ch;
    }
    while(ch == 'y');
    return 0;
}

