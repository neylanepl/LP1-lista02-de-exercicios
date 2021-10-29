/**
 * @file copy.h
 * @author Neylane Lopes (neylane.lopes.127@ufrn.edu.br)
 * @version 0.1
 * @date 2021-06-21
 * 
 * @copyright Copyright (c) 2021
 * 
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
 * @return Um iterator para o primeiro elemento no range se o predicado é verdadeiro. Se o predicado for falso em todos os elementos, retona o iterator last
 * 
 */
template<class InputIt, class UnaryPredicate>
InputIt find_if(InputIt first, InputIt last, UnaryPredicate p)
{   
    for (InputIt i = first; i < last; ++i){
      if (p(*i)){ //! <Condicional para verificar se o retorno da função é verdadeiro(um determinado predicado é satisfeito)
        return i;
      }
    }

    return last;
}

}
#endif
