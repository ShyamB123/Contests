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
int a[N];

vector<bool> visited(N,false);
vi pathvert;

void dfs(int src)
{
    pathvert.pb(src);
    visited[src] = true;
    if(visited[a[src]] == false)
    {
        dfs(a[src]);
    }
}

void solve()
{
    int n;
    cin>>n;

    int c[n + 1];

    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }

    int indeg[n + 1] = {0};
    
    for(int i=1;i<=n;i++)
    {
        indeg[a[i]]++;
    }

    for(int i= 1;i<=n;i++)
    {
        visited[i] = false;
    }

    queue<int> q;


    for(int i = 1;i<=n;i++)
    {
        if(indeg[i] == 0)
        {
            q.push(i);
        }
    }
    vi ans;
    while(!q.empty())
    {
        int el = q.front();
        q.pop();
        visited[el] = true;

        ans.pb(el);
        indeg[a[el]]--;
        if(indeg[a[el]] == 0)
        {
            q.push(a[el]);
        }
    }

    //now we have cycles

    for(int i =1;i<=n;i++)
    {
        if(visited[i] == false)
        {
            dfs(i);

            // dbg(pathvert);

            ll high = inf;
            vi temp;
            int minindx;
            for(int it = 0;it<pathvert.size();it++)
            {
                if(c[pathvert[it]] < high)
                {
                    high = c[pathvert[it]];
                    minindx = it; 
                }
            }
            // dbg(minindx);

            for(int j = minindx + 1;j<pathvert.size();j++)
            {
                ans.pb(pathvert[j]);
            }
            for(int j = 0;j<=minindx;j++)
            {
                ans.pb(pathvert[j]);
            }

            pathvert.clear();
        }
    }

    for(auto it : ans)
    {
        cout << it <<" ";
    }
    cout << nl;



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