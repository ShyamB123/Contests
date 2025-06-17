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

    vl a(n);
    vl b(n);

    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i = 0;i<n;i++)
    {
        cin>>b[i];
    }

    vll ans;
    for(int i = 0;i<n;i++)
    {
        ll topnum = i * 2 + 1;
        ll botnum = i * 2 + 2;

        {
        // check if topnum is in a 
            bool ok = false;
            for(int j =0;j<n;j++)
            {
                if(a[j] == topnum)
                {
                    ok = true;
                }
            }
            if(ok == false)
            {
                for(int j =0;j<n;j++)
                {
                    if(b[j] == topnum)
                    {
                        ans.pb({3,j});
                        swap(a[j],b[j]);
                    }
                }
            }
            // send this to the ith place

            int indx = 0;
            for(int j =0;j<n;j++)
            {
                if(a[j] == topnum)
                {
                    indx = j;
                }
            }

            for(int j = indx - 1;j>=i;j--)
            {
                swap(a[j],a[j + 1]);
                ans.pb({1,j});
            }
        }
        {
        // check if topnum is in a 
            bool ok = false;
            for(int j =0;j<n;j++)
            {
                if(b[j] == botnum)
                {
                    ok = true;
                }
            }
            if(ok == false)
            {
                for(int j =0;j<n;j++)
                {
                    if(a[j] == botnum)
                    {
                        ans.pb({3,j});
                        swap(a[j],b[j]);
                    }
                }
            }
            // send this to the ith place

            int indx = 0;
            for(int j =0;j<n;j++)
            {
                if(b[j] == botnum)
                {
                    indx = j;
                }
            }

            for(int j = indx - 1;j>=i;j--)
            {
                swap(b[j],b[j + 1]);
                ans.pb({2,j});
            }
        }
    }

    cout << ans.size() << nl;

    for(auto [u,v] : ans)
    {
        cout << u << " " << v + 1<< nl;
    }
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