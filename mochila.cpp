#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> F;  // Tabla de memorización
vector<int> p, b;       // Vectores de pesos y valores

// Función recursiva con memorización para el problema de la mochila
int Mochila(int i, int j) {
    // Caso base: si la tabla de memorización ya tiene el valor, devolverlo
    if (F[i][j] >= 0) {
        return F[i][j];
    }

    // Casos base adicionales
    if (i == 0 || j == 0) {
        return 0;
    }

    // Caso general
    if (j < p[i]) {
        F[i][j] = Mochila(i - 1, j);
    } else {
        F[i][j] = max(Mochila(i - 1, j), b[i] + Mochila(i - 1, j - p[i]));
    }

    return F[i][j];
}

vector<int> ReconstruirSolucion(int numObjetos, int pesoMaximo) {
    vector<int> solucion(numObjetos + 1, 0);

    for (int i = numObjetos, j = pesoMaximo; i > 0; --i) {
        if (F[i][j] != F[i - 1][j]) {
            solucion[i] = 1; // Se incluye el objeto i en la solución
            j -= p[i];
        }
    }

    return solucion;
}


int main() {
    // Entrada de datos
    int pesoMaximo;
    cout << "Ingrese el peso máximo de la mochila: ";
    cin >> pesoMaximo;

    int numObjetos;
    cout << "Ingrese el número de objetos: ";
    cin >> numObjetos;

    p.resize(numObjetos + 1);
    b.resize(numObjetos + 1);

    cout << "Ingrese los pesos de los objetos (separados por espacio): ";
    for (int i = 1; i <= numObjetos; ++i) {
        cin >> p[i];
    }

    cout << "Ingrese el beneficio de los objetos (separados por espacio): ";
    for (int i = 1; i <= numObjetos; ++i) {
        cin >> b[i];
    }

    // Ajustar el tamaño de la tabla de memorización y la tabla de ganancias
    F.resize(numObjetos + 1, vector<int>(pesoMaximo + 1, -1));
    vector<vector<int>> ganancias(numObjetos + 2, vector<int>(pesoMaximo + 1, 0));

    // Rellenar la tabla de ganancias
    for (int i = 1; i <= numObjetos + 1; ++i) {
        for (int j = 1; j <= pesoMaximo; ++j) {
            ganancias[i][j] = max(ganancias[i - 1][j], ganancias[i][j - 1]);

            if (i <= numObjetos && j >= p[i]) {
                ganancias[i][j] = max(ganancias[i][j], ganancias[i - 1][j - p[i]] + b[i]);
            }
        }
    }

    // Imprimir la tabla de ganancias
    cout << "Tabla de ganancias:\n";
    for (int i = 0; i <= numObjetos; ++i) {
        for (int j = 0; j <= pesoMaximo; ++j) {
            cout << ganancias[i][j] << "\t";
        }
        cout << endl;
    }

    // Llamada a la función KnapsackMem para obtener la solución
    int result = Mochila(numObjetos, pesoMaximo);

	// Obtener el vector solución
    vector<int> solucion = ReconstruirSolucion(numObjetos, pesoMaximo);

    // Mostrar la solución
    cout << "Vector solución (1 para incluir, 0 para excluir): x = (";
    for (int i = 1; i < numObjetos; ++i) {
		cout << solucion[i] << ", ";
    }
    cout << solucion[numObjetos] << ")" << endl;


    // Mostrar el resultado
    cout << "El valor máximo que se puede obtener es: " << result << endl;

    return 0;
}
