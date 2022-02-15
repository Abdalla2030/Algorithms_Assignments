#include <iostream>
using namespace std;
//O(n) using  frequency array
int firstIndexRepeated(int *arr, int n)
{
    int maxNumber = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxNumber) {
            maxNumber = arr[i];
        }
    }
    // use frequency array
    int temp[maxNumber];
    // initialize array with zero
    for (int i = 0; i < maxNumber; i++){
        temp[i] = 0;
    }
    for (int i = 0; i < n; i++) {
           temp[arr[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (temp[arr[i]] > 1) {
            return i;
        }
    }

    return -1; // if no repeating element found
}
////////////////////////////////////////////
int main()
{

    int Numbers[] = { 5, 6, 3, 4, 3, 6, 4 };
    int Size = sizeof(Numbers) / sizeof(Numbers[0]);
    int index = firstIndexRepeated(Numbers,Size);
    if (index != -1) {
        cout << "The minimum index of the repeating element is " << index<<endl;
    }
    else {
        cout << "Invalid Input"<<endl;
    }

    return 0;
}
