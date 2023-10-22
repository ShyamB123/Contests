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

const int N = 1001;
char a[N][N];
vector<vector<bool>> visited(N,vector<bool> (N,false));
int h,w;

// n s e w ne nw se sw
int dx[] = {0,0,1,-1,1,-1,1,-1};
int dy[] = {-1,1,0,0,-1,-1,1,1};

void dfs(int x,int y)
{
    visited[x][y] = true;

    for(int dir = 0;dir < 8;dir++)
    {
        int i = x + dx[dir];
        int j = y + dy[dir];

        if(i >=0 && j>=0 && i < h && j < w && a[i][j] == '#' && visited[i][j] == false)
        {
            dfs(i,j);
        }
    }
}

void solve()
{
    cin>>h>>w;

    for(int i =0;i<h;i++)
    {
        for(int j =0;j<w;j++)
        {
            cin>>a[i][j];
        }
    }    

    int ans =0;
    for(int i =0;i<h;i++)
    {
        for(int j =0;j<w;j++)
        {
            if(visited[i][j] == false && a[i][j] == '#')
            {
                dfs(i,j);
                ans++;
            }
        }
    }

    cout << ans <<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}