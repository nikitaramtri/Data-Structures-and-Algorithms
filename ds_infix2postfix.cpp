//
//  ds_infix2postfix.cpp
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
char postfix_exp[100]; // postfix expression

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
            postfix_exp[index_p] = element;
            index_p ++;
        
        }
    }
    else if( op == '*' || op == '/'){
        while(stack[top] == '*' || stack[top] == '/' || stack[top] == '^'){
            element = pop();
            postfix_exp[index_p] = element;
            index_p ++;        }
    }
    else if( op == '^'){
        while(stack[top] == '^'){
            element = pop();
            postfix_exp[index_p] = element;
            index_p ++;        }
    }
    push(op);
   
}

//infix to postfix conversion
void infix2postfix(char infix_exp[], int length){
    
    int index_i, element; // index_i is the loop variable for infix expression
    index_p = 0;
    infix_exp[length] = ')';
    
    push('(');
    for(index_i = 0; index_i <= length; index_i ++){
        if(isalnum(infix_exp[index_i])){
            // when operand is encountered
            postfix_exp[index_p] = infix_exp[index_i];
            index_p ++;
        }
        else if(infix_exp[index_i] == '('){
            //when '(' is encountered
            push('(');
        }
        else if(infix_exp[index_i] == ')'){
            //when ')' is encountered
            while(!(stack[top] == '(')){
                element = pop();
                postfix_exp[index_p] = element;
                index_p ++;
            }
            top --;
        }
        else{
            //when operator is encountered
            eval_operator(infix_exp[index_i]);
        }
    }
}

int main(){
    char infix_exp[20];
    top = -1;
    
    // input infix expression
    cout<<"Enter the infix expression"<<endl;
    cin>>infix_exp;
    int length = strlen(infix_exp);
    
    infix2postfix(infix_exp, length);
    
    cout<<" Postfix expression: "<<postfix_exp<<endl;
    
    return 0;
    
    
}

