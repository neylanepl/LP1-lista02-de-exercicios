/**
 * @file minmax.h
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

/*! 
 * Exemplo de documentação seguindo o formato Doxygen
 *
 * @tparam Itr iterator para o range.
 * @tparam Compare o tipo de uma função bool(const T &a, const T &b)
 *
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param cmp A função de comparação que retorna true quando o primeiro parâmetro é menor do que o segundo
 *
 * @return Um std::pair contendo o menor e maior elemento, nesta ordem
 *
 */
template <typename Itr, typename Compare >
std::pair<Itr, Itr> minmax( Itr first, Itr last, Compare cmp )
{   
    if ((first >= last)){ //! <Condicional para verificar se o range é vazio
        return std::make_pair(first, first);
    }
    else{
        std::pair<Itr, Itr> MinMax; //! <Um par de valores
        Itr menor = first, maior = first;
        
        for (Itr i = first+1; i < last; ++i){//! <Laço que se repete do segundo elemento do range até o último elemento do range
            if ((cmp(*i, *menor))){ //! <Condicional para verificar se o retorno da função é verdadeiro(o primeiro parâmetro é menor do que o segundo)
                menor = i;
            }
            else if (!cmp(*i, *maior)){ //! <Condicional para verificar se o retorno da função é falso(primeiro parâmetro é maior do que o segundo)
                maior = i;
            }
        }

        MinMax.first = menor; //!< Atribui a primeira ocorrencia do menor elemento do range ao primeiro elemento do par
        MinMax.second = maior; //!< Atribui a primeira ocorrencia do maior elemento do range ao segundo elemento do par

        return MinMax;
    }
    
}

}
#endif
