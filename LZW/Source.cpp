#include "bits/stdc++.h"
#include <unordered_map>
using namespace std;


vector<int> encoding(string s1)
{
	cout << "Encoding\n";
	/*unordered_map<string, int> table;
	for (int i = 0; i <= 255; i++) {
		string ch = "";
		ch += char(i);
		table[ch] = i;
	}*/


	cout << "String\tOutput_Code\tAddition\n";
	unordered_map<string, int> table;
	int	Initialization_count=0;
	for (int i = 0; i < 2; i++) {
		Initialization_count++;
		string ch = "";
		ch += char(97 + i);
		table[ch] = i;
	cout << "\t\t\t"<<ch << "\t" << table[ch] << "\t\t"<< endl;
	}

	string p = "", c = "";
	p += s1[0];
	int code = Initialization_count;
	vector<int> output_code;
	for (int i = 0; i < s1.length(); i++) {
		if (i != s1.length() - 1)
			c += s1[i + 1];
		if (table.find(p + c) != table.end()) {
			p = p + c;
		}
		else {
			cout << p << "\t" << table[p] << "\t\t"
				<< p + c << "\t" << code << endl;
			output_code.push_back(table[p]);
			table[p + c] = code;
			code++;
			p = c;
		}
		c = "";
	}
	cout << p << "\t" << table[p] << endl;
	output_code.push_back(table[p]);
	return output_code;
}

void decoding(vector<int> op)
{
	cout << "\nDecoding\n";
	/*unordered_map<int, string> table;
	for (int i = 0; i <= 255; i++) {
		string ch = "";
		ch += char(i);
		table[i] = ch;
	}*/
	unordered_map<int ,string> table;
	int Initialization_count = 0;
	for (int i = 0; i < 2; i++) {
		Initialization_count++;
		string ch = "";
		ch += char(97 + i);
		table[i] = ch;
	}
	int old = op[0],n;
	string s = table[old];
	string c = "";
	c += s[0];
	cout << s;
	int count = Initialization_count;
	for (int i = 0; i < op.size() - 1; i++) {
		n = op[i + 1];
		if (table.find(n) == table.end()) {
			s = table[old];
			s = s + c;
		}
		else {
			s = table[n];
		}
		cout << s;
		c = "";
		c += s[0];
		table[count] = table[old] + c;
		count++;
		old = n;
	}
}



class blocksort {
private:
	std::string str;
	std::string key;
	std::vector<std::string> sort_offset;
public:
	blocksort();//Def Constructor
	blocksort(std::string str);//Constructor
	std::string PatrolStr();//Make Patroldata
	int findIndex(std::string value)
	{
		auto iter = std::find(sort_offset.begin(), sort_offset.end(), value);
		size_t index = std::distance(sort_offset.begin(), iter);
		if (index == sort_offset.size())
		{
			return -1;
		}
		return index;
	}
	void takesort(std::string offset);
	//void call() { std::cout << str << std::endl; };
	void call_sortoffset();
	string PassKey(){return key; }
	string PassStr() { return str; }
};



blocksort::blocksort() {
	str = "デフォルトコンストラクタがコールされました";
}
//Constructor
blocksort::blocksort(std::string str) {
	this->str = str;
}


//DefPat
std::string blocksort::PatrolStr()
{
	cout << "PatrolStr" << endl;
	int size = str.size();
	std::string offset_stream = str;
	std::string buf = str;
	for (int i = 0; i < size; i++) {
		cout << buf << endl;
		buf.push_back(buf[0]);
		buf.erase(buf.begin());
		offset_stream += buf;
	}
	cout << endl;
	return std::string(offset_stream);
}


void blocksort::takesort(std::string offset) {
	for (int i = 0; i < str.size(); i++) {
		sort_offset.push_back(offset.substr(0 + i * str.size(), str.size()));
		std::sort(sort_offset.begin(), sort_offset.end());
	}
	for (int i = 0; i < str.size(); i++) {
		key += sort_offset[i].back();
	}
}

void blocksort::call_sortoffset() {
	cout << "BlocksSort"<<std::endl;
	for (auto it = sort_offset.begin(); it != sort_offset.end(); ++it)
		std::cout << *it << std::endl;
	cout << std::endl;
	std::cout << "Key\t\t" <<"InputStr\t"<< "IndexNumber" << std::endl 
		<< key << "\t" << str <<"\t"<<findIndex(str)<< std::endl << std::endl;
}


int main()
{


	std::string data("ababbbababba");
	blocksort step1(data);//dataをコンストラクタにpass
	step1.takesort(step1.PatrolStr());
	step1.call_sortoffset();


	string s = step1.PassKey();
	cout << "Apply_Blocksort" << endl;
	vector<int> output_code = encoding(s);
	cout << "Output Codes are: ";
	for (int i = 0; i < output_code.size(); i++) {
		cout << output_code[i] << " ";
	}
	cout << endl;

	decoding(output_code);

	cout << endl<<endl;
	s = step1.PassStr();
	cout << "Not_Appy_Blocksort" << endl;
	output_code = encoding(s);
	cout << "Output Codes are: ";
	for (int i = 0; i < output_code.size(); i++) {
		cout << output_code[i] << " ";
	}
	cout << endl;

	decoding(output_code);
}