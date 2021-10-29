/**
 * @file reverse.h
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
 * @tparam BidirIt iterator para o range
 * 
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * 
 */
template<class BidirIt>
void reverse(BidirIt first, BidirIt last)
{   
    for (BidirIt i = first; i < last-1; ++i){
        last-=1; //! <Aponta para uma nova posição do range a cada repetição do laço
        std::swap(*i,*last); //! <Troca os valores de i(aponta para uma nova posição do range a cada repetição do laço) e last 
    }

}

}
#endif
