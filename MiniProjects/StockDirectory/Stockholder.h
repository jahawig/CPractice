#ifndef STOCK_HOLDER_HEADER
#define STOCK_HOLDER_HEADER

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Stock.h"
#include <map>


using namespace std;

struct Stockholder {
public:
	string holder_name;
	map <string, pair<Stock*, int>> Portfolio;
	map <string, pair<Stock*, int>>::iterator port_iterator;
	float current_cash;
	Stockholder(string _name);
	~Stockholder();
	bool Purchase(Stock* stock, int count);
	bool Sell(string short_name, int count);
	float NetWorth();
	void Print();
	
	struct PortfolioValue{
		float total_value;
		// single parameter name for that whole object
		void operator()(pair<string, pair<Stock*, int>> step){
			float im_sum;
			im_sum = step.second.first->new_value * step.second.second;
			total_value = total_value + im_sum;
		}
	};
};

#endif
