#include "main.hpp"

int stackAccessOperator(std::ofstream &outfile) {
    outfile << std::endl << "* [STACK] Operator[]  --- *" << std::endl;
    STDFT::stack<int> mystack;
    for (int i=0; i<5; ++i) mystack.push(i);
    outfile << "Popping out elements...";
    while (!mystack.empty()) {
        outfile << ' ' << mystack.top();
        mystack.pop();
    }
    outfile << std::endl;
    return 0;
}

int stackAssign(std::ofstream &outfile) {
    outfile << std::endl << "* [STACK] Assign  --- *" << std::endl;
    STDFT::stack<int> first;
    STDFT::stack<int> second;
    first.push(10);
    first.push(20);
    second = first;
    first.push(30);
    outfile << "Size of first: " << first.size() << std::endl;
    outfile << "Size of second: " << second.size() << std::endl;
    return 0;
}

int stackEmpty(std::ofstream &outfile) {
    outfile << std::endl << "* [STACK] Empty  --- *" << std::endl;
    STDFT::stack<int> mystack;
    int sum (0);
    for (int i=1;i<=10;i++) mystack.push(i);
    while (!mystack.empty()) {
        sum += mystack.top();
        mystack.pop();
    }
    outfile << "total: " << sum << std::endl;
    return 0;
}

int stackEnd(std::ofstream &outfile) {
    outfile << std::endl << "* [STACK] End  --- *" << std::endl;
    STDFT::stack<int> mystack;
    for (int i=0; i<5; ++i) mystack.push(i);
    outfile << "Popping out elements...";
    while (!mystack.empty()) {
        outfile << ' ' << mystack.top();
        mystack.pop();
    }
    outfile << std::endl;
    return 0;
}

int stackErase(std::ofstream &outfile) {
    outfile << std::endl << "* [STACK] Erase  --- *" << std::endl;
    STDFT::stack<int> mystack;
    for (int i=0; i<5; ++i) mystack.push(i);
    mystack.pop();
    outfile << "Popping out elements...";
    while (!mystack.empty()) {
        outfile << ' ' << mystack.top();
        mystack.pop();
    }
    outfile << std::endl;
    return 0;
}

int stackOperatorEqual(std::ofstream &outfile) {
    outfile << std::endl << "* [STACK] Operator=  --- *" << std::endl;
    STDFT::stack<int> first;
    STDFT::stack<int> second;
    first.push(10);
    first.push(20);
    second = first;
    first.push(30);
    outfile << "Size of first: " << first.size() << std::endl;
    outfile << "Size of second: " << second.size() << std::endl;
    return 0;
}

int stackPop(std::ofstream &outfile) {
    outfile << std::endl << "* [STACK] Pop  --- *" << std::endl;
    STDFT::stack<int> mystack;
    for (int i=0; i<5; ++i) mystack.push(i);
    outfile << "Popping out elements...";
    while (!mystack.empty()) {
        outfile << ' ' << mystack.top();
        mystack.pop();
    }
    outfile << std::endl;
    return 0;
}

int stackPush(std::ofstream &outfile) {
    outfile << std::endl << "* [STACK] Push  --- *" << std::endl;
    STDFT::stack<int> mystack;
    for (int i=0; i<5; ++i) mystack.push(i);
    outfile << "Popping out elements...";
    while (!mystack.empty()) {
        outfile << ' ' << mystack.top();
        mystack.pop();
    }
    outfile << std::endl;
    return 0;
}
