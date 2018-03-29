
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H
class TextQuery{
public:
	typedef vector<string>::size_type line_no;
	void read_file(ifstream& is){
		store_file(is);
		build_map();
	}
	set<line_no> run_query(const string&) const;
	string text_line(line_no) const;
private:
	void store_file(ifstream& is);
	void build_map();
	vector<string> lines_of_text;
	map<string, set<line_no> > word_map;
};

#endif
