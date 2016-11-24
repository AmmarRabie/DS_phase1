#include"Fight.h"
#include<fstream>
using namespace std;

void  simulate_Time(Node**Enemy_lists, ofstream &output_file, int Time_step);




int main()
{
	Node *enemy_lists[lists_num] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

	castle ct; // define a castle 
	ct.Xstrt = CastleXStrt;
	ct.Ystrt = CastleYStrt;
	ct.W = CastleWidth;
	ct.L = CastleLength;

	int N, time_simulation = 1;
	float c1, c2, c3;
	ofstream outPUT("results.txt", ios::out);

	load_file(ct, N, c1, c2, c3, enemy_lists);


	for (int i = 0; i < 5; i++, time_simulation++)
	{
		simulate_Time(enemy_lists, outPUT, time_simulation);
		//Sleep(1000);
		//getchar();
		cout << endl << endl;
	}

	return 0;
}


void  simulate_Time(Node**Enemy_lists, ofstream &output_file, int Time_step)
{
	int num_active_enemies;
	int num_killed_enemies;
	int num_active_shielded_enemies;
	Node * killed_list = NULL;

	int n_others_killed = 0;
	int n_shielded_killed = 0;
	for (int i = 0; i < lists_num; i++)
	{
		if (i % 2 == 0)
		{
			killed_list = NULL;
			num_active_enemies = 0;
			num_killed_enemies = 0;
			num_active_shielded_enemies = 0;

		}
		Node *Temp = Enemy_lists[i];
		Node *pre = Enemy_lists[i];

		while (Temp != NULL)
		{
			if (Temp->E_data.Health <= 0)
			{
				Temp->E_data.Time_killed = Time_step;
				remove_enemy(Enemy_lists[i], Temp, pre, killed_list);
				num_killed_enemies++;
			}
			else
			{
				if (Time_step == Temp->E_data.Time_Arrival)
				{
					Temp->E_data.Distance = 60;
					num_active_enemies++;

					if (i % 2 == 0)
						num_active_shielded_enemies++;
				}

				if (Time_step > Temp->E_data.Time_Arrival)
				{
					num_active_enemies++;
					if (i % 2 == 0)
						num_active_shielded_enemies++;
					Temp->E_data.Distance--;
				}

				pre = Temp;
				Temp = Temp->link;
			}

		}
		if (i % 2 == 0 && n_shielded_killed < 2 && Time_step != 1)
		{
			if (kill_random_enemy(Enemy_lists[i], num_active_shielded_enemies, killed_list, Time_step))
			{
				n_shielded_killed++;
				num_killed_enemies++;
				num_active_enemies--;
				num_active_shielded_enemies--;
			}
		}
		if (i % 2 == 1 && n_others_killed < 2 && Time_step != 1)
		{
			if (kill_random_enemy(Enemy_lists[i], num_active_enemies - num_active_shielded_enemies, killed_list, Time_step))
			{
				n_others_killed++;
				num_killed_enemies++;
				num_active_enemies--;
			}
		}
		if (i % 2 == 1)
		{
			int R = (i - i % 2) / 2 + 65;
			print_region_info(Enemy_lists[i - 1], Enemy_lists[i], killed_list, num_active_enemies, num_killed_enemies, Time_step, R);
			Destroy_List(killed_list);
		}

	}
}
