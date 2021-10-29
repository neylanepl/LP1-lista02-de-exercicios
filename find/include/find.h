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
 * @tparam T o tipo do valor a ser comparado na função
 * @tparam Equal o tipo de uma função bool( const Type &a, const Type &b)
 * 
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range 
 * @param value Valor a ser comparado na função
 * @param eq Uma função que retorna true se o elemento é igual ao segundo, ou falso caso contrário
 * 
 * @return Um iterator para o primeiro elemento no range que é igual ao valor recebido por parâmetro. Se o valor não for encontrado no range, a função deve retornar o iterator last
 * 
 */
template<class InputIt, class T, class Equal>
InputIt find(InputIt first, InputIt last, const T& value, Equal eq)
{   
    for (InputIt i = first; i < last; ++i){
        if (eq(*i, value)){//! <Condicional para verificar se o retorno da função é verdadeiro(quando dois elementos recebidos por parâmetro são iguais);
            return i;
        }
    }

    return last;
}

}
#endif
