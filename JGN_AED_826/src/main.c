//Jonathan Goulart Nickel - 23200579
/*
You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).

Every worker can be assigned at most one job, but one job can be completed multiple times.
For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.
*/

/*
Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
*/


//Cada trabalhador não pode pegar um trabalho com dificuldade maior que seu nivel.
//organiza os valores em ordem de dificuldade, todas maiores que o trabalhador não interessam, organiza em ordem de dinheiro e pega a maior.


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int difficulty;
    int profit;
} Task;

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize);
int DifficultyLowerHigher(const void* a, const void* b);
int WorkersLowerHigher(const void* a, const void* b);

int main()
{
    int difficulty[] = {2, 4, 6, 8, 10};
    int profit[] = {10, 20, 30, 40, 50};
    int worker[] = {4, 5, 6, 7};

    int difficultySize = sizeof(difficulty) / sizeof(difficulty[0]);
    int profitSize = sizeof(profit) / sizeof(profit[0]);
    int workerSize = sizeof(worker) / sizeof(worker[0]);

    int result = maxProfitAssignment(difficulty, difficultySize, profit, profitSize, worker, workerSize);

    printf("Lucro máximo total: %d\n", result);

    return 0;
}

/*
=============================================================================
maxProfitAssignment
 Aloca a quantidade de tasks necessárias e junta as dificuldades dos valores.
 Chama a função que organiza o vetor das tasks em ordem crescente.
 Chama a função que organiza o vetor dos funcionarios em ordem crescente.
 Percorre cada trabalhador por todas dificuldades.
 Se a dificuldade for menor ou igual ao nivel do trabalhador verifica o valor
 da atividade, se for o maior valor salva ela como a atividade que ele faz.
=============================================================================
*/
int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {

    int totalProfit = 0, taskIndex = 0, maxProfit = 0;
    Task* tasks = (Task*)malloc(difficultySize * sizeof(Task));
    
    for (int i = 0; i < difficultySize; i++) {
        tasks[i].difficulty = difficulty[i];
        tasks[i].profit = profit[i];
    }

    qsort(tasks, difficultySize, sizeof(Task), DifficultyLowerHigher);
    
    qsort(worker, workerSize, sizeof(int), WorkersLowerHigher);

    for (int i = 0; i < workerSize; i++) {
        while (taskIndex < difficultySize && tasks[taskIndex].difficulty <= worker[i]) {
            if (tasks[taskIndex].profit > maxProfit) {
                maxProfit = tasks[taskIndex].profit;
            }
            taskIndex++;
        }
        totalProfit += maxProfit;
    }

    free(tasks);
    return totalProfit;
}

/*
=============================================================================
DifficultyLowerHigher
 Organiza o vetor das tasks em ordem crescente com base na dificuldade.
=============================================================================
*/
int DifficultyLowerHigher(const void* a, const void* b) {
    return ((Task*)a)->difficulty - ((Task*)b)->difficulty;
}

/*
=============================================================================
WorkersLowerHigher
 Organiza o vetor dos trabalhadores em ordem crescente.
=============================================================================
*/
int WorkersLowerHigher(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}