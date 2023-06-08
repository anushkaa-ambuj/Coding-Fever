#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

struct Lamp{
    int a, b;
};

bool compareb(const Lamp& l1, const Lamp& l2){
    return l1.b > l2.b;
}

bool comparea(const Lamp& l1, const Lamp& l2){
    return l1.a < l2.a;
}

int MaxScore(int n, vector<Lamp>& lamps){
    sort(lamps.begin(), lamps.end(), compareb);
    sort(lamps.begin(), lamps.end(), comparea);
    
    int x = 0;
    int score = 0;
    for (int i=0;i<n;i++)
    {
        if (x < lamps[i].a){
            x++;
            score += lamps[i].b;
        }
    }
    return score;
}

int main(){
    int t,n;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        cin>>n;
        vector<Lamp> lamps(n);

        for (int j=0;j<n;j++)
        {
            cin>>lamps[j].a>>lamps[j].b;
        }

        int maxscore = MaxScore(n,lamps);
        cout<<maxscore<<endl;
    }
    return 0;
}