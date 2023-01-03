#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIN 0.55 // try 0.25 also
#define GAMMA 0.9
#define EPSILON 0.001

// Reinforcement Learning: An Introduction by Sutton and Barto. Exercise 4.8

double absolute(double a){
	if(a > 0){
		return a;
	}
	return -a;
}

double max(double a, double b){
	if(a > b){
		return a;
	}
	return b;
}

double sum(int a, int s, double* v){
	double ret = 0;
	ret += WIN*((a+s == 100) + GAMMA*v[s+a]);
	ret += (1-WIN)*GAMMA*v[s-a];
	return ret;
}

int main(){
	double delta, temp;
	double* v = malloc(101*sizeof(double));
	for(int i = 0; i < 100; i++){
		v[i] = (double)i/(double)100;
	}
	v[100] = 1;
	do{
		delta = 0;
		for(int s = 1; s < 100; s++){
			temp = -1;
			for(int a = 1; a <= s && a <= (100-s); a++){
				temp = max(temp, sum(a, s, v));
			}
			delta = max(delta, absolute(temp-v[s]));
			v[s] = temp;
		}
	}
	while(delta > EPSILON);

	int* pi = malloc(sizeof(int)*99);
	printf("State\tAction\tValue\n");
	for(int s = 1; s < 100; s++){
		int max_a;
		double max = -1;
		double temp;
		for(int a = 1; a <= s && a <= (100-s); a++){
			temp = sum(a, s, v);
			if(temp > max){
				max_a = a;
				max = temp;
			}
		}
		pi[s-1] = max_a;
		printf("%d\t%d\t%lf\n", s, max_a, v[s]);
	}
	
	return 0;
}
