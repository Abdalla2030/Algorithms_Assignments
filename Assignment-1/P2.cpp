#include <bits/stdc++.h>
using namespace std;



#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

#define N 10000000



int divideMiddle(int nums[], int start, int end, int pivot)
{
    while (start <= end)
    {
        while (nums[start] < pivot)
        {
            start++;
        }
        while (nums[end] > pivot)
        {
            end--;
        }
        if (start <= end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    return start;
}

void quickSort(int nums[], int start, int end)
{
    if (start < end)
    {
        int index = (start + end) / 2;
        int pivot = nums[index];
        int rightIndex = divideMiddle(nums, start, end, pivot);
        quickSort(nums, start, rightIndex - 1);
        quickSort(nums, rightIndex, end);
    }
}
long long n, k, m_w, m_z;
int arr[N];

int getrandom()
{
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    long long res = (m_z << 16) + m_w;
    return res % 100000000;
}

int main()
{
    IOS 
    int t;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--)
    {

        cin >> n >> k >> m_w >> m_z;
        for (int i = 0; i < n; ++i)
        {
            arr[i] = getrandom();
        }
        quickSort(arr, 0, n - 1);
      
        cout << arr[k - 1] << "\n";
    }

    return 0;
}
