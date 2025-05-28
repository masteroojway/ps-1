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
    cin.tie(0);

    ifstream javaFile("test.java");
    if (!javaFile.is_open()) {
        cout << "Not able to open file." << endl;
        return 0;
    }

    string s;
    ll ans = 0;
    bool block = false; // present inside block (/*  */)

    while (getline(javaFile, s)) {
        for(int i = 0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                s.erase(s.begin() + i);i--;
            }
        }
        if (s.empty()) continue;

        bool line = false; //line is counted
        bool quote = false; //we are present inside a quote (" cfhsdhjab ")

        for (int i = 0; i < s.size(); i++) {
            // Skip rest of line after // if not in string or block comment
            if (!quote && !block && i + 1 < s.size() && s[i] == '/' && s[i + 1] == '/') {
                break;
            }
            // Start of block
            if (!quote && i + 1 < s.size() && s[i] == '/' && s[i + 1] == '*') {
                block = true;
                i++;
                continue;
            }

            // End of block comment
            if (!quote && block && i + 1 < s.size() && s[i] == '*' && s[i + 1] == '/') {
                block = false;
                i++;
                continue;
            }
            // Skip anything inside block comment if */ is not found
            if (block) continue;
            else line = true;

            // Toggle quote state (ignore escaped quotes)
            if (s[i] == '"') {
                quote = !quote;
                continue;
            }
        }

        if (line && !block) ans++;
    }

    cout << ans << endl;
}
