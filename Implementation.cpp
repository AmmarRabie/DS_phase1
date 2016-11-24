#include"Implementation.h"



void insert_end(Node *&E_head, enemy data)
{
	Node* newnode = new Node;
	newnode->link = NULL;
	newnode->E_data = data;
	if (E_head == NULL)
	{
		E_head = newnode;
		return;
	}
	Node* temp = E_head;


	while (temp->link != NULL)
	{
		temp = temp->link;
	}
	temp->link = newnode;
}


void Insert_Sort(Node *&killed_list, Node* killed)
{
	if (killed_list == NULL)		// list is empty
	{
		killed_list = killed;
		killed->link = NULL;
		return;
	}

	if (killed_list->E_data.Health <= killed->E_data.Health)
	{
		killed->link = killed_list;
		killed_list = killed;
		return;
	}
	Node *temp = killed_list;
	Node *pretemp = killed_list;

	while (temp != NULL && temp->E_data.Health >= killed->E_data.Health)
	{
		pretemp = temp;
		temp = temp->link;
	}

	killed->link = temp;
	pretemp->link = killed;

}


void Destroy_List(Node *&List)
{
	Node *temp = List;

	while (List != NULL)
	{
		List = List->link;
		delete temp;
		temp = List;
	}
}