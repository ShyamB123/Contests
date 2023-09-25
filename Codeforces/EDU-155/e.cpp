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

const int N = 101;

vector<vi> adj(N);
int p[N + 1] = {0};
int deg[N + 1] = {0};
int subtree[N + 1] = {0};
int c[N] = {0};
map<pair<int,int>,int> edge;
map<int,int> m;

bool ok = true;
vector<vi> dp(N,vi(2,0));

void dfs(int src,int par,int lvl)
{
    bool added = false;
    if(src != 1 && deg[src] == 2)
    {
        added = true;
        dp[subtree[src]][lvl%2]++;
        m[subtree[src]] = lvl%2;
    }

    for(auto it : adj[src])
    {
        if(it != par)
        {
            dfs(it,src,lvl + 1);
        }
    }

}

void dfs2(int src,int par,int col)
{
    for(auto it : adj[src])
    {
        if(it != par)
        {
            c[edge[{src,it}]] = col;

            dfs2(it,src,(col + 1)%2);
        }
    }
}

void dfs3(int src,int par,int col)
{
    for(auto it : adj[src])
    {
        if(it != par)
        {
            c[edge[{src,it}]] = col;

            dfs3(it,src,(col + 1)%3);
        }
    }
}
void solve()
{
    int n;
    cin>>n;



    p[1] = 1;
    subtree[1] = 1;

    int maxdeg = 0;

    for(int i =2;i<=n;i++)
    {
        cin>>p[i];
        edge[{p[i],i}] = i - 2;
        deg[i]++;
        deg[p[i]]++;
        adj[p[i]].pb(i);
        adj[i].pb(p[i]);
        if(p[i] == 1)
        {
            subtree[i] = i;
        }
        else
        {
            subtree[i] = subtree[p[i]];
        }
    }

    for(int i = 2;i<=n;i++)
    {
        maxdeg = max(maxdeg,deg[i]);
    }

    set<int> s;
    dfs(1,1,0);

    for(int i = 2;i<=n;i++)
    {
        // cout << deg[i]<<nl;
        if(dp[subtree[i]][0] > 0 && dp[subtree[i]][1] > 0 )
        {
            ok = false;
        }
    }

    // dbg(dp);
    // dbg(deg);

    if(maxdeg == 1)
    {
        // depth one
        cout << 1 << nl;
        cout.flush();
        for(int i=0;i<n-1;i++)
        {
            cout << 1<<" ";
        }
        cout << nl;
        cout.flush();
        int giv;
        cin>>giv;

        

        if(giv == 0)
        {
            int x;
            cin>>x;

            cout << 1 <<nl;
            cout.flush();
        }
        return;
    }
    else if(ok == true)
    {

        for(auto it : adj[1])
        {
            if(m.find(subtree[it]) == m.end() || m[subtree[it]] == 0)
            {
                c[edge[{1,it}]] = 1;
                dfs2(it,1,0);
            } 
            else
            {
                c[edge[{1,it}]] = 0;

                dfs2(it,1,1);
            }      
            
        }

        cout << 2 <<nl;
        cout.flush();

        for(int i =0;i<n-1;i++)
        {
            cout << c[i] + 1<<" ";
        }

        cout << nl;
        cout.flush();

        int giv;
        while(1)
        {
            cin >> giv;

            if(giv != 0)
            {
                break;
            }

            int v[2];

            cin >>v[0]>>v[1];

            if(v[0] == 1 && v[1] == 1)
            {
                cout << 1 <<nl;
                cout.flush();
            }
            else
            {
                if(v[0] == 1)
                {
                    cout << 1 <<nl;
                    cout.flush();
                }
                else
                {
                    cout << 2 <<nl;
                    cout.flush();
                }
            }
        }

        return;

    }
    else
    {
        // 3 colours

        dfs3(1,1,0);
        cout <<3 <<nl;
        cout.flush();

        for(int i =0;i<n-1;i++)
        {
            cout << c[i] + 1<<" ";
        }

        cout << nl;
        cout.flush();

        int giv;

        while(1)
        {
            cin>>giv;

            if(giv != 0)
            {
                break;
            }

            int v[3];

            cin>>v[0]>>v[1]>>v[2];

            int count =0 ;
            int indx = -1;
            for(int i=0;i<3;i++)
            {
                if(v[i] > 0)
                {
                    count++;
                    indx = i;
                }
            }

            if(count == 1)
            {
                cout << indx + 1<<nl;
                cout.flush();
            }
            else
            {
                if(v[0] > 0 && v[1] > 0)
                {
                    cout << 1 << nl;
                    cout.flush();
                }
                else if(v[1] > 0 && v[2] > 0)
                {
                    cout << 2 << nl;
                    cout.flush();
                }
                else
                {
                    cout << 3 << nl;
                    cout.flush();
                }
            }
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