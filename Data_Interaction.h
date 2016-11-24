#include"Implementation.h"
#include<iostream>
#include<fstream>

using namespace std;

void load_file(castle& C, int &N, float &C1, float &C2, float&C3, Node ** nodes);
void Print_Enemy_info(Node* temp);
void print_region_info(Node *sheild, Node *otherEnemies, Node* killed_list, int n_active, int n_killed, int timestep, int region);