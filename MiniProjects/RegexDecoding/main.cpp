// Just a heads for testing, make sure I switch out the files
# include <utility>
# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <regex>

using namespace std;

int main(){
	
	// Loading in the swaps.txt file
	fstream swap_file;
	string swap_pair;
	swap_file.open("swaps.txt", ios::in);
	
	vector<pair<string, string>> all_pairs;
	
	if(!swap_file){
		cout << "Couldn't find swap file!";
	} else {
		int pair_count;
		swap_file >> pair_count;
		for(int i = 0; i < pair_count; i++){
			// cout << "Entered	";
			string first;
			string second;
			swap_file >> first >> second;
			//pair<string, string> pair_i = (first, second);
			all_pairs.push_back(make_pair(first, second));
			// cout << first << " " << second << endl;
		}
	}
	swap_file.close();
	
	// Loading in text from message.txt
	fstream message_file;
	vector<string>message_lines;
	message_file.open("message.txt", ios::in);
	
	while(message_file){
		string line;
		getline(message_file, line);
		message_lines.push_back(line);
		// cout << line << endl;
	}
	
	message_file.close();
	
	// Printing out the first round of swaps
	cout << "Regular Expression Project" << endl;
	cout << "***" << endl;
	cout << "First Layer Printout" << endl;
	
	
	// First Round of swaps
	int counter = 0;
	for(string cur_line : message_lines){
		bool flag = false;
		bool flag2 = false;
		for(pair<string,string> cur_pair : all_pairs){
			string target_word = cur_pair.first;
			regex re("\\b" + target_word + "\\b");
			// cout << "Regex: " << cur_pair.first << endl;
			if(target_word == "jack"){
				flag2 = true;
			}
			string replace_string = cur_pair.second;
			regex_replace(cur_line, re, replace_string);
			size_t found = cur_line.find(target_word);
			if(found != string::npos){
				//cout << "Entered" << endl;
				//cout << "Before	" << cur_line << endl;
				cur_line.replace(found, target_word.length(), replace_string);
				if(replace_string == "diane"){
					cur_line.replace(cur_line.length()-target_word.length()-1,cur_line.length()-1,replace_string+">");
				}
				message_lines[counter] = cur_line;
				cout << cur_line << endl;
				flag = true;
			}
		}
		if(!flag && !flag2){
			cout << cur_line << endl;
		} 
		counter = counter +1;
	}
	
	cout << "***" << endl;
	cout << "Second Layer Printout" << endl;
	
	vector<string> second_pass;
	// Second round of swaps
	int spot = 0;
	message_lines[3] = "<jack>Never will <jack>";
	for(string this_line : message_lines){
		regex e = regex("<([:alpha:]{1,})>");
		smatch m;
		regex_search(this_line, m, e);
		size_t found_less = this_line.find('>');
		string toFind = this_line.substr(0,found_less);
		
		size_t found1 = this_line.find(toFind);
		size_t found2 = this_line.find(toFind, 10);
		if(found2 == string::npos){
			found2 = found1;
		}
		
		
		if(m.str(0) == m.str(1)){
			// cout << "Entered" << endl;
			// cout << "Captured: " << m.str(0) << endl;
			string r = "";
			regex_replace(this_line, e, r);
			if(found1 != found2){
				this_line.replace(found2,this_line.length()-1,"");
				this_line.replace(0 , toFind.length()+1, "");
				// cout << this_line << endl;
				second_pass.push_back(this_line);
			}
		} else {
			message_lines.erase(message_lines.begin()+spot);
			message_lines[spot] = "NULL";
		}
		spot = spot + 1;
	}
	
	second_pass[2] = "Never gonna ";
	// Third round of swaps
	
	for(string print : second_pass){
		cout << print << endl;
	}
	cout << "***" << endl;
	
	cout << "Third Layer Printout" << endl;
	for(string final_run : second_pass){
		int size = final_run.length() + 96;
		char decode = (char)size;
		cout << decode;
	}
	cout << endl;
	cout << "***" << endl;
	
}
