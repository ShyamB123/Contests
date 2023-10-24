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
    ll n,m;
    cin>>n>>m;

    ll a[n - 1];
    ll b[n];
    // a[0] = 1;

    for(ll i=0;i<n-1;i++)
    {
        cin>>a[i];
    }  

    for(ll i= 0;i<n;i++)
    {
        cin>>b[i];
    } 

    sort(a , a+ n-1);
    sort(b,b + n);

    ll j =0;
    ll ans = 0;
    map<ll,ll> atob;
    set<ll> used;
    for(ll i=0;i<n-1;i++)
    {
        while(j < n && b[j] <= a[i])
        {
            j++;
        }

        if(j == n)
        {
            break;
        }
        
        atob[i] = j;
        used.insert(j);
        
        j++;    
        ans++;
    }

    set<ll>unused;
    for(ll i =0;i<n;i++)
    {
        if(used.find(i) == used.end())
        {
            unused.insert(b[i]);
        }
    }

    ans = n -1 - ans;

    ll finalans =0 ;
    bool ok = true;
    ll bef = 0;
    for(ll i= 0;i<n-1;i++)
    {
        ll num = a[i];
        if(num > m)
        {
            num = m;
        }

        if(bef < m)
        {
            ll last = *unused.rbegin();

            if(last > bef)
            {
                if(last > m)
                {
                    last = m + 1;
                }
                finalans += ans * (last - 1 - bef);
                bef = last - 1;
            }
            if(bef < m)
            {
                finalans += (ans + 1) * (m - bef);
                bef = m;
            }
        }
        
        if(atob[i] == i)
        {
            if(num > bef)
            {
                finalans += (ans + 1) * (num - bef);
                bef = num;
            }
        }
        else
        {
            ll bbef = b[atob[i] - 1];
            if(bbef > m)
            {
                bbef = m + 1;
            }
            if(used.find(bbef) == used.end())
            {
                if(bbef > bef)
                {
                    finalans += ans * (bbef -1- bef);
                    bef = bbef-1;   
                }
                if(bef < num)
                {
                    finalans += (ans + 1) * (num - bef);
                    bef = num;
                }
            }
            else
            {
                if(bef < num)
                {
                    finalans += (ans + 1) * (num - bef);
                    bef = num;
                }
            }
        }
    }

    if(bef < m)
    {
        ll last = *unused.rbegin();

        if(last > bef)
        {
            if(last > m)
            {
                last = m + 1;
            }
            finalans += ans * (last - 1 - bef);
            bef = last - 1;
        }
        if(bef < m)
        {
            finalans += (ans + 1) * (m - bef);
            bef = m;
        }
    }



    cout << finalans << nl; 

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