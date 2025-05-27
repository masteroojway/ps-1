#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = int(a); i < int(b); i++)
#define ff first
#define ss second
#define ll long long
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define sqr(a) ((a)*(a))
long long hashing(string s, ll size, int seed)
{
    ll temp = 0;
    for(auto c: s)
    {
        temp+=(c*seed);
        temp%=size;
    }
    return temp;
}
void insert(vector<bool> &filter, string s,vector<ll> &seeds)
{
    for(int i = 0; i < seeds.size(); i++)
    {
        ll temp = hashing(s, filter.size(), seeds[i]);
        filter[temp] = true;
    }
}
bool search(string s, vector<bool> &filter, vector<ll> &seeds)
{
    for(int i = 0; i< seeds.size() ;i++)
    {
        ll temp = hashing(s, filter.size(), seeds[i]);
        if(filter[temp]==false) return false;
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s[33] = { "abound",   "abounds",       "abundance",
            "abundant", "accessible",    "bloom",
            "blossom",  "bolster",       "bonny",
            "bonus",    "bonuses",       "coherent",
            "cohesive", "colorful",      "comely",
            "comfort",  "gems",          "generosity",
            "generous", "generously",    "genial",
            "bluff",    "cheater",       "hate",
            "war",      "humanity",      "racism",
            "hurt",     "nuke",          "gloomy",
            "facebook", "geeksforgeeks", "twitter" };
    ll m = 1000; // change value of filter size
    ll k = 5; // number of hash maps to be used
    int seed = 10*k; // seed range
    vector<bool> filter(m);
    vector<ll> seeds(k);
    rep(i,0,k)
    {
        seeds[i] = rand()%(seed);
    }
    for(int i = 0; i < 33 ;i++)
    {
        insert(filter, s[i], seeds);
    }
    cout<<"String to perform Search for: "<<endl;
    string inp;
    cin>>inp;
    if(search(inp,filter, seeds))cout<<"True"<<endl;
    else cout<<"False"<<endl;
    
}
