/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:22:00 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/08 19:06:55 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include <iostream>

Character::Character()
    : name_(""), slot_cnt_(0)
{
    for (int i = 0; i < kMaxSlot; i++)
        slots_[i] = NULL;
}

Character::Character(const Character &origin) {

}

Character::Character(const std::string &name)
    : Character()
{
    name_ = name;
}

Character::~Character() {}

Character &Character::operator=(const Character &rhs) {

}

std::string const &Character::getName() const { return name_; }

void Character::equip(AMateria *m) {
    if (slot_cnt_ == kMaxSlot)
        std::cout << name_ << "'s slot is full" << std::endl;
    else {
        slots_[slot_cnt_ - 1] = m;
        std::cout << name_ << "gets " << m->getType() << "material." << std::endl;
        slot_cnt_++;
    }
}

void Character::unequip(int idx) {
    if (slot_cnt_ == 0)
        std::cout << name_ << "doesn't have material." << std::endl;
    else if (idx > kMaxSlot || idx < 0)
        std::cout << "range out of idx" << std::endl;
    else {
        std::cout << name_ << " drops " << slots_[idx] << " material." << std::endl;
        slots_[idx] = NULL;
        slot_cnt_--;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (slot_cnt_ == 0)
        std::cout << name_ << "doesn't have material." << std::endl;
    else if (idx > kMaxSlot || idx < 0)
        std::cout << "range out of idx" << std::endl;
    else
        slots_[idx]->use(target);
}