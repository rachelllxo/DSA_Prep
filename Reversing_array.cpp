// Given an array, reverse its elements such that the first becomes last, etc.
#include <iostream>
#include <vector>
#include <algorithm>

void vector_array(std::vector<int>& array) { 
    int left_pointer = 0;
    int right_pointer = array.size() - 1;

    while (left_pointer < right_pointer) { 
        std::swap(array[left_pointer], array[right_pointer]);
        left_pointer++;
        right_pointer--;
    }
}

int main() {
    int input_size;
    std::cout << "Enter the number of elements of the array: ";
    std::cin >> input_size;

    std::vector<int> input_value(input_size); 

    std::cout << "Enter the elements: ";
    for (int count = 0; count < input_size; count++) {
        std::cin >> input_value[count];
    }

    vector_array(input_value); 

    std::cout << "The reversed array is: ";
    for (int count : input_value) {
        std::cout << count << " "; 
    }

    return 0;
}
