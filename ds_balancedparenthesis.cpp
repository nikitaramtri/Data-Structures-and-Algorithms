//
//  ds_balancedparenthesis.cpp
//  ds_2
//
//  Created by Radhika on 18/10/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include<iostream>
#include<cstring>
using namespace std;

char stack[100];
int top;


// push operation
void push(char element){
    top ++;
    stack[top] = element;
}

//pop operation
char pop(){
    char element = stack[top];
    top --;
    return element;
}

//function to check character1 and character2 are openeing and closing brackets of the same type
bool matching_paranthesis( char character1, char character2){
    if( character1 == '(' && character2 == ')')
        return 1;
    else if( character1 == '[' && character2 == ']')
        return 1;
    else if( character1 == '{' && character2 == '}')
        return 1;
    else
        return 0;
}

//function to check if stack is empty
bool is_stack_empty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

//function to check if the expression consists of balanced paranthesis
int check_bal_parenthesis(char exp[], int length){
    
    int index; //looping variable
    top = -1;
    char element;
    
    for(index = 0; index < length; index ++){
        if(exp[index] == '(' || exp[index] == '[' || exp[index] == '{'){
            push(exp[index]);
        }
        else if(exp[index] == ')' || exp[index] == ']' || exp[index] == '}'){
            if(is_stack_empty())
                return 0;
            element = pop();
            if(!matching_paranthesis(element, exp[index]))
                return 0;
        }
    }
    
    if(is_stack_empty())
        return 1;
    else
        return 0;
}
int main(){
    
    char exp[100]; // expression to input from user to check balance parenthesis
    
    cout<<"Enter the exprssion"<<endl;
    cin>>exp;
    
    int length = strlen(exp);
    
    int check = check_bal_parenthesis(exp, length);
    if(check)
        cout<<"Balanced paranthesis"<<endl;
    else
        cout<<"Unbalanced paranthesis"<<endl;
    
    return 0;
}
