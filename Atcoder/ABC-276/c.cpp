#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e9
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
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/



void solve()
{
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vi v;

    int indx;
    int val = 0;
    for(int i=n-1;i>=0;i--)
    {
        indx = i;
        if(i == 0)
        {
            v.pb(a[0]);
            break;
        }
        if(i - 1 >= 0 && a[i] > a[i - 1])
        {
            v.pb(a[i]);
        }
        else
        {
            v.pb(a[i]);
            v.pb(a[i- 1]);
            indx = i-1;
            val = a[i-1];
            break;
        }
    }

    sort(all(v));
    // dbg(indx);
    // dbg(a[indx]);

    // dbg(v);

    vi rest;

    int ign;
    for(int i =0;i<v.size() -1 ;i++)
    {
        if(v[i + 1] == val)
        {
            rest.pb(v[i]);
            ign = v[i];
            break;

        }
    }

    for(int i =v.size() -1;i>=0;i--)
    {
        if(v[i] != ign)
        {
            rest.pb(v[i]);
        }
    }

    for(int i = indx;i<n;i++)
    {
        a[i] = rest[i - indx];
    }

    // dbg(rest);

    for(int i=0;i<n;i++)
    {
        cout << a[i]<<" ";
    }
    cout <<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}