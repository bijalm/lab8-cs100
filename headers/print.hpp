#include "visitorLaTeX.hpp"
#include "visitorMathML.hpp"
#include "iterator.hpp"
#include <string>

// functions

std::string print_latex(Base* ptr) {
	VisitorLaTeX* visitor = new VisitorLaTeX();
	Iterator iterator(ptr);
	
	while(!iterator.is_done()) {
		iterator.current_node()->accept(visitor, iterator.current_index());
		iterator.next();
	}
	
	std::string result;
	result += "$" + visitor->getString() + "$";
	delete visitor;
	return result;
}

std::string print_mathML(Base* ptr) {
	VisitorMathML* visitor = new VisitorMathML();
	Iterator iterator(ptr);
	
	while(!iterator.is_done()) {
		iterator.current_node()->accept(visitor, iterator.current_index());
		iterator.next();
	}

	std::string result;
	result += "<math>\n" + visitor->getString() + "</math>";
	delete visitor;
	return result;
}
