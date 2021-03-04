#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "op.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "div.hpp"
#include "add.hpp"
#include "sub.hpp"

class Factory{
	public:
		virtual Base* parse(char** input, int length) = 0;
};
#endif