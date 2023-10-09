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

const int N = 2e5 + 1;
vector<vi> adj(N);
bool visited[N] = {false};
bool ok = true;
bool must[N + 1] = {false};
bool circle[N + 1] = {false};

void dfs(int src,int len)
{
    visited[src] = true;
    if(len%2== 0)
    {
        must[src] = true;
    }
    else
    {
        circle[src] = true;
    }

    for(auto it : adj[src])
    {
        if(visited[it] == true)
        {
            if(len%2 == 1)
            {
                ok = false;
            }
        }
        else
        {
            dfs(it,len + 1);
        }
    }
}



void solve()
{
    int n;
    cin>>n;

    ll a[n + 1] ;
    set<int> s;

    vector<vi> rev(n + 1);

    vector<int> freq(n + 1,0);


    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        rev[a[i]].pb(i);
        s.insert(a[i]);
        freq[a[i]]++;
    }



    queue<int> mus,cir;

    for(int i= 1;i<=n;i++)
    {
        if(s.find(i) == s.end())
        {
            // must be present
            if(circle[a[i]] == false)
            {
                mus.push(a[i]);
            }
            must[i] = true;
        }
    }


    while(!mus.empty() || !cir.empty())
    {

        // dbg("dbg");
        while(!mus.empty())
        {
            auto el = mus.front();
            mus.pop();
            // dbg(el);

            int it = el;
                // this must be circled;
            if(must[it] == true)
            {
                // if(a[1] == 44011 )
                //     cout << "failed must test"<<nl;
                cout << -1 <<nl;
                return;
            }
            else
            {
                if(circle[it] == false)
                {
                    freq[a[it]]--;
                    circle[it] = true;
                    if(freq[a[it]] == 0)
                    {
                        cir.push(a[it]);
                    }
                }
            }
            
        }

        while(!cir.empty())
        {
            auto el = cir.front();
            cir.pop();

            if(circle[el] == true)
            {
                // if(a[1] == 44011 )
                //     cout << "failed circle test"<<nl;
                cout << -1 <<nl;
                return;
            }
            else
            {
                if(must[el] == false)
                {
                    must[el] = true;
                    mus.push(a[el]);
                }
            }
        }
    }

    

    for(int i=1;i<=n;i++)
    {
        if(must[i] == false && circle[i] == false)
        {
            for(auto it : rev[i])
            {
                if(must[it] == false && circle[it] == false)
                {
                    adj[i].pb(it);
                }
            }
        }
        // dbg(adj[i]);
    }

    // for(int i =1;i<=n;i++)
    //     {
    //         if(must[i]) cout << 1 <<" ";
    //         else cout << 0 <<" ";
    //     }
    //     cout <<nl;


    //     for(int i =1;i<=n;i++)
    //     {
    //         if(circle[i]) cout << 1 <<" ";
    //         else cout << 0 <<" ";
    //     }
    //     cout <<nl;
    ok = true;
    for(int i =1;i<=n;i++)
    {
        if(must[i] == false && circle[i] == false && visited[i] == false)
        {
            dfs(i,1);
        }
    }
    if(ok == false)
    {
    //         if(a[1] == 44011 )
    //                 cout << "failed cycle test"<<nl;
        cout << -1 <<nl;
        return;
    }
    // for(int i =1;i<=n;i++)
    //     {
    //         if(must[i]) cout << 1 <<" ";
    //         else cout << 0 <<" ";
    //     }
    //     cout <<nl;


    //     for(int i =1;i<=n;i++)
    //     {
    //         if(circle[i]) cout << 1 <<" ";
    //         else cout << 0 <<" ";
    //     }
    //     cout <<nl;
    vi ans;
    for(int i =1;i<=n;i++)
    {
        if(must[i] == true)
        {
            ans.pb(a[i]);
        }
    }

    cout << ans.size()<<nl;

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

    solve();
}