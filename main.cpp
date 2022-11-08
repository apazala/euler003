#include <iostream>
#include <cstdint>
#include <cmath>
#include <cstring>

using namespace std;

//#define TARGET 13195
#define TARGET 600851475143

int primesList[63000];
int numprimes;

int64_t iscompound[12200];

int64_t compute(int64_t target){
	
	int64_t res = 1;
	
	for(int *pprime = primesList, *primesend = pprime+numprimes, p; pprime < primesend; pprime++){
		p = *pprime;
		if(p*p > target) break;
		
		if(target%p == 0){
			res = p;
			do{
				target /= p;
			}while(target%p == 0);
			
		}
	}
	
	if(target > res){
		res = target;
	}
		
	return res;
}


void fillprimes(int upperBound);

int main(int argc, char **argv)
{
	fillprimes(sqrt(TARGET) + 1);
	
	int res = compute(TARGET);
	
	cout << res << endl;
	
    return 0;
}


#define baisset(ba, i) ((ba)[(i)>>6] & (1ull << ((i) & 63))) != 0
#define baisclear(ba, i) ((ba)[(i)>>6] & (1ull << ((i) & 63))) == 0
#define baset(ba, i) (ba)[(i)>>6] |= (1ull << ((i) & 63))


void fillprimes(int upperBound) {
	int i, j;


	baset(iscompound, 0);
	baset(iscompound, 1);
	int sqrtUb = sqrt(upperBound);
	for (i = 2; i <= sqrtUb; i++) {
		if (baisclear(iscompound, i)) {
			primesList[numprimes++] = i;
			for (j = i*i; j <= upperBound; j += i) {
				baset(iscompound, j);
			}
		}
	}

	for (i = sqrtUb + 1; i <= upperBound; i++) {
		if (baisclear(iscompound, i)) {
			primesList[numprimes++] = i;
		}
	}

}