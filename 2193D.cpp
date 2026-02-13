/*
    Date : 13th Feb 2026
    Revisit and Explore 2 pointer solution
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
using ll = long long;
const ll MOD = 1e9 + 7;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r)
{
   return uniform_int_distribution<ll>(l, r)(rng);
}

template <typename T>
using ordered_multiset = tree<
    T,
    null_type,
    less_equal<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

bool MULTI_TEST = true;

void brute()
{
    ll n;
    cin >> n;

    vector<ll> a(n, 0), b(n, 0);

    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];

    ll x = 1, ans = 0, maxx = *max_element(a.begin(), a.end());
    while(x <= maxx + 1)
    {
        ll i = 0, j = 0;
        for(i = 0; i < n; i++)
        {
            ll count = 0;
            if(j == n) break;
            while(j < n && count < b[i])
            {
                if(a[j++] >= x) count++;
            }
            if(count < b[i]) break;
        }

        ans = max(ans, i * (x++));
    }

    cout << ans << '\n';
}

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n, 0), b(n, 0);

    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end());

    vector<ll> pf(n, b[0]);
    for(ll i = 1; i < n; i++) pf[i] = pf[i - 1] + b[i];

    ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        ll greater_elements = n - i;
        ll level = upper_bound(pf.begin(), pf.end(), greater_elements) - pf.begin();
        ans = max(ans, level * a[i]);
    }

    cout << ans << '\n';
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    fastio();

    int t = 1;
    if(MULTI_TEST) cin >> t;

    while(t--) solve();

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    cerr << "Runtime : " << elapsed.count() << " ms\n";
    return 0;
}
