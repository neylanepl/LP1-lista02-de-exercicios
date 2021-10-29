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
 * @tparam InputIt iterator para o range
 * @tparam UnaryPredicate o tipo de uma função bool( const Type &a)
 * 
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário
 * 
 * @return True se todos os elementos do range satisfazem p, false caso contrário
 * 
 */
template<class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p)
{
    if (first >= last){ //! <Condicional para verificar se o range é vazio
        return false;
    }
    
    for (InputIt i = first; i < last; ++i){
        if (!p(*i)){ //! <Condicional para verificar se o retorno da função é falso(o predicado p é falso para algum elemento do range)
            return false;
        }
    }

    return true;
}

/**
 * 
 * @tparam InputIt iterator para o range
 * @tparam UnaryPredicate o tipo de uma função bool( const Type &a)
 * 
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário
 * 
 * @return True se ao menos um elemento do range satisfaz p, false caso contrário
 * 
 */
template<class InputIt, class UnaryPredicate>
bool any_of(InputIt first, InputIt last, UnaryPredicate p)
{
    for (InputIt i = first; i < last; ++i){
        if (p(*i)){ //! <Condicional para verificar se o retorno da função é verdadeiro(o predicado p é verdadeiro para pelo menos um elemento do range)
            return true;
        }
    }

    return false;
}

/**
 * 
 * @tparam InputIt iterator para o range
 * @tparam UnaryPredicate o tipo de uma função bool( const Type &a)
 * 
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param p Uma função que retorna true quando uma determinada condição é satisfeita ou falso caso contrário
 * 
 * @return True se todos os elementos do range não satisfazem p, false caso contrário
 * 
 */
template<class InputIt, class UnaryPredicate>
bool none_of(InputIt first, InputIt last, UnaryPredicate p)
{   
    if (first > last){ //! <Condicional para verificar se o range é vazio
        return false;
    }

    for (InputIt i = first; i < last; ++i){
        if (p(*i)){ //! <Condicional para verificar se o retorno da função é verdadeiro(o predicado p é verdadeiro para pelo meno um elemento do range)
            return false;
        }
    }

    return true;
}

}
#endif
