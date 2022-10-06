#include "main.hpp"

static void	vectorTests() {
	std::ofstream outfile;

	outfile.open(VECTORFILE);

    vectorAccessOperator(outfile);
    vectorAssign(outfile);
    vectorAt(outfile);
    vectorBack(outfile);
    vectorBegin(outfile);
    vectorCapacity(outfile);
    vectorClear(outfile);
    vectorConstructor(outfile);
    vectorEmpty(outfile);
    vectorEnd(outfile);
    vectorErase(outfile);
    vectorFront(outfile);
    vectorInsert(outfile);
    vectorMaxSize(outfile);
    vectorOperatorEqual(outfile);
    vectorPopBack(outfile);
    vectorPushBack(outfile);
    vectorRbegin(outfile);
    vectorRend(outfile);
    vectorResize(outfile);

	outfile.close();
}

static void	stackTests() {
    std::ofstream outfile;

    outfile.open(STACKFILE);

    stackAccessOperator(outfile);
    stackAssign(outfile);
    stackEmpty(outfile);
    stackEnd(outfile);
    stackErase(outfile);
    stackOperatorEqual(outfile);
    stackPop(outfile);
    stackPush(outfile);

    outfile.close();
}

static void	mapTests() {
    std::ofstream outfile;

    outfile.open(MAPFILE);

    mapAccessOperator(outfile);
    mapAt(outfile);
    mapBegin(outfile);
    mapClear(outfile);
    mapCount(outfile);
    mapEmpty(outfile);
    mapErase(outfile);
    mapEqualRange(outfile);
    mapFind(outfile);
    mapInsert(outfile);

    outfile.close();
}

int main(int ac, char **av) {
	std::string input;

	if (ac != 2) {
		std::cout << "missing arg" << std::endl;
		return (0);
	}
	input = av[1];
	if (input.compare("vector") == 0)
		vectorTests();
    else if (input.compare("stack") == 0)
        stackTests();
    else if (input.compare("map") == 0)
        mapTests();
	else
		std::cout << "bad argument" << std::endl;
	return (0);
}