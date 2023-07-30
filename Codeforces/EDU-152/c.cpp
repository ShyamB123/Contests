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
1
6 4
000111
3 4
2 5
1 6
1 1
*/



void solve()
{
    int n,m;
    cin>>n>>m;

    string a;
    cin>>a;

    vi pre(n,0);
    for(int i=0;i<n;i++)
    {
        if(i - 1>=0)
        {
            pre[i] =pre[i-1];
        }

        if(a[i] == '1')
        {
            pre[i]++;
        }
    }
    // dbg(pre);
    vii v;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;

        v.pb({x,y});
    }

    vi left(n);
    vi right(n);
    left[0] = 0;

    for(int i=1;i<n;i++)
    {
        if(a[i-1] == '0')
        {
            left[i] = left[i-1];
        }
        else
        {
            left[i] = i;
        }
    }
    right[n-1] = n-1;

    for(int i =n-2;i>=0;i--)
    {
        if(a[i + 1] == '1')
        {
            right[i] = right[i + 1];
        }
        else
        {
            right[i] = i;
        }
    }
    // dbg(left);
    // dbg(right);
    set<pair<int,int>> s;

    bool ok = false;
    int ans =0;

    for(int i =0;i<m;i++)
    {
        int x = v[i].F;
        int y = v[i].S;
        int val = pre[y];
        int l = 0;
        if(x != 0)
        {
            val -= pre[x-1];
            l = pre[x-1];
        }

        int r;
        if(y - val >= 0)
        {
            r = pre[y - val];
        }
        else
        {
            r = 0;
        }
        if(r == l)
        {
            ok = true;
            continue;
        }

        x = left[x];
        y = right[y];

        
        s.insert({x,y});
        
    }
    // dbg(s);

    if(ok)
    {
        ans++;
    }

    ans += s.size();

    cout << ans<<nl;

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