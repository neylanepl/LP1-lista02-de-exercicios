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
 * @tparam InputIt1 iterator para o range
 * @tparam InputIt2 o tipo do valor a ser comparado na função
 * @tparam Equal o tipo de uma função bool( const Type &a, const Type &b)
 * 
 * @param first1 Ponteiro para o primeiro elemento do range
 * @param last1 Ponteiro para a posição logo após o último elemento do range
 * @param first2 O range(ou inicio do range) que deve ser levado em consideração para a comparação
 * @param eq Uma função que retorna true se o primeiro elemento é igual ao segundo, ou falso caso contrário
 * 
 * @return True se todos os elementos do primeiro range são iguais aos do range2, e false caso contrário
 * 
 */
template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, Equal eq)
{   
    if (first1 >= last1){ //! <Condicional para verificar se o range é vazio
        return false;
    }

    for (InputIt1 i = first1; i < last1; ++i){
        if (!eq(*i, *first2)){ //! <Condicional para verificar se o retorno da função é falso(o primeiro elemento é diferente do segundo)
            return false;
        }
        first2+=1; //! <Aponta para uma nova posição do range, que deve ser levado em consideração para a comparação, a cada repetição do laço
    }

    return true;
}

/**
 * 
 * @tparam InputIt1 iterator para o range
 * @tparam InputIt2 o tipo do valor a ser comparado na função
 * @tparam Equal o tipo de uma função bool( const Type &a, const Type &b)
 * 
 * @param first1 Ponteiro para o primeiro elemento do range
 * @param last1 Ponteiro para a posição logo após o último elemento do range
 * @param first2 Ponteiro para o primeiro elemento do range que deve ser levado em consideração para a comparação
 * @param last2 Ponteiro para a posição logo após o último elemento do range que deve ser levado em consideração para a comparação
 * @param eq Uma função que retorna true se o primeiro elemento é igual ao segundo, ou falso caso contrário
 * 
 * @return True quando todos os elementos do range1 são iguais aos do range2 e false caso contrário
 * 
 */
template<class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1,
           InputIt2 first2, InputIt2 last2,
           Equal eq )
{   
    if ((first1 >= last1) || (first2 >= last2)){ //! <Condicional para verificar se o range1 ou range2 são vazios
        return false;
    }

    for (InputIt1 i = first1; i < last1; ++i){ 
        if (!eq(*i, *first2)){ //! <Condicional para verificar se o retorno da função é falso(o primeiro elemento é diferente do segundo)
            return false;
        }
        first2+=1; //! <Aponta para uma nova posição do range, que deve ser levado em consideração para a comparação, a cada repetição do laço
    }
  
    return true;
}

}
#endif
