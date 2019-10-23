#include <string>

class Itv{
 private :
  double bi, bs;
 public :
  // constructeur
  Itv();
  Itv(double bi, double bs);
  // accesseur en lecture
  double getBi() const;
  double getBs() const;
  // accesseur en ecriture
  void setBi(double);
  void setBs(double);
  // méthodes
  double longueur();
  bool appartient(double) const;
  void afficher() const;

  //méthodes 2
  bool estEgal(const Itv &intervalle) const;
  bool estInclus(const Itv &intervalle) const;
  bool estDisjoint(const Itv &intervalle) const;
  bool estAccole(const Itv &intervalle) const;
  bool estImbrique(const Itv &intervalle) const;
  void move(double x);
};

void translate(Itv &intervalle, double v);
