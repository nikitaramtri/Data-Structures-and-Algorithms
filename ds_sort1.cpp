//
//  ds_sort1.cpp
//  ds
//
//  Created by Radhika on 10/09/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include<iostream>
using namespace std;

void swap_sort(int &num1, int &num2){
    int temp;
    temp = num1;
    num1= num2;
    num2 = temp;
}
void sort(int array[], int size){
    
    if(size == 1)
        return;
    
    
    int index1, index2;
    
    for(index1 = 0; index1 < size-1; index1++){
        
        for(index2 = index1+1; index2 <size; index2++){
            if(array[index1] > array[index2]){
                swap_sort(array[index1], array[index2]);
                
            }}
        
    }
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
