//asdfasdfasdfadf

#include <iostream>
#include <cstring>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>

using namespace std;

struct vertex {
  char* name;
  vector <vertex*> edges;
  vector <int> weight; 
};

void ADD(vector <vertex* > v, char* first, char* second, int weight); 
void REMOVEE(vector <vertex*> &v, char* first, char* second);
void REMOVEV(vector <vertex*> &v, char* name); 
void PRINT(vector <vertex*> v); 
void FIND(vector <vertex*> v, vertex *first, vertex* second);
bool CONTAINS(vector <vertex*> v, vertex* ver); 

int main () {
  vector <vertex*> v;
  bool running = true; 
  while (running == true) {
  cout << "Welcome to Graph Creator, type 'ADDE' to add an edge, type 'ADDV' to add a vertex, type 'PRINT' to print, type 'REMOVEE' to remove an edge, type 'REMOVEV' to remove a vertex, type 'FIND' to find the shortest path, and type 'EXIT' to quit" << endl;
  char* input = new char[100];
  cin.getline(input, 100);
  if (strcmp(input, "ADDE") == 0) {
    char* first = new char();
    char* second = new char();
    int weight;
    cout << "What is the first vertex: \n";
    cin.getline(first, 20);
    cout << "What is the second vertex: \n";
    cin.getline(second, 20);
    cout << "What is the line weight: \n";
    cin >> weight;
    cin.get();
    ADD(v, first, second, weight); 
  }
  
  else if (strcmp(input, "ADDV") == 0) {
    char* name = new char();
    cout << "What is the name of the vertex? \n";
    cin.getline(name, 20);
    vertex *temp = new vertex();
    temp -> name = name;
    v.push_back(temp); 
  }
  
  else if (strcmp(input, "PRINT") == 0) {
    PRINT(v); 
  }
  else if (strcmp(input, "REMOVEE") == 0) {
    char* first = new char();
    char* second = new char();
    cout << "What is the first vertex: \n";
    cin.getline(first, 20);
    cout << "What is the second vertex: \n";
    cin.getline(second, 20);
    REMOVEE(v, first, second); 
  }
  else if (strcmp(input, "REMOVEV") == 0) {
    char* name = new char();
    cout << "What is the name of the vertex? \n";
    cin.getline(name, 20);
    REMOVEV(v, name); 
  }
  else if (strcmp(input, "FIND") == 0) {
    char* first = new char();
    char* second = new char();
    cout << "Where is the starting vertex? \n";
    cin.getline(first, 20);
    cout << "Where is the second vertex? \n";
    cin.getline(second, 20);
    vertex * v1 = NULL;
    vertex * v2 = NULL;
    for (vector <vertex*> ::iterator it = v.begin(); it != v.end(); ++it) {
      if (strcmp((*it) -> name, first) == 0) {
	v1 = *it; 
      }
      else if(strcmp((*it) -> name, second) == 0) {
        v2 = *it; 
      }
    }
    if (v1 != NULL && v2 != NULL) {
      FIND(v, v1, v2); 
    }
    else {
      cout << "Some vertexes do not exist as you entered \n"; 
    }
  }
  else if (strcmp(input, "EXIT") == 0) {
    running = false; 
  }
  else {
    cout << "Valid Input Plz";
  }
  
  }   
    
}

void ADD(vector <vertex* > v, char* first, char* second, int weight) {
  vertex* v1 = NULL;
  vertex* v2 = NULL;
  for (vector < vertex*> ::iterator it = v.begin(); it != v.end(); ++ it) {
    if (strcmp((*it) -> name, first) == 0) {
      v1 = *it; 
    }
    else if (strcmp((*it) -> name, second) == 0) {
      v2 = *it; 
    }
  }
  if (v1 != NULL && v2 != NULL) {
    v1 -> edges.push_back(v2);
    v1 -> weight.push_back(weight); 
  }
}

void REMOVEE(vector <vertex*> &v, char* first, char* second) {
  vertex *v1 = NULL;
  vertex *v2 = NULL;
  for (vector <vertex*> ::iterator it = v.begin(); it !=v.end(); ++it) {
    if (strcmp((*it) -> name, first) == 0) {
      v1 = *it;
    }
    else if (strcmp((*it) -> name, second) == 0) {
      v2 = *it;
    }
  }
    vector <vertex*> fEdges = v1 -> edges;
    vector <int> fWeights = v1 -> weight;
    int count = 0;
    for (vector < vertex*> ::iterator it = fEdges.begin(); it !=fEdges.end(); ++it) {
      count++;
      if ((*it) == v2) {
	fEdges.erase(it);
	fWeights.erase(fWeights.begin() + (count - 1));
	v1 -> edges = fEdges;
	v1 -> weight = fWeights;
	break; 
      }
    }
}

void REMOVEV(vector <vertex*> &v, char* name) {
  vertex* temp = NULL;
  for (vector <vertex*> ::iterator it = v.begin(); it != v.end(); ++it) {
    if (strcmp((*it) -> name, name) == 0) {
      temp = *it;
      v.erase(it);
      cout << "Deleted \n";
      break; 
    }
  }
  for (vector < vertex*> ::iterator it = v.begin(); it != v.end(); ++it) {
    vector <vertex*> vEdges = (*it) -> edges;
    vector <int> vWeight = (*it) -> weight;
    int count = 0;
    for (vector < vertex*> ::iterator ite = vEdges.begin(); ite != vEdges.end(); ++ite) {
      count++;
      if ((*ite) == temp) {
	vEdges.erase(ite);
	vWeight.erase(vWeight.begin() + (count - 1));
	(*it) -> edges = vEdges;
	(*it) -> weight = vWeight;
	break; 
      }
    }
  }
}

bool CONTAINS(vector <vertex*> v, vertex* ver) {
  if (std::find(v.begin(), v.end(), ver) != v.end()) {
    return true; 
  }
  return false; 
}
 
void PRINT(vector <vertex*> v) {
  cout << " ";
  for (vector <vertex*> ::iterator it = v.begin(); it != v.end(); ++it) {
    cout << "       " << (*it) -> name; 
  }
  for (vector < vertex*> ::iterator it = v.begin(); it != v.end(); ++it) {
    cout << endl;
    cout << (*it) -> name;
    vector <vertex*> connect = (*it) -> edges;
    vector <int> length = (*it) -> weight;
    for (vector < vertex*> ::iterator ite = v.begin(); ite != v.end(); ++ite) {
      int count = 0;
      bool found = false;
      if (connect.empty()) {
	cout << "       " << "0"; 
      }
      else {
      for (vector <vertex*> ::iterator iter = connect.begin(); iter != connect.end(); ++iter) {
	count ++;
	if ((*iter) -> name == (*ite) -> name) {
	  cout << "       " << length.at(count - 1);
	  found = true; 
	}
      }
      if (!found) {
	cout << "       " << "0"; 
      }
      }
    }
  }
  cout << endl; 
}

void FIND(vector <vertex*> v, vertex *first, vertex* second) {

}
