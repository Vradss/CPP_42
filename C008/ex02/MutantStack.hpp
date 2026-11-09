/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 18:50:39 by vrads             #+#    #+#             */
/*   Updated: 2026/11/09 18:50:40 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>


template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:

    // Constructor por defecto: crea una stack vacía (llama al de std::stack).
    MutantStack() : std::stack<T, Container>() {}

    // Constructor de copia: copia la parte std::stack de "other" (o sea, su c).
    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}

    MutantStack& operator=(const MutantStack& other)
    {
        if (this != &other)
            std::stack<T, Container>::operator=(other);
        return *this;
    }

    ~MutantStack() {}

    //tenemos que usar iteradores porque la unica forma de ver elementos seria con pop()
    //y si lo hacemos con pop destruimos el stack
    typedef typename Container::iterator                iterator;
    typedef typename Container::const_iterator          const_iterator;
    typedef typename Container::reverse_iterator        reverse_iterator;
    typedef typename Container::const_reverse_iterator  const_reverse_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end()   const { return this->c.end(); }
    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend()   { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend()   const { return this->c.rend(); }
};



#endif
