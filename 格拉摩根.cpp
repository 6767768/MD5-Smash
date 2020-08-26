#include<iostream>
#include<cstring>
#include<Windows.h>
#include<cmath>
#include<stdlib.h>
#include<ctime>
#include<fstream>
#include<string>
#include<stdio.h>
#include "mmsystem.h"
#pragma comment(lib,"winmm.lib")
#include <Mmsystem.h>


using namespace std;

static char mainfile[100] = "main.txt";
static char peom[100] = "peom.txt";
static char win[100] = "win.txt";
static char title[100] = "title.txt";
static char read[100] = "read.txt";
static char pathsound[100] = "Andreas Waldetoft - Main Theme (Guns, Drums and S.mp3";
static char path[100] = "test.txt";

string UTF8ToGB(const char* str)
{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;

	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}
void Color()
{
	int rd = rand() % 8;
	switch (rd)
	{
	case 0:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		break;
	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//设置红色
		break;
	case 2:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//设置绿色
		break;
	case 3:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);//设置蓝色
		break;
	case 4:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);//设置红色和绿色相加
		break;
	case 5:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);//设置红色和蓝色相加
		break;
	case 6:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//设置绿色和蓝色相加
		break;
	case 7:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);//设置颜色，没有添加颜色，故为原色
		break;
	}
}
void print(int n, char *a)
{
	ifstream in;
	if (!in)
	{
		cout << "文件打开失败" << endl;
		exit(1);
	}
	in.open(a);
	string str;
	for (int i = 0; i < n; i++)
	{
		in >> str;
		str.clear();
	}
	in >> str;
	str = UTF8ToGB(str.c_str()).c_str();
	Color();
	cout << str << endl;
	Sleep(40);
	str.clear();
	in.close();
}
void Slowprint(int n, char *a)
{
	ifstream in;
	if (!in)
	{
		cout << "文件打开失败" << endl;
		exit(1);
	}
	in.open(a);
	string str;
	for (int i = 0; i < n; i++)
	{
		in >> str;
		str.clear();
	}
	in >> str;
	str = UTF8ToGB(str.c_str()).c_str();
	Color();
	for (int i = 0; i < str.length(); i++)
	{
		Sleep(40);
		cout << str[i];
	}
	cout << endl;
	Sleep(40);
	str.clear();
	in.close();
}
void print(int n, int m, char *a)
{
	for (int i = n; i <= m; i++)
	{
		Slowprint(i, a);
	}
}




struct Nation
{
	//政府
	int money;
	int army;
	int citizen;
};

class crusder
{
private:
	//个人
	int HP;//血量
	int DA;//攻击
	int DEF;//防御
	int LUC;
	//等级
	char name[100];
	char crown[100];

	//政府
	Nation nation;
	//外交
	int prestige;
public:
	crusder() {}
	crusder(int HP, int DA, int DEF, int LUC, char *name, char *crown, int money, int army, int citizen, int prestige);
	~crusder() {}

