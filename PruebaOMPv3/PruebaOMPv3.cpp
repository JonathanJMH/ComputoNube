// Solucion suma de arreglos en paralelo
// Jonathan Marmolejo Hernández - A01795195
// Inteligencia Artificial Aplicada - Cómputo en la nube (GPO10)

// Declaración de librerías a utilizar en el programa.
#include <iostream>
#include <omp.h>

// Validación de ejecución de directivas de OMP
int main()
{
    std::cout << "Verificando la ejecucion de directivas de OMP: ";

    # ifdef _OPENMP
       std::cout << "OMP disponible y funcionando" << std::endl;
    # endif

// Definición de variables iniciales y sus respectivos valores  
#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float *d);

    std::cout << "\nSumando arreglos en paralelo\n";
    float a[N], b[N], c[N];
    int i;

// Declaración del primer ciclo for para calculo de variables a y b
    for (i = 0; i < N; i++)
    {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
    }
    int pedazos = chunk;

    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)

// Declaración del segundo ciclo for para calculo de la variable c
    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];
    
// Impresión de valores de arreglos 
    std::cout << "\nimprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
}

// Separación de valores y colocación de división
void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}
