// Name: Jacob Hawig
// WISC ID: 9078102226
// Assignment #6

#ifndef NorthAmericanMember_HEADER
#define NorthAmericanMember_HEADER

#include <iostream>
#include <iomanip>
#include <string>
#include "Punches.h"

using namespace std;

class NorthAmericanMember {
public:
	// Variables Necessary for NorthAmericanMember
	string member_name;
	vector<char> strategy;
	int strength;
	bool school_o_rock;
	bool paper_tiger;
	NorthAmericanMember(){}
	// Constructor for NorthAmericanMember
	NorthAmericanMember(string _name, int _strength, vector<char> _strategy, bool _rockschool, bool _tiger){
		member_name = _name;
		strategy = _strategy;
		strength = _strength;
		school_o_rock = _rockschool;
		paper_tiger = _tiger;
	}
	
	// Overriding < operator
	bool operator<(const NorthAmericanMember& defender){
		if(this->paper_tiger && defender.school_o_rock){
			Punches p = Punches(this->strength, defender.strength);
			throw(p);
		} else if(this->school_o_rock && defender.paper_tiger){
			Punches p = Punches(this->strength, defender.strength);
			throw(p);
		}
		int this_count = 0;
		int defender_count = 0;
		for(int i = 0; i < 5; i++){
			// THIS WINS
			if(this_count >= 3){
				return false;
			}
			// DEFENDER WINS
			if(defender_count >= 3){
				return true;
			}
			// Rock Cases for THIS
			if(this->strategy[i] == 'r' && defender.strategy[i] == 's'){
				this_count++;
			} else if(this->strategy[i] == 'r' && defender.strategy[i] == 'p'){
				defender_count++;
			}
			// Scissors Case for THIS
			if(this->strategy[i] == 's' && defender.strategy[i] == 'p'){
				this_count++;
			} else if(this->strategy[i] == 's' && defender.strategy[i] == 'r'){
				defender_count++;
			}
			// Paper Case for THIS
			if(this->strategy[i] == 'p' && defender.strategy[i] == 'r'){
				this_count++;
			} else if(this->strategy[i] == 'p' && defender.strategy[i] == 's'){
				defender_count++;
			}
		}
		// If neither reach 3 wins, have to go what wins they did get
		if(this_count > defender_count){
			return false;
		} else {
			// As long as defender has as many or more wins as this it will win
			return true;
		}
	}
	
	// Overriding << operator
	friend ostream& operator<<(ostream& out, const NorthAmericanMember& member){
		out << member.member_name;
		if(member.school_o_rock){
			out << " (School of Rock)";
		} else if(member.paper_tiger){
			out << " (Paper Tigers)";
		}
		out << endl;
		return out;
	}
};

#endif