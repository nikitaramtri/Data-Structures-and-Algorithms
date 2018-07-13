//
//  main.cpp
//  ds_3
//
//  Created by Radhika on 18/10/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include <iostream>
using namespace std;
int max_capacity = 100;

//enque
void insertion(int queue[], int &rear, int element, int max_capacity){
    if( rear == max_capacity ){
        cout<<"OVERFLOW"<<endl;
        return;
    }
    queue[rear] = element;
    rear ++;
    cout<<"inserted"<<endl;
}

//deque
void deletion(int queue[], int &front, int &rear){
    if(front == rear){
        cout<<"UNDERFLOW"<<endl;
        return;
    }
    front ++;
    if(front == rear)
        front = rear = 0;
    cout<<"deleted"<<endl;
}

//function to display the queue
void display(int queue[], int front, int rear){
    int index;//looping variable
    
    cout<<"Queue :";
    for(index = front; index < rear; index ++){
        cout<<queue[index]<<" ";
    }
    cout<<endl;
}

int main(){
    
    int queue[max_capacity], front = 0, rear = 0, element;
    
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
                
            case 1 :     cout<<"ENQUE"<<endl;
                        cout<<"Enter element to be inserted"<<endl;
                        cin>>element;
                        insertion(queue, rear, element, max_capacity);
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

