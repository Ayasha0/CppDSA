#include <iostream>
using namespace std;

int maxSum(int arr[], int n, int k){

int maxi = 0;
    // compute sum of first window of size k
    for(int i=0; i<k; i++){
        maxi += arr[i];
    }

    int window_sum = 0;
    for(int i = k ; ii++){

    }


return maxi;
}

int main() {

    int arr[] = {5,2,-1,0,3};

    cout <<maxSum(arr, 5, 3);


    return 0;
}