	void setIndi(int HP, int DA, int DEF, int LUC);
	void setPlace(char *name, char *crown);
	void setGov(int money, int army, int citizen);
	void setDip(int prestige);
	void Hit(crusder &knight);
	void Horse(crusder &knight);
	void Toxic(crusder &knight);
	void Show();
	void claim(crusder &knight);
	void declarewar(crusder &x);
	int campaign(crusder &x);
	void peace(int ptr, crusder &x);
	void ally();
	void rebel();
	void fullIndi();
	void Recover();
	void setCiti(int citizen);
	void setArmy(int army);
	void setprestige(int prestige);
	void setHP(int HP);
	void setDEF(int DEF);
	void setLUC(int LUC);
	void setMoney(int money);
	void setDA(int DA);
	void addMoney(int money);
	void addArmy(int army);
	void addCitizen(int citizen);
	void addPrestige(int prestige);
	void addHP(int HP);
	void win();
	void savegame(); 
	////////////////////////////////////////////////////指示函数
	int checkHP()
	{
		return HP;
	}
	char *checkStatus()
	{
		return crown;
	}
	int checkarmy()
	{
		return nation.army;
	}
	int checkmoney()
	{
		return nation.money;
	}
	char *ShowName()
	{
		return name;
	}
	//////////////////////////////////////////////////////////
};
///////////////////////////////////////////////////初始化和参数设置
crusder::crusder(int HP, int DA, int DEF, int LUC, char *name, char *crown, int money, int army, int citizen, int prestige)
{
	setIndi(HP, DA, DEF, LUC);
	setPlace(name, crown);
	setGov(money, army, citizen);
	setDip(prestige);
}
void crusder::savegame()
{
	ofstream out;
	out.open("memory.txt",ios::out|ios::app);
	if (strcmp(crown,"公爵")==0)
	{
		strcpy(crown,"dutch"); 
	}
	else if (strcmp(crown,"国王")==0)
	{
		strcpy(crown,"king"); 
	}
	else if (strcmp(crown,"皇帝")==0)
	{
		strcpy(crown,"emperor"); 
	}
	out<<HP<<" "<<DA<<" "<<DEF<<" "<<LUC<<" "<<name<<" "<<crown<<" "<<nation.money<<" "<<nation.army<<" "<<nation.citizen<<" "<<prestige<<endl;
	out.close();
}

void crusder::setDip(int prestige)
{
	this->prestige = prestige;
}
void crusder::setGov(int money, int army, int citizen)
{
	this->nation.money = money;
	this->nation.citizen = citizen;
	this->nation.army = army;
}
void crusder::setIndi(int HP, int DA, int DEF, int LUC)
{
	this->LUC = LUC;
	this->DA = DA;
	this->HP = HP;
	this->DEF = DEF;
}
void crusder::setPlace(char *name, char *crown)
{
	strcpy(this->name, name);
	strcpy(this->crown, crown);
}
void crusder::setCiti(int citizen)
{
	this->nation.citizen = citizen;
}
void crusder::setprestige(int prestige)
{
	this->prestige = prestige;
}
void crusder::setArmy(int Army)
{
	this->nation.army = Army;
}
void crusder::setMoney(int Money)
{
	this->nation.money = Money;
}
void crusder::setDEF(int DEF)
{
	this->DEF = DEF;
}
void crusder::setDA(int DA)
{
	this->DA = DA;
}
void crusder::setHP(int HP)
{
	this->HP = HP;
}
void crusder::setLUC(int LUC)
{
	this->LUC = LUC;
}
void crusder::addMoney(int money)
{
	this->nation.money = this->nation.money + money;
}
void crusder::addArmy(int army)
{
	this->nation.army = this->nation.army + army;
}
void crusder::addPrestige(int prestige)
{
	this->prestige = this->prestige + prestige;
}
void crusder::addCitizen(int citizen)
{
	this->nation.citizen = this->nation.citizen + citizen;
}
void crusder::addHP(int HP)
{
	this->HP = this->HP + HP;
}

