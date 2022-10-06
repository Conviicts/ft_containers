#include "main.hpp"

int		vectorAccessOperator(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Operator[]  --- *" << std::endl;
	STDFT::vector<int> ft_vec (10);
	STDFT::vector<int>::size_type sz = ft_vec.size();

	for (unsigned i=0; i<sz; i++) ft_vec[i]=i;

	for (unsigned i=0; i<sz/2; i++) {
		int temp;
		temp = ft_vec[sz-1-i];
		ft_vec[sz-1-i]=ft_vec[i];
		ft_vec[i]=temp;
	}
	outfile << "ft_vec contains:";
	for (unsigned i=0; i<sz; i++)
		outfile << ' ' << ft_vec[i];
	outfile << '\n';
	return 0;
}

int		vectorAssign(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Assign  --- *" << std::endl;
	STDFT::vector<int> first;
	STDFT::vector<int> second;
	STDFT::vector<int> third;

	first.assign (7,100);
	outfile << "first" << std::endl;
	for (unsigned int i = 0; i < first.size(); i++)
		outfile << first[i] << " ";
	outfile << std::endl;
	STDFT::vector<int>::iterator it;
	it=first.begin()+1;
	second.assign (it,first.end()-1);
	outfile << "second" << std::endl;
	for (unsigned int i = 0; i < second.size(); i++)
		outfile << second[i] << " ";
	outfile << std::endl;
	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);

	outfile << "third" << std::endl;
	for (unsigned int i = 0; i < third.size(); i++)
		outfile << third[i] << " ";
	outfile << std::endl;
	outfile << "vector:" << std::endl;
	outfile << "Size of first: " << int (first.size()) << '\n';
	outfile << "Size of second: " << int (second.size()) << '\n';
	outfile << "Size of third: " << int (third.size()) << '\n';
	return 0;
}

int		vectorAt(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] At  --- *" << std::endl;
	STDFT::vector<int> myvector (10);
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;
	outfile << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		outfile << ' ' << myvector.at(i);
	outfile << '\n';
	return 0;
}

int		vectorBack(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Back  --- *" << std::endl;
	STDFT::vector<int> myvector;
	myvector.push_back(10);
	while (myvector.back() != 0) {
		myvector.push_back ( myvector.back() -1 );
	}
	outfile << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
		outfile << ' ' << myvector[i];
	outfile << '\n';
	return 0;
}

int		vectorBegin(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Begin  --- *" << std::endl;
	STDFT::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);
	outfile << "myvector contains:";
	for (STDFT::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		outfile << ' ' << *it;
	outfile << '\n';
	return 0;
}

int		vectorCapacity(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Capacity  --- *" << std::endl;
	STDFT::vector<int> myvector;
	for (int i=0; i<100; i++) myvector.push_back(i);
	outfile << "size: " << myvector.size() << std::endl;
	outfile << "capacity: " << myvector.capacity() << std::endl;
	outfile << "max_size: " << myvector.max_size() << std::endl;
	return 0;
}

int		vectorClear(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Clear  --- *" << std::endl;
	STDFT::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	outfile << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		outfile << ' ' << myvector[i];
	outfile << '\n';
	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);
	outfile << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		outfile << ' ' << myvector[i];
	outfile << '\n';
	return 0;
}

int		vectorConstructor(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Constructor  --- *" << std::endl;
	STDFT::vector<int> first;
	STDFT::vector<int> second (4,100);
	STDFT::vector<int> third (second.begin(),second.end());
	STDFT::vector<int> fourth (third);
	outfile << "The contents of fourth are:";
	for (unsigned i=0; i<fourth.size(); i++)
		outfile << ' ' << fourth[i];
	outfile << '\n';
	return 0;
}

int		vectorEmpty(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Empty  --- *" << std::endl;
	STDFT::vector<int> myvector;
	int sum (0);
	for (int i=1;i<=10;i++) myvector.push_back(i);
	while (!myvector.empty()) {
		sum += myvector.back();
		myvector.pop_back();
	}
	outfile << "total: " << sum << '\n';
	return 0;
}

int		vectorEnd(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] End  --- *" << std::endl;
	STDFT::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);
	outfile << "myvector contains:";
	for (STDFT::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		outfile << ' ' << *it;
	outfile << '\n';
	return 0;
}

int		vectorErase(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Erase  --- *" << std::endl;
	STDFT::vector<int> myvector;
	for (int i=1; i<10; i++) myvector.push_back(i);
	myvector.erase (myvector.begin()+5);
	outfile << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		outfile << ' ' << myvector[i];
	outfile << '\n';
	return 0;
}

int		vectorFront(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Front  --- *" << std::endl;
	STDFT::vector<int> myvector;
	myvector.push_back(78);
	myvector.push_back(16);
	myvector.front() -= myvector.back();
	outfile << "myvector.front() is now " << myvector.front() << '\n';
	return 0;
}

int		vectorInsert(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Insert  --- *" << std::endl;
	STDFT::vector<int> myvector (3,100);
	STDFT::vector<int>::iterator it;
	it = myvector.begin();
	it = myvector.insert ( it , 200 );
	myvector.insert (it,2,300);
	it = myvector.begin();
	std::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());
	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);
	outfile << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		outfile << ' ' << *it;
	outfile << '\n';
	return 0;
}

int		vectorMaxSize(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] MaxSize  --- *" << std::endl;
	STDFT::vector<int> myvector;
	if (myvector.max_size()>1000) {
		for (int i=0; i<1000; i++) myvector.push_back(0);
		outfile << "The vector contains 1000 elements.\n";
	}
	else outfile << "The vector could not hold 1000 elements.\n";
	return 0;
}

int		vectorOperatorEqual(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Operator=  --- *" << std::endl;
	STDFT::vector<int> foo (3,0);
	STDFT::vector<int> bar (5,0);
	bar = foo;
	foo = STDFT::vector<int>();
	outfile << "Size of foo: " << int(foo.size()) << '\n';
	outfile << "Size of bar: " << int(bar.size()) << '\n';
	return 0;
}

int		vectorPopBack(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] PopBack  --- *" << std::endl;
	STDFT::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	while (!myvector.empty()) {
		sum += myvector.back();
		myvector.pop_back();
	}
	outfile << "The elements of myvector add up to " << sum << '\n';
	return 0;
}

int		vectorPushBack(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] PushBack  --- *" << std::endl;
	STDFT::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);
	while (!myvector.empty()) {
		sum += myvector.back();
		myvector.pop_back();
	}
	outfile << "The elements of myvector add up to " << sum << '\n';
	return 0;
}

int		vectorRbegin(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Rbegin  --- *" << std::endl;
	STDFT::vector<int> myvector (5);  // 5 default-constructed ints
	int i=0;
	STDFT::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;
	outfile << "myvector contains:";
	for (STDFT::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		outfile << ' ' << *it;
	outfile << '\n';
	return 0;
}

int		vectorRend(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Rend  --- *" << std::endl;
	STDFT::vector<int> myvector (5);  // 5 default-constructed ints
	int i=0;
	STDFT::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;
	outfile << "myvector contains:";
	for (STDFT::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		outfile << ' ' << *it;
	outfile << '\n';
	return 0;
}

int		vectorResize(std::ofstream &outfile) {
	outfile << std::endl << "* [VECTOR] Resize  --- *" << std::endl;
	STDFT::vector<int> myvector;
	for (int i=1; i<10; i++) myvector.push_back(i);
	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);
	outfile << "myvector contains:";
	for (size_t i=0; i<myvector.size(); i++)
		outfile << ' ' << myvector[i];
	outfile << '\n';
	return 0;
}
