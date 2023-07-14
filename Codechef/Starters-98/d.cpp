#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld  long double
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define mod 1000000007
#define inf 1e17
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
    ll n;
    cin>>n;

    ll a[n];
    ll b[n];

    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(ll i= 0;i<n;i++)
    {
        cin>>b[i];
    }


    vector<vector<ll>> ldp(2 * n + 1,vl(2,-inf));
    vector<vector<ll>> rdp(2 * n + 1,vl(2,-inf));


    for(ll i =0;i<n;i++)
    {
        // ai bi
        ldp[2 * i][0] = a[i];
        if(2 * i - 1>=0)
        {
            ldp[2 * i][0] = max(ldp[2 * i][0],max(ldp[2 * i-1][0],ldp[2 * i-1][1]) + a[i]);
        }
        ldp[2 * i + 1][0] = b[i];
        ldp[2 * i + 1][0] = max(ldp[2 * i + 1][0],ldp[2 * i][0] + b[i]);


        // bi ai
        ldp[2 * i][1] = b[i];
        if(2 * i - 1>=0)
        {
            ldp[2 * i][1] = max(ldp[2 * i][1],max(ldp[2 * i-1][0],ldp[2 * i-1][1]) + b[i]);
        }
        ldp[2 * i + 1][1] = a[i];
        ldp[2 * i + 1][1] = max(ldp[2 * i + 1][1],ldp[2 * i][1] + a[i]);
    }

    // dbg(ldp);



    // right side
    for(ll i =n-1;i>=0;i--)
    {
        // bi ai
        rdp[2 * i + 1][1] = a[i];
        if(2 * i + 2 < 2 * n)
        {
            rdp[2 * i + 1][1] = max(rdp[2 * i + 1][1],max(rdp[2 * i + 2][0],rdp[2 * i + 2][1]) + a[i]);
        }
        rdp[2 * i][1] = b[i];
        rdp[2 * i][1] = max(rdp[2 * i][1],rdp[2 * i + 1][1] + b[i]);


        // ai bi
        rdp[2 * i + 1][0] = b[i];
        if(2 * i  + 2 < 2 * n)
        {
            rdp[2 * i + 1][0] = max(rdp[2 * i + 1][0],max(rdp[2 * i + 2][0],rdp[2 * i + 2][1]) + b[i]);
        }
        rdp[2 * i][0] = a[i];
        rdp[2 * i][0] = max(rdp[2 * i][0],rdp[2 * i + 1][0] + a[i]);
    }

    // dbg(rdp);

    ll ans = 0;

    multiset<ll> msr,msl;
    for(ll i =1;i<n;i++)
    {
        msr.insert(max({rdp[2 * i + 1][0],rdp[2 * i + 1][1],rdp[2 * i][0],rdp[2 * i][1]}));
    }

    ll finalans = inf;

    for(ll i=0;i<n;i++)
    {
        ll cur = 0;

        ll x = max({ldp[2 * i][0] + rdp[2 * i + 1][0],a[i],b[i],ldp[2 * i][0],rdp[2 * i + 1][0]});
        ll y = max({ldp[2 * i][1] + rdp[2 * i + 1][1],a[i],b[i],ldp[2 * i][1],rdp[2 * i + 1][1]});

        // alice will choose min of these

        ll opt = min(x,y);

        ll leftmax = 0,rightmax = 0;

        if(msl.size() > 0)
        {
            leftmax = *msl.rbegin();
        } 
        if(msr.size() > 0)
        {
            rightmax = *msr.rbegin();
        } 

        ll ansindx = max({leftmax,rightmax,opt,0ll});
        finalans = min(finalans,ansindx);


        msl.insert(max({ldp[2 * i + 1][0],ldp[2 * i + 1][1],ldp[2 * i][0],ldp[2 * i][1]}));
        if(i != n-1)
        {
            ll t = i + 1;
            msr.erase(msr.find(max({rdp[2 * t + 1][0],rdp[2 * t + 1][1],rdp[2 * t][0],rdp[2 * t][1]})));
        }
    }

    

    cout << finalans<<nl;



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