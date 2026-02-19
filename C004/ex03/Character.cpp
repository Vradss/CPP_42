/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrads <vrads@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 00:53:01 by vrads             #+#    #+#             */
/*   Updated: 2026/02/20 00:53:02 by vrads            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const& name) : _name(name) {
	for (int i = 0; i < _kInventorySize; i++)
		_inventory[i] = 0;
}

Character::Character(Character const& other) : _name(other._name) {
	for (int i = 0; i < _kInventorySize; i++)
		_inventory[i] = 0;
	for (int i = 0; i < _kInventorySize; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
}

Character& Character::operator=(Character const& other) {
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < _kInventorySize; i++) {
			if (_inventory[i]) {
				delete _inventory[i];
				_inventory[i] = 0;
			}
		}
		for (int i = 0; i < _kInventorySize; i++) {
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = 0;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < _kInventorySize; i++) {
		if (_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = 0;
		}
	}
}

std::string const& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < _kInventorySize; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= _kInventorySize)
		return;
	_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= _kInventorySize || !_inventory[idx])
		return;
	_inventory[idx]->use(target);
}
