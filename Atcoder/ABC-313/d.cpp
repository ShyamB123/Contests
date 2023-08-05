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
    int n,k;
    cin>>n>>k;
    int a[n] = {-1};

    set<int> cur;
    for(int i= 0;i<=k;i++)
    {
        cur.insert(i);
    }

    int firstk;
    cout << "? ";
    for(int it = 0;it<k;it++)
    {
        cout << it + 1 <<" ";
    }
    cout <<endl;

    cin>>firstk;

    int secondk;
    cout << "? ";
    for(int it = 1;it<=k;it++)
    {
        cout << it + 1 <<" ";
    }
    cout <<endl;
    cin>>secondk;
    
    int partotal = (firstk + secondk)%2;

    if(firstk == secondk)
    {
        a[0] = a[k] = 1;
    }
    else
    {
        a[0] = 1;
        a[k] = 0;
    }

    int middle =0;
    for(int i = 1;i<k;i++)
    {
        int curk;
        cout << "? ";
        for(auto it : cur)
        {
            if(it == i)
            {
                continue;
            }
            cout << it + 1 <<" ";
        }
        cout <<endl;
        cin>>curk;
        if(curk == firstk)
        {
            a[i] = a[k];
        }
        else
        {
            a[i] = 1 - a[k];
        }
        middle = (middle + a[i])%2;
    }

    int sum =0;
    for(int i =0;i<k;i++)
    {
        sum = (sum + a[i])%2;
    }
    if(sum != firstk)
    {
        for(int i=0;i<=k;i++)
        {
            a[i] = 1 - a[i];
        }
    }

    int curk = secondk;
    for(int i = k + 1;i<n;i++)
    {
        int val;
        cout << "? ";
        for(int j = i;j>i - k;j--)
        {
            cout << j + 1<<" ";
        }
        cout <<endl;
        cin>>val;

        if(val == curk)
        {
            a[i] = a[i - k];
        }
        else
        {
            a[i] = 1 - a[i-k];
        }
        curk = val;
    }

    cout << "! ";

    for(int i=0;i<n;i++)
    {
        cout << a[i]<< " ";
    }
    cout <<endl;

}


int main()
{
    fast_io;
    cout << fixed;
    cout << setprecision(10);

    solve();
}