#include <bits/stdc++.h>
using namespace std;




#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

int main()
{
    IOS  
     multiset<int> s;
    while (true)
    {
        int n, x;
        cin >> n;
        if (n == -1)
        {
            break;
        }
        cin >> x;
        if (n == 1)
        {
            s.insert(x);
        }
        else if (n == 2)
        {
            auto it = s.find(x);
            if (it != s.end())
            {
                s.erase(it);
            }
        }

        else if (n == 3)
        {
            auto it = s.find(x);
            if (it != s.end())
            {
                int index = distance(s.begin(), it);
                cout << index + 1 << "\n";
            }

            else
            {
                cout << "-1"
                     << "\n";
            }
        }
        else if (n == 4)
        {
            if (x <= 0 || x > s.size())
            {
                cout << "-1"
                     << "\n";
            }

            else
            {
                auto it = s.begin();
                x--;
                advance(it, x);
                cout << *it << "\n";
            }
        }
    }
    return 0;
}
