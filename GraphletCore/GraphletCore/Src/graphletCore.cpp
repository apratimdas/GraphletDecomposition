
#include <graphletCore.h>
#include <algorithm>

using namespace graphlet;
using namespace std;

void GraphletCore::initialize() {
	maxDegree = 0;
	minDegree = 0;
	avgDegree = 0;
	fn = "";
	isAdj = false;
	verbose = false;
}

GraphletCore::~GraphletCore() { }

