// working.cpp by Bill Weinman <http://bw.org/>
// updated 2002-06-24
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

static const char * filename = "items.txt";
constexpr size_t maxstring = 1024;
constexpr char tab_char = '\t';

class Item{
	int _sku;
	std::string _name;
	std::string _desc;
public:
	Item(){reset();};
	Item(int sku,std::string & name,std::string & desc):_sku(sku),_name(name),_desc(desc){}
	Item(const Item &);

	Item & operator = (const Item &);
	~Item(){reset();}
	void reset(){_sku=0,_name=_desc="unk";}

	void setSku(int sku){_sku=sku;}
	int getSku(){return _sku;}
	void setName(std::string & name){_name=name;}
	std::string getName()const{return _name;}
	void setDesc(std::string & desc){_desc=desc;}
	std::string getDesc()const{return _desc;}
};


Item::Item(const Item & item ){
	_sku=item._sku;
	_name=item._name;
	_desc=item._desc;
}

Item & Item::operator = (const Item & item){
	if(this!=&item){
		_sku=item._sku;
		_name=item._name;
		_desc=item._desc;
	}
}

std::vector<std::string> Split (const std::string & buf){
	std::vector<std::string> str_v;
	size_t iniStr=0;
	size_t indTab=0;

	while(true){
		indTab=buf.find(tab_char,iniStr);
		str_v.push_back(buf.substr(iniStr, indTab-iniStr));
		if(indTab==std::string::npos)break;
		iniStr=indTab+1;
	}
	return str_v;
}

int main()
{
    char buf[maxstring];

    // read a file
    std::cout << "read the file:" << std::endl;
    std::ifstream infile(filename);
    while (infile.good()) {
        infile.getline(buf, sizeof(buf));
        //std::cout << buf << std::endl;
        if(*buf==0)break;

        std::vector<std::string> str_v = Split(buf);
        if(str_v.size()<3)continue;

        Item item(std::stoi(str_v[0]),str_v[1],str_v[2]);
        //printf("skuu: %d, name: %s, desc: %s\n",item.getSku(),item.getName(),item.getDesc());

        std::cout << "sku: " << item.getSku()
				<< ", name: " << item.getName()
				<< ", desc: " << item.getDesc() << std::endl;
    }
    infile.close();

    return 0;
}
