/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:41:41 by txisto-d          #+#    #+#             */
/*   Updated: 2025/01/26 16:33:46 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "data.hpp"
# include "utils.hpp"

class Serializer
{
	public:
		Serializer();
		virtual ~Serializer() = 0;
		Serializer(Serializer& obj);
		Serializer& operator=(Serializer& obj);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		
};



#endif