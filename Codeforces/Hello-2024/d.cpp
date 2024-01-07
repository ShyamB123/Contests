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
true
1
8
2 3 1 2 2 2 1 0

true
1
8
2 3 1 1 2 2 1 0

false


*/



void solve()
{
    ll n;
    cin>>n;

    vi a(n);

    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }

    stack<int> st;

    for(int i =0;i<n;i++)
    {
        if(st.size() == 0)
        {
            st.push(a[i]);
        }
        else
        {
            int cur = a[i];
            while(st.size() > 0 && abs(st.top() - cur) == 1)
            {
                if((cur > st.top()) && (i == n - 1 || cur >= a[i + 1]))
                {
                    cur = min(st.top(),cur);
                    st.pop();
                }
                else if(st.size() >= 2)
                {
                    int f = st.top();
                    st.pop();
                    int s = st.top();
                    if(f >= s && f > cur)
                    {
                        cur = cur;
                    }
                    else
                    {
                        st.push(f);
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            st.push(cur);
        }
    }
    vi v;
    // auto tempst =st;

    // while(tempst.size() > 0)
    // {
    //     cout << tempst.top()<<" ";
    //     tempst.pop();
    // }
    // cout << nl;

    if(st.size() == 1 && st.top() == 0)
    {
        cout << "YES"<<nl;
        return;
    }

    // reverse(all(v));
    
    while(st.size() > 0)
    {
        v.pb(st.top());
        st.pop();
    }

    for(auto it : v)
        st.push(it);

    


    int cur = st.top();

    st.pop();

    while(st.size() > 0)
    {
        if(abs(st.top() - cur) != 1)
        {
            cout << "NO"<<nl;
            // dbg(abs(st.top() - cur));
            // dbg(cur);
            // dbg(st.top());
            return;
        }
        cur = min(st.top(),cur);
        st.pop();
    }


    if(cur == 0)
    {
        cout << "YES"<<nl;
        return;
    }
    else
    {
        cout << "NO"<<nl;
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