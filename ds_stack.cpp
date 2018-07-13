//
//  main.cpp
//  ds_2
//
//  Created by Radhika on 20/09/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include <iostream>
using namespace std;
int max_size = 100;

//inserting an element in the stack : PUSH operation
void push(int stack[], int &top, int max_size, int element){
    
    if(top == max_size-1){
        cout<<"OVERFLOW"<<endl;
        return;
    }
    
    top ++;
    stack[top] = element;
}

//deleting an element from the stack : POP operation
void pop(int stack[], int &top){
    
    if(top == -1){
        cout<<"UNDERFLOW"<<endl;
        return;
    }
    
    cout<<stack[top]<<" is deleted"<<endl;
    top--;
}

//displaying the stack elements : DISPLAY operation
void display(int stack[], int top){
    
    if(top == -1){
        cout<<"Stack is empty"<<endl;
        return;
    }
    
    cout<<"STACK:- ";
    while(top>=0){
        cout<<stack[top]<<" ";
        top --;
    }
}


int main() {
    
    int stack[max_size], top = -1, element;
    int choice;//choice of operation to be performed
    char ch;
    
    cout<<"Choose :"<<endl;
    cout<<"1 = push"<<endl;
    cout<<"2 = pop"<<endl;
    cout<<"3 = disply"<<endl;
    
    do{
        
    cout<<"enter (1/2/3)"<<endl;
        cin>>choice;
        
        switch(choice){
                
            case 1 :    cout<<"PUSH OPERATION"<<endl;
                        cout<<"Enter element to be inserted"<<endl;
                        cin>>element;
                        push(stack, top, max_size, element);
                        break;
                
            case 2 :    cout<<"POP OPERATION"<<endl;
                        pop(stack, top);
                        break;
            
            case 3 :    cout<<"DISPLAY OPERATION"<<endl;
                        display(stack, top);
                        break;
        
            default :   cout<<"Invalid entry"<<endl;
        }
        
        cout<<"Do you want to make another operation?(y/n)"<<endl;
        cin>>ch;
    }
    while(ch == 'y');
    
    return 0;
}
