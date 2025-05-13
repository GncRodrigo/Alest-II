#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, (last - first + 1));
}
Graph::Graph() {
}

Graph::Graph(string filename) {
	ifstream file;
	file.open(filename);
	string line;
	if(file.is_open()) {
		while(getline(file, line)) {
			stringstream ss(line);
			string movie;
			getline(ss, movie, '/');
			movie = trim(movie);
			string actor;
			while(getline(ss, actor, '/')) {
				actor = trim(actor);
				if(!actor.empty()) {
  	    	addEdge(movie, actor);
    	}
	}
}
file.close();
}
}

vector<string> Graph::getAdj(string v) {
	return graph[v];
}

vector<string> Graph::getVerts() {
	vector<string> keys;
	for(auto const& element : graph)
		keys.push_back(element.first);
	return keys;
}

void Graph::addEdge(string v, string w) {
	addToList(v, w);
	addToList(w, v);
}

string Graph::toDot() {
    // Usa um conjunto de arestas para evitar duplicatas
	set<string> edges;
	const string NEWLINE = "\n";
	string sb;
    sb = "graph {"+NEWLINE;
    sb += "rankdir = LR;"+NEWLINE;
    sb += "node [shape = circle];"+NEWLINE;
    for(auto const& v: getVerts()) {
      for (auto const& w: getAdj(v)) {
        string edge = v < w ? v + w : w + v;
        if(edges.find(edge) == edges.end()) {
          sb += v + " -- " + w + NEWLINE;
          edges.insert(edge);
        }
      }
    }
    sb += "}" + NEWLINE;
    return sb;
}

void Graph::addToList(string v, string w) {
	vector<string>& list = graph[v];
	list.push_back(w);
}
