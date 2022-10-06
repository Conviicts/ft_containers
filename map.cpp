#include "main.hpp"

int		mapAccessOperator(std::ofstream &outfile) {
	outfile << std::endl << "* [MAP] Operator[]  --- *" << std::endl;
	STDFT::map<char,std::string> myMap;

	myMap['a']="1";
	myMap['b']="2";
	myMap['c']="3";
	myMap['d']="4";
	myMap['e']=myMap['d'];

	outfile << "myMap['a'] is " << myMap['a'] << '\n';
	outfile << "myMap['b'] is " << myMap['b'] << '\n';
	outfile << "myMap['c'] is " << myMap['c'] << '\n';
	outfile << "myMap['d'] is " << myMap['d'] << '\n';
	outfile << "myMap['e'] is " << myMap['e'] << '\n';

	outfile << "myMap now contains " << myMap.size() << " elements.\n";

	return 0;
}

int		mapAt(std::ofstream &outfile) {
    outfile << std::endl << "* [MAP] At  --- *" << std::endl;
    STDFT::map<char,std::string> myMap;

    myMap['a']="1";
    myMap['b']="2";
    myMap['c']="3";
    myMap['d']="4";
    myMap['e']=myMap['d'];

    outfile << "myMap['a'] is " << myMap.at('a') << '\n';
    outfile << "myMap['b'] is " << myMap.at('b') << '\n';
    outfile << "myMap['c'] is " << myMap.at('c') << '\n';
    outfile << "myMap['d'] is " << myMap.at('d') << '\n';
    outfile << "myMap['e'] is " << myMap.at('e') << '\n';

    outfile << "myMap now contains " << myMap.size() << " elements.\n";

    return 0;
}

int		mapBegin(std::ofstream &outfile) {
    outfile << std::endl << "* [MAP] Begin  --- *" << std::endl;
    STDFT::map<char,int> myMap;

    myMap['a']=10;
    myMap['b']=20;
    myMap['c']=30;

    STDFT::map<char,int>::iterator it = myMap.begin();
    outfile << it->first << " => " << it->second << '\n';

    return 0;
}

int		mapClear(std::ofstream &outfile) {
    outfile << std::endl << "* [MAP] Clear  --- *" << std::endl;
    STDFT::map<char,int> myMap;

    myMap['a']=10;
    myMap['b']=20;
    myMap['c']=30;

    outfile << "myMap.size() is " << myMap.size() << '\n';
    myMap.clear();
    outfile << "myMap.size() is " << myMap.size() << '\n';

    return 0;
}

int		mapCount(std::ofstream &outfile) {
    outfile << std::endl << "* [MAP] Count  --- *" << std::endl;
    STDFT::map<char,int> myMap;

    myMap['a']=10;
    myMap['b']=20;
    myMap['c']=30;

    outfile << "myMap.count('a') is " << myMap.count('a') << '\n';
    outfile << "myMap.count('b') is " << myMap.count('b') << '\n';
    outfile << "myMap.count('c') is " << myMap.count('c') << '\n';
    outfile << "myMap.count('d') is " << myMap.count('d') << '\n';

    return 0;
}

int		mapEmpty(std::ofstream &outfile) {
    outfile << std::endl << "* [MAP] Empty  --- *" << std::endl;
    STDFT::map<char,int> myMap;

    outfile << "myMap.empty() is " << myMap.empty() << '\n';
    myMap['a']=10;
    myMap['b']=20;
    myMap['c']=30;
    outfile << "myMap.empty() is " << myMap.empty() << '\n';

    return 0;
}

int		mapEnd(std::ofstream &outfile) {
    outfile << std::endl << "* [MAP] End  --- *" << std::endl;
    STDFT::map<char,int> myMap;

    myMap['a']=10;
    myMap['b']=20;
    myMap['c']=30;

    STDFT::map<char,int>::iterator it = myMap.end();
    outfile << it->first << " => " << it->second << '\n';

    return 0;
}

int		mapErase(std::ofstream &outfile) {
    outfile << std::endl << "* [MAP] Erase  --- *" << std::endl;
    STDFT::map<char,int> myMap;

    myMap['a']=10;
    myMap['b']=20;
    myMap['c']=30;
    myMap['d']=40;
    myMap['e']=50;
    myMap['f']=60;

    outfile << "myMap contains " << myMap.size() << " elements.\n";
    outfile << "myMap.erase('b')\n";
    myMap.erase('b');
    outfile << "myMap contains " << myMap.size() << " elements.\n";
    outfile << "myMap.erase('e')\n";
    myMap.erase('e');
    outfile << "myMap contains " << myMap.size() << " elements.\n";

    return 0;
}

int		mapEqualRange(std::ofstream &outfile) {
    outfile << std::endl << "* [MAP] EqualRange  --- *" << std::endl;
    STDFT::map<char,int> myMap;

    myMap['a']=10;
    myMap['b']=20;
    myMap['c']=30;

    STDFT::pair<STDFT::map<char,int>::iterator,STDFT::map<char,int>::iterator> ret;
    ret = myMap.equal_range('b');

    outfile << "lower bound points to: ";
    outfile << ret.first->first << " => " << ret.first->second << '\n';

    outfile << "upper bound points to: ";
    outfile << ret.second->first << " => " << ret.second->second << '\n';

    return 0;
}

int		mapFind(std::ofstream &outfile) {
    outfile << std::endl << "* [MAP] Find  --- *" << std::endl;
    STDFT::map<char,int> myMap;

    myMap['a']=10;
    myMap['b']=20;
    myMap['c']=30;

    STDFT::map<char,int>::iterator it = myMap.find('b');
    if (it != myMap.end())
        myMap.erase (it);

    outfile << "elements in myMap:" << '\n';
    outfile << "a => " << myMap.find('a')->second << '\n';
    outfile << "c => " << myMap.find('c')->second << '\n';

    return 0;
}

int		mapInsert(std::ofstream &outfile) {
    outfile << std::endl << "* [MAP] Insert  --- *" << std::endl;
    STDFT::map<char,int> myMap;

    // first insert function version (single parameter):
    myMap.insert ( STDFT::pair<char,int>('a',100) );
    myMap.insert ( STDFT::pair<char,int>('z',200) );

    STDFT::pair<STDFT::map<char,int>::iterator,bool> ret;
    ret = myMap.insert ( STDFT::pair<char,int>('z',500) );
    if (ret.second==false) {
        outfile << "element 'z' already existed";
        outfile << " with a value of " << ret.first->second << '\n';
    }

    // second insert function version (with hint position):
    STDFT::map<char,int>::iterator it = myMap.begin();
    myMap.insert (it, STDFT::pair<char,int>('b',300));  // max efficiency inserting
    myMap.insert (it, STDFT::pair<char,int>('c',400));  // no max efficiency inserting

    // third insert function version (range insertion):
    STDFT::map<char,int> anotherMap;
    anotherMap.insert(myMap.begin(),myMap.find('c'));

    // showing contents:
    outfile << "myMap contains:\n";
    for (it=myMap.begin(); it!=myMap.end(); ++it)
        outfile << it->first << " => " << it->second << '\n';

    outfile << "anotherMap contains:\n";
    for (it=anotherMap.begin(); it!=anotherMap.end(); ++it)
        outfile << it->first << " => " << it->second << '\n';

    return 0;
}
