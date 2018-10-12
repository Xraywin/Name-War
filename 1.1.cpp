//Name War (1.1)
//by Xraywin

#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>
using std::string;

int num;

const string atk_skill[] = {"普通攻击", "暴击", "连击"};

const int MaxNum = 15 + 1;

struct Player
{
	bool flag;
	int HP;
	string s;
}player[MaxNum];

void slowsay(string);
void input();
void game();
void print(int);

bool check(int);

int calc(string, int);

int main()
{
	srand(time(0));
	slowsay("游戏名：Name War 版本：1.0 作者：Xraywin");
	Sleep(1000);
	slowsay("请输入您的游玩人数：（不得超过15人）（且必须大于1人）");
	std::cin >> num;
	while(num > 10)
	{
		slowsay("请重新输入您的游玩人数：（不得超过15人）（且必须大于1人）");
		std::cin >> num;
	}
	input();
	game();
	return 0;
}

void slowsay(string s)
{
	int len = s.size();
	for(int i = 0; i < len; i ++)
	{
		std::cout << s[i];
		Sleep(80);
	}
	std::cout << std::endl;
}

void input()
{
	for(int i = 1; i <= num; i ++)
	{
		std::cout << "请输入玩家" << i << "的姓名（禁止输入中文字符）（长度禁止超过5字符）" << std::endl;
		std::cin >> player[i].s;
		int len = player[i].s.size();
		while(len > 5)
		{
			std::cout << "请输入玩家" << i << "的姓名（禁止输入中文字符）（长度禁止超过5字符）" << std::endl;
			std::cin >> player[i].s;
			len = player[i].s.size();
		}
		player[i].HP = calc(player[i].s, len);
		std::cout << player[i].s << "的HP为" << player[i].HP << std::endl;
		Sleep(500);
	}
	Sleep(2000);
}

void game()
{
	int sur_num = num;
	int cnt = 0;
	for( ; num > 1; )
	{
		int atk = 1 + rand() % num, def = 1 + rand() % num;
		while(atk == def || (player[atk].flag || player[def].flag))
			atk = 1 + rand() % num, def = 1 + rand() % num;
		int skill = rand() % 4;
		if(skill == 0)
		{
			std::cout << player[atk].s << "向" << player[def].s << "使用了普通攻击" << std::endl;
			int random = rand();
			if(random % 7 == 0)
				std::cout << player[def].s << "躲避了攻击" << std::endl;
			else
			{
				std::cout << "造成了15点伤害" << std::endl;	
				player[def].HP -= 15;
			}
			if(check(def))
				print(def); 
		}
		else if(skill == 1)
		{
			std::cout << player[atk].s << "向" << player[def].s << "使用了暴击" << std::endl;
			int random = rand();
			if(random % 11 == 0)
				std::cout << player[def].s << "躲避了攻击" << std::endl;
			else
			{
				std::cout << "造成了30点伤害" << std::endl;
				player[def].HP -= 30;
			}
			if(check(def))
				print(def);
		}
		else
		{
			for(int i = 1; i <= 3; i ++)
			{
				std::cout << player[atk].s << "向" << player[def].s << "使用了连击" << std::endl;
				int random = rand();
				if(random % 3 == 0)
					std::cout << player[def].s << "躲避了攻击" << std::endl;
				else
				{
					std::cout << "造成了10点伤害" << std::endl;
					player[def].HP -= 10;
					if(check(def))
					{
						print(def);
						break;
					}
				}
			}
		}
		std::cout << std::endl;
		Sleep(5000);
		for(int i = 1; i <= num; i ++)
			if(!player[i].flag) cnt ++;
		if(cnt == 1)
		{
			int ans;
			for(int i = 1; i <= num; i ++)
				if(!player[i].flag)
				{
					ans = i;
					break;
				}
			std::cout << player[ans].s << "获胜！" << std::endl;
			return;
		}
		cnt = 0;
	}
}

void print(int def)
{
	std::cout << player[def].s << "被击倒了" << std::endl;
	player[def].flag = true;
}

int calc(string s, int len)
{
	int ans = 0;
	for(int i = 0; i < len; i ++)
		ans += (s[i] - '0') / 3;
	return ans;
}

bool check(int def)
{
	if(player[def].HP < 0) return true;
	return false;
}
