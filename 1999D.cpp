/*
    Date : 10th Feb 2026
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
    string s, x;
    cin >> s >> x;

    ll i = 0, j = 0;
    while(i < (ll)s.size() && j < (ll)x.size())
    {
        if(s[i] == x[j] || s[i] == '?')
        {
            s[i] = x[j];
            j++;
        }
        i++;
    }

    for(ll i = 0; i < (ll)s.size(); i++) if(s[i] == '?') s[i] = 'a';

    if(j == (ll)x.size()) cout << "YES" << '\n' << s << '\n';
    else cout << "NO" << '\n';
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
