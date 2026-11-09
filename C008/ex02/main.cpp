/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 18:50:44 by vrads             #+#    #+#             */
/*   Updated: 2026/11/09 19:31:37 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "MutantStack.hpp"


static void testSubject()
{
    std::cout << std::endl << "--- Test subject ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    (void)s;
}


static void testList()
{
    std::cout << std::endl << "--- Test with list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}


static void printConst(const std::string& name, const MutantStack<int>& ms)
{
    std::cout << name << ": ";
    for (MutantStack<int>::const_iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    //*ms.begin() = 5;   // <- no compilaría: es const
}

static void testCopyConst()
{
    std::cout << std::endl << "--- Const_iterator and copy---" << std::endl;
    MutantStack<int> a;
    a.push(1);
    a.push(2);

    MutantStack<int> b(a);  // nace como copia de a
    b.push(3);

    MutantStack<int> c;
    c = a;
    c.pop();

    printConst("a", a);
    printConst("b", b);
    printConst("c", c); 
}



static void testModify()
{
    std::cout << std::endl << "--- Modify with iterator ---" << std::endl;
    MutantStack<int> ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        *it *= 100;
    std::cout << "top() = " << ms.top()  << std::endl;
}


static void testEmpty()
{
    std::cout << std::endl << "--- Empty stack ---" << std::endl;
    MutantStack<int> ms;
    std::cout << "empty() -> " << ms.empty() << std::endl;
    std::cout << "begin() == end() -> "
              << (ms.begin() == ms.end()) << std::endl;
}


static void testOtherTypes()
{
    std::cout << std::endl << "--- string type & vector ---" << std::endl;
    MutantStack<std::string, std::vector<std::string> > ms;
    ms.push("hola");
    ms.push("soy");
    ms.push("Vradiss");
    for (MutantStack<std::string, std::vector<std::string> >::iterator it = ms.begin();
         it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}



int main()
{
    testSubject();
    testList();
    testCopyConst();
    testModify();
    testEmpty();
    testOtherTypes();
    return 0;
}
