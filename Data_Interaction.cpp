#include"Data_Interaction.h"


void load_file(castle& C, int &N, float &C1, float &C2, float&C3, Node ** nodes)
{
	ifstream input_file("inputs.txt");
	int Health; int ID;
	input_file >> Health;
	for (int i = 0; i < 4; i++)
		C.towers[i].Health = Health;

	input_file >> N;
	int fire_power;
	input_file >> fire_power;

	for (int i = 0; i < 4; i++)
		C.towers[i].Fire_Power = fire_power;

	input_file >> C1 >> C2 >> C3;
	input_file >> ID;
	while (ID != -1)
	{
		enemy E;
		E.ID = ID;
		int type;
		char region;
		input_file >> type >> E.Time_Arrival >> E.Health >> E.Fire_power >> E.Reload_period >> region;

		if (type == 0)
			E.Type = PVR;
		else if (type == 1)
			E.Type = FITR;
		else
			E.Type = SHLD_FITR;

		E.Region = REGION(region);

		int x;
		if (E.Type == 2)
			x = 0;
		else
			x = 1;

		insert_end(nodes[(E.Region - 65) * 2 + x], E);

		input_file >> ID;
	}
}

void print_region_info(Node *sheild, Node *otherEnemies, Node* killed_list, int n_active, int n_killed, int timestep, int region)
{
	if (region == 'A')
		cout << "\t\t\t\t\tFor time step: " << timestep << endl;

	cout << "\nRegion: " << char(region) << endl;

	cout << "Total number of active enemies = " << n_active << endl;

	Node *temp = NULL;

	if (sheild != NULL)
	{
		temp = sheild;
		while (temp != NULL && temp->E_data.Time_Arrival <= timestep)
		{
			Print_Enemy_info(temp);
			temp = temp->link;
		}
	}

	if (otherEnemies != NULL)
	{
		temp = otherEnemies;
		while (temp != NULL && temp->E_data.Time_Arrival <= timestep)
		{
			Print_Enemy_info(temp);
			temp = temp->link;
		}
	}



	cout << "Total number of killed enemies = " << n_killed << endl;
	while (killed_list != NULL)
	{
		cout << "Time killed: ";
		cout << killed_list->E_data.Time_killed << "\t";

		Print_Enemy_info(killed_list);

		killed_list = killed_list->link;
	}
}

void Print_Enemy_info(Node* temp)
{
	cout << "ID: ";
	cout << temp->E_data.ID << "\t";

	cout << "Type: ";
	switch (temp->E_data.Type)
	{
	case 0:
	{
		cout << "PAVER";
		break;
	}
	case 1:
	{
		cout << "FIIGHTER";
		break;
	}
	case 2:
	{
		cout << "SHIELDED";
		break;
	}
	}
	cout << "\t";

	cout << "Time Arrival: ";
	cout << temp->E_data.Time_Arrival << "\t";

	cout << "Health: ";
	cout << temp->E_data.Health << "\t";

	cout << "Fire Power: ";
	cout << temp->E_data.Fire_power << "\t";

	cout << "Reload Period: ";
	cout << temp->E_data.Reload_period << "\t";

	cout << endl;
}

