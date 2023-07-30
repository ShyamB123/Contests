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
    int n,m;
    cin>>n>>m;

    char a[n][m];
    set<pair<int,int>> s;

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(j + 8 >= m || i + 8 >=n)
            {
                continue;
            }

            bool ok = true;

            for(int x = i;x<i + 3;x++)
            {
                for(int y = j;y<j + 3;y++)
                { 
                    if(a[x][y] == '.')
                    {
                        ok = false;
                    }
                }
            }
            for(int x = i + 6;x<i + 9;x++)
            {
                for(int y = j + 6;y<j + 9;y++)
                { 
                    if(a[x][y] == '.')
                    {
                        ok = false;
                    }
                }
            }

            for(int x = i;x < i + 4;x++)
            {
                if(a[x][j + 3] == '#')
                {
                    ok = false;
                }
            }
            for(int x = i + 5;x < i + 9;x++)
            {
                if(a[x][j + 5] == '#')
                {
                    ok = false;
                }
            }
            for(int y = j;y < j + 4;y++)
            {
                if(a[i + 3][y] == '#')
                {
                    ok = false;
                }
            }
            for(int y = j + 5;y < j + 9;y++)
            {
                if(a[i + 5][y] == '#')
                {
                    ok = false;
                }
            }

            if(ok)
            {
                s.insert({i,j});
            }
        }
    }

    for(auto it : s)
    {
        cout << it.F + 1<<" "<<it.S + 1<<nl;
    }
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}