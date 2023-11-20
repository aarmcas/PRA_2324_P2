#include <iostream>
#include <limits>
#include <algorithm>

void cambio(int v[], int M, int N){
	int** matrix = new int*[N];
  		for(int i=0; i<N; i++){
                	matrix[i] = new int[M];
			int n_monedas;
			for(int j = 0; j = M; j++ ){
				if(j = 0)
					n_monedas = 0;
				else if(v[i] == 1)
					n_monedas = j;
				else if(v[i] > j){
					if(v[i-1] < v[i])
						n_monedas = j - v[i-1] + 1;
					else
						n_monedas = j - v[i] + 1;
				}
				else if(j >= v[i])
					n_monedas = j/v[i] + j%v[i];
			}
		}
}

int main(){
	int infinito = std::numeric_limits<int>::max();
	std::min(5,7);
}
