/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:00:00 by vrads             #+#    #+#             */
/*   Updated: 2026/10/23 15:18:48 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base {
    public:
        virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif
