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
    ll n,k;
    cin>>n>>k;

    vll a(n);
    vl dp(n,inf);
    vl couldbe(n,0);
    priority_queue<pair<ll,ll>> pq;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].F;
        a[i].S = i;
    }

    for(ll i =0;i<k;i++)
    {
        ll x;
        cin>>x;
        x--;
        a[x].F = 0;
    }

    for(ll i=0;i<n;i++)
    {
        dp[a[i].S] = a[i].F;
        pq.push({-a[i].F,a[i].S});
    }
   

    vector<set<ll>> v(n);
    vector<set<ll>> m(n);
    for(ll i=0;i<n;i++)
    {
        ll el;
        cin>>el;

        for(ll j =0;j<el;j++)
        {
            ll x;
            cin>>x;
            x--;
            v[i].insert(x);
            m[x].insert(i);
        }
    }
    // dbg(m);

    // dbg(pq);

    while(!pq.empty())
    {
        auto el = pq.top();
        pq.pop();
        ll cost = -el.F;
        ll src = el.S;

        if(dp[src] < cost)
        {
            continue;
        }
        for(auto it : m[src])
        {
            v[it].erase(src);
            couldbe[it] += cost;
            if(v[it].size() == 0)
            {
                if(couldbe[it] < dp[it])
                {
                    dp[it] = couldbe[it];
                    pq.push({-dp[it],it});
                }
            }
        }
    }

    for(ll i =0;i<n;i++)
    {
        cout << dp[i]<< " ";
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