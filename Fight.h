#include"Data_Interaction.h"
#include<fstream>
#include<Windows.h>


void remove_enemy(Node *& head, Node *&pre, Node *&temp, Node*&killed_list);
bool kill_random_enemy(Node *&head, int nActive, Node*&killed_list, int Time_step);