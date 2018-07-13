//
//  ds_linearsearch.cpp
//  ds
//
//  Created by Radhika on 09/09/17.


#include<iostream>
using namespace std;

int search(int array[], int size, int element){
    int index;
    
    for(index = 0; index < size; index ++)
        if(array[index]==element)
            return 1;
    
    
    return 0;
}


int main(){
    int index, size, array[100], element;
    
    cout<<"Enter array size(<100)"<<endl;
    cin>>size;
    
    cout<<"Enter array elements: "<<endl;
    for(index = 0; index < size; index ++)
        cin>>array[index];
    
    cout<<"Enter element to be saerch"<<endl;
    cin>>element;
    
    int result = search(array, size, element);
    
    if(result == 1)
        cout<<element<<" found "<<endl;
    else
        cout<<element<<" not found"<<endl;
    
    return 0;
}
