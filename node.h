#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

struct node { //state objects
  string detailText;
  node* ifYes;
  node* ifNo;

  node (string q, node* yes = NULL, node* no = NULL)
    : detailText(q), ifYes(yes), ifNo(no)
    {}
  static void read (istream& in, node*& t);
  static void write (ostream& out, const node* root);
  
private:
  friend istream& operator>>(istream&, node*&);
  friend ostream& operator<<(ostream&, const node*);

};

inline
ostream& operator<< (ostream& out, const node* n)
{
  node::write (out, n);
  return out;
}

inline
std::istream& operator>> (std::istream& in, node*& n)
{
  node::read (in, n);
  return in;
}

#endif