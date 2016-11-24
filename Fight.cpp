#include"Fight.h"


void remove_enemy(Node *& head, Node *&pre, Node *&temp, Node*&killed_list)
{
	if (pre == head && temp == head)	// special case : first node
	{
		head = head->link;
		pre = head;
	}

	else                               //  general case
		pre->link = temp->link;

	Node *temp1 = temp;
	temp = temp->link;
	Insert_Sort(killed_list, temp1);
}

bool kill_random_enemy(Node *&head, int nActive, Node*&killed_list, int Time_step)
{
	Node *temp;
	Node *pre;
	bool found = false;
	srand(nActive);
	int location = rand() % (nActive + 1);
	pre = temp = head;

	int i;
	for (i = 0; i < location - 1; i++)
	{
		pre = temp;
		temp = temp->link;
	}
	if (nActive > 0)
	{
		temp->E_data.Time_killed = Time_step;
		remove_enemy(head, pre, temp, killed_list);
		return true;
	}
	return false;

}
