/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 07:00:09 by sishizaw          #+#    #+#             */
/*   Updated: 2025/06/06 07:00:11 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int rawBits;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed &other);
	~Fixed();

	Fixed &operator=(const Fixed &other);

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++();     // pre-increment
	Fixed operator++(int);   // post-increment
	Fixed &operator--();     // pre-decrement
	Fixed operator--(int);   // post-decrement

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
