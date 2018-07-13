//
//  ds_insertion.cpp
//  ds
//
//  Created by Radhika on 09/09/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include<iostream>
using namespace std;

void insert(int array[], int &size, int element, int position){
    int index;
    
    for(index = size; index > position; index --)
        array[index] = array[index-1];
    
    array[position] =  element;
    size ++;
}

void display(int array[], int size){
    int index;
    
    cout<<"Array: "<<endl;
    for(index = 0; index < size; index ++)
        cout<<array[index]<<endl;
}

int main(){
    int index, element, position, size, array[100];
    
    cout<<"Enter array size(<100)"<<endl;
    cin>>size;
    
    cout<<"Enter array elements: "<<endl;
    for(index = 0; index < size; index ++)
        cin>>array[index];
    
    cout<<"Enter element and position a which it is to be inserted"<<endl;
    cin>>element>>position;
    
    insert(array, size, element, position);
    display(array, size);
    
    return 0;
}
