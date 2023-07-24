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



void solve()
{
    int n;
    cin>>n;

    vii a(n);
    // vi b;
    int zeros = 0;
    set<int> s;

    for(int i=0;i<n;i++)
    {
        cin>>a[i].F;
        a[i].S = i;
        s.insert(a[i].F);
        if(a[i].F == 0)
        {
            zeros++;
        }

    }

    if(n == 1)
    {
        cout <<"YES"<<nl;
        if(a[0].F > 0)
        {
            cout << 1<<nl;
        }
        else
        {
            cout <<-1<<nl;
        }
        return;
    }


    sort(all(a));
    reverse(all(a));

    vi v;
    // v.pb(INT_MIN);

    int cur = zeros == 0 ? n : n-1;
    for(int i =0;i<n;i++)
    {
        if(a[i].F == 0)
        {
            v.pb(-n);
        }
        else if(i == 0)
        {
            v.pb(cur);
            cur--;
            
                if(cur == 0)
                    cur--;
        }
        
        else
        {
            if(v.size() < a[i].F)
            {
                if(s.find(v.size()) != s.end())
                {
                    v.pb(cur-1);
                    cur-=2;
                }
                else
                {
                    v.pb(cur);
                    cur--;
                }
                if(cur == 0)
                    cur--;
            }
            else
            {
                int indx = a[i].F - 1;
                if(v[indx] < 0)
                {
                    cout <<"NO"<<nl;
                    return;
                }
                else
                {
                    v.pb(-v[indx] + 1);
                }
            }
        }
    }
    // dbg(v);
    
    for(int i =0;i<n;i++)
    {
        int num = v[i];

        int s = 0;
        int e = n-1;
        int tar = -num;

        int vert = 0;
        while(s <= e)
        {
            int mid = (s + e)/2;

            if(v[mid] > tar)
            {
                vert = mid;
                s = mid + 1;
            }
            else
            {
                e = mid-1;
            }
        }

        if(a[i].F!= 0 && vert + 1 != a[i].F)
        {
            cout << "NO"<<nl;
            return; 
        }
    }

    cout <<"YES"<<nl;

    vi ans(n);

    for(int i =0;i<n;i++)
    {
        ans[a[i].S] = v[i];
    }

    for(auto it : ans)
    {
        cout << it << " ";
    }
    cout <<nl;
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