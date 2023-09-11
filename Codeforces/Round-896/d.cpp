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

bool ok = false;
ll n;
const ll N = 2e5 + 1;
vector<bool> visited(N + 1,false);

void dfs(ll src,vector<set<ll>> &adj,ll start)
{
    visited[src] = true;

    for(auto it : adj[src])
    {
        if(visited[it] == true && it == start)
        {
            ok = true;
        }
        if(visited[it] == false)
        {
            dfs(it,adj,start);
        }
    }
}


void solve()
{
    cin>>n;

    ll a[n];

    ll sum = 0;
    for(ll i = 0;i<n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }

    if(sum % n != 0)
    {
        cout << "No"<<nl;
        return;
    }

    ll tar = sum/n;


    ll twopower[60];

    ll p = 1;
    set<ll> s;
    for(ll i = 0;i<60;i++)
    {
        twopower[i] = p;
        s.insert(twopower[i]);
        p*= 2;
    }
    vector<set<ll>> need(60);
    vector<set<ll>> give(60);
    for(ll i =0;i<n;i++)
    {
        visited[i] = false; 
    }

    for(ll i =0;i<n;i++)
    {
        ll dif = abs(a[i] - tar);

        if(dif != 0)
        {
            for(ll j = 0;j<60;j++)
            {
                ll get = twopower[j];
                ll giv = a[i] + get - tar;

                if(giv > 0 && s.find(giv) != s.end())
                {
                    need[j].insert(i);
                    // dbg((ll)log2(giv));
                    give[(ll)(log2(giv))].insert(i);
                }
            }
        }
        else
        {
            visited[i] = true;
        }
    }
    // dbg(give);
    // dbg(need);

    vector<set<ll>> adj(n + 1);
    for(ll j = 0;j<60;j++)
    {
        if(need[j].size() != give[j].size())
        {
            cout << "No"<<nl;
            return;
        }

        vi x;
        vi y;

        for(auto it : need[j])
        {
            x.pb(it);
        }
        for(auto it : give[j])
        {
            y.pb(it);
        }
        
        for(int i =0;i<x.size();i++)
        {
            adj[y[i]].insert(x[i]);
        }
    }

    // dbg(adj);


    // ok = false;
    for(ll i =0 ;i<n;i++)
    {
        if(visited[i] == false)
        {

            // dbg(reachable);
            
            ok = false;
            dfs(i,adj,i);

            if(ok == false)
            {
                cout <<"No"<<nl;
                return;
            }
        }
    }

    ok = true;

    for(ll i= 0;i<n;i++)
    {
        if(visited[i] == false)
        {
            ok = false;
        }
    }

    if(ok)
    {
        cout << "Yes"<<nl;
    }
    else
    {
        cout <<"No"<<nl;
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