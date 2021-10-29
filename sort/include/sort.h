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
 * @tparam Comparison o tipo de uma função bool( const Type &a, const Type &b)
 * 
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param cmp Uma função que retorna true se o primeiro elemento é menor do que o segundo, ou false caso contrário
 * 
 */
template<class ForwardIt, class Comparison>
void sort(ForwardIt first, ForwardIt last, Comparison cmp)
{
    int contador;

    for (ForwardIt i = first+1; i < last; ++i){ //! <Laço que se repete do segundo elemento até o último elemento do range
        contador = 0;
        for (ForwardIt j = i-1; j >= first; --j){ //! <Laço que se repete do elemento i-1 até o primeiro elemento do range
            if (cmp(*(i-contador), *j)){ //! <Condicional para verificar se o retorno da função é verdadeiro(o primeiro parâmetro é menor do que o segundo)
                std::swap(*j, *(i-contador)); //! <Troca o valor de j com algum valor antes(ou igual) a i
            }
            contador+=1; //! <Incrementa 1 a contador a cada repetição do laço interno
        }       
    }
}

}
#endif
