#include <iostream>

using namespace std;

int BinarySearch(int *a,const int x,int left, int right)
{
    int middle ;
    while(left <= right)
    {
        middle = (left+right)/2;
        if(x == a[middle])
          return middle;
        if(x>a[middle])
          left = middle +1;
        else 
          right = middle -1;
    }
    if(x>a[middle])
       return middle;
    else 
       return middle -1;
}

void shiftright(int* arry, int s, int t, int k) // i,p,p-j+1
{
    for(int i=0; i< k ;i++)
    {
        int temp = arry[t];
        for(int j=k;j>s;j--)
            arry[j] = arry[j-1];
        arry[s] = temp;
    }
} 
void mergefor(int *arry,int k,int n)
{
    int i = 0, j = k;
    while(i<j && j<n)
    {
        int p = BinarySearch(arry,arry[i],j,n-1);
        shiftright(arry,i,p,p-j+1);   //a[0] -> a[p]  往右循环 p-j+1  个位置for(int i=0; i< k ;i++)
        //i += p-j+ 2;
        //j = p+1;
        j = p+1;
        i+=p - j + 2;
    }
}
int main(){
    int arry[10] = {1 ,2 , 3, 4 ,5 , 2 ,4 ,6 ,8 ,10};
    mergefor(arry,5,10);
    for(int i=0;i<10;i++)
       cout<<arry[i]<<" ";
    return 0;
}
