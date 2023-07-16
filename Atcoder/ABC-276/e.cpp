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

bool ok;
int n,m;

void dfs(int i,int j,int pi,int pj,vector<vector<char>> &a,vector<vector<bool>> &visited)
{
    
    if(i - 1 >= 0 && (i-1 != pi) &&  a[i-1][j] == 'S' && visited[i-1][j] == true)
    {
        ok = true;
    }
    if(j - 1 >= 0 && (j-1 != pj) &&   a[i][j-1] == 'S' && visited[i][j -1] == true)
    {
        ok = true;
    }
    if(i + 1 < n && (i+1 != pi) &&  a[i+1][j] == 'S' && visited[i+1][j] == true)
    {
        ok = true;
    }
    if(j + 1 < m && (j+1 != pj) &&  a[i][j+1] == 'S' && visited[i][j + 1] == true)
    {
        ok = true;
    }
    visited[i][j] = true;



    if(i - 1 >= 0 && a[i-1][j] == '.' && visited[i-1][j] == false)
    {
        dfs(i-1,j,i,j,a,visited);
    }
    if(j - 1 >= 0 && a[i][j-1] == '.' && visited[i][j - 1] == false)
    {
        dfs(i,j -1,i,j,a,visited);
    }
    if(i + 1 < n && a[i+1][j] == '.' && visited[i+1][j] == false)
    {
        dfs(i+1,j,i,j,a,visited);
    }
    if(j + 1 < m && a[i][j+1] == '.' && visited[i][j + 1] == false)
    {
        dfs(i,j + 1,i,j,a,visited);
    }


    
}

void solve()
{
    
    cin>>n>>m;

    vector<vector<char>> a(n,vector<char>(m));
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin>>a[i][j];
            visited[i][j] = false;
        }
    }   

    ok = false;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if(a[i][j] == 'S')
            {
                dfs(i,j,i,j,a,visited);
            }
        }
    }

    if(ok)
    {
        cout << "Yes"<<nl;
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

    solve();
}