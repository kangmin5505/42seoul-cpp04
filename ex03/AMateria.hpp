/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:26:41 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/08 14:53:14 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H_
# define AMATERIA_H_

# include "ICharacter.hpp" // check recursive include

# include <string>

class AMateria {
public:
    AMateria();
    AMateria(const AMateria &origin);
    ~AMateria();
    AMateria &operator=(const AMateria &rhs);

    AMateria(std::string const &type);
    std::string const &getType() const;
    void setType(std::string const &type);

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter &target);

protected:
    std::string type_;
};

#endif
