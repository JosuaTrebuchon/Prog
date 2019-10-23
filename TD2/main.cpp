#include "Itv.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv){
  Itv I1, I2(3,1);
  I2.afficher();
  I1.afficher();
  std::cout << I2.getBi() << std::endl;
  I1.setBi(-6);
  I1.afficher();
  I2.setBs(0);
  I2.afficher();
  std::cout << "longueur I2 : " << I2.longueur() << std::endl;
  std::cout << "longueur I1 : " << I1.longueur() << std::endl;

  Itv I3(3,5), I4(3,4), I5(5,10), I6(3,4);

  std::cout << "I3 appartient à I4 : " << I4.estInclus(I3) << std::endl;
  std::cout << "I4 appartient à I3 : " << I3.estInclus(I4) << std::endl;
  std::cout << "I3 accolé à I5 : " << I3.estAccole(I5) << std::endl;
  std::cout << "I5 accolé à I3 : " << I5.estAccole(I3) << std::endl;
  std::cout << "I3 égale à I5 : " << I3.estEgal(I5) << std::endl;
  std::cout << "I6 égale à I4 : " << I6.estEgal(I4) << std::endl;
  std::cout << "I3 disjoint à I5 : " << I3.estDisjoint(I5) << std::endl;
  std::cout << "I6 disjoint à I5 : " << I6.estDisjoint(I5) << std::endl;

  I2.afficher();
  I2.move(2);
  I2.afficher();

  return 0;
}
