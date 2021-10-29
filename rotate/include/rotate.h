/**
 * @file copy.h
 * @author Neylane Lopes (neylane.lopes.127@ufrn.edu.br)
 * @version 0.1
 * @date 2021-06-21
 * 
 * @copyright Copyright (c) 2021
 */
#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;
#include <iterator>
using std::distance;
#include <algorithm>
using std::sort;

namespace graal {

/**
 *
 * @tparam ForwardIt iterator para o range
 * 
 * @param first Ponteiro para o primeiro elemento do range
 * @param n_first O elemento que deve aparecer no inicio do range após a rotação
 * @param last Ponteiro para a posição logo após o último elemento do range
 * 
 * @return  Um iterator que aponta para a nova posição que se encontra o primeiro elemento do range antes da rotação
 * 
 */
template<class ForwardIt>
ForwardIt rotate(ForwardIt first, ForwardIt n_first, ForwardIt last)
{   
    
    ForwardIt auxiliar = n_first;
    for (ForwardIt i = first; i < auxiliar; ++i)
    {
        std::swap (*first,*auxiliar); //! <Troca os valores de first e auxiliar 
        first+=1; //! <Aponta para uma nova posição do range a cada repetição do laço
        auxiliar+=1; //! <Aponta para uma nova posição do range a cada repetição do laço
        if (auxiliar == last){ //! <Condicional para verificar se auxiliar aponta para a posição logo após o último elemento do range
            auxiliar = n_first; //! <Realiza a atribuição de n_first a auxiliar(para fazer a troca dos elementos que estão apartir da posição do elemento que deve aparecer no inicio do range após a rotação)
        } 
        else if (first == n_first){ //! <Condicional para verificar se first aponta para a posição do elemento que deve aparecer no inicio do range após a rotação
            n_first = auxiliar; //! <Realiza a atribuição de auxiliar a n_first(para fazer a troca do último elemento do range com o elemento que está na posição do elemento que deve aparecer no inicio do range após a rotação)
        } 
        
    }

    return n_first;
}

}
#endif
