#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Stock.h"
#include "Stockholder.h"
#include <algorithm>
#include <map>

using namespace std;

// Constructor
Stockholder::Stockholder(string _name){
	holder_name = _name;
	// Have to initialize the portfolio
	Portfolio = {};
	port_iterator = Portfolio.begin();
	// 100,000 is the default starting value for stockholders
	current_cash = 100000.00;
}

// Destructor
Stockholder::~Stockholder(){
	// Only required if I use dynamic allocation within Stockholder
}

// Returns true if stock is purchased, false if stock cant be purchased
bool Stockholder::Purchase(Stock* stock, int count){
	float total_value = 0.0;
	total_value = stock->new_value * count;
	if(total_value > this->current_cash){
		return false;
	} else {
		Portfolio.insert({stock->short_name, pair<Stock*, int>(stock, count)});
		current_cash = current_cash - total_value;
		return true;
	}
}


bool Stockholder::Sell(string short_name, int count){
	int count_amount = 0;
	float current_price = 0.0;
	port_iterator = Portfolio.find(short_name);	
	// Handling case when a Portfolio doesnt include the stock
	if(port_iterator == Portfolio.end()){
		return false;
	}
	count_amount = port_iterator->second.second;
	current_price = port_iterator->second.first->new_value;
	
	if(count_amount < count){
		return false;
	} else {
		port_iterator->second.second = count_amount - count;
		current_cash = current_cash + (current_price * count);
		return true;
	}
}

float Stockholder::NetWorth(){
	PortfolioValue pV;
	// Passing the pV object, do not need a parameter
	// This way it will be called each time
	
	// For each loop to calcualte PortfolioValue
	for_each(Portfolio.begin(),Portfolio.end(), pV);
	float netWorth;
	// Combining PortfolioValue with current cash to get net worth
	netWorth = pV.total_value + current_cash;
	return netWorth;
}

void Stockholder::Print(){
	cout << "Name: " << holder_name << ", NetWorth: $" << NetWorth() << endl;
	map <string, pair<Stock*, int>>::iterator it;
	for(it = Portfolio.begin(); it != Portfolio.end(); it++){
		// Use the -> for pointer notation, after the second call we are returned an object
		// Can switch back to . notation, then the object we are working with is a pointer (->)
		it->second.first->Print();
		cout << "  Count:  " << it->second.second << endl;
	}
}
