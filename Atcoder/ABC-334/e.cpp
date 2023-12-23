#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 998244353
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
ll binexp1(ll a,ll b, ll m){
    ll result = 1;
    while(b){
        if(b&1){
            result = (result*a)%m;
        }
        a = (a*a)%m;
        b>>=1;
    }
    return result;
}

ll divmod (ll a,ll b, ll m){
    ll inv = binexp1(b,m-2,m);
    ll ans = ((a%m)*(inv%m))%m;
    return ans;
}
const int N = 1001;

char a[N][N];

// n s w e
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int n,m;

vector<vl> dp(N,vl(N,-1));

void dfs(int x,int y,int comp)
{
    dp[x][y] = comp;

    for(int k = 0;k<4;k++)
    {
        int i = x + dx[k];
        int j = y + dy[k];

        if(i >= n || i<0 || j >= m || j<0)
        {
            continue;
        }

        if(dp[i][j] == -1 && a[i][j] == '#')
        {
            dfs(i,j,comp);
        }
    }
}

void solve()
{
    cin>>n>>m;

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
            cin>>a[i][j];
    }


    int comp = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(a[i][j] == '#' && dp[i][j] == -1)
            {
                dfs(i,j,comp);
                comp++;
            }
        }
    }

    // for(int i =0;i<n;i++)
    // {
    //     for(int j =0;j<m;j++)
    //     {
    //         cout << dp[i][j]<<" ";
    //     }
    //     cout << nl;
    // }

    ll ans =0 ;
    ll den = 0;

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(a[i][j] == '.')
            {
                den++;
                set<int> s;
                for(int k =0;k<4;k++)
                {
                    int xi = i + dx[k];
                    int xj = j + dy[k];

                    if(xi >= n || xi<0 || xj >= m || xj<0)
                    {
                        continue;
                    }

                    if(a[xi][xj] == '#')
                    {
                        s.insert(dp[xi][xj]);
                    }
                }

                if(s.size() == 0)
                {
                    ans += comp + 1;
                    ans %= mod;
                }
                else
                {
                    // dbg(s);

                    // dbg(comp - max(0,int(s.size() - 1)));
                    ans += (comp - max(0,int(s.size() - 1)));
                    ans %= mod;
                }

            }
        }
    }

    // dbg(ans);
    // dbg(den);

    

    ans = divmod(ans,den,mod);
    cout << ans << nl;
}




int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}