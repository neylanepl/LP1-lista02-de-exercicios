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
 * @tparam UnaryPredicate o tipo de uma função bool( const Type &a)
 * 
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range 
 * @param p  Uma função que retorna true quando uma determinada condição é satisfeita ou false caso contrário
 * 
 * @return Um iterator apontando para o endereço logo após o último elemento para qual o predicado é verdadeiro
 * 
 */
template<class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    if (first >= last){ //! <Condicional para verificar se o range é vazio
        return last;
    }

    for (ForwardIt i = first; i < last; ++i){
        if (p(*i)){ //! <Condicional para verificar se o retorno da função é verdadeiro(um determinado predicado é satisfeito)
            std::swap(*i, *first); //! <Troca os valores de i e last
            first+=1; //! <Aponta para uma nova posição do range a cada repetição do laço
        }

    }

    return first;
}

}
#endif
