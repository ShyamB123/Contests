#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e16
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

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    ll prod = 1;
    bool ok = false;
    for(ll i = 0;i<n;i++)
    {
        if(prod > inf/a[i])
        {
            ok = true;
            break;
        }
        prod *= a[i];
    }

    if(ok == true)
    {
        ll l = 0;
        while(l<n && a[l] == 1)
        {
            l++;
        }


        ll r = n - 1;
        while(r>=0 && a[r] == 1)
        {
            r--;
        }

        cout << l + 1<<" "<<r + 1<<nl;
        return;
    }

    int pre[n + 1] = {0};
    int suf[n + 1] = {0};

    for(int i=0;i<n;i++)
    {
        pre[i + 1] = pre[i] + a[i];        
    }

    for(int i = n- 1;i>=0;i--)
    {
        suf[i] = suf[i + 1] + a[i];
    }

    vii v;
    for(int i =0;i<n;i++)
    {
        if(a[i] != 1)
        {
            v.pb({a[i],i});
        }
    }

    ll ans = 0;
    int l = 0;
    int r = 0;
    for(int i =0;i<v.size();i++)
    {
        ll cur = 1;
        ll left = pre[v[i].S];
        for(int j =i;j<v.size();j++)
        {
            cur *= v[j].F;
            ll right = suf[v[j].S + 1];

            ll curans = cur + left + right;
            if(curans > ans)
            {
                ans = curans;
                l = v[i].S;
                r = v[j].S;
            }
        }
    }

    cout << l + 1<<" "<<r + 1<<nl;
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