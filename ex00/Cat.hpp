/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:50:44 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 23:10:31 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H_
# define CAT_H_

# include "Animal.hpp"

class Cat : public Animal {
public:
  Cat(void);
  ~Cat(void);

  void makeSound(void) const;

private:
  Cat(const Cat &rhs);
  Cat &operator=(const Cat &rhs);
};

#endif
