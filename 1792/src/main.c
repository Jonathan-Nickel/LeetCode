/*
There is a school that has classes of students and each class will be having a final exam. 
You are given a 2D integer array classes, where classes[i] = [passi, totali]. 
You know beforehand that in the ith class, there are totali total students, 
but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant 
students that are guaranteed to pass the exam of any class they are assigned to. 
You want to assign each of the extraStudents students to a class in a way that 
maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that 
will pass the exam divided by the total number of students of the class. 
The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. 
Answers within 10-5 of the actual answer will be accepted.*/
#include <stdio.h>
#include <stdlib.h>

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents);

int main() {
    int teste;
    do{
    printf("Escolha um teste:\n");
    scanf("%d", &teste);
    
    if ( teste == 1 ) {
        int classesSize = 3;
        int classesColSize[] = {2, 2, 2};
        int* classes[3];
        
        classes[0] = (int*)malloc(2 * sizeof(int));
        classes[1] = (int*)malloc(2 * sizeof(int));
        classes[2] = (int*)malloc(2 * sizeof(int));
        
        classes[0][0] = 1; classes[0][1] = 2;
        classes[1][0] = 3; classes[1][1] = 5;
        classes[2][0] = 2; classes[2][1] = 2;
        int extraStudents = 2;

        double result = maxAverageRatio(classes, classesSize, classesColSize, extraStudents);
        printf("Resultado para Teste 1: %.5f\n", result);
        
        for (int i = 0; i < classesSize; i++) {
            free(classes[i]);
        }
        
    } else if ( teste == 2 ) {
        int classesSize = 4;
        int classesColSize[] = {2, 2, 2, 2};
        int* classes[4];
        
        classes[0] = (int*)malloc(2 * sizeof(int));
        classes[1] = (int*)malloc(2 * sizeof(int));
        classes[2] = (int*)malloc(2 * sizeof(int));
        classes[3] = (int*)malloc(2 * sizeof(int));
        
        classes[0][0] = 2; classes[0][1] = 4;
        classes[1][0] = 3; classes[1][1] = 9;
        classes[2][0] = 4; classes[2][1] = 5;
        classes[3][0] = 2; classes[3][1] = 10;
        
        int extraStudents = 4;
        
        double result = maxAverageRatio(classes, classesSize, classesColSize, extraStudents);
        printf("Resultado para Teste 2: %.5f\n", result);

        for (int i = 0; i < classesSize; i++) {
            free(classes[i]);
        }
        
    }
    } while (teste != 3);
    return 0;
}

/*
============================================================
computeGain
 calcula o valor do ganho caso adicione mais uma pessoa.
============================================================
*/
double computeGain(int pass, int total) {
    return ((double)(pass + 1) / (total + 1)) - ((double)pass / total);
}

/*
========================================================================
 tipo Class que vai ter dois inteiros para guardar o numero de alunos
 aprovados e totais, e um double para guardar o ganho.
========================================================================
*/
typedef struct {
    int pass;
    int total;
    double gain;
} Class;

/*
================================================================================
compare
 estrutura utilizada com o qsort para organizar em ordem crescente os valores.
================================================================================
*/
int compare(const void* a, const void* b) {
    double diff = ((Class*)b)->gain - ((Class*)a)->gain;
    return (diff > 0) - (diff < 0);
}

/*
================================================================================
maxAverageRatio
 aloca dinamicamente a heap, do tamanho necessario para adicionar o numero de
 turmas no tamanho de uma class para cada;
 armazena todos valores de cada turma em uma class;
 organiza em ordem crescente a porcentagem de aprovado das turmas;
 distribui os alunos extras na turma com menor porcentagem de aprovados;
 reorganiza em ordem crescente novamente;
 calcula o total de porcentagens e divide pelo número de turmas e retorna esse valor.
================================================================================
*/

double maxAverageRatio(int** classes, int classesSize, int* classesColSize, int extraStudents) {

    Class* heap = (Class*)malloc(classesSize * sizeof(Class));
    
    for ( int i = 0; i < classesSize; i++ ) {
        heap[i].pass = classes[i][0];
        heap[i].total = classes[i][1];
        heap[i].gain = computeGain(heap[i].pass, heap[i].total);
    }
    
    qsort( heap, classesSize, sizeof(Class), compare );
    
    while ( extraStudents-- > 0 ) {
        heap[0].pass++;
        heap[0].total++;
        heap[0].gain = computeGain(heap[0].pass, heap[0].total);
        qsort(heap, classesSize, sizeof(Class), compare);
    }
    
    double totalRatio = 0.0;
    for ( int i = 0; i < classesSize; i++ ) {
        totalRatio += (double)heap[i].pass / heap[i].total;
    }
    
    free( heap );
    return totalRatio / classesSize;
}
