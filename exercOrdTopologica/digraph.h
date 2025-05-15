#include <map>
#include <string>
#include <vector>

#include "graph.h"

#ifndef DIGRAPH_H
#define DIGRAPH_H

class Digraph : public Graph {
 public:
  Digraph() : Graph() {}
  Digraph(std::string filename);
  void addEdge(std::string v, std::string w);
  void ordenacaotopologica(std::vector<std::string> &v);
  std::string toDot();
};

#endif
