// TextRPG.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <format>
using namespace std;

enum PlayerType
{
	PT_None = 0,
	PT_Knite = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_None = 0,
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

string line = "------------------------";

PlayerType playerType;
StatInfo playerStat;

MonsterType monsterType;
StatInfo monsterStat;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRendomMonster();
void EnterBattle();
void WaitForNextKey();

int main()
{
	EnterLobby();
}

void EnterLobby()
{
	while (true)
	{
		cout << line << endl;
		cout << "로비에 들어왔습니다!" << endl;
		cout << line << endl;

		SelectPlayer();

		cout << line << endl;
		cout << "1) 필드 입장 2) 게임 종료" << endl;
		cout << line << endl;

		int select;
		cin >> select;

		if (select == 1) {
			EnterField();
		}
		else {
			return;
		}
	}
}

void SelectPlayer()
{
	// 직업이랑 상관없는 수를 골랐을때 반복하기 위함
	while (true)
	{
		cout << line << endl;
		cout << "직업을 골라주세요" << endl;
		cout << "1) 기사 2) 궁수 3) 법사" << endl;
		cout << "> ";

		int choice;
		cin >> choice;

		switch (choice)
		{
			case PT_None:
				cout << "Please Select Exist Character." << endl;
				break;
			case PT_Knite:
				cout << "기사 생성중..." << endl;
				playerStat.hp = 150;
				playerStat.attack = 10;
				playerStat.defence = 5;
				playerType = PT_Knite;
				return;
			case PT_Archer:
				cout << "궁수 생성중..." << endl;
				playerStat.hp = 100;
				playerStat.attack = 15;
				playerStat.defence = 3;
				playerType = PT_Archer;
				return;
			case PT_Mage:
				cout << "법사 생성중..." << endl;
				playerStat.hp = 80;
				playerStat.attack = 25;
				playerStat.defence = 0;
				playerType = PT_Mage;
				return;
		}
	}
}

void EnterField()
{
	while (true)
	{
		cout << line << endl;
		cout << "필드에 입장했습니다!" << endl;
		cout << line << endl;

		cout << "[PLAYER] HP : " << playerStat.hp << " / ATT : " << playerStat.attack << " / DEF : " << playerStat.defence << endl;

		CreateRendomMonster();

		cout << line << endl;
		cout << "1) 전투 2) 도주" << endl;
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1) 
		{
			EnterBattle();

			if(playerStat.hp == 0)
				return;
		}
		else
		{
			return;
		}
	}
}

void CreateRendomMonster()
{
	int randomChoice = 1 + (rand() % 3);

	switch (randomChoice)
	{
		case MT_Slime:
			monsterStat.hp = 30;
			monsterStat.attack = 2;
			monsterStat.defence = 0;
			monsterType = MT_Slime;
			cout << "슬라임 생성중...! (HP:" << monsterStat.hp << " / ATT:" << monsterStat.attack << " / DEF:" << monsterStat.defence << ")" << endl;
			break;
		case MT_Orc:
			monsterStat.hp = 40;
			monsterStat.attack = 10;
			monsterStat.defence = 3;
			monsterType = MT_Orc;
			cout << "오크 생성중...! (HP:" << monsterStat.hp << " / ATT:" << monsterStat.attack << " / DEF:" << monsterStat.defence << ")" << endl;
			break;
		case MT_Skeleton:
			monsterStat.hp = 80;
			monsterStat.attack = 15;
			monsterStat.defence = 5;
			monsterType = MT_Skeleton;
			cout << "해골 생성중...! (HP:" << monsterStat.hp << " / ATT:" << monsterStat.attack << " / DEF:" << monsterStat.defence << ")" << endl;
			break;
	}
}

void EnterBattle()
{
	while (true)
	{
		// 플레이어 선공
		int damage = playerStat.attack - monsterStat.defence;
		if (damage < 0)
		{
			damage = 0;
		}

		monsterStat.hp -= damage;
		if (monsterStat.hp < 0)
		{
			monsterStat.hp = 0;
		}

		cout << "몬스터 남은 체력 : " << monsterStat.hp << endl;

		// 후공
		damage = monsterStat.attack - playerStat.defence;
		if (damage < 0)
		{
			damage = 0;
		}

		playerStat.hp -= damage;
		if (playerStat.hp < 0)
		{
			playerStat.hp = 0;
		}

		cout << "플레이어 남은 체력 : " << playerStat.hp << endl;

		if (playerStat.hp == 0)
		{
			cout << "당신은 사망했습니다... GAME OVER" << endl;
			WaitForNextKey();
			return;
		}
	}
}

void WaitForNextKey()
{
	cout << "계속하려면 1을 눌러주세요" << endl;
	cout << "> ";

	int input;
	cin >> input;

	system("cls");
}
