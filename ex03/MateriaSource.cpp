/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:51:38 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/09 01:02:26 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <string>
#include <iostream>

MateriaSource::MateriaSource() 
  : create_cnt_(0), learn_cnt_(0)
{
  for (int i = 0; i < kMaxCreateMateria; i++)
    create_slot_[i] = NULL;
  for (int i = 0; i < kMaxSlot; i++)
    learn_slot_[i] = NULL;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < create_cnt_; i++)
    delete create_slot_[i];
  for (int i = 0; i < learn_cnt_; i++)
    delete learn_slot_[i];
}

void MateriaSource::learnMateria(AMateria *m) {
  if (m && learn_cnt_ < kMaxSlot) {
    learn_slot_[learn_cnt_] = m;
    learn_cnt_++;
  }
  else if (learn_cnt_ == kMaxSlot) {
    std::cout << "learnMateria is full" << std::endl;
    delete m;
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  if (type != "ice" && type != "cure") {
    std::cout << "Wrong type" << std::endl;
    return NULL;
  }
  else if (create_cnt_ >= kMaxCreateMateria) {
    std::cout << "Can't create materia. Because materia source is empty" << std::endl;
    return NULL;
  }

  AMateria *m = NULL;

  if (type == "ice")
    m = new Ice;
  else if (type == "cure")
    m = new Cure;

  create_slot_[create_cnt_] = m;
  create_cnt_++;
  return m;
}
