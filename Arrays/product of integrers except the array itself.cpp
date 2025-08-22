#include<iostream>
#include<vector>
using namespace std; 

int main() {
    int numberOfElements;
    cout << "Enter the number of elements: ";
    cin >> numberOfElements;

    vector<int> nums(numberOfElements);
    cout << "Enter the elements: ";
    for (int i = 0; i < numberOfElements; i++) {
        cin >> nums[i];
    }

    vector<int> output(numberOfElements, 1);

    int prefix = 1;
    for (int i = 0; i < numberOfElements; i++) {
        output[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = numberOfElements - 1; i >= 0; i--) {
        output[i] *= suffix;
        suffix *= nums[i];
    }

    cout << "The product array is: ";
    for (int i = 0; i < numberOfElements; i++) {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}
