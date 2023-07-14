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



void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    if(n%3 == 1)
    {
        cout << "YES"<<nl;
        return;
    }

    if(n%3 == 2)
    {
        for(int ch = 0;ch<26;ch++)
        {
            bool ok = false;
            char tar = (char)(ch + 'a');
            for(int i=0;i<n;i++)
            {
                if(i%3 == 0 && s[i] == tar && ok == false)
                {
                    ok = true;
                }
                if(i%3 == 1 && s[i] == tar && ok == true)
                {
                    cout <<"YES"<<nl;
                    return;
                }
            }
        }
        cout <<"NO"<<nl;
    }
    else
    {
        for(int ch = 0;ch<26;ch++)
        {
            bool ok = false;
            char tar = (char)(ch + 'a');
            for(int i=0;i<n;i++)
            {
                if(i%3 == 0 && s[i] == tar && ok == false)
                {
                    ok = true;
                }
                if(i%3 == 2 && s[i] == tar && ok == true)
                {
                    cout <<"YES"<<nl;
                    return;
                }
            }
        }
        cout <<"NO"<<nl;
    }
    
}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    ll t;
    cin>>t;

    while(t--)
    {
        solve();
    }
}