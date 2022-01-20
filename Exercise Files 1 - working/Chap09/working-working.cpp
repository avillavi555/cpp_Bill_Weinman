// working.cpp by Bill Weinman <http://bw.org/>
// updated 2002-06-24
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>


using namespace std;

static const char * filename = "items.txt";
constexpr size_t maxstring = 1024;  // size of line buffer
constexpr char tab_char = '\t';

class Item {
	int _sku;
	std::string _name;
	std::string _desc;
public:
	Item(){reset();}
	Item(int sku, std::string & name, std::string & desc): _sku(sku), _name(name), _desc(desc){}
	Item(const Item &);

	Item & operator = (const Item &);
	~Item(){reset();}

	void reset(){_sku=0; _name=_desc="unk";}
	void setSku(int sku ){ _sku=sku; }
	int getSku(){return _sku;};
	void setName(std::string & name){ _name=name; }
	std::string getName()const{return _name;}
	void setDesc(std::string & desc){ _desc=desc; }
	std::string getDesc()const{return _desc;}
};

Item::Item(const Item & item){
	_sku = item._sku;
	_name = item._name;
	_desc = item._desc;
}

Item & Item::operator = (const Item & item){
	if(this != &item){
		_sku = item._sku;
		_name = item._name;
		_desc = item._desc;
	}
}

std::vector<std::string> SplitStr (const std::string & str){
	std::vector<std::string> str_v;
	size_t iniStr=0;
	size_t indTab=0;

	while(true){
		indTab=str.find(tab_char, iniStr);
		str_v.push_back(str.substr(iniStr,indTab-iniStr));
		if(indTab==std::string::npos) break;
		iniStr=indTab+1;
	}
	return str_v;
}


int main()
{
	static char buf[maxstring];

	// read a file
	std::cout << "read the file:" << std::endl;
	std::ifstream infile(filename);
	while (infile.good()) {
	    infile.getline(buf, sizeof(buf));
	    if(*buf == 0) break;
	    //std::cout << buf << std::endl;

	    std::vector<std::string> split_v = SplitStr(buf);
		if(split_v.size()<3) continue;

		Item currentItem(std::stoi(split_v[0]),split_v[1],split_v[2]);
		std::cout << "sku: " << currentItem.getSku()
				<< ", name: " << currentItem.getName()
				<< ", desc: " << currentItem.getDesc() << std::endl;

	}
	infile.close();

	// delete file
	//std::cout << "delete file." << std::endl;
	//remove(filename);

    return 0;
}//main
