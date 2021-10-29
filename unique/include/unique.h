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
 * @tparam Equal o tipo de uma função bool( const Type &a, const Type &b)
 * 
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range  
 * @param eq Uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário
 * 
 * @return Um iterator para o endereço logo após o último elemento do range processado
 * 
 */
template<class InputIt, class Equal>
InputIt unique( InputIt first, InputIt last, Equal eq )
{   
    for (InputIt i = first; i < last; ++i){
        for (InputIt j = i; j >= first; --j){ //! <Laço que se repete do elemento i até o primeiro elemento do range
            if(eq( *i, *j )){ //! <Condicional para verificar se o retorno da função é verdadeiro(o primeiro elemento é igual ao segundo)
                last-=1; //! <Aponta para uma nova posição do range a cada repetição do laço
                std::swap(i,last); //! <Troca as posições de i e last 
            }
        }
    }

  return last;
}

}
#endif
