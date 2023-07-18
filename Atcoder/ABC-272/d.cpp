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


const int MAXN = 1e6 + 1;
int sqr[MAXN + 1];

ll sqr_root(ll tar)
{
    ll l = 0;
    ll r = 1e9;

    ll ans = 1;

    while(l<=r)
    {
        ll mid = (l+r)/2;

        if(mid*mid <= tar)
        {
            ans = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }

    return ans;
}

void cal_squares(int n)
{
    for(int i =0;i<n;i++)
    {
        sqr[i] = sqr_root(i);
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<bool>> visited(n,vector<bool>(n,false));
    vector<vector<int>> dp(n,vector<int>(n,-1));

    queue<vi> q;

    vi temp = {0,0,0};

    q.push(temp);
    visited[0][0] = true;
    dp[0][0] =0 ;

    while(!q.empty())
    {
        auto el = q.front();
        int x = el[0];
        int y = el[1];
        int dist = el[2];
        q.pop();

        for(int i =0;i<n;i++)
        {
            int z = m - (i - x) * (i - x);
            if(z>=0)
            {
                int temp = sqr[z];
                if(temp*temp == z)
                {
                    int j1 = y + temp;
                    int j2 = y - temp;

                    if( j1 < n && visited[i][j1] == false)
                    {
                        visited[i][j1] = true;
                        vi v;
                        v.pb(i);
                        v.pb(j1);
                        v.pb(dist + 1);
                        q.push(v);
                        dp[i][j1] = dist + 1;
                    }
                    if(j2 >=0 && visited[i][j2] == false)
                    {
                        visited[i][j2] = true;
                        vi v;
                        v.pb(i);
                        v.pb(j2);
                        v.pb(dist + 1);
                        q.push(v);
                        dp[i][j2] = dist + 1;
                    }
                }
            }
        }
        // dbg(dp);
    }

    
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
           cout << dp[i][j]<<" ";
        }
        cout <<nl;
    }

    

 
}


int main()
{


    fast_io;
    cout << fixed;
    cout << setprecision(10);

    cal_squares(MAXN-1);

    solve();
}