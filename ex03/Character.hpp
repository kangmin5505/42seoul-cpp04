/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:22:27 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/08 16:18:27 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H_
# define CHARACTER_H_

# include "ICharacter.hpp"

# include <string>

class Character : public ICharacter {
public:
    Character();
    Character(const Character &origin);
    Character(const std::string &name);
    ~Character();
    Character &operator=(const Character &rhs);

    std::string const &getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

private:
    static const int kMaxSlot = 4;

    std::string name_;
    AMateria *slots_[kMaxSlot];
    int slot_cnt_;
};

#endif