#include<iostream>

using namespace std;

int factorial(int n){
    if (n ==0){
        return 1;
    }else{
        return (n * factorial(n-1));
    }   
}

int main(){
    int n;
    cout<< "enter a number: ";
    cin >> n;
    cout << "the factorial of " << n << " is "<<factorial(n);
    return 0;
}

