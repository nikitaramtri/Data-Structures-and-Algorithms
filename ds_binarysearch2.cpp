//
//  ds_binarysearch2.cpp
//  ds
//
//  Created by Radhika on 09/09/17.
//  Copyright © 2017 Nikita. All rights reserved.
//

#include<iostream> 
using namespace std;

int search(int array[], int lower_bound, int upper_bound, int element){
    int mid, lb = lower_bound, ub = upper_bound;
    
    while(lb <= ub){
        mid = (lb + ub)/2;
        
        if(array[mid] == element)
            return mid;
        else if(array[mid] > element)
            return search(array, lower_bound, mid - 1, element );
        else
            return search(array, mid + 1, upper_bound, element );
        
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
    
    int result = search(array,0, size-1, element);
    
    if(result == -1)
        cout<<element<<" not found "<<endl;
    else
        cout<<element<<" is present at index "<<result<<endl;
    
    return 0;
}
