#include <bits/stdc++.h>
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
    cout<<"Are you an Admin? (Y/N) => ";
    // flag for checking if admin or not
    bool flag = false;
    
    string temp;
    cin>>temp;
    if(temp[0]=='y'||temp[0]=='Y')flag = true;
    else if(temp[0]=='N'||temp[0]=='n')flag = false;
    else {
        cout<<"Invalid answer"<<endl;
        return 0;
    }
    
    cout<<"Type new password: "<<endl;
    string s;
    cin>>s;
    vector<pair<bool, string>> norm, admin;
    norm.push_back({false, "Have a length greater than 7 characters"});
    norm.push_back({false, "Contain at least one alphabetic character"});
    norm.push_back({false, "Contain at least one digit"});
    admin.push_back({false, "have a length greather than 10 characters"});
    admin.push_back({false, "have special character"});
    bool strong = true;
    if(s.size()<=7)
    {
        norm[0].ff = true;
        strong = false;
    }
    ll alpha = 0;
    ll nums = 0;
    for(int i = 0;i<s.size();i++)
    {
        if((s[i]<=90&&s[i]>=65)||(s[i]>=97&&s[i]<=122))
        {
            alpha++;
        }
        if(s[i]>=49&&s[i]<=57)
        {
            nums++;
        }
    }
    if(alpha==0)
    {
        norm[1].ff = true;
        strong = false;
    }
    if(nums==0)
    {
        norm[2].ff = true;
        strong = false;
    }
    if(strong == false&&flag == false)
    {
        cout<<"Password is not strong as password doesnt: "<<endl;
        for(int i = 0; i < 3;i++)
        {
            if(norm[i].ff)
            cout<<norm[i].ss<<endl;
        }
        return 0;
    }
    else if(strong == true && flag == false)
    {
        cout<<"Password is strong enough"<<endl;
        return 0;
    }
    if(s.size()<=10)
    {
        admin[0].first = true;
        strong = false;
    }
    if(alpha+nums == s.size())
    {
        admin[1].first = true;
        strong = false;
    }
    if(strong)
    {
        cout<<"Password is not strong as password doesnt: "<<endl;
        for(int i = 0; i < 3;i++)
        {
            cout<<norm[i].ss<<endl;
        }
        return 0;
    }
    else
    {
        cout<<"Password is not strong as password doesnt: "<<endl;
        for(int i = 1; i < 3;i++)
        {
            if(norm[i].ff)
            cout<<norm[i].ss<<endl;
        }
        for(int i = 0;i<2;i++)
        {
            if(admin[i].ff)
            cout<<admin[i].ss<<endl;
        }
    }


}
