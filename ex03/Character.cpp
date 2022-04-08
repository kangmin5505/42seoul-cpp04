/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:22:00 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/09 01:01:16 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

#include <iostream>

Character::Character()
    : name_(""), inventory_cnt_(0)
{
    for (int i = 0; i < kMaxSlot; i++)
        inventory_[i] = NULL;
}

Character::Character(const Character &origin) {
    if (this != &origin) {
        inventory_cnt_ = origin.inventory_cnt_;
        name_ = origin.name_;

        for (int i = 0; i < inventory_cnt_; i++)
            inventory_[i] = origin.inventory_[i]->clone();
    }
}

Character::Character(const std::string &name)
    : name_(name), inventory_cnt_(0)
{
    for (int i = 0; i < kMaxSlot; i++)
        inventory_[i] = NULL;
}

Character::~Character() {}

Character &Character::operator=(const Character &rhs) {
    if (this != &rhs) {
        inventory_cnt_ = rhs.inventory_cnt_;
        name_ = rhs.name_;

        for (int i = 0; i < inventory_cnt_; i++)
            inventory_[i] = rhs.inventory_[i]->clone();
    }
    return *this;
}

std::string const &Character::getName() const { return name_; }

void Character::equip(AMateria *m) {
    if (!m) {
        std::cout << "AMateria is NULL" << std::endl;
    }
    else if (inventory_cnt_ == kMaxSlot)
        std::cout << name_ << "'s slot is full" << std::endl;
    else {
        inventory_[inventory_cnt_] = m;
        inventory_cnt_++;
    }
}

void Character::unequip(int idx) {
    if (inventory_cnt_ == 0)
        // std::cout << name_ << "doesn't have material." << std::endl;
        ;
    else if (idx >= kMaxSlot || idx < 0)
        std::cout << "range out of idx" << std::endl;
    else if (inventory_[idx] == NULL)
        std::cout << "Inventory of idx is empty" << std::endl;
    else {
        std::cout << name_ << " drops " << inventory_[idx]->getType() << " material." << std::endl;
        inventory_[idx] = NULL;
        inventory_cnt_--;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (inventory_cnt_ == 0)
        // std::cout << name_ << " doesn't have material." << std::endl;
        ;
    else if (idx >= kMaxSlot || idx < 0)
        std::cout << "range out of idx" << std::endl;
    else
        inventory_[idx]->use(target);
}
