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

    ll a[n];
    ll b[n];

    ll ca[n];
    ll cb[n];

    set<ll> bcol;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>ca[i];
    }

    for(ll i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(ll i=0;i<n;i++)
    {
        cin>>cb[i];
        bcol.insert(cb[i]);
    }

    vector<multiset<ll>> adj(2 * n + 1);

    for(ll i = 0;i<n;i++)
    {
        adj[ca[i]].insert(a[i]);
        adj[cb[i]].insert(b[i]);
    }


    ll bef = -1;
    for(ll i=0;i<n;i++)
    {
        ll curcol = ca[i];

        if(bcol.find(curcol) != bcol.end())
        {
            auto it = adj[curcol].lower_bound(bef);
            if(it == adj[curcol].end())
            {
                cout <<"No"<<nl;
                return;
            }
            ll val = *it;
            bef = val;

            adj[curcol].erase(adj[curcol].find(val));
        }
        else
        {
            if(a[i] < bef)
            {
                cout <<"No"<<nl;
                return;
            }
            bef = a[i];
            // adj[curcol].erase(adj[curcol].find(a[i]));
        }
    }

    cout <<"Yes"<<nl;


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