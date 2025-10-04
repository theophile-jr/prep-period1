#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void sieve(int n) {
    bool primes[n+1];
    for(int i=0;i<=n;i++) primes[i]=true;
    primes[0]=primes[1]=false;

    for(int i=2;i<=sqrt(n);i++) {
        if(primes[i])
            for(int j=i*i;j<=n;j+=i)
                primes[j]=false;
    }

    for(int i=2;i<=n;i++)
        if(primes[i]) printf("%d ", i);
}

int main() {
    sieve(30);
    return 0;
}
