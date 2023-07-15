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

ld cal_dist(ll x1,ll y1,ll x2,ll y2)
{
    ld ans = sqrt((x1 - x2) *(x1 - x2) + (y1 - y2) *(y1 - y2));

    return ans;
}

const int N = 2001;
vector<vi> adj(N);

vector<bool> visited(N,false);

void dfs(int src)
{
    visited[src] = true;

    for(auto it : adj[src])
    {
        if(visited[it] == false)
        {
            dfs(it);
        }
    }
}


void solve()
{
    int n,d;
    cin>>n>>d;

    vii a;

    

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;

        a.pb({x,y});
    }

    for(int i=0;i<n;i++)
    {
        for(int j =i + 1;j<n;j++)
        {
            double dist = cal_dist(a[i].F,a[i].S,a[j].F,a[j].S);

            if(dist <= d)
            {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    dfs(0);

    for(int i =0;i<n;i++)
    {
        if(visited[i] == true)
        {
            cout << "Yes"<<nl;
        }
        else
        {
            cout <<"No"<<nl;
        }
    }



}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}