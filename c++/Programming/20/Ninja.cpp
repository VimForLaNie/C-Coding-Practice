#include <bits/stdc++.h>
using namespace std;
#define ll long long

int i, total_ninja;
int leader;
ll price = 1e9;
ll leadership;
ll money;
priority_queue< pair<ll, int> > nin;

ll happy(int leader,ll leadership, ll money, priority_queue< pair<ll, int> > nin)
{
    ll cnt = 0;
    ll cost = 0;
    i = 0;
    while (money >= 0 && i < total_ninja)
    {
        if(i == leader){
            i++;
            continue;
        }
        cost = nin.top().first;
        if (money + cost >= 0)
        {
            money += cost;
            cnt++;
        }
        i++;
        nin.pop();
    }
    return leadership * cnt;
}

int main()
{
    cin >> total_ninja >> money;
    pair<pair<ll, ll>, ll> ninja[total_ninja];
    for (i = 0; i < total_ninja; i++)
    {
        cin >> ninja[i].first.first >> ninja[i].first.second >> ninja[i].second;
        nin.push({-ninja[i].first.second, i});
        if(ninja[i].first.first <= price && ninja[i].second >= leadership){
            price = ninja[i].first.first;
            leadership = ninja[i].second;
            leader = i;
        }
    }
    ll ans = happy(leader,leadership,money - price,nin);
	cout << ans << endl;
}	