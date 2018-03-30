#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
class TextQuery{
public:
	typedef std::vector<std::string>::size_type line_no;
	void read_file(std::ifstream& is);
	std::set<line_no> run_query(const std::string&) const;
	std::string text_line(line_no) const;
private:
	void store_file(std::ifstream& is);
	void build_map();
	std::vector<std::string> line_of_text;
	std::map< std::string, std::set<line_no> > word_map;
}
#endif
