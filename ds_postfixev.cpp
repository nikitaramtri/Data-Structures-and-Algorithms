//
//  ds_postfixev.cpp
//  ds_2
//
//  Created by Radhika on 14/10/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include<iostream>
#include<cstring>
using namespace std;

int stack[100], top;

 //pop operation : insertion
void push(int element){
    top ++;
    stack[top] = element;
}

 // pop operation : deletion
int pop(){
    int element = stack[top];
    top --;
    return element;
}

 // procedure to be followed when an operator is encountered
void eval_operator(char op){
    int operand2 = pop();
    int operand1 = pop();
    int result = 1, index;
    
    switch(op){
        case '+'    :   result = operand1 + operand2;
                        break;
            
        case '-'    :   result = operand1 - operand2;
                        break;
        case '*'    :   result = operand1 * operand2;
                        break;
        case '/'    :   result = operand1 / operand2;
                        break;
        case '^'    :   for(index = 1; index <= operand2; index ++)
                        result *= operand1;
                        break;
        default     :   cout<<"Invalid expression"<<endl;
    }
    
    push(result);
}
 
 // evaluation of postfix expression
void evaluate(char postfix_exp[], int length){
    
    int index;
    
    for(index = 0; index < length; index ++){
        if(isdigit(postfix_exp[index])){
            push(postfix_exp[index] - '0');
        }
        else{
            eval_operator(postfix_exp[index]);
        }
    }
    
}

int main(){
    char postfix_exp[20];// postfix expression
    top = -1;
    
    cout<<"Enter the postfix expression"<<endl;
    cin>>postfix_exp;
 
    int length = strlen(postfix_exp);
    evaluate(postfix_exp, length);
    int result = pop();
 
    cout<<"Evaluating "<<postfix_exp<<" we get "<<result;
    return 0;
    
    
}

