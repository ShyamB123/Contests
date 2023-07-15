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

map<pair<int,int>,int> inv;
map<set<vi>,int> dp;
int n,t,m;

// int ans;
int tempans =0;

bool check(set<vi> &adj)
{
    if(adj.size() != t)
    {
        return false;
    }
    for(auto i : adj)
    {
        vi v;
        for(auto it :i)
        {
            v.pb(it);
        }

        for(int j =0;j<v.size();j++)
        {
            for(int k =0;k<v.size();k++)
            {
                if(inv.find({v[j],v[k]}) != inv.end())
                {
                    return false;
                }
            }
        }
    }

    
    // dbg(adj);
    
    return true;
}

int ways(int cur,int unfilled,set<vi> &adj)
{
    if(n - cur + 1< unfilled)
        return 0;
    if(cur == n + 1)
    {
        if(check(adj))
        {
            // ans++;
            tempans++;
            return 1;
        }
        
        return 0;
    }
    if(dp.find(adj) != dp.end())
    {
        return dp[adj];
    }
    

    int ans =0;
    
    set<vi> temp = adj;
    for(vector<int> i : adj)
    {
        vi v = i;
        v.pb(cur);
        // dbg(adj);
        temp.erase(i);
        temp.insert(v);
        ans += ways(cur + 1,unfilled,temp);
        temp.erase(v);
        temp.insert(i);
        // dbg(adj);
    }
    vi v;
    v.pb(cur);
    adj.insert(v);
    ans += ways(cur + 1,unfilled-1,adj);
    adj.erase(v);

    // dbg(ans);
    return dp[adj] = ans;

}



void solve()
{
  
    cin>>n>>t>>m;

    set<vi> adj;

    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        inv[{u,v}]++;
        inv[{v,u}]++;
    }
    int unfilled = t;

    // ans =0;
    tempans = 0;
    cout << ways(1,unfilled,adj)<<nl;
    // dbg(tempans);

    // cout << ans<<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}