#include<iostream>
using namespace std;

int main(){
	int *ptr_to_int;
	int value;
	value=10;
	ptr_to_int=&value;
	cout<<"*ptr_to_int\n"<<*ptr_to_int;
	cout<<"\n ptr_to_int"<<ptr_to_int;
	cout<<"\n &ptr"<<&ptr_to_int;
	cout<<"\n";
	
	int input;
	cout<<"Enter the size of the array:";
	cin>>input;
	int *ptr = (int *)malloc(sizeof(int)*input);
	  for (int i = 0; i < input; i++){
        ptr[i] = i + 1;
        
        
    }
        
    // Print the array
    for (int i = 0; i < input; i++)
        cout<<ptr[i];
    return 0;
}