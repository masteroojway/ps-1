#include <iostream>
using namespace std;

#define rep(i,a,b) for (int i = int(a); i < int(b); i++)
#define ff first
#define ss second
#define ll long long
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define sqr(a) ((a)*(a))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<"After last line press enter and CNTRL + D to indicate end of paragraph"<<endl;
    cout<<"Enter the string to be sorted: "<<endl;
    string s = "";
    string temp;
    while(getline(cin, temp))
    {
        s+=temp;
    }
    //removing spaces
    for(int i = 0; i < s.size();i++)
    {
        if(s[i]==' ')s.erase(s.begin()+i--);
    }
    int v[26] = {0};
    //bool which tells us if characters other than letters are present
    bool other = false;
    for(int i = 0; i < s.size();i++)
    {
        if(!(s[i]>=65 && s[i]<=90)&&!(s[i]>=97&&s[i]<=122))
        {
            continue;
        }
        if(s[i]>=65 && s[i]<=90)s[i]+=32;
        v[s[i] -'a']++;
    }
    if(other){
        cout<<"String contains characters other than numbers"<<endl;
        return 0;
    }
    for(int i = 0;i<26;i++)
    {
        for(int j = 0;j<v[i];j++)
        {
            cout<<(char)('a'+i);
        }
    }
    cout<<endl;

}