//////////////////////////////////////////国家行动
void crusder::peace(int ptr, crusder &x)
{
	cout << "呼吁和平!" << endl;
	if (ptr==0)//0获胜
	{
		if (strcmp(crown, "公爵") == 0)
		{
			strcpy(crown, "国王");
			cout << "由于战争的胜利，你的公国变成了一个王国，越来越多的贵族开始对你刮目相看" << endl;
		}
		else if (strcmp(crown, "国王") == 0)
		{
			strcpy(crown, "皇帝");
			cout << "由于战争的胜利，你的王国变成了一个帝国，贵族们越来越敬畏你了" << endl;
		}
		else if (strcmp(crown, "皇帝") == 0)
		{
			strcpy(crown, "奥古斯都");
			cout <<this->name<< "成功的复兴了罗马帝国，现在任何你的臣民都能够想但丁的史诗中那样没有阻碍地从尼科米底亚到迦太基再到君士坦丁堡周游帝国了" << endl;
			cout << "你的功绩无人能敌!" << endl;
		}
	}
	else 
	{
		cout << "我们战败了，越来越多的贵族开始嘲笑我们了，甚至就连街上的乞丐都在嘲笑" << this->name << endl;
		cout << "声望降低5" << endl;
		this->prestige = this->prestige - 5;
	}
}
void crusder::rebel()
{
	Sleep(1000);
	cout << "一场新的起义，" << endl;
	Sleep(1000);
	cout << "由于我们的战败，林登万出现了" << endl;
	Sleep(1000);
	cout << this->name << "：让我们碾碎他们" << endl;
	Sleep(500);
	int temp = rand() % (this->nation.citizen / 10);
	cout << "叛军的人数有" << temp << endl;
	if (temp > this->nation.army)
	{
		HP = 0;
	}
	else
	{
		nation.army = nation.army - temp / 2;
		Sleep(1000);
		cout << "清剿叛军，我们的军队伤亡惨重，人数减少" << temp << endl;
	}
	this->nation.citizen = this->nation.citizen - temp;
}
void crusder::ally()
{
	int x = rand() % 100;
	nation.army = nation.army + x;
}
void crusder::declarewar(crusder &x)
{
	Sleep(1000);
	cout << "新的战争!" << endl;
	Sleep(1000);
	char xxx[100] = "我们向愚蠢的野蛮人发去了措辞高雅的宣战请求，但他们好像不太高兴";
	Sleep(1000);
	char xxxx[100] = "的恶名从爱尔兰到契丹无人不知无人不晓，越来越多的人卷入了这场战争";
	Sleep(1000);

	for (int i = 0; xxx[i] != '\0'; i++)
	{
		Sleep(40);
		cout << xxx[i];
	}
	cout << endl;

	if (this->prestige > x.prestige)
	{
		Sleep(1000);
		cout << x.name;
		for (int i = 0; xxxx[i] != '\0'; i++)
		{
			Sleep(40);
			cout << xxxx[i];
		}
		this->ally();
	}
	else
	{
		Sleep(1000);
		cout << this->name;
		for (int i = 0; xxxx[i] != '\0'; i++)
		{
			Sleep(40);
			cout << xxxx[i];
		}
		x.ally();
	}

}
int crusder::campaign(crusder &x)
{
	char lost[100] = "一场失败的战役，我们将领的脑袋碎成了两半，他的尸体被废弃在战场旁的水沟里面，我军损失了";
	char won[100] = "一场胜利的战役，敌人将领的脑袋碎成了两半，他的尸体被废弃在战场旁的水沟里面，我军损失了";
	char peo[100] = "黑云压城城欲摧，甲光向日金鳞开";
	char peo1[100] = "角声满天秋色里，塞上燕脂凝夜紫";
	char peo2[200] = "战士们一个个冲上去, 挥舞着大刀浴血奋战, 一个倒下了, 另一个就替上去, 一个战士浑身划得稀烂, 在倒下去的一刻, 还高喊口号, 悲壮极了!";
	char peo3[200] = "血红的晚霞在渐渐消退, 双方就这样死死对峙着, 既没有任何一方撤退, 也没有任何一方冲杀, 谷地主战场上的累累尸体和丢弃的战车辎重也没有任何一方争夺.就象两只猛虎的凝视对峙, 谁也不能先行脱离战场.";
	int rd = rand() % 3;

	if (this->nation.army > x.nation.army)
	{
		cout << "新的战役!" << endl;
		Sleep(500);
		cout << "我军占据人数优势" << endl;
		cout << endl;
		Sleep(500);
		for (int i = 0; peo[i] != '\0'; i++)
		{
			Sleep(30);
			cout << peo[i];
		}
		cout << endl;
		for (int i = 0; peo1[i] != '\0'; i++)
		{
			Sleep(30);
			cout << peo1[i];
		}
		cout << endl;
		int temp0 = rand() % (this->nation.army / 10);
		int temp = rand() % (x.nation.army / 10);
		x.nation.army = x.nation.army - temp0;
		this->nation.army = this->nation.army - temp;
		for (int i = 0; won[i] != '\0'; i++)
		{
			Sleep(40);
			cout << won[i];
		}
		cout << temp;
		cout << endl;
		return 1;
	}
	else
	{
		cout << "新的战役!" << endl;
		Sleep(500);
		cout << "敌人占据人数优势" << endl;
		cout << endl;
		for (int i = 0; peo2[i] != '\0'; i++)
		{
			Sleep(30);
			cout << peo2[i];
		}
		cout << endl;
		for (int i = 0; peo3[i] != '\0'; i++)
		{
			Sleep(30);
			cout << peo3[i];
		}
		cout << endl;
		int temp0 = rand() % (x.nation.army / 10);
		int temp = rand() % (this->nation.army / 10);
		this->nation.army = this->nation.army - temp0;
		x.nation.army = x.nation.army - temp;
		for (int i = 0; lost[i] != '\0'; i++)
		{
			Sleep(40);
			cout << lost[i];
		}
		cout << temp0;
		cout << endl;
		return 0;
	}
}

