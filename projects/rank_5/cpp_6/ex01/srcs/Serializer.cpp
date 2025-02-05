/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:09:52 by txisto-d          #+#    #+#             */
/*   Updated: 2025/01/26 16:32:18 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "utils.hpp"
#include "data.hpp"

Serializer::Serializer()
{

}

Serializer::Serializer(Serializer& obj)
{
	*this = obj;
}

Serializer& Serializer::operator=(Serializer& obj)
{
	if (this != &obj)
		*this = obj;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast <uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast <Data*>(raw));
}
