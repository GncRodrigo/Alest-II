#include <iostream>
#include "digraph.h"
#include "directedcycle.h"

using namespace std;
int main()
{
  Digraph g("es.txt");
  DirectedCycle dcycle(g);

  cout << g.toDot() << endl;

  cout << "Tem ciclo? " << dcycle.containsCycle() << endl;
}