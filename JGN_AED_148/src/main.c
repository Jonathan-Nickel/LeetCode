/*
Jonathan Goulart Nickel - 23200579
Given the head of a linked list, return the list after sorting it in ascending order.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    return 0;
}

struct ListNode {
    int val;
    struct ListNode *next;
};

/*
================================================================================
merge
 cria um nó cabeça temporario para a lista e um ponteiro tail para o final da lista.
 Enquanto l1 e l2 não forem nulos, compara os valores dos nós.
 Se o valor de l1 for menor que o de l2, adiciona l1 à lista e move l1 para o próximo nó.
 Caso contrário, adiciona l2 à lista e move l2 para o próximo nó.
 Muda o ponteiro tail para o próximo nó adicionado.
 Se l1 ou l2 ainda tiverem nós restantes, adiciona o restante à lista.
 retorna o próximo nó do cabeça temporario, que é o início da lista ordenada.
================================================================================
*/
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode thead;
    struct ListNode *tail = &thead;
    thead.next = NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return thead.next;
};

/*
================================================================================
sortList
 Ve se a cabeça da lista esta vazia ou se tem apenas um elemento.
 Se sim, retorna a cabeça.
 cria dois ponteiros, um para o primeiro elemento e outro para o segundo.
 Enquanto o segundo ponteiro e o próximo do segundo ponteiro não forem nulos,
 move o primeiro ponteiro para o próximo elemento e o segundo ponteiro para o próximo do próximo.
 cria um ponteiro para o meio da lista, que é o próximo do primeiro ponteiro.
 muda o próximo do primeiro ponteiro para nulo, dividindo a lista em duas partes.
 Chama recursivamente sortList para a parte esquerda e direita da lista.
 returna a junção merge com as duas partes ordenadas.
================================================================================
*/
struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next){
        return head;
    }
    struct ListNode *first = head, *proximo = head->next;
    while (proximo && proximo->next) {
        first = first->next;
        proximo = proximo->next->next;
    }
    struct ListNode *mid = first->next;
    first->next = NULL;

    struct ListNode *left = sortList(head);
    struct ListNode *right = sortList(mid);

    return merge(left, right);
}
