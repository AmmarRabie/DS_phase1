#include"Constants.h"






//Tower
struct Tower
{
	int TW; //Tower width
	int TL; //Tower Height
	int Health;

	// Additions:
	int Fire_Power;
};

struct castle
{
	//starting x,y
	int Xstrt;
	int Ystrt;
	int W;	   //width
	int L;	   //Height
	Tower towers[4]; //Castle has 4 towers
};

struct enemy
{

	int ID;	//Each enemy has a unique ID (sequence number)
	REGION Region; //Region of this enemy
	int Distance;  //Distance to the castle
	float Health;  //Enemy health
	Etype Type;    //PVR, FITR, SHLD_FITR

	// Additions:
	int Time_Arrival; // Enemy arrival time
	int Fire_power;
	int Reload_period;
	// int Reload_period_static; //k to be const to compere with the daynamic reload period
	int Time_killed;	  //time which killed
	int Time_Frist_shot;      //frist time to go in high piriorty array

	int Time_attack;	// time to attack castle after reload period
	/*
	int Fight_delay;	// FD = T_firstShot - T_arrival
	int Killed_delay;	// KD = T_killed - T_firstshot
	int Fight_time;		// FT = FD + KD
	*/
};



struct Node
{
	enemy E_data;
	Node *link;
};