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

void solve()
{
    ll l, r;
    cin >> l >> r;

    ll temp = l, xl = 0, xr = 0, ans = 0;
    while(temp > 0)
    {
        temp /= 3;
        xl++;
    } // O(log_3(l))

    temp = r;
    while(temp > 0)
    {
        temp /= 3;
        xr++;
    } // O(log_3(r))

    ll fact = pow(3, xl); // O(log_2(log_3(l)))
    ans += (fact - l) * xl;

    for(ll i = xl + 1; i < xr; i++) // O(log_3(r / l))
    {
        ans += 2 * fact * i;
        fact = fact * 3;
    }

    ans += (r - fact + 1) * xr;

    cout << ans + xl << '\n';
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

// Total Time Complexity : O(2 * log_3(r) + log_2(log_3(l))) for exh query
