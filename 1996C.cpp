/*
    Date : 8th Feb 2026
    Revisit
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
    ll n, q;
    cin >> n >> q;

    string x, y;
    cin >> x >> y;

    vector<vector<ll>> prefx(n, vector<ll>(26, 0)), prefy(n, vector<ll>(26, 0));
    prefx[0][x[0] - 'a']++, prefy[0][y[0] - 'a']++;
    for(ll i = 1; i < n; i++)
    {
        prefx[i] = prefx[i - 1], prefy[i] = prefy[i - 1];
        prefx[i][x[i] - 'a']++, prefy[i][y[i] - 'a']++;
    }

    for(ll t = 0; t < q; t++)
    {
        ll l, r;
        cin >> l >> r;

        l--, r--;

        ll ans = 0;
        for(ll i = 0; i < 26; i++)
        {
            ll xx = prefx[r][i] - prefx[l][i] + ('a' + i == x[l]);
            ll yy = prefy[r][i] - prefy[l][i] + ('a' + i == y[l]);

            ans += abs(xx - yy);
        }

        cout << (ans >> 1) << '\n';
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
