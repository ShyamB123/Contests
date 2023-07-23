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
//----------------------------------------------------------------------------------------


bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return p1.second < p2.second;
}

/*

*/



void solve()
{
    ll h,w,n;
    cin>>h>>w>>n;

    vector<vl> a(h,vl(w,1));

    for(ll i=0;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        a[u][v] = 0;
    }

    vector<vl> pre(h +1,vl(w + 1,0));
    
    for(ll i=1;i<=h;i++)
    {
        for(ll j =1;j<=w;j++)
        {
            pre[i][j] = pre[i][j-1] + a[i-1][j-1];
        }
    }

    for(ll j =1;j<=w;j++)
    {
        for(ll i =1;i<=h;i++)
        {
            pre[i][j] += pre[i-1][j];
        }
    }
    // dbg(pre);

    ll ans =0;

    for(ll i=0;i<h;i++)
    {
        for(ll j =0;j<w;j++)
        {
            
            if(a[i][j] == 1)
            {
                ll cur =0;
                ll s = 1;
                ll e = min(h-i,w-j);

                while(s <= e)
                {
                    ll mid = (s + e)/2;
                    ll x = i + mid -1;
                    ll y = j + mid -1;
                    ll should = mid*mid;

                    ll val = pre[x + 1][y + 1] + pre[i][j] - pre[i][y + 1] - pre[x + 1][j];
                    if(val == should)
                    {
                        cur = mid;
                        s = mid +1;
                    }
                    else
                    {
                        e = mid-1;
                    }
                }
                ans += cur;
            }
        }
    }

    cout << ans<<nl;

}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}