//////////////////////////////////////////////
void crusder::Recover()
{
	this->nation.army = this->nation.army + this->nation.money / 100;
	this->nation.citizen +=20;
	this->nation.money +=(this->nation.citizen / 10);
	this->prestige +=2;
	this->LUC +=10;
	this->DEF +=10;
	this->DA +=10;
	this->HP +=10;
}
//////////////////////////////////////////////////////

void crusder::Show()
{
	cout << "英雄：" << name << endl;
	cout << "所处位置：" << crown << endl;
	cout << "生命值：" << HP << "   攻击力：" << DA << "   防御力：" << DEF << endl;
	cout << "军队：" << nation.army << "   人力：" << nation.citizen << "   金钱：" << nation.money << endl;
	cout << "外交声誉" << prestige << endl;
}

//////////////////////////////////////////////////////////////决斗
void crusder::Hit(crusder &knight)//步战
{
	print(0, 0, mainfile);
	srand(time(NULL));
	int rd = rand() % 4;
	int harm = rand() % 20 + 10;
	if (rd == 0)//砍人
	{
		cout<<endl;
		cout<<"新的战斗！"<<endl;
		cout << this->name << "拔剑砍了" << knight.name << "一剑";
		cout<<endl;
		if (this->LUC > knight.LUC)
		{
			srand(time(NULL));
			int s = rand() % 2;
			if (s == 0)
			{
				cout << "由于" << knight.name << "摔倒了，" << this->name << "赶去补刀，造成了" << 2 * harm << "点伤害" << endl;
				cout<<endl;
				knight.HP = knight.HP - harm;
			}
			else if (s == 1)
			{
				cout << "造成了" << harm << "点伤害" << endl;
				cout<<endl;
				knight.HP = knight.HP - harm;

			}
		}
		else
		{
			int s = rand() % 3;
			if (s == 0)
			{
				cout << this->name << "被绊倒了，由此被" << knight.name << "补刀，" << this->name << "受到" << harm << "点伤害" << endl;
				cout<<endl;
				this->HP = this->HP - 2 * harm;
			}
			else if (s == 1)
			{
				this->HP = this->HP - 2 * harm;
				cout << "你的武艺不如对方，被对方打的毫无还手之力，受到了" << 2 * harm << "点伤害" << endl;
				cout<<endl;
				
			}
			else if (s == 2)
			{
				this->HP = this->HP - 3 * harm;
				cout << "你的武艺不仅不如对方，还被对手暗算了，受到了" << 3 * harm << "重创" << endl;
				cout<<endl;
			}
		}
	}
	else if (rd == 1)//堂吉诃德
	{
		cout<<endl;
		cout<<"新的战斗！"<<endl;
		cout<<this->name<<"决定以自己崇高的声望先嘲讽对方"<<endl;
		cout<<endl;
		print(9, 9, mainfile);
		if (this->prestige > knight.prestige)
		{
			cout << this->name << "防御力下降5点" << endl;
			cout<<endl;
			this->DEF = this->DEF - 5;
		}
		else
		{
			cout << knight.name << "防御力下降5点" << endl;
			cout<<endl;
			knight.DEF = knight.DEF - 5;
		}
	}
	else if (rd == 2)//扔石头
	{
		cout<<endl;
		cout<<"新的战斗！"<<endl;
		cout<<this->name<<"向对手扔了一块大石头"<<endl;
		cout<<endl;
		print(10, 10, mainfile);
		if (this->DA > knight.DA)
		{
			cout << this->name << "扔出去的石头弹了回来，自己被石头重重的击中了" << endl;
			cout << "生命值下降5点" << endl;
			cout<<endl;
			this->HP = this->HP - 5;
		}
		else
		{
			cout << knight.name << "被石头重重的击中了" << endl;
			cout << "生命值下降5点" << endl;
			cout<<endl;
			knight.HP = knight.HP - 5;
		}
	}
	else if (rd == 3)//带着盾牌撞人
	{
		cout<<endl;
		cout<<"新的战斗！"<<endl;
		cout << this->name;
		print(8, 8, mainfile);
		if (this->DEF > knight.DEF)
		{
			cout << this->name << "使用盾牌撞倒了对方" << endl;
			cout << "对方受到6点伤害" << endl;
			cout<<endl;
			knight.HP = knight.HP - 6;
		}
		else
		{
			cout << this->name << "被对方使用盾牌撞倒了" << endl;
			cout << this->name << "受到5点伤害" << endl;
			cout<<endl;
			this->HP = this->HP - 5;
		}
	}

}
void crusder::Horse(crusder &knight)//骑马
{
	cout<<endl;
	cout<<"新的战斗！"<<endl;
	cout<<this->name<<"决定与对手骑马决斗"<<endl;
	cout<<endl;
	print(1, 1, mainfile);
	srand(time(NULL));
	int rd = rand() % 2;
	if (rd == 0)//拿长枪刺过去
	{
		cout << this->name;
		print(5, 5, mainfile);
		if (this->DA > knight.DA)
		{
			cout << this->name;
			print(7,7, mainfile);
			knight.HP = knight.HP - 10;
			cout << knight.name << "受伤，减少10生命值" << endl;
			cout<<endl;
		}
		else
		{
			print(6, 6, mainfile);
			cout << this->name << "受伤，减少10生命值" << endl;
			cout<<endl;
			this->HP = this->HP - 10;
		}
	}
	else if (rd == 1)//盾牌撞过去
	{
		cout<<endl;
		cout<<"新的战斗！"<<endl;
		cout << this->name;
		print(8,8, mainfile);
		if (this->DEF > knight.DEF)
		{
			cout<<endl;
			cout << this->name << "使用盾牌撞倒了" << knight.name << endl;
			cout << "对方受到5点伤害" << endl;
			cout<<endl;
			knight.HP = knight.HP - 5;
		}
		else
		{
			cout<<endl;
			cout << this->name << "被对方使用盾牌撞倒了" << endl;
			cout << this->name << "受到5点伤害" << endl;
			cout<<endl;
			this->HP = this->HP - 5;
		}
	}
}
void crusder::Toxic(crusder &knight)
{
	cout<<endl;
	cout<<this->name<<"进行了投毒活动"<<endl; 
	cout<<endl;
	print(4, 4, mainfile);
	cout<<endl;
	srand(time(NULL));
	int rd = rand() % 2;
	if (rd == 0)//投毒成功
	{
		cout << "由于对方长期服用某种具有毒性的药物，因此已对毒药产生了抗体，你的对手并没有被毒死" << endl;
		cout<<endl;
		if (knight.LUC >= 98)//没死
		{

		}
		else//毒死了
		{
			cout << "你的对手被你暗算了，他在吃完下了毒的晚餐之后就一命呜呼了" << endl;
			cout<<endl;
			knight.HP = 0;
		}
	}
	else if (rd == 1)//被发现逃脱
	{
		
		if (this->LUC > 60)//逃脱
		{
			cout << "尽管投毒的时候被发现了，但是并没有被卫兵抓住，你侥幸逃过一劫" << endl;
			cout << "你的声望大幅下降15" << endl;
			cout<<endl;
			this->prestige = this->prestige - 15;
		}
		else
		{
			cout << "你在投毒的时候被人发现了，并且很不幸的被卫兵抓住了，" << this->name << "被绞死在城堡的外墙内" << endl;
			cout<<endl;
			this->HP = 0;
		}
	}

}
void crusder::claim(crusder &knight)
{
	cout<<endl;
	print(2, 3, mainfile);
	srand(time(NULL));
	int rd = rand() % 2;
	if (rd == 0)
	{
		cout << knight.name << "大喝一声：我来杀你" << endl;
		this->HP = 0;
	}
	else if (rd == 1)
	{
		cout << "无人前来，威望增加5" << endl;
		cout<<endl;
		this->prestige = this->prestige + 5;
	}
}
void crusder::win()
{
		if (strcmp(crown, "公爵") == 0)
		{
			strcpy(crown, "国王");
			cout << "由于你打败了异教徒，教皇决定加冕你为格拉摩根国王，" << this->name << "的地位大大提高了" << endl;
		}
		else if (strcmp(crown, "国王") == 0)
		{
			strcpy(crown, "皇帝");
			cout << "由于你赢得了比赛的胜利，你的威名远播，现在" << this->name << "的家族已成为最显赫的家族之一了" << endl;
		}
		else if (strcmp(crown, "皇帝") == 0)
		{
			strcpy(crown, "奥古斯都");
			cout << this->name << "复兴了罗马帝国，现在任何你的臣民都能够想但丁的史诗中那样没有阻碍地从尼科米底亚到迦太基再到君士坦丁堡周游帝国了" << endl;
			cout << "你的功绩无人能敌!" << endl;
		}
	}
