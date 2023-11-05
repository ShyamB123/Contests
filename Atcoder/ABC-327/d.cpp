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



void solve()
{
    ll n,m;
    cin>>n>>m;

    ll a[m];
    ll b[m];

    bool visited[n + 1] = {false};
    vector<vi> adj(n + 1);

    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }


    for(int i =0;i<m;i++)
    {
        adj[a[i]].pb(b[i]);
        adj[b[i]].pb(a[i]);

        if(a[i] == b[i])
        {
            cout <<"No"<<nl;
            return;
        }
    }

    set<int> first,second;


    for(int i=1;i<=n;i++)
    {
        if(visited[i] == false)
        {
            queue<pair<int,int>> q;
            q.push({i,0});
            first.insert(i);

            while(!q.empty())
            {
                auto el = q.front();
                q.pop();
                int src = el.F;
                int gp = el.S;

                if(gp == 0)
                {
                    for(auto it : adj[src])
                    {
                        if(first.find(it) != first.end())
                        {
                            cout <<"No"<<nl;
                            return;
                        }
                        else
                        {
                            if(visited[it] == false)
                            {
                                q.push({it,1 - gp});
                                visited[it] = true;
                                second.insert(it);
                            }   
                        }
                    }
                }
                else
                {
                    for(auto it : adj[src])
                    {
                        if(second.find(it) != second.end())
                        {
                            cout <<"No"<<nl;
                            return;
                        }
                        else
                        {
                            if(visited[it] == false)
                            {
                                q.push({it,1 - gp});
                                visited[it] = true;
                                first.insert(it);
                            }   
                        }
                    }
                }
            }

        }       
    }

    cout <<"Yes"<<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}