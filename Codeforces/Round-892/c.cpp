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

const int MAXN = 1e6;
vi primes;
int arr[MAXN + 1] ={0};
void prime_sieve(int n)
{
    
    int len = n;
    arr[0] = arr[1] = 0;
    arr[2] = 1;

    for (ll i = 3; i <= len; i += 2)
    {
        arr[i] = 1;
    }

    for (ll i = 3; i <= len; i += 2)
    {
        if (arr[i] == 0)
            continue;

        for (ll j = i * i; j <= len; j += i)
        {
            arr[j] = 0;
        }
    }
    for(int i =0;i<=len;i++)
    {
        if(arr[i] == 1)
        {
            primes.pb(i);
        }
    }
}

void solve()
{
    int n;
    cin>>n;

    vi ans;
    ans.pb(1);

    for(int i=0;i<=n;i++)
    {
        arr[i] = 1;
    }
    
    

    for (ll i = 2; i <= n; i++)
    {
        if (arr[i] == 0)
            continue;
        
        ans.pb(i);
        for (ll j = 2 * i; j <= n; j *=2)
        {
            arr[j] = 0;
            ans.pb(j);
        }
    }

    for(auto it : ans)
    {
        cout << it << " "; 
    }
    cout <<nl;

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