//
//  ds_binarysearch1.cpp
//  ds
//
//  Created by Radhika on 09/09/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include<iostream>
using namespace std;

int search(int array[], int size, int element){
    int mid, lb = 0, ub = size - 1;
    
    while(lb <= ub){
        mid = (lb + ub)/2;
        
        if(array[mid] == element)
            return mid;
        else if(array[mid] > element)
            ub = mid - 1;
        else
            lb = mid + 1;
    }
        return -1;
}


int main(){
    int index, size, array[100], element;
    
    cout<<"Enter array size(<100)"<<endl;
    cin>>size;
    
    cout<<"Enter array elements: "<<endl;
    for(index = 0; index < size; index ++)
        cin>>array[index];
    
    cout<<"Enter element to be searched"<<endl;
    cin>>element;
    
    int result = search(array, size, element);
    
    if(result == -1)
        cout<<element<<" not found "<<endl;
    else
        cout<<element<<" is present at index "<<result<<endl;
    
    return 0;
}
