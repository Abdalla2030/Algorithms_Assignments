//Abdalla Fadl
// 20190305
#include <iostream>
#include <unordered_map>
using namespace std;
/*
// O(n^2)
void findPairs(int *arr, int n, int sum){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i] + arr[j] == sum){
                cout<<"Pair found ("<<arr[i]<<"," <<arr[j]<<")"<<endl;
                return ;
            }
        }
    }
    cout<<"Pair not found"<<endl;
}
//////////////////////////////////////
int main()
{
    int numbers[] = {8, 7, 2, 5, 3, 1};
    int target = 10;
    int Size = sizeof(numbers)/sizeof(numbers[0]);
    findPairs(numbers,Size,target);
    return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//O(n) using map
void findPairs(int *arr, int n, int sum)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        // m[sum - arr[i])]+arr[i]= sum
        if (m.find(sum-arr[i]) != m.end())
        {
            cout << "Pair found ("<< arr[m[sum - m[i]]]<<","<<arr[i]<<")"<<endl;
            return;
        }
        // we store in map index of arr[i]
       m[arr[i]] = i;
    }
    cout << "Pair not found"<<endl;
}
////////////////////////////////////////////
int main()
{
    int numbers[] = {8, 7, 2, 5, 3, 1};
    int target = 10;
    int Size = sizeof(numbers)/sizeof(numbers[0]);
    findPairs(numbers,Size,target);
    return 0;
}
