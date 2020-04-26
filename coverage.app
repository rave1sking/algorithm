#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coverage(vector<int> x,int k){
    int sum =1 , n = x.size();
    sort(x.begin(),x.end());           //在数轴上表示出来
    for(int i=1, temp = x[0];i<n;i++)
    {
        if(x[i] - temp > k)
        {
            sum++;
            temp = x[i];
        }
    }
    return sum;
}
int main()
{
    vector<int> x;
    int n,k;
    cin>>n>>k;
    int in;
    for(int i=0;i<n;i++)
    {
        cin>>in;
        x.push_back(in);
    }
    cout<<coverage(x,k);
}


//1.用vector<int x> 存放点集，并用sort函数排序。
//2.令temp = x[0]依次遍历该vector数组，若x[i] - temp > k，即规定的覆盖范围覆盖不到x[i]，则覆盖数sum+1。
//3.返回值sum即为最小覆盖数。
