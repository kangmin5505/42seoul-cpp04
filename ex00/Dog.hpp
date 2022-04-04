/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:50:44 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 23:12:00 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H_
# define DOG_H_

# include "Animal.hpp"

class Dog : public Animal {
public:
  Dog(void);
  ~Dog(void);

  void makeSound(void) const;

private:
  Dog(const Dog &rhs);
  Dog &operator=(const Dog &rhs);
};

#endif
