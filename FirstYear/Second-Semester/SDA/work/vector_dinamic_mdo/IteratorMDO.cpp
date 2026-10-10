#include "IteratorMDO.h"
#include "MDO.h"

IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
	this->prim();
}

void IteratorMDO::prim(){
	// BC = Theta(1)
	// WC = Theta(n)
	// AC = Theta(n)
	// General = O(n)
	this->index_inner = 0;
	this->index_outer = 0;
	if (this->index_outer < this->dict.used_capacity) {
		this->cached_values = this->dict.elements[this->index_outer]->get_all();
	}
}

void IteratorMDO::urmator(){
	// BC = Theta(1)
	// WC = Theta(n)
	// AC = Theta(1)
	// General = Theta(1) amortizat
	this->index_inner++;
	if (this->index_inner < this->cached_values.size()) {
		return;
	}
	this->index_outer++;
	this->index_inner = 0;
	if (this->index_outer < this->dict.used_capacity) {
		this->cached_values = this->dict.elements[this->index_outer]->get_all();
	}
}

bool IteratorMDO::valid() const{
	// BC = WC = AC = General = Theta(1)
	return this->index_outer < this->dict.used_capacity;
}

TElem IteratorMDO::element() const{
	// BC = WC = AC = General = Theta(1)
	return pair <TCheie, TValoare>  (this->dict.elements[this->index_outer]->get_key(), this->cached_values[this->index_inner]);
}


