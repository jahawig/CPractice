# include <cstdlib>
# include <ctime>
# include <iostream>
# include <fstream>
# include <list>
# include <map>
# include "Stock.h"
# include "Stockholder.h"
# include <algorithm>

using namespace std;

int PrintMainMenu();
int PrintUserMenu();
string GetName();

// Load value, only want to load in the values on startup
int load = 0;
// Init an empty list of Stock
list <Stock> stocks = {};
// Init empty list of Stockholders
map <string, Stockholder> stockholders = {};


int main(){
	// To generate random numbers every time
	srand((unsigned int) time(NULL));
	
	// Loading in the file
	if(load == 0){
		ifstream in;
		in.open("stocks.txt", ios::in);
		int num_stocks;
		in >> num_stocks;
		for(int i = 0; i < num_stocks; i++){
			list<Stock>::iterator iter = stocks.begin();
			Stock reading_stock;
			// Want to use >> overridden operator
			in >> reading_stock;
			stocks.insert(iter, reading_stock);
		}
		load++;
	}
	
	// GUI - User Interface
	int menu_choice = PrintMainMenu();
	switch(menu_choice){
		
		// Log In
		case 1:{
			string entered_name;
			entered_name = GetName();
			
			// Checking if we have a stockholder with the given name
			// If not we are adding him to the list of stockholders
			if(stockholders.find(entered_name) == stockholders.end()){
				Stockholder newest = Stockholder(entered_name);
				stockholders.insert({entered_name, newest});
			}
			
			int user_choice = PrintUserMenu();
			switch(user_choice){
				// List Available Stocks
				case 1:{
					// Printing all the available stocks
					for(Stock s : stocks){
						s.Print();
						cout << endl;
					}
					
					// Checking for number before returning to main menu
					int return_num;
					cout << "Enter any number to return to menu: " << endl;
					cin >> return_num;
					while(!cin){
						cin.clear();
						cin.ignore(100,'\n');
						cout << "Please enter a number." << endl;
						cin >> return_num;
					}
					
					if(return_num >= 1 || return_num < 1){
						// Back to Main Menu (recursive call)
						main();
					}
					
					break;
				}
				// List My Stocks
				case 2:{
					
					
					//for(find_name = stockholders.begin(); find_name != stockholders.end(); find_name++){
					//	if(find_name->first == entered_name){
					//		&find_name.Print();
					//	}
					//}
					
					// stockholders[entered_name].Print();
					
					map<string, Stockholder>::iterator find_name;
					find_name = stockholders.find(entered_name);
					if(find_name == stockholders.end()){
						cout << "Sorry no stocks yet" << endl;
					} else {
						find_name->second.Print();
					}
					
					
					
					// Checking for number before returning to main menu
					int return_num;
					cout << "Enter any number to return to menu: " << endl;
					cin >> return_num;
					while(!cin){
						cin.clear();
						cin.ignore(100,'\n');
						cout << "Please enter a number." << endl;
						cin >> return_num;
					}
					
					if(return_num >= 1 || return_num < 1){
						// Back to Main Menu (recursive call)
						main();
					}
					
					break;
				}
				// Purchase Stocks
				case 3:{
					cout << "Perfect, lets purchase a stock!" << endl;
					cout << "Please enter the short name of the stock: " << endl; 
					string short_in;
					cin >> short_in;
					
					// Handling case if the short name is not found in stocks!
					//if(find(stocks.begin(), stocks.end(), short_in) == stocks.end()){
					//	cout << "Sorry we could not find that stock" << endl;
					///	cout << "Returning you to the main menu" << endl;
					//	main();
					//}
					
					Stock * target_stock;
					list<Stock>::iterator finder;
					for(finder = stocks.begin(); finder != stocks.end(); finder++){
						string current_name = finder->short_name;
						if(current_name == short_in){
							target_stock = &*finder;
						}
					}
					
					cout << "Sounds good, how many of " << short_in << " do you want to purchase: " << endl;
					int stock_count;
					cin >> stock_count;
					bool purchased;
					map<string, Stockholder>::iterator find_name_2;
					find_name_2 = stockholders.find(entered_name);
					if(find_name_2 != stockholders.end()){
						purchased = find_name_2->second.Purchase(target_stock, stock_count);
					}
					
					if(purchased == true){
						cout << "Congrats! You bought " << stock_count << " shares of " << short_in << "!" << endl;
					} else {
						cout << "Sorry! You did not have enought current cash to purchase that many stocks!" << endl;
					}
					main();
					
					break;
				}
				// Sell Stocks
				case 4:{
					
					cout << "Perfect, lets  sell some stock!" << endl;
					cout << "Please enter the short name of the stock: " << endl; 
					string sell_in;
					cin >> sell_in;
					
					// Handling case if the short name is not found in stocks!
					//if(find(stockholders[entered_name].Portfolio.begin(), stockholders[entered_name].Portfolio.end(), sell_in) == stockholders[entered_name].Portfolio.end()){
					//	cout << "Sorry you do not have that stock" << endl;
					//	cout << "Returning you to the main menu" << endl;
					//	main();
					//}
					
					cout << "Sounds good, how many of " << sell_in << " do you want to sell: " << endl;
					int stock_sell;
					cin >> stock_sell;
					bool purchased;
					map<string, Stockholder>::iterator find_name_3;
					find_name_3 = stockholders.find(entered_name);
					if(find_name_3 != stockholders.end()){
						purchased = find_name_3->second.Sell(sell_in, stock_sell);
					}
					if(purchased == true){
						cout << "Congrats! You sold " << stock_sell << " shares of " << sell_in << "!" << endl;
					} else {
						cout << "Sorry! You did not have that many stocks to sell!" << endl;
					}
					main();
					break;
				}
				// Log Out
				case 5:{
					main();
					break;
				}
			}
			break;
		}
		
		// List Directory
		case 2:{
			// Printing out names of all stockholders
			for(pair<string, Stockholder> holders : stockholders){
				cout << holders.first << endl;
			}
			int return_num;
			cout << "Enter any number to return to menu: " << endl;
			cin >> return_num;
			while(!cin){
				cin.clear();
				cin.ignore(100,'\n');
				cout << "Please enter a number." << endl;
				cin >> return_num;
			}
			if(return_num >= 1 || return_num < 1){
				// Back to Main Menu (recursive call)
				main();
			}
			break;
		}
		
		// Advance a Day
		case 3:{
			for(Stock s : stocks){
				// Calling AdvanceDay function given to us on each Stock
				s.AdvanceDay();
			}
			
			//list<Stock>::iterator fly;
			//for(fly = stocks.begin(); fly != stocks.end(); fly++){
				
			//	fly.AdvanceDay();
			//}
			//for_each(stocks.begin(), stocks.end(), AdvanceDay());
			
			
			main();
			break;
		}
		
		// Exiting the program
		case 4:{
			break;
		}
	}
	
}

