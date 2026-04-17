#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
#define INITIAL_CAPACITY 10
#define ALPHA 0.8
#define BETA 0.8

using namespace std;

MDOElement::MDOElement(TCheie key) {
	// BC = WC = AC = General = Theta(1)
	this->key = key;
	this->size = 0;
	this->capacity = INITIAL_CAPACITY;
	this->values = new TValoare[this->capacity];
}

MDOElement::~MDOElement() {
	// BC = WC = AC = General = Theta(1)
	delete[] this->values;
	this->values = nullptr;
}

void MDOElement::resize(int capacity) {
	// BC = WC = AC = General = Theta(n)
	TValoare* new_elements = new TValoare[capacity];
	for (int i = 0; i < min(this->size, this->capacity); i++) {
		new_elements[i] = this->values[i];
	}
	delete[] this->values;
	this->values = new_elements;
	this->capacity = capacity;
}

void MDOElement::add(TValoare v) {
	// BC = Theta(1)
	// WC = Theta(n)
	// AC = Theta(1)
	// General = Theta(1) amortizat
	if (this->size >= ALPHA * this->capacity) {
		this->resize(this->capacity * 2);
	}
	this->values[this->size++] = v;
}

bool MDOElement::delete_value(TValoare v) {
	// BC = WC = AC = General = Theta(n)
	int i = 0;
	for (i = 0; i < this->size; i++) {
		if (this->values[i] == v) {
			break;
		}
	}
	if (i >= this->size) {
		return false;
	}
	for (; i < this->size - 1; i++) {
		this->values[i] = this->values[i + 1];
	}
	this->size--;
	if (this->size < BETA * this->capacity / 2) {
		this->resize(this->capacity / 2);
	}
}

vector<TValoare> MDOElement::get_all() const {
	// BC = WC = AC = General = Theta(n)
	vector<TValoare> elements;
	for (int i = 0; i < this->size; i++) {
		elements.push_back(this->values[i]);
	}
	return elements;
}

TCheie MDOElement::get_key() const {
	return this->key;
}

int MDOElement::get_size() const {
	return this->size;
}

MDO::MDO(Relatie r) {
	this->relation = r;
	this->used_capacity = 0;
	this->total_size = 0;
	this->capacity = INITIAL_CAPACITY;
	this->elements = new MDOElement*[this->capacity];
}


int MDO::binary_search(TCheie key) const {
	// BC = Theta(1)
	// WC = Theta(log(n))
	// AC = Theta(log(n))
	// General = O(log(n))
	int start = 0, end = this->used_capacity;
	while (start < end) {
		int mid = (start + end) / 2;
		if (this->elements[mid]->get_key() == key) {
			return mid;
		}
		if (this->relation(this->elements[mid]->get_key(), key)) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
	return -1;
}

void MDO::resize(int capacity) {
	// BC = WC = AC = General = Theta(n)
	MDOElement** new_elements = new MDOElement*[capacity];
	for (int i = 0; i < min(this->used_capacity, capacity); i++) {
		new_elements[i] = this->elements[i];
	}
	delete[] this->elements;
	this->elements = new_elements;
	this->capacity = capacity;
}

void MDO::adauga(TCheie c, TValoare v) {
	// BC = Theta(1)
	// WC = Theta(n)
	// AC = Theta(n)
	// General = O(n)
	this->total_size++;
	int index = this->binary_search(c);
	if (index != -1) {
		this->elements[index]->add(v);
		return;
	}
	if (this->used_capacity >= ALPHA * this->capacity) {
		this->resize(this->capacity * 2);
	}
	this->elements[this->used_capacity] = new MDOElement(c);
	this->elements[this->used_capacity]->add(v);
	this->used_capacity++;
	for (int i = this->used_capacity - 1; i >= 1 && this->relation(
		this->elements[i]->get_key(),
		this->elements[i - 1]->get_key()
	); i--) {
		MDOElement* aux = this->elements[i];
		this->elements[i] = this->elements[i - 1];
		this->elements[i - 1] = aux;
	}
}

vector<TValoare> MDO::cauta(TCheie c) const {
	// BC = Theta(n), n = cate elemente sunt in elements
	// BC = Theta(log(len_keys))
	// WC = Theta(log(len_keys) + n)
	// AC = Theta(log(len_keys) + n)
	// General = O(log(len_keys) + n)
	int index = this->binary_search(c);
	if (index == -1) {
		return vector<TValoare>();
	}
	return this->elements[index]->get_all();
}

bool MDO::sterge(TCheie c, TValoare v) {
	// BC = Theta(min(log(len_keys), n))
	// WC = Theta(log(keys) + n)
	// AC = Theta(log(keys) + n)
	// General = O(log(keys) + n)
	int index = this->binary_search(c);
	if (index == -1) {
		return false;
	}
	bool was_deleted = this->elements[index]->delete_value(v);
	if (!was_deleted) {
		return false;
	}
	this->total_size--;
	if (this->elements[index]->get_size() > 0) {
		return true;
	}
	for (int i = index; i <= this->used_capacity - 1; i++) {
		this->elements[i] = this->elements[i + 1];
	}
	this->used_capacity--;
	if (this->used_capacity < BETA * this->capacity / 2) {
		this->resize(this->capacity / 2);
	}
	return true;
}

int MDO::dim() const {
	// BC = WC = AC = General = Theta(1)
	return this->total_size;
}

bool MDO::vid() const {
	// BC = WC = AC = General = Theta(1)
	return this->dim() == 0;
}

IteratorMDO MDO::iterator() const {
	// BC = WC = AC = General = Theta(1)
	return IteratorMDO(*this);
}

MDO::~MDO() {
	// BC = WC = AC = General = Theta(n)
	for (int i = 0; i < this->used_capacity; i++) {
		delete this->elements[i];
	}
	delete[] this->elements;
	this->elements = nullptr;
}
