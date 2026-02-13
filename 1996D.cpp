/*
    Date : 9th Feb 2026
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
    ll n, x;
    cin >> n >> x;

    ll ans = 0;

    for(ll a = 1; a <= min(x - 2, (n - 1) / 2); a++)
    {
        for(ll b = 1; b <= min((n - a) / (a + 1), x - a - 1); b++)
        {
            ans += min((n - a * b) / (a + b), x - a - b);
        }
    }

    cout << ans << '\n';
}

void optimised()
{
    ll n, x;
    cin >> n >> x;

    ll ans = 0;

    for(ll a = 1; a <= x - 2 && a <= (n - 1) / 2; a++) // a > b > c
    {
        for(ll b = 1; b <= (n - a) / (a + 1) && b <= x - a - 1 && a > b; b++)
        {
            ans += 6 * min({(n - a * b) / (a + b), x - a - b, b - 1});
        }
    }

    for(ll a = 1; a <= min((ll)sqrt(n + 1) - 1, (x - 1) / 2); a++) // a = b != c
    {
        ll temp = min((n - a * a) / (2 * a), x - 2 * a);
        if(temp >= a) temp--; // Removing a = b = c case
        ans += 3 * temp;
    }

    ans += min(x / 3, (ll)sqrt(n / 3.0)); // a = b = c

    cout << ans << '\n';
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    fastio();

    int t = 1;
    if(MULTI_TEST) cin >> t;

    while(t--) optimised();

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    cerr << "Runtime : " << elapsed.count() << " ms\n";
    return 0;
}

/*
    Condition 1 : a + b + c <= x
    Condition 2 : ab + bc + ca <= n
    Condition 3 : a, b, c > 0

    Fixing b = 1, c = 1 => highest possible value of a, which will be (n - 1) / 2

    Fixing c = 1 => ab + a + b <= n
    => (a + 1)(b + 1) <= n + 1
    => As a goes from 1 to (n - 1) / 2, b only goes to (n - a)/(a + 1) times.
    => So, if we loop for a and loop for b from (n - a)/(a + 1), then then the time complexity for this structure will be nlogn
       as the b doesn't completely go till a constant.
    => We can traverse through a & b in O(nlogn) and get c as min(x - a - b, (n - ab)/(a + b))

    ****Optimisation****
    The problem is symmetric with respect to a, b and c =>
    1. We can multiply the answer with 3! for problems where a != b != c and a > b > c - (A cases)
    2. We can multiply by 3! / 2! for cases where a = b != c - (B cases)
    In case a = b = c, we can seperate these cases out - (C)

    Time Complexity of optimised() as well as solve() is O(nlogn)

    Total Cases = 6A + 3B + C
*/