void crusder::fullIndi()
{
	cout << this->name;
	print(11, mainfile);
	if (this->LUC = 100)
	{
		cout << this->name << "生命值全满" << endl;
		this->setHP(100);
	}
}
///////////////////////////////////////////////////////////

class Event
{
public:
	void Comet(crusder &x);
	void Successor(crusder &x);
	void Tea(crusder &x);
	void starve(crusder &x);
	void colony(crusder &x);
	void Gold(crusder &x);
	void Spring(crusder &x);
	void Canal(crusder &x);
	void Prestiage(crusder &x);
	void humanity(crusder &x);
	void painting(crusder &x);
	void competitation(crusder &x);
	void pirate(crusder &x);
};//事件类
void Event::pirate(crusder &x)
{
	x.addPrestige(-1);
	print(9, 11,path);
}
void Event::competitation(crusder &x)
{
	x.addPrestige(1);
	print(27, 29,path);
}
void Event::painting(crusder &x)
{
	x.addPrestige(5);
	print(24, 26,path);
}
void Event::humanity(crusder &x)
{
	x.addPrestige(20);
	print(21, 23,path);
}
void Event::Prestiage(crusder &x)
{
	x.addPrestige(10);
	print(18, 20,path);
}
void Event::Canal(crusder &x)
{
	x.addPrestige(-20);
	print(15, 17,path);
}
void Event::Spring(crusder &x)
{
	x.addMoney(-100);
	print(12, 14,path);
}
void Event::Gold(crusder &x)
{
	x.addMoney(100);
	print(8, 10,path);
}
void Event::colony(crusder &x)
{
	print(4, 5,path);
	x.addMoney(-100);
}
void Event::Tea(crusder &x)
{
	print(2, 3,path);
	x.addMoney(-100);
}
void Event::starve(crusder &x)
{
	print(0,1,path);
	x.setCiti(-100);
}
void Event::Successor(crusder &x)
{
	print(6,8,path);
	
}
void Event::Comet(crusder &x)
{
	char s[200] = "夜空中神秘现象一直被认为是世界末日的凶兆，一个像巨大的彗星这样格外显眼的现象近期被人们所目击造成了不小的混乱";
	x.addCitizen(100);
	for (int i = 0; s[i] != '\0'; i++)
	{
		Sleep(40);
		cout << s[i];
	}
	cin.get();
	cout << "我希望生活在一个开明的时代" << endl;
	cout << "人力加100" << endl;
}


