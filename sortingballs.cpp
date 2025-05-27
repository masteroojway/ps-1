#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = int(a); i < int(b); i++)
#define ff first
#define ss second
#define ll long long
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define sqr(a) ((a)*(a))
void inserting(vector<int> &balls, int num)
{
    if(balls.empty())
    {
        balls.push_back(num);
        return;
    }
    int n = balls.size();
    if(num>=balls[n-1]){
        balls.push_back(num);
        return;
    }
    // implementing binary search for getting index to insert the given number
    int low = 0, high = n-1, ans = 0;
    while(low<=high)
    {
        ll mid = (low+high)/2;
        if (balls[mid] == num) {
            ans = mid;
            break;
        }        
        if(balls[mid]>num)
        {
            high = mid - 1;
            continue;
        }
        if(balls[mid]<num)
        {
            ans = mid+1;
            low = mid+1;
            continue;
        }
    }
    balls.insert(balls.begin() + ans, num);
    return;

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> temp;
    for(int i = 0; i < 60;i++)
    {
        temp.push_back(i);
    }
    random_device rd;
    mt19937 gen(rd());
    vector<int> balls;
    int k = rand() % 15 + 1;
    shuffle(temp.begin(), temp.end(), gen);
    
    for(int i = 0; i < k;i++)
    {
        inserting(balls, temp[i]);
    }
    for(int i = 0; i < balls.size();i++)
    {
        cout<<balls[i]<<' ';
    }
    cout<<endl;
    
}
