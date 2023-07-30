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
    ll n;
    cin>>n;

    ll a[n-1];

    for(ll i=0;i<n-1;i++)
    {
        cin>>a[i];
    }

    vl v;
    v.pb(a[0]);

    for(ll i=0;i<n-2;i++)
    {
        v.pb(a[i + 1] - a[i]);
    }

    ll freq[n + 1] = {0};

    ll extra = 0;
    ll cnt = 0;
    for(auto it : v)
    {
        if(it > n)
        {
            extra = it;
            cnt++;
        }
        else
        {
            freq[it]++;
        }
    }

    if(cnt > 1)
    {
        cout <<"NO"<<nl;
        return;
    }  

    ll l =0;
    for(ll i=1;i<=n;i++)
    {
        if(freq[i] == 1)
        {
            l++;
        }
    }
    if(l == n-1)
    {
        cout <<"YES"<<nl;
        return;
    }

    if(cnt == 0)
    {
        for(ll i=1;i<=n;i++)
        {
            if(freq[i] > 1)
            {
                extra = i;
                freq[i]--;
                break;
            }
        }
    }

    ll sum =0;
    ll count =0;
    for(ll i=1;i<=n;i++)
    {
        if(freq[i] > 1)
        {
            cout <<"NO"<<nl;
            return;
        }
        if(freq[i] == 0)
        {
            sum += i;
            count++;
        }
    }

    if(count > 2 || sum != extra)
    {
        cout <<"NO"<<nl;
    }
    else
    {
        cout <<"YES"<<nl;
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