#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

void ShowStr(const std::string& s);
class Store
{
public:
	Store(std::ofstream& osin):os(osin) {}
	void operator()(const std::string& str) 
	{
		size_t len = str.length();
		os.write((char*)&len, sizeof(std::size_t));
		os.write(str.data(), len);
	}
private:
	std::ofstream& os;
};
void GetStrs(std::ifstream& is, std::vector<std::string>& vis);

int main()
{
	using namespace std;
	vector<string> vostr;
	string temp;
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is you input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not opn file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the string read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
	return 0;
}

void ShowStr(const std::string& s)
{
	std::cout << s << std::endl;
}
void GetStrs(std::ifstream& is, std::vector<std::string>& vis)
{
	char chr; 
	size_t len;
	while (is.read((char*)&len, sizeof(std::size_t)))
	{
		std::string str;
		for (size_t i = 0; i < len; ++i)
		{
			is.read(&chr, 1);
			str.push_back(chr);
		}
		vis.push_back(str);
	}
}