#include <bits/stdc++.h>
#include<iostream>

using namespace std;

int getMaxNumberOfThieves(char arr[], int n, int k)
{
    int police = -1;
    int thief = -1;
    int numberOfThieves = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'P')
        {
            police = i;
            break;
        }
    }


    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'T')
        {
            thief = i;
            break;
        }
    }

    if (police == -1 || thief == -1)
        return 0;

    while (police < n && thief < n)
    {
        if (abs(police - thief) <= k)
        {

            police++;
            while (police < n && arr[police] != 'P')
            {
                police++;
            }

            thief++;
            while (thief < n && arr[thief] != 'T')
            {
                thief++;
            }

            numberOfThieves++;
        }
        else if (thief < police)
        {
            thief++;
            while (thief < n && arr[thief] != 'T')
            {
                thief++;
            }
        }
        else
        {
            police++;
            while (police < n && arr[police] != 'P')
            {
                police++;
            }
        }
    }

    return numberOfThieves;
}


int main()
{
    int K;
    int N;
    cout<<"Please enter number of elements : ";
    cin>>N;
    char arr[N];
    cout<<"Please enter number of units that the thief is away from the police : ";
    cin>>K;
    for(int i =0; i<N; i++)
    {
        cout<<"Please enter the elements :";
        cin>>arr[i];

    }
    cout << "\n\tMaximum number of thieves caught are : "<< getMaxNumberOfThieves(arr, N, K) <<"\n\n";

    return 0;
}


