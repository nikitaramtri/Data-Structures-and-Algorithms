//
//  ds_bubblesort2.cpp
//  ds
//
//  Created by Radhika on 10/09/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include<iostream>
using namespace std;

void sort(int array[], int size){
    int index, temp;
    
    if(size == 1)
        return;
    
    
    for(index = 0; index <size-1; index++)
        if(array[index] > array[index+1]){
                temp = array[index];
                array[index] = array[index+1];
                array[index+1]=temp;
            }
    sort(array, size-1);
    
}


void display(int array[], int size){
    int index;
    
    cout<<"Sorted Array: "<<endl;
    for(index = 0; index < size; index ++)
        cout<<array[index]<<endl;
}

int main(){
    int index, size, array[100];
    
    cout<<"Enter array size(<100)"<<endl;
    cin>>size;
    
    cout<<"Enter array elements: "<<endl;
    for(index = 0; index < size; index ++)
        cin>>array[index];
    
    sort(array, size);
    display(array, size);
    
    return 0;
}