void death(crusder &x)
{
	cout << endl;
	cout << endl;
	cout << x.ShowName() << "被杀了" << endl;
	cout << endl;
	x.Show();
	print(0, 50, peom);
	exit(1);
}
void emperor(crusder &x)
{
	cout << x.ShowName() << "加冕成为伟大的奥古斯都" << endl;
	x.Show();
	print(0, 50, win);
	exit(1);
}
void check(crusder &x)
{
	if (x.checkHP() <= 0)
	{
		death(x);
	}
	else if (x.checkHP() > 0 && strcmp(x.checkStatus(), "奥古斯都") == 0)
	{
		emperor(x);
	}
}
void choice(crusder &x, crusder &y)
{
	int i = 1;
	cout << "请输入你的选择 1. 向其它国家宣战  2.寻找对手决斗 3.休养生息 4.保存并退出游戏" << endl;
	cin >> i;
	if (i == 1)//宣战
	{
		x.declarewar(y);
		cout << endl;
		int num = 0;
		for (int t = 0; t < 2; t++)
		{
			Sleep(40);
			int temp;
			temp = x.campaign(y);
			if (temp == 1)
			{
				num++;
			}
			if (x.checkarmy() <= 0)
			{
				death(x);
			}
			else if (y.checkarmy() <= 0)
			{
				x.peace(1, y);
			}
		}
		if (num >= 2)
		{
			x.peace(0, y);
			check(x);
		}
		else
		{
			x.peace(1, y);
			check(x);
			x.rebel();
			check(x);
		}
	}
	else if (i == 2)
	{
		for (int j = 0; j < 3; j++)
		{
			srand(time(0));
			int rd = rand() % 4;
			if (rd == 0)
			{
				x.Hit(y);
				check(x);
				if (y.checkHP() <= 0)
				{
					x.win();
					check(x);
					break;
				}
				cout << "比赛难分胜负，最终" << x.ShowName() << "和" << y.ShowName() << "缔结了和平条约" << endl;
			}
			else if (rd == 1)
			{
				x.claim(y);
				check(x);
			}
			else if (rd == 2)
			{
				x.Toxic(y);
				check(x);
				if (y.checkHP() <= 0)
				{
					x.win();
					check(x);
				}
			}
			else if (rd == 3)
			{
				x.Horse(y);
				check(x);
				if (y.checkHP() <= 0)
				{
					x.win();
					check(x);
				}
				cout << "比赛难分胜负，最终" << x.ShowName() << "和" << y.ShowName() << "缔结了和平条约" << endl;	
			}
		}
		x.fullIndi();
	}
	else if (i == 3)
	{
		Event event;
		for (int i = 0; i < 3; i++)
		{
			cout << endl;
			cout << "重大事件！尊敬的"<<x.checkStatus()<<"大人"<< endl;
			srand(time(NULL));
			int rd = rand() % 13;
			switch (rd)
			{
			case 0:
				event.Canal(x);
				break;
			case 1:
				event.colony(x);
				break;
			case 2:
				event.Comet(x);
				break;
			case 3:
				event.competitation(x);
				break;
			case 4:
				event.Gold(x);
				break;
			case 5:
				event.humanity(x);
				break;
			case 6:
				event.painting(x);
				break;
			case 7:
				event.pirate(x);
				break;
			case 8:
				event.Prestiage(x);
				break;
			case 9:
				event.Spring(x);
				break;
			case 10:
				event.starve(x);
				break;
			case 11:
				event.Successor(x);
				break;
			case 12:
				event.Tea(x);
				break;
			}
		}
	}
	else if (i==4)
	{
		fstream file("memory.txt", ios::out);
		x.savegame();
		y.savegame();
		cout<<"游戏已成功保存"<<endl;
		exit(1);
	}
	check(x);
}
void InitKing(crusder &king)
{
	int da = rand() % 5 + 95;
	int def = rand() % 5 + 95;
	int luc = rand() % 5 + 95;
	int hp = rand() % 5 + 95;
	int army = rand() % 50 + 950;
	int citizen = rand() % 50 + 950;
	int money = rand() % 50 + 950;
	int prestige = rand() % 5 + 95;

	char status[100] = "公爵";
	cout << "请输入你的名字" << endl;
	char namehero[100];
	cin.getline(namehero, 100);

	king.setIndi(hp, da, def, luc);
	king.setGov(money, army, citizen);
	king.setPlace(namehero, status);
	king.setDip(prestige);
}
void InitRobot(crusder &robot)
{
	int da = rand() % 5 + 95;
	int def = rand() % 5 + 95;
	int luc = rand() % 5 + 95;
	int hp = rand() % 5 + 95;
	int army = rand() % 50 + 950;
	int citizen = rand() % 50 + 950;
	int money = rand() % 50 + 950;
	int prestige = rand() % 5 + 95;

	char status[100] = "公爵";
	char namehero[100] = "SyntheticExecution";

	robot.setIndi(da, def, luc, hp);
	robot.setGov(army, money, citizen);
	robot.setPlace(namehero, status);
	robot.setDip(prestige);
}

