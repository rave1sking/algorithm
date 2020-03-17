#include <iostream>

using namespace std;
void reverse(int *a, int from, int to) {
	while(from<to)
    {
        swap(a[from],a[to]);
        from++;
        to--;
    }
}
 
//循环右移num位 时间复杂度O(n)
void RightRotate(int *a, int n, int k) {
	reverse(a, 0, k-1);
	reverse(a, k, n-1);
	reverse(a, 0, n-1);
}

int main(){
    int arr[10] = {1,2,3,4,5,2,4,6,8,10};
    RightRotate(arr,10,5);
}
