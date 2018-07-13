//
//  ds_infix2prefix.cpp
//  ds_2
//
//  Created by Radhika on 18/10/17.
//  Copyright © 2017 Nikita. All rights reserved.
//


#include<iostream>
#include<cstring>
#include <string>
using namespace std;

char stack[100]; //stack
int top, index_p;// 'index_ p' is the index of postfix expression and 'top' is the top of stack
char prefix_exp[100]; // postfix expression

// push operation : push operators and paranthesis onto the stack
void push(char element){
    top ++;
    stack[top] = element;
}

//pop operation : pop operators and paranthesis out of the stack
char pop(){
    char element = stack[top];
    top --;
    return element;
}

//procedure to be followed when operator is encountered
void eval_operator(char op){
    
    int element;
    
    if( op == '+' || op == '-'){
        while(stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/' || stack[top] == '^'){
            element = pop();
            prefix_exp[index_p] = element;
            index_p ++;
            
        }
    }
    else if( op == '*' || op == '/'){
        while(stack[top] == '*' || stack[top] == '/' || stack[top] == '^'){
            element = pop();
            prefix_exp[index_p] = element;
            index_p ++;        }
    }
    else if( op == '^'){
        while(stack[top] == '^'){
            element = pop();
            prefix_exp[index_p] = element;
            index_p ++;        }
    }
    push(op);
    
}

//infix to postfix conversion
void infix2prefix(char infix_exp[], int length){
    
    int index_i, element; // index_i is the loop variable for infix expression
    index_p = 0;
    for(index_i = length; index_i >0; index_i --)
        infix_exp[index_i] = infix_exp[index_i - 1];
    infix_exp[0] = '(';
    cout<<infix_exp<<endl;
    
    push(')');
    for(index_i = length; index_i >= 0 ; index_i --){
        if(isalnum(infix_exp[index_i])){
            // when operand is encountered
            prefix_exp[index_p] = infix_exp[index_i];
            index_p ++;
        }
        else if(infix_exp[index_i] == ')'){
            //when ')' is encountered
            push(')');
        }
        else if(infix_exp[index_i] == '('){
            //when '(' is encountered
            while(!(stack[top] == ')')){
                element = pop();
                prefix_exp[index_p] = element;
                index_p ++;
            }
            top --;
        }
        else{
            //when operator is encountered
            eval_operator(infix_exp[index_i]);
        }
    }
    
    //reversing postfix expression
    int index1, index2, mid = (index_p - 1)/2;
    char temp;
    for(index1= 0, index2 = index_p - 1; index1 <= mid; index1 ++, index2 --){
        temp = prefix_exp[index1];
        prefix_exp[index1] = prefix_exp[index2];
        prefix_exp[index2] = temp;
    }
}

int main(){
    char infix_exp[100];
    top = -1;
    
    // input infix expression
    cout<<"Enter the infix expression"<<endl;
    cin>>infix_exp;
    int length = strlen(infix_exp);
    
    infix2prefix(infix_exp, length);
    
    cout<<" Prefix expression: "<<prefix_exp<<endl;
    
    return 0;
    
    
}
