#pragma once
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <map>
#include <stack>
#include <deque>

#include "vector.hpp"
#include "stack.hpp"
#include "reverse_iterator.hpp"
#include "map.hpp"

#ifdef STL
    #define STDFT		std
    #define VECTORFILE	"stdVectorOutput"
    #define STACKFILE	"stdStackOutput"
    #define MAPFILE		"stdMapOutput"
#else
    #define STDFT		ft
    #define VECTORFILE	"ftVectorOutput"
    #define STACKFILE	"ftStackOutput"
    #define MAPFILE		"ftMapOutput"
#endif


int vectorAccessOperator(std::ofstream &outfile);
int vectorAssign(std::ofstream &outfile);
int vectorAt(std::ofstream &outfile);
int vectorBack(std::ofstream &outfile);
int vectorBegin(std::ofstream &outfile);
int vectorCapacity(std::ofstream &outfile);
int vectorClear(std::ofstream &outfile);
int vectorConstructor(std::ofstream &outfile);
int vectorEmpty(std::ofstream &outfile);
int vectorEnd(std::ofstream &outfile);
int vectorErase(std::ofstream &outfile);
int vectorFront(std::ofstream &outfile);
int vectorInsert(std::ofstream &outfile);
int vectorMaxSize(std::ofstream &outfile);
int vectorOperatorEqual(std::ofstream &outfile);
int vectorPopBack(std::ofstream &outfile);
int vectorPushBack(std::ofstream &outfile);
int vectorRbegin(std::ofstream &outfile);
int vectorRend(std::ofstream &outfile);
int vectorResize(std::ofstream &outfile);


int stackAccessOperator(std::ofstream &outfile);
int stackAssign(std::ofstream &outfile);
int stackEmpty(std::ofstream &outfile);
int stackEnd(std::ofstream &outfile);
int stackErase(std::ofstream &outfile);
int stackOperatorEqual(std::ofstream &outfile);
int stackPop(std::ofstream &outfile);
int stackPush(std::ofstream &outfile);

int mapAccessOperator(std::ofstream &outfile);
int mapAt(std::ofstream &outfile);
int mapBegin(std::ofstream &outfile);
int mapClear(std::ofstream &outfile);
int mapCount(std::ofstream &outfile);
int mapEmpty(std::ofstream &outfile);
int mapErase(std::ofstream &outfile);
int mapEqualRange(std::ofstream &outfile);
int mapFind(std::ofstream &outfile);
int mapInsert(std::ofstream &outfile);