#ifndef IRPSSHierarchy_HEADER
#define IRPSSHierarchy_HEADER

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Punches.h"
#include "NorthAmericanMember.h"
#include "SouthAmericanMember.h"

using namespace std;

template<class T>
class IRPSSHierarchy {
public:
	T member;
	IRPSSHierarchy * left;
	IRPSSHierarchy * right;
	
	// Parametrized Constructor
	IRPSSHierarchy(T _member){
		member = _member;
		left = NULL;
		right = NULL;
	}
	
	void Insert(T new_member){
		// Checking if Punch is thrown
		try{
			if(new_member < this->member){ // going to the left
				if(left == NULL){
					IRPSSHierarchy * newLeft = new IRPSSHierarchy(new_member);
					left = newLeft;
				} else{
					// If the left pointer is not null - recursive call
					left->Insert(new_member);
				}
			} else { // going to the right
				if(right == NULL){
					IRPSSHierarchy * newRight = new IRPSSHierarchy(new_member);
					right = newRight;
				} else {
					right->Insert(new_member);
				}
			}
		}catch(Punches p){
			cout << p.what() << endl;
			if(p.challenger > p.defender){
				member = new_member;
			}
		}
	}
	
	// Overriding << operator
	friend ostream& operator<<(ostream& out, const IRPSSHierarchy& hierarchy){
		// PreOrder Print: Left Node, Current Node, Right Node
		if(hierarchy.left != NULL){
			// get pointer and then derefrence the pointer
			IRPSSHierarchy& toPrint = *hierarchy.left;
			out << toPrint;
		}
		
		out << hierarchy.member;
		
		if(hierarchy.right != NULL){
			// get pointer and then derefrence the pointer
			IRPSSHierarchy& toPrint_2 = *hierarchy.right;
			out << toPrint_2;
		}
		return out;
	}
};

#endif
