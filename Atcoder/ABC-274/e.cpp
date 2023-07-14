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

ld cal_dist(ll x1,ll y1,ll x2,ll y2)
{
    ld ans = sqrt((x1 - x2) *(x1 - x2) + (y1 - y2) *(y1 - y2));

    return ans;
}

map<int,int> logfn;

ll n,m;
vll vertex;
map<pair<ll,ll>,ll> pointtonode;
map<ll,pair<ll,ll>> nodetopoint;
vector<vector<pair<ll,ld>>> adj(n);
set<ll> chest;
ll must;
ll total;
ll mask;




ld check(ll num,ll cur,ll ches, vector<vector<vector<ld>>> &dp)
{
    if(num == 0)
    {
        if(chest.find(cur) != chest.end())
        {
            ches *= 2;
        }
        auto u = nodetopoint[cur];
        return (cal_dist(0,0,u.F,u.S)/ches);
    }
    if(dp[num][cur + 1][logfn[ches]] != -1)
    {
        return dp[num][cur + 1][logfn[ches]];
    }


    ld ans = inf;

    if((num & mask) == 0)
    {
        auto u = nodetopoint[cur];
        ans = (cal_dist(0,0,u.F,u.S)/ches);
    }

    if(cur == -1)
    {
        for(ll i = 0;i<n;i++)
        {
            if((num & (1<<i)) > 0)
            {
                ll rem = (num ^ (1<<i));
                auto u = nodetopoint[i];
                ll j = 1;
                if(chest.find(cur) != chest.end())
                {
                    j = 2;
                    // ches *= 2;
                }
                ans = min(ans,(cal_dist(0,0,u.F,u.S) * 1.0/(ches * j)) + check(rem,i,ches * j,dp));
                
            }
        }   
    }
    else
    {
        for(ll i = 0;i<n;i++)
        {
            if((num & (1<<i)) > 0)
            {
                ll rem = (num ^ (1<<i));
                auto u = nodetopoint[i];
                auto v = nodetopoint[cur];
                ll j = 1;
                if(chest.find(cur) != chest.end())
                {
                    j = 2;
                    // ches*=2;
                }
                
            
                ans = min(ans,(cal_dist(v.F,v.S,u.F,u.S) * 1.0 /(ches * j)) + check(rem,i,ches * j,dp));
            }
        }  
    }


    return dp[num][cur + 1][logfn[ches]] = ans;
}

void solve()
{
    
    cin>>n>>m;



    must = n;
    mask = 0;

    for(ll i =0;i<must;i++)
    {
        mask |= (1<<i);
    }
    total = (1<<n) - 1;


    ll cur =0;

    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;

        pointtonode[{x,y}] = cur;
        nodetopoint[cur] = {x,y};
        cur++;
    }

    for(ll i =0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;

        pointtonode[{x,y}] = cur;
        nodetopoint[cur] = {x,y};
        chest.insert(cur);
        cur++;
    }
    n = cur;


    for(int i=0;i<=n;i++)
    {
        int num = (1<<i);
        logfn[num] = i;
    }

    vector<vector<vector<ld>>> dp((1<<n),vector<vector<ld>>(n + 2,vector<ld>(m + 2,-1)));


    ld useless = check((1<<n) - 1,-1,1,dp);
    cout << useless<<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}