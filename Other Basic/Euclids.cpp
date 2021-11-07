#include<bits/stdc++.h>
using namespace std;


// Euclids Algo
int gcd(int a,int b){
    if(b==0) return a;

    return gcd(b,a%b);
}

// Seive Of Erastothenes

vector<bool> seiveOfErastothenes(int n){
    vector<bool> isprime(n+1,true);
   // memset(isprime,sizeof(isprime),true);
    isprime[0]=false;
    isprime[1]=false;

    for(int i=2;i*i<=n;i++){
            for(int j=2*i;j<=n;j+=i){
                isprime[j]=false;
            }
    }
    return isprime;
}

int main(){
    int n=20;
    vector<bool> isprime=seiveOfErastothenes(n);
    for(int i=1;i<=n;i++){
        cout << i << " " << isprime[i] << endl;
    }

    int a=24,b=60;
    cout << "GCD of 24 and 60 is " << gcd(24,60) << endl;
    return 0;
}