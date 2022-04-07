/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:55:24 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/07 01:19:04 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main() {
  Animal *arr[10];

  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0)
      arr[i] = new Dog;
    else
      arr[i] = new Cat;
  }
  for (int i = 0; i < 10; i++)
    delete arr[i];

  Dog dog;
  Cat cat;

  std::cout << dog.get_idea(0) << std::endl;
  std::cout << cat.get_idea(0) << std::endl;

  Dog dog2;
  Cat cat2;

  dog2 = dog;
  cat2 = cat;

  dog2.set_idea(0, "another idea!!");
  cat2.set_idea(0, "another idea!!");

  std::cout << dog.get_idea(0) << std::endl;
  std::cout << cat.get_idea(0) << std::endl;
  std::cout << dog2.get_idea(0) << std::endl;
  std::cout << cat2.get_idea(0) << std::endl;
}
