/*
    Date : 13th Feb 2026
    Brute force Solution
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

void solve()
{
    ll n, d, k;
    cin >> n >> d >> k;

    vector<pair<ll, ll>> interval(k);
    for(ll i = 0; i < k; i++)
    {
        cin >> interval[i].first >> interval[i].second;
        interval[i].first--, interval[i].second--;
    }

    vector<ll> overlap(n - d + 1, 0);
    for(ll i = 0; i <= n - d; i++)
    {
        for(ll j = 0; j < k; j++)
        {
            if(!(interval[j].second < i || interval[j].first > i + d - 1)) overlap[i]++;
        }
    }

    ll min_day = 0, max_day = 0;
    for(ll i = 1; i <= n - d; i++)
    {
        if(overlap[i] < overlap[min_day]) min_day = i;
        if(overlap[i] > overlap[max_day]) max_day = i;
    }

    cout << 1 + max_day << ' ' << 1 + min_day << '\n';
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
