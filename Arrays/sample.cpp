#include<iostream>

using namespace std;

int main(){
	int number[5];
	cout<<"initial values before assignment: ";
	for (int count=0; count<5; count++){
		cout<<number[count];
		cout<<"\n";
	}
	
	cout<<"assigning values: ";
	number[0]=23;
	number[1]=30;
	number[2]=5;
	number[3]=30;
	number[4]=5;
	
	for (int count=0; count<5; count++){
		cout<<number[count];
		cout<<"\n";
	}
	cout<<"created using malloc: ";
	int *pointer_arr;
	pointer_arr=(int*)malloc(sizeof(int)*5);
	for (int count=0; count<5; count++){
		cout<<pointer_arr[count];
		cout<<"\n";
	}
	cout<<"created using calloc: ";
	int *pointer_arr_c;
	pointer_arr_c=(int*)calloc(sizeof(int),5);
	for (int count=0; count<5; count++){
		cout<<pointer_arr_c[count];
		cout<<"\n";
	}
	free(pointer_arr_c);
	free(pointer_arr);
}