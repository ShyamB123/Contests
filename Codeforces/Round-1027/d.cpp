#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e18
#define F first
#define S second
#define pb push_back
#define mp make_pair

#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int, int>>
#define vll vector<pair<ll, ll>>
#define all(a) a.begin(), a.end()
#define nl '\n'

using namespace std;

//----------------------DEBUGGER----------------------------------------------------------
#define dbg(x) cout << #x <<" "; _print(x); cout << endl;
 
void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(ld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}

 
template <class T> void _print(vector<vector<T>> v) {for(int j =0;j<v.size();j++){cout <<nl<<"[ "; for (T i : v[j]){_print(i); cout << " ";} cout << "]";};}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.F); cout << ","; _print(p.S); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T>void _print(vector<vector<vector<T>>> v){for(int k =0;k<v.size();k++){_print(v[k]);}}
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/



void solve()
{
    ll n;
    cin>>n;

    vll a(n);

    vl xs,ys;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i].F>>a[i].S;

        xs.pb(a[i].F);
        ys.pb(a[i].S);
    }

    sort(all(xs));
    sort(all(ys));

    ll ans = (xs[n - 1] - xs[0] + 1) * (ys[n - 1] - ys[0] + 1);

    if(n == 1)
    {
        cout << ans << nl;
        return;
    }

    if(xs[0] < xs[1])
    {
        // move the top most down smallest x
        ll area = (xs[n - 1] - xs[1] + 1) * (ys[n - 1] - ys[0] + 1);
        // dbg(area);

        if(area >= n)
        {
            ans = min(ans,area);
        }
        else
        {
            ans = min(ans,(xs[n - 1] - xs[1] + 1) * (ys[n - 1] - ys[0] + 1 + 1));
            ans = min(ans,(xs[n - 1] - xs[1] + 1 + 1) * (ys[n - 1] - ys[0] + 1));
        }
    }

    if(xs[n - 1] > xs[n - 2])
    {
        // move the top most down smallest x
        ll area = (xs[n - 2] - xs[0] + 1) * (ys[n - 1] - ys[0] + 1);
        // dbg(area);

        if(area >= n)
        {
            ans = min(ans,area);
        }
        else
        {
            ans = min(ans,(xs[n - 2] - xs[0] + 1) * (ys[n - 1] - ys[0] + 1 + 1));
            ans = min(ans,(xs[n - 2] - xs[0] + 1 + 1) * (ys[n - 1] - ys[0] + 1));
        }
    }

    swap(xs,ys);

    if(xs[0] < xs[1])
    {
        // move the top most down smallest x
        ll area = (xs[n - 1] - xs[1] + 1) * (ys[n - 1] - ys[0] + 1);
        // dbg(area);

        if(area >= n)
        {
            ans = min(ans,area);
        }
        else
        {
            ans = min(ans,(xs[n - 1] - xs[1] + 1) * (ys[n - 1] - ys[0] + 1 + 1));
            ans = min(ans,(xs[n - 1] - xs[1] + 1 + 1) * (ys[n - 1] - ys[0] + 1));
        }
    }

    if(xs[n - 1] > xs[n - 2])
    {
        // move the top most down smallest x
        ll area = (xs[n - 2] - xs[0] + 1) * (ys[n - 1] - ys[0] + 1);
        // dbg(area);

        if(area >= n)
        {
            ans = min(ans,area);
        }
        else
        {
            ans = min(ans,(xs[n - 2] - xs[0] + 1) * (ys[n - 1] - ys[0] + 1 + 1));
            ans = min(ans,(xs[n - 2] - xs[0] + 1 + 1) * (ys[n - 1] - ys[0] + 1));
        }
    }

    // if(a[n])
    swap(xs,ys);

    for(int i =0;i<n;i++)
    {
        if(a[i].F == xs[0] && a[i].S == ys[0] && xs[0] < xs[1] && ys[0] < ys[1])
        {
            ll area = (xs[n - 1] - xs[1] + 1) * (ys[n - 1] - ys[1] + 1);
            if(area >= n)
            {
                ans = min(ans,area);
            }
            else
            {
                ans = min(ans,(xs[n - 1] - xs[1] + 1) * (ys[n - 1] - ys[1] + 1 + 1));
                ans = min(ans,(xs[n - 1] - xs[1] + 1 + 1) * (ys[n - 1] - ys[1] + 1));
            }
        }
        if(a[i].F == xs[0] && a[i].S == ys[n - 1] && xs[0] < xs[1] && ys[n - 1] > ys[n - 2])
        {
            ll area = (xs[n - 1] - xs[1] + 1) * (ys[n - 2] - ys[0] + 1);
            if(area >= n)
            {
                ans = min(ans,area);
            }
            else
            {
                ans = min(ans,(xs[n - 1] - xs[1] + 1) * (ys[n - 2] - ys[0] + 1 + 1));
                ans = min(ans,(xs[n - 1] - xs[1] + 1 + 1) * (ys[n - 2] - ys[0] + 1));
            }
        }


        if(a[i].F == xs[n - 1] && a[i].S == ys[n - 1] && xs[n - 1] > xs[n - 2] && ys[n - 1] > ys[n - 2])
        {
            ll area = (xs[n - 2] - xs[0] + 1) * (ys[n - 2] - ys[0] + 1);
            if(area >= n)
            {
                ans = min(ans,area);
            }
            else
            {
                ans = min(ans,(xs[n - 2] - xs[0] + 1) * (ys[n - 2] - ys[0] + 1 + 1));
                ans = min(ans,(xs[n - 2] - xs[0] + 1 + 1) * (ys[n - 2] - ys[0] + 1));
            }
        }
        if(a[i].F == xs[n - 1] && a[i].S == ys[0] && xs[n - 1] > xs[n - 2] && ys[0] < ys[1])
        {
            ll area = (xs[n - 2] - xs[0] + 1) * (ys[n - 1] - ys[1] + 1);
            if(area >= n)
            {
                ans = min(ans,area);
            }
            else
            {
                ans = min(ans,(xs[n - 2] - xs[0] + 1) * (ys[n - 1] - ys[1] + 1 + 1));
                ans = min(ans,(xs[n - 2] - xs[0] + 1 + 1) * (ys[n - 1] - ys[1] + 1));
            }
        }
    }

    cout << ans << nl;

}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    ll t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}