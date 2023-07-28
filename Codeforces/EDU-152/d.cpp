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
    int n;
    cin>>n;

    vector<vi> a(3);
    vi v(n);


    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        a[v[i]].pb(i);
    }

    

    bool visited[n] = {false};

    int ans = 0;    
    for(auto it : a[2])
    {
        if(visited[it] == false)
        {
            ans++;
            int i = it - 1;
            visited[it] = true;
            while(i>=0 && v[i] > 0)
            {
                visited[i] = true;
                i--;
            }
            if(i>=0)
            {
                visited[i] = true;
            }
            i = it + 1;
            while(i<n && v[i] > 0)
            {
                visited[i] = true;
                i++;
            }
            if(i<n)
            {
                visited[i] = true;
            }
        }
    }

    reverse(all(a[1]));

    for(auto it : a[1])
    {
        if(visited[it] == false)
        {
            ans++;
            if(it + 1 < n && visited[it + 1] == false)
            {
                visited[it + 1] = true;
                int i = it;
                while(i>=0 && v[i] > 0)
                {
                    visited[i] = true;
                    i--;
                }
            }
            else
            {
                int i = it;
                while(i>=0 && v[i] > 0)
                {
                    visited[i] = true;
                    i--;
                }
                if(i>=0)
                {
                    visited[i] = true;
                }
            }
        }
    }

    for(int i =0;i<n;i++)
    {
        if(visited[i] == false)
        {
            ans++;
        }
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