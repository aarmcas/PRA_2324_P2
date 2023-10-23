#include<iostream>
#include<vector>

void BusquedaBinaria (int x, std::vector<int> v, int ini, int fin){
	if(ini > fin)
		std::cout << "No se encuentra el array" << std::endl;
	int medio = (ini+fin)/2;
	if(v[medio] == x)
		std::cout <<  medio;
	else if(v[medio] > x)
		return BusquedaBinaria(x, v, ini, medio - 1);
	else
		return BusquedaBinaria(x, v, medio + 1, fin);
}

void BusquedaBinaria_INV (int x, std::vector<int>& v, int ini, int fin){
	if(ini > fin)
                std::cout << "No se encuentra el array" << std::endl;
        int medio = (ini+fin)/2;
        if(v[medio] == x)
                std::cout <<  medio;
	else if(v[medio] < x)
                return BusquedaBinaria(x, v, ini, medio - 1);
        else
                return BusquedaBinaria(x, v, medio + 1, fin);

}

void QuickSort (std::vector<int>& v, int ini, int fin){
	if(ini < fin){
		int pivot = Partition(v, ini, fin);
		QuickSort(v, ini, pivot - 1);
		QuickSort(v, pivot + 1, fin);
	}
}

void Partition (std::vector<int>& v, int ini, int fin){
	int x = v[fin];
	int i = ini;
	for(int j = ini; j < fin; j++){
		if(v[j] <= x){
			int aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
		}
	}

}
