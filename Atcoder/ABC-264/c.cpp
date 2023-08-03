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
    int h,w;
    cin>>h>>w;

    int a[h][w];

    for(int i=0 ;i<h;i++)
    {
        for(int j = 0;j<w;j++)
        {
            cin>>a[i][j];
        }
    }

    int n,m;
    cin>>n>>m;

    int b[n][m];

    for(int i=0 ;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>b[i][j];
        }
    }

    int t[n][m];
    for(int i= 0;i<(1<<h);i++)
    {
        for(int j =0 ;j<(1<<w);j++)
        {
            if(__builtin_popcount(i) != n ||  __builtin_popcount(j) != m)
            {   
                continue;
            }

            int x = 0;
            int y = 0;

            for(int l = 0;l<h;l++)
            {
                if((i & (1<<l)) == 0)
                {
                    continue;
                }
                for(int r = 0;r<w;r++)
                {
                    if((j & (1<<r)) == 0)
                    {
                        continue;
                    }
                    t[x][y] = a[l][r];
                    y++;
                }
                x++;
                y =0;
            }
            bool ok= true;
            for(int l=0;l<n;l++)
            {
                for(int r =0;r<m;r++)
                {
                    // cout << t[l][r]<< " ";
                    if(t[l][r] != b[l][r])
                    {
                        ok = false;
                    }
                }
            }
            if(ok)
            {
                cout << "Yes"<<nl;
                return;
            }
        }

    }

    cout <<"No"<<nl;

    
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}