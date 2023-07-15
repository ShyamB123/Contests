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
7 6
6
3 5
6 1
3 1
4 2
1 5
6 2
2
2 5
2
3 4
*/



void solve()
{
    ll h,w;
    cin>>w>>h;


    vll a;

    ll n;
    cin>>n;

    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        a.pb({x,y});
    }

    ll A,B;
    cin>>A;
    set<ll> xs,ys;
    map<ll,ll> xtoline;
    map<ll,ll> ytoline;


    for(ll i =0;i<A;i++)
    {
        ll x;
        cin>>x;

        xs.insert(x);
        xtoline[x] = i;
    }
    xs.insert(w + 1);
    xtoline[w + 1] = A;

    cin>>B;
    
    for(ll i =0;i<B;i++)
    {
        ll x;
        cin>>x;

        ys.insert(x);
        ytoline[x] = i;
    }

    ys.insert(h + 1);
    ytoline[h + 1] = B;

    vector<vi> adj(xs.size());

    for(ll i= 0;i<n;i++)
    {
        ll x = a[i].F;

        ll val = *xs.lower_bound(x);
        ll indx = xtoline[val];
        adj[indx].pb(i);
        // cout << x << " "<<val<<nl;
    }

    ll minans = inf;
    ll maxans = 0;

    map<ll,ll> par,m1;

    multiset<ll> temp,s1;

    for(ll i = 0;i<=A;i++)
    {
        
        for(auto j : adj[i])
        {
            ll y = a[j].S;

            ll val = *ys.lower_bound(y);
            ll indx = ytoline[val];

            par[indx]++;
            if(par[indx] > 1)
            {
                temp.erase(temp.find(par[indx] - 1));
                temp.insert(par[indx]);
            }
            else
            {
                temp.insert(par[indx]);
            }
            maxans = max(maxans,par[indx]);
        }
        if(temp.size() == B + 1)
        {
            minans = min(minans,*temp.begin());
        }
        else
        {
            minans = 0;
        }
        // temp = s1;
        // par = m1;

        temp.clear();
        par.clear();
    }

    cout <<minans<<" "<< maxans<<nl;

}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}