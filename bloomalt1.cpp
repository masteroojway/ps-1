#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = int(a); i < int(b); i++)
#define ff first
#define ss second
#define ll long long
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define sqr(a) ((a)*(a))

string stringToBinary(const string& input) {
    string binary = "";
    for (char c : input) {
        for (int i = 7; i >= 0; --i) {
            binary += ((c >> i) & 1) ? '1' : '0';
        }
    }
    return binary;
}

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
void insert(vector<bool> &filter, string s,vector<ll> &seeds, string pass)
{
    for(int i = 0; i < seeds.size(); i++)
    {
        ll temp = hashing(s, filter.size(), seeds[i]) % pass.size();
        filter[temp] = (bool)(pass[temp] - '0');
    }
}
bool search(string s, vector<bool> &filter, vector<ll> &seeds, string pass)
{
    for(int i = 0; i< seeds.size() ;i++)
    {
        ll temp = hashing(s, filter.size(), seeds[i]) % pass.size();
        if(filter[temp]!= (bool)(pass[temp]-'0')) return false;
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
            "facebook", "geeks", "twitter" };
    string pass;
    cout<<"Give your Pass: "<<endl;
    cin>>pass;
    pass = stringToBinary(pass);
    ll m = 1000; // change value of filter size
    ll k = 5; // number of hash maps to be used
    int seed = 10*k; // seed range
    vector<bool> filter(m);// m bit size array (main filter)
    vector<ll> seeds(k);
    rep(i,0,k)
    {
        seeds[i] = rand()%(seed);
    }

    //insert all words from dictionary
    for(int i = 0; i < 33 ;i++)
    {
        insert(filter, s[i], seeds, pass);
    }

    //input
    cout<<"String to perform Search for: "<<endl;
    string inp;
    cin>>inp;
    
    if(search(inp,filter, seeds, pass))cout<<"True"<<endl;
    else cout<<"False"<<endl;
}
