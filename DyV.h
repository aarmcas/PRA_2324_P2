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
