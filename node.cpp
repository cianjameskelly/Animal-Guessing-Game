#include "node.h"
#include <cassert>//handles fatal errors
#include <cctype>//for "isspace"

using namespace std;

// write helper
void writeHelper(ostream& out, const node* n)
{
    if( n == nullptr )
        return;
    
    if( n->ifNo || n->ifYes )
    {
        out<<"Q   "<<n->detailText<<endl;
        writeHelper(out, n->ifYes);
        writeHelper(out, n->ifNo);
    }
    
    else
        out<<"A   "<<n->detailText<<endl;
}

// write the tree whose root is given
void node::write(std::ostream& out, const node* root)
{
    writeHelper(out, root);
}

// the helper method
node* insertQuestion(istream& in,node* curr)
{
    // read in the line
    string line;
    getline(in,line);
    
    // the point where the description text starts
    size_t index = 1;
    while(isspace(line[index]))
        index++;
    
    // if this is a question
    if( line[0] == 'Q' )
    {
        // get the question
        string question = line.substr(index);
        
        // then, create a new node and recur
        curr = new node(question);
        curr->ifYes = insertQuestion(in, curr->ifYes);
        curr->ifNo = insertQuestion(in, curr->ifNo);
    }
    else
    {
        // get the answer
        string answer = line.substr(index);
        curr = new node(answer);
    }
    
    // return the current
    return curr;
}

// read a tree from in storing the tree root in t
void node::read(istream& in, node*& t)
{
  // replace the line below by your own code
    t = insertQuestion(in, t);
}