int main()
{
	print(0, 1, read);
	
	cin.get();
	cout << endl;
	cout << endl;
	cout << endl;
	//Sound();
	cout << "************************************************************************************************" << endl;
	cout << endl;
	cout << "			         格拉摩根的野望" << endl;
	cout << endl;
	cout << "************************************************************************************************" << endl;
	cout << endl;
	cout<<endl;
	print(6,6,read);
	cout<<endl;
	print(2,5,read);
	cin.get();
	//print(0, 10, title);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);//设置蓝色
	cin.get();
	int c;
	srand(time(NULL));
	crusder king;
	InitKing(king);
	while (1)
	{
		cout << "按0离开，按1进入选择界面，按2查看状态，按3读取存档" << endl;
		cin >> c;
		if (c == 0)
		{
			break;
		}
		else if (c==1)
		{
			crusder robot;
			InitRobot(robot);
			choice(king, robot);
		}
		else if (c == 2)
		{
			king.Show();
			cout << endl;
		}
		else if (c==3)
		{
			int HP;
			int DA;
			int DEF;
			int LUC;
			char name[20];
			char crown[20];
			int money;
			int army;
			int citizen;
			int prestige;
			
			ifstream in;
			
			if (!in)
			{
				cerr<<"存档读取失败"<<endl;
			}
			in.open("memory.txt");
			
			in>>HP>>DA>>DEF>>LUC>>name>>crown>>money>>army>>citizen>>prestige;
			if (strcmp(crown,"dutch")==0)
			{
				strcpy(crown,"公爵"); 
			}
			else if (strcmp(crown,"king")==0)
			{
				strcpy(crown,"国王"); 
			}
			else if (strcmp(crown,"emperor")==0)
			{
				strcpy(crown,"皇帝"); 
			}
			
			king.setIndi(HP, DA, DEF, LUC);
			king.setGov(money, army, citizen);
			king.setPlace(name, crown);
			king.setDip(prestige);

			crusder robot;
			in>>HP>>DA>>DEF>>LUC>>name>>crown>>money>>army>>citizen>>prestige;
			if (strcmp(crown,"dutch")==0)
			{
				strcpy(crown,"公爵"); 
			}
			else if (strcmp(crown,"king")==0)
			{
				strcpy(crown,"国王"); 
			}
			else if (strcmp(crown,"emperor")==0)
			{
				strcpy(crown,"皇帝"); 
			}
			robot.setIndi(HP, DA, DEF, LUC);
			robot.setGov(money, army, citizen);
			robot.setPlace(name, crown);
			robot.setDip(prestige);
			in.close();
			cout<<"存档已经成功读取"<<endl;
			cout<<endl;
			choice(king, robot);
		}
	}
	
	return 0;
}
