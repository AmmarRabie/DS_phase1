//The four regions: A, B, C , and D
enum  REGION
{
	A_REG = 'A',
	B_REG,
	C_REG,
	D_REG
};

//Enemy types: Paver, Fighter, and Shielded Fighter
enum Etype
{
	PVR,
	FITR,
	SHLD_FITR
};

//constants
#define CmdWidth 150
#define CmdHeight 50
#define CastleWidth 30
#define CastleLength 20
#define CastleXStrt (CmdWidth / 2 - (CastleWidth / 2))
#define CastleYStrt (CmdHeight / 2 - (CastleLength / 2))
#define TowerWidth 7
#define TowerLength 3

#define EnemyShape 219 //ASCII code of enemy char shape

//////////////////////////////////////	Additions	//////////////////////////////////////

#define lists_num 8	