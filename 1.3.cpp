//Name War (1.3)
//by Xraywin
#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>
using namespace std;
int num;
const string atk_skill[]={"普通攻击","暴击","连击"};
const int MaxNum=int(23.3);
struct Player {
	bool flag;
	int HP;
	string s;
}player[MaxNum];
void slowsay(string);
void input();
void game();
void print(int);
bool check(int);
int calc(string,int);
int main() {
	srand(time(0));
	slowsay("游戏名：Name War 版本：1.3 作者：xhw");
	Sleep(500);
	slowsay("请输入您的游玩人数：（不得超过 20 人，且必须大于 1 人）");
	cin>>num;
	while (num>20) {
		slowsay("请重新输入您的游玩人数：（不得超过 20 人，且必须大于 1 人）");
		cin>>num;
	}	
	input();
	game();
	return 0;
}
void slowsay(string s) {
	int len=s.size();
	for (int i=0;i<len;i++) {
		cout<<s[i];
		Sleep(50);
	}
	puts("");
}
void input() {
	for (int i=1;i<=num;i++) {
		cout<<"请输入玩家"<<i<<"的姓名（禁止输入中文字符，长度禁止超过 5 字符）"<<'\n';
		cin>>player[i].s;
		int len=player[i].s.size();
		while (len>5) {
			cout<<"请输入玩家"<<i<<"的姓名（禁止输入中文字符，长度禁止超过 5 字符）"<<'\n';
			cin>>player[i].s;
			len=player[i].s.size();
		}
		player[i].HP=calc(player[i].s,len);
		cout<<player[i].s<<" 的 HP 为 "<<player[i].HP<<'\n';
		Sleep(500);
	}
	Sleep(2000);
}
void game() {
	int sur_num=num,cnt=0;
	for (;num>1;) {
		int atk=1+rand()%num,def=1+rand()%num;
		while (atk==def||(player[atk].flag||player[def].flag)) {
			atk=1+rand()%num;
			def=1+rand()%num;
		}
		int skill=rand()%4;
		if (!skill) {
			cout<<player[atk].s<<" 向 "<< player[def].s<<" 使用了普通攻击"<<'\n';
			int random=rand();
			if (!(random%7))
				cout<<player[def].s<<" 躲避了攻击"<<'\n';
			else {
				int val=rand()%11+10;
				cout<<"造成了 "<<val<<" 点伤害"<<'\n';
				player[def].HP-=val;
				if (check(def))
					print(def);
				else
					cout<<player[def].s<<" 的 HP 现在为 "<<player[def].HP<<'\n';
			}
		}
		else if (skill==1) {
			cout<<player[atk].s<<" 向 "<<player[def].s<<" 使用了暴击"<<'\n';
			int random=rand();
			if (!(random%5))
				cout<<player[def].s<<" 躲避了攻击"<<'\n';
			else {
				int val=rand()%16+25;
				cout<<"造成了 "<<val<<" 点伤害"<<'\n';
				player[def].HP-=val;
				if (check(def))
					print(def);
				else
					cout<<player[def].s<<" 的 HP 现在为 "<<player[def].HP<<'\n';
			}
		}
		else {
			for (int i=1;i<=3;i++) {
				cout<<player[atk].s<<" 向 "<<player[def].s<<" 使用了连击"<<'\n';
				int random=rand();
				if(!(random%3))
					cout<<player[def].s<<" 躲避了攻击"<<'\n';
				else {
					int val=rand()%11+5;
					cout<<"造成了 "<<val<<" 点伤害"<<'\n';
					player[def].HP-=val;
					if (check(def)) {
						print(def);
						break;
					}
				}
			}
			if (player[def].HP>0)
				cout<<player[def].s<<" 的 HP 现在为 "<<player[def].HP<<'\n';
		}
		puts("");
		Sleep(2000);
		for (int i=1;i<=num;++i)
			if (!player[i].flag)
				cnt++;
		if (cnt==1) {
			int ans;
			for (int i=1;i<=num;i++)
				if (!player[i].flag) {
					ans=i;
					break;
				}
			cout<<player[ans].s<<" 获胜！"<<'\n';
			exit(0);
		}
		cnt=0;
	}
}
void print(int def) {
	cout<<player[def].s<<" 被击倒了"<<'\n';
	player[def].flag=true;
}
int calc(string s,int len) {
	if (len==1)
		return (s[0]-48)*1.8;
	int ret=0;
	for (int i=0;i<len;i++)
		ret+=(s[i]-48)/3;
	return ret/len*5-rand()%5;
}
bool check(int def) {
	if (player[def].HP<=0)
		return true;
	return false;
}
