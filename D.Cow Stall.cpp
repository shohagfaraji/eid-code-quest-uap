#include <bits/stdc++.h>
#define mx 100001
using namespace std;

char f;
string s;
vector<int> t(mx * 3);

void init(int n, int b, int e) {
    if (b == e) {
        t[n] = (s[b] == f);
        return;
    }
    int l, r, md;
    l = n << 1;
    r = l + 1;
    md = b + ((e - b) >> 1);
    init(l, b, md);
    init(r, md + 1, e);
    t[n] = t[l] + t[r];
}

int query(int n, int b, int e, int i, int j) {
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j)
        return t[n];
    int l, r, md;
    l = n << 1;
    r = l + 1;
    md = b + ((e - b) >> 1);
    int p1, p2;
    p1 = query(l, b, md, i, j);
    p2 = query(r, md + 1, e, i, j);
    return p1 + p2;
}

void update(int n, int b, int e, int i, char c) {
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        s[i] = c;
        t[n] = (s[i] == f);
        return;
    }
    int l, r, md;
    l = n << 1;
    r = l + 1;
    md = b + ((e - b) >> 1);
    update(l, b, md, i, c);
    update(r, md + 1, e, i, c);
    t[n] = t[l] + t[r];
}

void Solve() {
    int n, q;
    cin >> n >> q >> f >> s;
    s = "0" + s;
    init(1, 1, n);
    int x, i, l, r;
    char c;
    while (q--) {
        cin >> x;
        if (x) {
            cin >> i >> c;
            update(1, 1, n, i, c);
        } else {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ts = 1;
    cin >> ts;
    while (ts--) {
        Solve();
        cout << '\n';
    }

    return 0;
}