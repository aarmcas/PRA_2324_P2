#include<iostream>
#include"DyV.h"
#include<vector>

int main(){
	int ini = 0, fin = 4, x = 10;
	int medio = (ini+fin)/2;
	std::vector<int> v{2, 5, 6, 7, 10};
	if(v[ini] < v[fin])
		BusquedaBinaria(x, v, ini, fin);
	else 
		BusquedaBinaria_INV(x, v, ini, fin);
	
	QuickSort(V, ini, fin); 

}
