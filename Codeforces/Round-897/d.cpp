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

const int N = 1e5 + 1;

vector<set<int>> adj(N);
vector<bool> visited(N,false);
bool ok = true;
    int k;


void dfs(int src)
{
    visited[src] = true;

    // auto it = adj[src];

    for(auto it : adj[src])
    {
        if(visited[it] == true)
        {
            if(it == src)
            {
                if(k != 1)
                {
                    ok = false;
                }
            }
            else
            {
                int len = 0;
                int x = it;
                while(x != src)
                {
                    len++;
                    x = *adj[x].begin();
                }
                len++;
                if(len != k)
                {
                    ok = false;
                }
            }
        }
        else
        {
            dfs(it);
        }
    }
    
}

void solve()
{
    int n;
    cin>>n;

    cin>>k;

    for(int i = 0;i<=n;i++)
    {
        adj[i].clear();
    }

    int a[n];
    int indeg[n + 1] = {0};
    // vector<vi> indeg(n + 1);

    for(int i =0;i<n;i++)
    {
        cin>>a[i];
        adj[i + 1].insert(a[i]);

        indeg[a[i]]++;
    }    


    if(k == 1)
    {
        for(int i =0;i<n;i++)
        {
            if(a[i] != i + 1)
            {
                cout <<"No"<<nl;
                return;
            }
        }
        cout <<"Yes"<<nl;
        return;
    }

    queue<int> q;

    for(int i =1;i<=n;i++)
    {
        if(indeg[i] == 0)
        {
            q.push(i);
        }
    }
    ok = true;

    for(int i = 1;i<=n;i++)
    {
        visited[i] = false;
    }
    while(!q.empty())
    {
        auto el = q.front();
        q.pop();

        // visited[el] = true;

        for(auto it : adj[el])
        {
            // adj[el].erase(it);
            indeg[it]--;
            if(indeg[it] == 0)
            {
                q.push(it);
            }
        }
        adj[el].clear();
    }
    // dbg(adj);

    for(int i = 1;i<=n;i++)
    {
        if(visited[i] == false)
        {
            dfs(i);
        }
    }


    if(ok)
    {
        cout <<"Yes"<<nl;
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