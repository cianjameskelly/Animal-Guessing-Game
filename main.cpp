//QA.txt must be included in the folder this program is being ran in
#include <cassert>//handles fatal errors
#include <fstream>//allows access to file
#include <string>
#include "node.h"

using namespace std;

bool getYesNoAnswer() 
{
  // get yes no answer
  while(true)
    {
      // initialize string ans
      string ans;
      getline(cin, ans);
      if((ans[0] == 'y') || (ans[0] == 'Y'))
	     return true;
      else if((ans[0] == 'n') || (ans[0] == 'N'))
	     return false;
      cout<<"Please answer y or n.\n";
    }
}

void learnNewAnimal(node* current)
{
  // learn new animal
  string currentAnimal = current->detailText;
  cout<<"What is your animal?\n";
  string newAnimal;
  getline(cin, newAnimal);
  cout<<"What is a yes/no question that can be used to tell a " <<current->detailText<< " from a "<<newAnimal<<" ?\n";
  string newQuestion;

  //these pointers make it possible to insert a new question for a new animal being added
  node * node1 = new node(newAnimal, 0, 0);
  node * node2 = new node(currentAnimal, 0, 0);
  // make sure allocation worked
  assert ((node1 != 0) && (node2 != 0));

  getline(cin, newQuestion);
  cout<<"For a "<<newAnimal<<" is the answer yes or no?\n";
  if (getYesNoAnswer() != 0) 
    {
      current->ifYes = node1;
      current->ifNo = node2;
    }
  else
    {
      current->ifYes = node2;
      current->ifNo = node1;
    }
  current->detailText = newQuestion;
}

void animalGame(const char* fileName) 
{
  //initialize the database
  node* root = 0;
  {
    ifstream in (fileName);
    if(in.good())
      in>>root;
  }

  // play the game
  node * current = root;
  // now start game
  cout<<"Let's play \"Guess the Animal\".\n";
  while(current != 0) 
    {
      // if current node has children it is a question
      if(current->ifYes != 0) 
	    {
	     cout<<current->detailText<<'\n';
	     if(getYesNoAnswer())
	      current = current->ifYes;
	     else
	      current = current->ifNo;
	    }
      // if no children it is an answer
      else 
	    {
	     cout<<"Is it a "<<current->detailText<<" ?\n";
	     if(getYesNoAnswer()) 
	      cout<<"\nWoohoo!\n";
	     else 
	     {
	      //failed to guess animal, so learn new one.
	      learnNewAnimal(current);
	     }
	     cout<<"Go again?\n";
	     if(getYesNoAnswer())
	      current = root;
	     else 
	      current = 0;
	    }
    }

  // Save the modified question set
  ofstream out(fileName);
  out<<root<<flush;
}

int main(int nargs, char** argv)
{
  animalGame("QA.txt");
  return 0;
}