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

int n,m;
set<string> t;
vector<string> a;
bool ok;
string ans;

void check(int num,string &s,int letters,int remletter)
{
    if(ok)
    {
        return;
    }
    if(16 - letters < remletter)
    {
        return;
    }
    if(s.size() > 16)
    {
        return;
    }
    if(num == 0)
    {
        if(t.find(s) == t.end() && s.size() >=3)
        {
            ok = true;  
            ans = s;
        }   
        return;
    }

    // add a underscore
    if(__builtin_popcount(num) != n && __builtin_popcount(num) != 0 )
    {
        s += '_';
        check(num,s,letters + 1,remletter);
        s.pop_back();
    }
    
    for(int j =0;j<n;j++)
    {
        if((num & (1<<j)) > 0)
        {
            int rem = (num ^ (1<<j));
            s += a[j];
            int len = a[j].size();
            if(__builtin_popcount(rem) != 0)
            {
                s += '_';
                len++;
            }
            check(rem,s,letters + len,remletter - a[j].size());
            for(int k =0;k<len;k++)
            {
                s.pop_back();
            }
        }
    }
    
}

void solve()
{
    cin>>n>>m;
    int total = 0;

    for(int i =0;i<n;i++)
    {
        string s;
        cin>>s;
        a.pb(s);
        total += s.size();
    }

    for(int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        t.insert(s);
    }

    int num = (1<<n) -1 ;
    string s = "";

    ok = false;
    check(num,s,0,total);

    if(ok)
    {
        cout << ans<<nl;
    }
    else
    {
        cout <<-1<<nl;
    }




}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}