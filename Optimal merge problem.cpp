最优合并问题。
问题描述：给定k个排好序的序列s1,s2, …, sk，用2路合并算法将这k个序列合并成一个序列。假设采用的2路合并算法合并2个长度分别为m和n的序列需要m+n-1次比较。试设计一个算法确定合并这个序列的最优合并顺序，使所需的总比较次数最少。
为了进行比较，还需要确定合并这个序列的最差合并顺序，使所需的总比较次数最多。
算法设计：对于给定的k个待合并序列，计算最多比较次数和最少比较次数合并方案。（提示：可采用huffman算法，贪心策略：每次选最短的序列合并得到最少比较次数；每次选最长的序列合并得到最多比较次数。）

设计思路
//每次选最小的序列合并得到最少比较次数；
//每次选最大的序列合并得到最多比较次数。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sort1(int x,int y)
{
    return x>y;
}
bool sort2(int x,int y)
{
    return x<y;
}
int merge(vector<int> x)
{
    int sum = 0;
    int num = x[0];
    for(int i=1;i<x.size();i++)
    {
        sum += num + x[i] - 1;
        num += x[i];
    }
    return sum;
}

int main()

{
    vector<int> x1;
    vector<int> x2;
    int n ;
    cin>>n;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        x1.push_back(temp);
        x2.push_back(temp);
    }
    sort(x1.begin(),x1.end(),sort1);
    sort(x2.begin(),x2.end(),sort2);
    cout<<"max:"<<merge(x1)<<endl;
    cout<<"min:"<<merge(x2)<<endl;
}

input:
4
5 12 11 2
output:
max:78
min:52
