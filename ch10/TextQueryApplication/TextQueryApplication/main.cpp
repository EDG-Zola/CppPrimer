#include "TextQuery.h"

/************************************************************************/
/* 函数声明                                                                     */
/************************************************************************/

string make_plural(size_t ctr, const string& word, const string& ending){
	return (ctr == 1) ? word : word +ending;
}

void print_results(const set<TextQuery::line_no>& locs, const string& sought, TextQuery& file){
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout << "\n" << sought << " occurs" << size << make_plural(size, "time", "s") << endl;
	line_nums::const_iterator it =locs.begin();
	for(; it != locs.end(); ++it){
		cout << "\t(line " << *it + 1 << ")" << file.text_line(*it) << endl;
		//打印输出查找的单词所在行及改行的内容 
	}
}


/************************************************************************/
/* 主函数                                                                     */
/************************************************************************/

int main(int argc, char **argv){
	std::ifstream infile;
	if(argc < 2 && infile.open(argv[1])){
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	TextQuery tq;
	//读取文件内容，会调用 store_file()和build_map()，
	//保存文件的vector对象，以及关联单词和行号的map对象
	tq.read_file(infile);
	while (true){
		cout << "Enter a word to look for, or q to quit: ";
		string s;
		cin >> s;
		if (!cin || s == "q")
			break;
		set<TextQuery::line_no> locs = tq.run_query(s);
		print_results(locs, s, tq);
	}
	system("pause");
	return 0;
}
