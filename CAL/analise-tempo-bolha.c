#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <Windows.h>

LARGE_INTEGER inicio, fim, tempo, frequencia;
const int N = 50000;
int i, j, l, aux;

//----------------------------------------------------
void vetorPreenche( int *v ){
    /// inicializa uma semente de n�meros aleat�rios
    srand ( time(NULL) );
    for(i=0; i<N; i++){
        v[i] = rand() % 1000;
    }
}
//----------------------------------------------------
void vetorMostra( int *v ){
    for(i=0; i<N; i++)
        printf("%i ", v[i]);
    puts("");
}
//----------------------------------------------------
double time_diff(struct timeval x , struct timeval y){
    double diff;
    diff = (y.tv_sec - x.tv_sec) + 1e-6 * (y.tv_usec - x.tv_usec); /* in seconds */
    return diff;
}
//----------------------------------------------------
void bubbleSort(int *vetor){
    for( i=0; i<N; i++ ){
        for( j=i+1; j<N; j++ ){
            if( vetor[j] < vetor[i] ){
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
    }
}
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
int main(){
    int vetor[N];
    vetorPreenche( vetor );
    //vetorMostra( vetor );

    // Inicia o rel�gio para contar o tempo
    QueryPerformanceFrequency( &frequencia );
    QueryPerformanceCounter( &inicio );

    // Tarefa a qual queremos medir o tempo de execu��o (aproxima��o em microssegundos)
    bubbleSort( vetor );

    // Interrompe o rel�gio e calcula o n�mero de microsegundos da opera��o
    QueryPerformanceCounter( &fim );
    tempo.QuadPart = fim.QuadPart - inicio.QuadPart;
    tempo.QuadPart *= 1000000;
    tempo.QuadPart /= frequencia.QuadPart;
    printf("Tempo da ordenacao: %li us\n" , tempo );
    printf("Relogio parado... Pressione qualquer tecla para continuar\n" );
    getchar();

    //-------------------------------------------------------------------------
    // Inicia o rel�gio para contar o tempo
    QueryPerformanceFrequency( &frequencia );
    QueryPerformanceCounter( &inicio );

    vetorMostra( vetor ); // teste do printf

    // Interrompe o rel�gio e calcula o n�mero de microsegundos da opera��o
    QueryPerformanceCounter( &fim );
    tempo.QuadPart = fim.QuadPart - inicio.QuadPart;
    tempo.QuadPart *= 1000000;
    tempo.QuadPart /= frequencia.QuadPart;
    printf("Tempo para mostrar o vetor: %li us\n" , tempo );

    return 0;
}