int PrintMainMenu(){
	// Welcome Menu
	int Menu_Choice;
	cout << "Welcome to the Stock Portfolio Manager!" << endl;
	cout << "[1] Log In" << endl;
	cout << "[2] List Directory" << endl;
	cout << "[3] Advance a Day" << endl;
	cout << "[4] Exit Program" << endl;
	cout << "Please enter a menu item: " << endl;
	cin >> Menu_Choice;
	while(!cin){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "That type is not supported, please try another input: " << endl;
		cin >> Menu_Choice;
		while (Menu_Choice < 1 || Menu_Choice > 4) {
			cout << "Invalid input, please try again with one of the four options: " << endl;
			cin >> Menu_Choice;	
		}
	}
	return Menu_Choice;
}

int PrintUserMenu(){
	// Welcome Menu
	int User_Choice;
	cout << "Welcome to the Downtown Dairy Bar!" << endl;
	cout << "[1] List Available Stocks" << endl;
	cout << "[2] List My Stocks" << endl;
	cout << "[3] Purchase Stocks" << endl;
	cout << "[4] Sell Stocks" << endl;
	cout << "[5] Log Out (return to main menu)" << endl;
	cout << "Please enter a menu item: " << endl;
	cin >> User_Choice;
	while(!cin){
		cin.clear();
		cin.ignore(100, '\n');
		cout << "That type is not supported, please try another input: " << endl;
		cin >> User_Choice;
		while (User_Choice < 1 || User_Choice > 5) {
			cout << "Invalid input, please try again with one of the five options: " << endl;
			cin >> User_Choice;	
		}
	}
	
	return User_Choice;
}

string GetName(){
	// Asking for stockholder name
	string stockholder_name;
	cout << "Hello Stockholder, what is your username: " << endl;
	cin >> stockholder_name;
	return stockholder_name;
}

