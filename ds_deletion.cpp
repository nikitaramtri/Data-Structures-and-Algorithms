//
//  ds_deletion.cpp
//  ds
//
//  Created by Radhika on 09/09/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include<iostream>
using namespace std;

void deletion(int array[], int &size, int position){
    int index;
    
    for(index = position; index < size-1; index ++)
        array[index] = array[index+1];
   
    size --;
}

void display(int array[], int size){
    int index;
    
    cout<<"Array: "<<endl;
    for(index = 0; index < size; index ++)
        cout<<array[index]<<endl;
}

 int main(){
 int index, position, size, array[100];
 
 cout<<"Enter array size(<100)"<<endl;
 cin>>size;
 
 cout<<"Enter array elements: "<<endl;
 for(index = 0; index < size; index ++)
 cin>>array[index];
 
 cout<<"Enter position at which the array element is to be deleted"<<endl;
 cin>>position;
 
     deletion(array, size, position);
     display(array, size);
 
 return 0;
 }
