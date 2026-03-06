#pragma once

#include "pair.hpp"
#include "vector.hpp"
#include <cstdio>

#include <iostream>
#include <iomanip>

#include <cassert>

namespace AyED
{

	typedef vector<pair<double>> vector_pair;

}

template <>
std::ostream &AyED::vector<AyED::pair<double>>::write(std::ostream &os) const
{

	os << std::setw(6) << sz_ << " ";

	os << "[ ";

	for (int i{0}; i < sz_; i++)
	{
		v_[i].write(os);
		os << " ";
	}

	os << " ]";

	return os;
}

template <>
std::istream &AyED::vector<AyED::pair<double>>::read(std::istream &is)
{

	is >> sz_;

	resize(sz_);

	for (int i{0}; i < sz_; i++)
		v_[i].read(is);

	return is;
}
