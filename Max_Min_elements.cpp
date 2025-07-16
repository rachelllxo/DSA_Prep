//finding maximum and minimum elements in an array
#include<iostream>
#include<vector>

int main() {
std::vector<int>vector={5,3,10,15,2};
int max_element=vector[0];
int min_element=vector[0];
for(int count=0;count<vector.size();count++){
if (max_element<vector[count]){
	max_element=vector[count];
}
if(min_element>vector[count]){
	min_element=vector[count];
}
}
std::cout<<"Maximum element: "<<max_element;
std::cout<<"Minimum element: "<<min_element;	
}
