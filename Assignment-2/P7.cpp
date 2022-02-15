#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>


using namespace std;
const int maxn = 100005;

int arr[maxn], freq[maxn], freq1[maxn], freq2[maxn];
long long  value[maxn];
vector<int> v;

struct query {
    int l, r, id, k;
};
query qu[maxn];

bool cmp(query a, query b) {
    return a.k < b.k || (a.k == b.k&&a.r < b.r);
}

void update(int pos, int val) {
    freq1[freq[pos]]--;
    freq[pos] += val;
    freq1[freq[pos]]++;
}

int main() {
    int n, i, j, k, q, l, r;
    cin>>n;
    memset(freq, 0, sizeof(freq));
    memset(value, 0, sizeof(value));
    int size = sqrt(n) + 1;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
        if (freq[arr[i]] == size) v.push_back(arr[i]);
    }
    cin >> q;
    for (i = 1; i <= q; i++) {
        cin >> qu[i].l >> qu[i].r;
        qu[i].id = i; qu[i].k = qu[i].l / size;
    }
    sort(qu + 1, qu + q + 1, cmp);
    l = 1; r = 0;
    memset(freq, 0, sizeof(freq)); memset(freq1, 0, sizeof(freq1));
    freq1[0] = n;
    for (i = 1; i <= q; i++) {
        while (l < qu[i].l) update(arr[l], -1), l++;
        while (l > qu[i].l) l--, update(arr[l], 1);
        while (r > qu[i].r) update(arr[r], -1), r--;
        while (r < qu[i].r) r++, update(arr[r], 1);
        priority_queue<int, vector<int>, greater<> > pq;
        memcpy(freq2, freq1, sizeof(int) * (size + 5));
        value[qu[i].id] = 0;
        for (j = 0; j < v.size(); j++) if (freq[v[j]] >= size) pq.push(freq[v[j]]);
        int last = 0;
        for (j = 1; j < size; j++) {
            if (freq2[j] > 0) {
                if (last) {
                    freq2[j]--; value[qu[i].id] += (long long )(last + j);
                    if (last + j < size) freq2[last + j]++; else pq.push(last + j);
                    last = 0;
                }
                if (freq2[j] % 2 == 1) freq2[j]--, last = j;
                value[qu[i].id] += freq2[j] * j;
                if (2 * j >= size)
                    for (k = 1; k <= freq2[j] / 2; k++) pq.push(j * 2);
                else freq2[j * 2] += freq2[j] / 2;
            }
        }
        if (last) pq.push(last);
        while (pq.size() > 1) {
            int b = pq.top(); pq.pop();
            int c = pq.top(); pq.pop();
            value[qu[i].id] += (long long )(b + c);
            pq.push(b + c);
        }
    }
    for (i = 1; i <= q; i++) cout << value[i] << endl;
    return 0;
}
