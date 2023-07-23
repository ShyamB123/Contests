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
4 4
####
#.##
#..#
####
*/

char a[201][201];
vector<vector<int>> vert(201),hor(201);
vector<vector<vector<bool>>> visited(201,vector<vector<bool>>(201,vector<bool>(2,false)));




void dfs(int x,int y)
{
    visited[x][y][0] = visited[x][y][1] = true;

    // up
    if(a[x-1][y] != '#' && (visited[x-1][y][0] == false ||visited[x-1][y][1] == false))
    {
        int indx = lower_bound(all(vert[y]),x) -vert[y].begin() -1 ;
        int val = vert[y][indx];
        bool ok = true;
        if(visited[val + 1][y][1] == true)
        {
            ok = false;
        }
        for(int i = x;i>val;i--)
        {
            visited[i][y][1] = true;
        }
        if(ok)
            dfs(val + 1,y);
    }

    //down
    if(a[x+1][y] != '#' && (visited[x+1][y][0] == false ||visited[x+1][y][1] == false))
    {
        int indx = lower_bound(all(vert[y]),x) -vert[y].begin();
        int val = vert[y][indx];
        bool ok = true;
        if(visited[val - 1][y][1] == true)
        {
            ok = false;
        }
        for(int i = x;i<val;i++)
        {
            visited[i][y][1] = true;
        }
        if(ok)
            dfs(val - 1,y);
    }

    // left
    if(a[x][y-1] != '#' && (visited[x][y -1][0] == false ||visited[x][y-1][1] == false))
    {
        int indx = lower_bound(all(hor[x]),y) - 1 - hor[x].begin();
        int val = hor[x][indx];
        bool ok = true;
        if(visited[x][val+1][0] == true)
        {
            ok = false;
        }
        for(int i = y;i>val;i--)
        {
            visited[x][i][0] = true;
        }
        if(ok)
            dfs(x,val + 1);
    }

    //right
    if(a[x][y+1] != '#' && (visited[x][y +1][0] == false ||visited[x][y+1][1] == false))
    {
        int indx = lower_bound(all(hor[x]),y)- hor[x].begin();
        int val = hor[x][indx];
        bool ok = true;
        if(visited[x][val-1][0] == true)
        {
            ok = false;
        }
        for(int i = y;i<val;i++)
        {
            visited[x][i][0] = true;
        }
        if(ok)
          dfs(x,val - 1);
    }

    

}

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=0 ;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(a[i][j] == '#')
            {
                hor[i].pb(j);
            }
        }
    }
    
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i][j] == '#')
            {
                vert[j].pb(i);
            }
        }
    }

    dfs(1,1);

    int ans =0;

    for(int i=0 ;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(visited[i][j][0] == true ||visited[i][j][1] == true)
            {
                ans++;
            }
            // if(visited[i][j][0] == true ||visited[i][j][1] == true)
            // {
            //     cout << 1;
            // }
            // else
            // {
            //     cout <<0;
            // }
        }
        // cout <<nl;
    }
    cout << ans<<nl;
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}