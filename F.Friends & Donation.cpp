#include <bits/stdc++.h>
#define ll long long
#define full(x) x.begin(), x.end()
using namespace std;

bool ck(vector<ll>& a, ll x, ll m) {
    ll ttl = 0, n = a.size();
    for (int i = 0; i < n; i++) {
        if ((a[i] - x) > 0) {
            ttl += (a[i] - x);
        }
    }
    return ttl >= m;
}

void Solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    ll mx = -1, s = 0;
    for (auto& i : a) {
        cin >> i;
        s += i;
        mx = max(mx, i);
    }
    if (s < m) {
        cout << -1;
    } else if (s == m) {
        cout << 0;
    } else {
        sort(full(a));
        ll l = 0, r = mx, md;
        while (r - l > 1) {
            md = l + ((r - l) >> 1);
            if (ck(a, md, m))
                l = md;
            else
                r = md - 1;
        }
        if (ck(a, r, m))
            cout << r;
        else if (ck(a, l, m))
            cout << l;
        else
            cout << -1;
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
