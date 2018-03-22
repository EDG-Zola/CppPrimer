/*用于将in.txt文件的内容拷贝的out.txt中
*思路：先将in.txt中的每行数据存储到vector<string>类的容器中
*再将容器里的元素写到out.txt中
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s;
	//关联in.txt与infile文件流,并打开infile(注意，每次打开前应clear并close文件流)
	ifstream infile("in.txt");
	if(!infile){
		cerr << "can not open file in.txt";
		return -1;
	}
	vector<string> vec_file;
	//按行读取infile
	while(getline(infile, s)){
		vec_file.push_back(s);
	}
	infile.close();//关闭文件

	/*标准输出vec_file的元素*/
	vector<string>::const_iterator it = vec_file.begin();
	while(it != vec_file.end()){
		cout << *it << endl;
		++it;
	}

	/*将vec_file的元素写到out.txt*/
	//关联out.txt与outfile文件流并以app模式打开out.txt(注意，每次打开前应clear并close文件流)
	//out.txt的路径为E:\Cpp Primer\CppPrimer\ch8\ReadWriteFile\ReadWriteFile
	ofstream outfile("out.txt", ofstream::app);
	it = vec_file.begin();
	while(it != vec_file.end()){
		outfile << *it << endl;
		++it;
	}
	system("pause");
	return 0;
}