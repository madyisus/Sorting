#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <iostream>
#include "sort_algorithm.h"

using namespace std;

int main(int argc, char *argv[]){

    //-------------esta sección hace el ordenamiento del array entregado como input usando un algoritmo dado---------------
    int n;
    string selected_algorithm;

    switch(atoi(argv[1])){        // selecciona el algoritmo a usar dependiendo del valor de argv[1]
    case 5: selected_algorithm = "selectionSort"; break;
    case 4: selected_algorithm = "std"; break;
    case 3: selected_algorithm = "bubblesort"; break; 
    case 2: selected_algorithm = "mergeSort"; break;  
    default: selected_algorithm = "quicksort"; break; 
  }

    if((argc > 2) && (strcmp(argv[2],"--test") == 0)){
    cin >> n;       // lee el tamaño del array y el array a partir
    int arr[n];     // del archivo correspondiente

    for(int i = 0; i < n;i++)
        cin >> arr[i];

    int arr_size = sizeof(arr) / sizeof(arr[0]);

    array_sort(arr,arr_size,selected_algorithm);    // Ejecuta el algoritmo de ordenamiento sobre array
    printArray(arr,n); 
    return 0;                             // imprime el array ya ordenado
    }
    //--------------------la sección siguiente testea el algoritmo para un n cada vez mas grande ---------------------------

  int i, n_1, N, num_of_experiments;
  string outfile_name = selected_algorithm + "_results.csv";
  ofstream outfile(outfile_name);
  string column_names = "n,time[ms]\n";
  outfile << column_names;

  i = 50, n_1 = 1, N = 5000, num_of_experiments = 10;

  // Se mide el tiempo promedio de ejecucion del algoritmo
  for(int n = n_1; n <= N; n += i){
    cout<<n<<endl;
    double mm_total_time = 0;
    
    int an_array[n];                  // se genera un array de tamaño n
    generateRandomArray(an_array,n);  // se llena el array con numeros enteros aleatorios
    sort(an_array,an_array+n);
    //sort(an_array,an_array+n/2);

    for(int j = 0; j < num_of_experiments; j++){ 
      long long single_execution_time = execution_time_ms(array_sort, an_array, n, selected_algorithm);
      mm_total_time += single_execution_time;
    }
    double mm_avg_time = mm_total_time / num_of_experiments;
    outfile << n << "," << mm_avg_time <<endl;
  }
  outfile.close(); 
    return 0;
}