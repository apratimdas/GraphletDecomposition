
#ifndef GRAPHLETCORE_H
#define GRAPHLETCORE_H

#ifdef WIN32
#else
//#include <sys/time.h>
//#include <unistd.h>
#endif
#include <stdlib.h>
#include <float.h>
#include <cstddef>
#include <iostream>
#include <limits>
#include "math.h"
//#include "graphlet_rand.h"
#include "graphletHeaders.h"
//#include "graphlet_utils.h"
//#include "graphlet_vertex.h"
//#include "graphlet_params.h"
//#include "graphlet_univar_stats.h"

namespace graphlet
{

//Placeholder class
//Switch to using graph library for graph representation

class GraphletCore
{

private:
	void read_edge_list(const string& filename);


public:
	/// Number of jobs each worker is assigned (at a time)
	unsigned int blockSize;
	double densityThreshold;

	/// Stores the (row/col) indices
	vector<int> edges;
	/// Stores the position of th neighbors in edges
	vector<long long> vertices;
	/// Input edge weights (optional)
	vector<double> wt;

	string fn;

	int minDegree, maxDegree, avgDegree;
	bool isAdj, isWeighted, verbose;


	void initialize();

	inline bool isAdjExists() { return isAdj; }

	void createAdjMatrix();


	~GraphletCore();
	GraphletCore() {}
	GraphletCore(const string& filename, string orderingTechnique = "degree", bool smallToLarge = false);
	GraphletCore(const string& filename);
	GraphletCore(vector<long long> vs, vector<int> es) : edges(es), vertices(vs) {}

	static bool testcheck() { return true; }

};

}


#endif //GRAPHLETCORE_H