#include <bits/stdc++.h>
using namespace std;

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    IOS 

    int q, n, x;
    cin >> q;
    multiset<int> ls;
    while (q--)
    {
        cin >> x >> n;
        if (x == 1)
        {
            ls.insert(n);
        }
        else
        {
            auto it = ls.find(n);
            if (it == ls.end())
            {
                cout << "-1\n";
            }

            else
            {
                int index = distance(ls.begin(), it);
                cout << index+1 << "\n";
            }
        }
    }
    return 0;
}
