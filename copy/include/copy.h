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
 *
 * @param first Ponteiro para o primeiro elemento do range
 * @param last Ponteiro para a posição logo após o último elemento do range
 * @param d_first Ponteiro para o inicio do range onde os elementos devem ser copiados
 * 
 * @return Um iterator apontando para a posição logo após o último elemento do range prenchido
 * 
 */
template<class InputIt>
InputIt copy(InputIt first, InputIt last, InputIt d_first)
{	
	for (InputIt i = first; i < last; ++i){
		*d_first = *i; //!< Copia um valor do range dentro de um novo range que inicia em d_first

		d_first+=1; //!< d_first aponta para uma nova posição do range a cada repetição do laço
	}

	return d_first;
}

}
#endif
