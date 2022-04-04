/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:41:22 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 23:09:02 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H_
# define ANIMAL_H_

# include <string>

class Animal {
public:
  Animal(void);
  virtual ~Animal(void);

  virtual void makeSound(void) const ;

  const std::string &getType(void) const ;

protected:
  std::string type_;

private:
  Animal(const Animal &rhs);
  Animal &operator=(const Animal &rhs);
};

#endif
