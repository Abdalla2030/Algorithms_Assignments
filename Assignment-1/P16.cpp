// Abdalla Fadl
// 20190305
////////////////////////////////////////////////////
// O(n) complexity
#include <iostream>
#include <unordered_map>
using namespace std;
void rearrangeFunction(int *arr, int n){
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) != m.end())
        {
            int numberOfOccurrence = m[arr[i]];
            while (numberOfOccurrence--) {
                cout << arr[i] << " ";
            }
            // remove number from map
            m.erase(arr[i]);
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////
int main()
{
    int Numbers[] = {  5, 4, 5, 5, 3, 1, 2, 2, 4 };
    int Size = sizeof(Numbers)/sizeof(Numbers[0]);

    rearrangeFunction(Numbers, Size);

    return 0;
}
