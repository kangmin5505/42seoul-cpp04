/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:15:20 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/09 01:02:45 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

#include <iostream>

// #include <cstdlib> // check memory

int main()
{
    std::cout << "===== Basic test =====" << std::endl;

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    std::cout << std::endl;

    std::cout << "===== Inventory test =====" << std::endl;

    IMateriaSource *m = new MateriaSource;
    m->learnMateria(new Ice());
    m->learnMateria(new Cure());
    m->learnMateria(new Ice());
    m->learnMateria(new Cure());
    m->learnMateria(new Ice()); // error : leanMateria is full


    ICharacter *kang = new Character("kang");
    AMateria *temp;
    ICharacter* bob1 = new Character("bob");
    kang->use(0, *bob1); // don't do anything
    temp = m->createMateria("wrong value"); // error : wrong type
    kang->equip(temp); // error : AMateria is NULL
    temp = m->createMateria("ice");
    kang->equip(temp);
    temp = m->createMateria("cure");
    kang->equip(temp);
    temp = m->createMateria("cure");
    kang->equip(temp);
    temp = m->createMateria("ice");
    kang->equip(temp);
    temp = m->createMateria("ice"); // error : Can't create material
    kang->equip(temp); // error : AMateria is NULL
    kang->unequip(0);
    kang->unequip(1);
    kang->unequip(0); // error : Inventory of idx is empty
    kang->unequip(2);
    kang->unequip(3);
    kang->unequip(4); // don't do anything


    kang->use(0, *bob1);
    kang->use(1, *bob1);
    kang->use(2, *bob1);
    kang->use(3, *bob1);
    kang->use(4, *bob1); // error : range out of idx

    delete m;
    delete bob1;
    delete kang;
    std::cout << std::endl;

    std::cout << "===== Deep copy test =====" << std::endl;
    IMateriaSource *m1 = new MateriaSource;
    ICharacter* bob2 = new Character("bob");
    Character c("copy_test");

    temp = m1->createMateria("ice");
    c.equip(temp);
    temp = m1->createMateria("ice");
    c.equip(temp);

    Character c2(c);
    Character c3;

    c3 = c2;

    c2.use(0, *bob2);
    c3.use(1, *bob2);

    delete m1;
    delete bob2;
    std::cout << std::endl;

    // system("leaks main"); // check memory
    return 0;
}
