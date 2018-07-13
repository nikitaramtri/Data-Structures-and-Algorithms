//
//  ds_bubblesort.cpp
//  ds
//
//  Created by Radhika on 09/09/17.
//  Copyright © 2017 Nikita. All rights reserved.
//


#include<iostream>
using namespace std;

void sort(int array[], int size){
    int index, pass, temp, swap;
    for(pass = 0; pass < size-1; pass++){
        swap = 0;
        for(index = 0; index <size-pass-1; index++){
            if(array[index] > array[index+1]){
                temp = array[index];
                array[index] = array[index+1];
                array[index+1]=temp;
                swap=1;
            }}
        if(swap==0)
        return;
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
