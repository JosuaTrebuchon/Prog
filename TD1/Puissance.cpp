#include <iostream>
#include <ctime>
#include <cstdlib>

int Puissance(int x, unsigned int n){
	int puis = 1;
	for(unsigned int i = 0; i<n; ++i){
		puis*=x;
	}
	return puis;
}

int PuissanceRecursive(int x, unsigned int n){
	if(n>=1){
		return x*PuissanceRecursive(x,n-1);
	}
	if(n==0){
		return 1;
	}
	return 0;
}

/*
int PuissanceRecursive(int x, unsigned int n){
	if(n>0){
	return x*PuissanceRecursive(x,n-1);
	}else{return 1;}
	return 0;
}

int PuissanceRecursive(int x, unsigned int n){
	return (n==0 ? 1 : x*PuissanceRecursive(x,n-1));
}

*/

int PuissanceOptimal(int x, unsigned int n){
	if(n==0){return 1;}
	else{
		return (n%2==0 ? PuissanceOptimal(x*x, n/2) : x*PuissanceOptimal(x*x, (n-1)/2));
	}
}


int PuissanceOptimal1(int x, unsigned int n){
	int aux = x;
	int res = 1;
	while(n>0){
		if(n%2==1){//n impair
			res *= aux;
		}
		aux *= aux;
		n/=2;
	}
	return res;
}


int main(int argc, char ** argv) {
	int x = 2;
	unsigned int n = 31;
	std::cout << x << " à la puissance " << n << " = " << Puissance(x,n) << std::endl;

	std::cout << PuissanceRecursive(x,n) << std::endl;
	std::cout << PuissanceOptimal(x,n) << std::endl;
	std::cout << PuissanceOptimal1(x,n) << std::endl;

	return 0;
}