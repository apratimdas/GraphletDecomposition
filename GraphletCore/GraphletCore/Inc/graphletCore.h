
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
public:

	static void ParseGraphToFile(GraphletCore& data, const string filename = "results.txt")
	{

		// Represent results into standard output here

	}


private:
	void read_edge_list(const string& filename);


public:
	/// Number of jobs each worker is assigned (at a time)
	unsigned int blockSize;
	double densityThreshold;

	// TODO: Try to incorporate the following members using Graph Lib
	/// Stores the (row/col) indices
	vector<int> edges;
	/// Stores the position of th neighbors in edges
	vector<long long> vertices;
	/// Input edge weights (optional)
	vector<double> wt;

	NGraph::tGraph<int> mGraph;	//https://math.nist.gov/~RPozo/ngraph/ngraph_index.html

	string fn;

	// TODO: Try to incorporate this using Graph Lib
	vector<int> degree;

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

	static bool unittestcheck() { return true; }



	int num_vertices()					{ return vertices.size() - 1; }
	int num_edges()						{ return edges.size() / 2; }
	vector <long long>* get_vertices()	{ return &vertices; }
	vector<int>* get_edges()			{ return &edges; }
	vector<int>* get_degree()			{ return &degree; }


	// graphlet measures
	// k=2
	unsigned long long total_2_1edge;
	unsigned long long total_2_indep;

	// k=3
	unsigned long long total_3_tris;
	unsigned long long total_2_star;
	unsigned long long total_3_1edge;
	unsigned long long total_3_indep;

	// k=4 Connected
	unsigned long long total_4_clique;
	unsigned long long total_4_chordcycle;
	unsigned long long total_4_tailed_tris;
	unsigned long long total_4_cycle;
	unsigned long long total_3_star;
	unsigned long long total_4_path;

	// k=4 Disconnected
	unsigned long long total_4_2edge;
	unsigned long long total_4_1edge;
	unsigned long long total_4_2star;
	unsigned long long total_4_tri;
	unsigned long long total_4_indep;


	// return vector of the k = 4 graphlet names / labels
	vector<string> get_graphlet_size4_names() 
	{
		vector<string> g4_names;
		g4_names.reserve(11);
		g4_names.push_back("4-clique");
		g4_names.push_back("4-chordal-cycle");
		g4_names.push_back("4-tailed-tri");
		g4_names.push_back("4-cycle");
		g4_names.push_back("3-star");
		g4_names.push_back("4-path");
		// DISCONNECTED
		g4_names.push_back("4-node-1-tri");
		g4_names.push_back("4-node-2-star");
		g4_names.push_back("4-node-2-edge");
		g4_names.push_back("4-node-1-edge");
		g4_names.push_back("4-node-indep");
		return g4_names;
	}

};

}


#endif //GRAPHLETCORE_H