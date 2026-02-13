/*
    Date : 8th Feb 2026
    Revisist
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
    ll x;
    cin >> x;

    ll a = __builtin_popcountll(x), b = __builtin_popcountll(x + 1);

    if(a == 1 || b == 1) cout << -1 << '\n';
    else
    {
        ll temp = x, num = 0;
        string s;

        while(temp)
        {
            s.push_back('0' + (temp & 1));
            temp = temp >> 1;
        }
        reverse(s.begin(), s.end());

        ll n = s.size(), i = 0;

        for(i = 0; i < n - 1; i++)
        {
            if(s[i] == '1' && s[i + 1] == '0')
            {
                swap(s[i], s[i + 1]);
                break;
            }
        }

        for(i = 0; i < n; i++)
        {
            num = num << 1;
            num += (s[i] - '0');
        }
        cout << num << '\n';
    }
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
