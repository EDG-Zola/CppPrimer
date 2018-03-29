/************************************************************************/
/* ���ͷ�ļ�                                                                     */
/************************************************************************/
#include "TextQuery.h"

/************************************************************************/
/* ��������                                                                     */
/************************************************************************/
ifstream& open_file(const ifstream &in, const string &file);//���ļ�����
void print_results(const set<TextQuery::line_no>& locs, const string& sought, TextQuery& file);//��������
string make_plural(size_t ctr, const string &word, const string &ending);//���ݵ��ʳ��ֵĴ���Ϊ�������Ǹ�����ӡ�Ƿ��s
/************************************************************************/
/* ������                                                                     */
/************************************************************************/

int main(int argc, char **argv){
	ifstream infile;
	if(argc < 2 && !open_file(infile, argv[1])){
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	TextQuery tq;
	//��ȡ�ļ����ݣ������ store_file()��build_map()��
	//�����ļ���vector�����Լ��������ʺ��кŵ�map����
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

ifstream& open_file(ifstream& in, const string &file){
	in.close();//�ر��ļ������Է��ļ��Ѿ���
	in.clear();//�ر��ļ������Է��ļ��Ѿ���
	in.open(file.c_str());//���ļ�file
	return in;
}

string make_plural(size_t ctr, const string& word, const string& ending){
	return (ctr == 1) ? word : word +ending;
}

void print_results(const set<TextQuery::line_no>& locs, const string& sought, TextQuery& file){
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout << "\n" << sought << " occurs" << size << make_plural(size, "time", "s") << endl;
	line_nums::const_iterator it =locs.begin();
	for(; it != locs.end(); ++it){
		cout << "\t(line " << *it + 1 << ")" << file.text_line(*it) << endl;//��ӡ������ҵĵ��������м����е����� 
	}
}