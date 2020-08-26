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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ���
		break;
	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//���ú�ɫ
		break;
	case 2:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//������ɫ
		break;
	case 3:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);//������ɫ
		break;
	case 4:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);//���ú�ɫ����ɫ���
		break;
	case 5:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);//���ú�ɫ����ɫ���
		break;
	case 6:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//������ɫ����ɫ���
		break;
	case 7:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);//������ɫ��û�������ɫ����Ϊԭɫ
		break;
	}
}
void print(int n, char *a)
{
	ifstream in;
	if (!in)
	{
		cout << "�ļ���ʧ��" << endl;
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
		cout << "�ļ���ʧ��" << endl;
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
	//����
	int money;
	int army;
	int citizen;
};

class crusder
{
private:
	//����
	int HP;//Ѫ��
	int DA;//����
	int DEF;//����
	int LUC;
	//�ȼ�
	char name[100];
	char crown[100];

	//����
	Nation nation;
	//�⽻
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
	////////////////////////////////////////////////////ָʾ����
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
///////////////////////////////////////////////////��ʼ���Ͳ�������
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
	if (strcmp(crown,"����")==0)
	{
		strcpy(crown,"dutch"); 
	}
	else if (strcmp(crown,"����")==0)
	{
		strcpy(crown,"king"); 
	}
	else if (strcmp(crown,"�ʵ�")==0)
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

//////////////////////////////////////////�����ж�
void crusder::peace(int ptr, crusder &x)
{
	cout << "������ƽ!" << endl;
	if (ptr==0)//0��ʤ
	{
		if (strcmp(crown, "����") == 0)
		{
			strcpy(crown, "����");
			cout << "����ս����ʤ������Ĺ��������һ��������Խ��Խ��Ĺ��忪ʼ�����Ŀ�࿴" << endl;
		}
		else if (strcmp(crown, "����") == 0)
		{
			strcpy(crown, "�ʵ�");
			cout << "����ս����ʤ����������������һ���۹���������Խ��Խ��η����" << endl;
		}
		else if (strcmp(crown, "�ʵ�") == 0)
		{
			strcpy(crown, "�¹�˹��");
			cout <<this->name<< "�ɹ��ĸ���������۹��������κ���ĳ����ܹ��뵫����ʷʫ������û���谭�ش�����׵��ǵ���̫���ٵ���ʿ̹�������ε۹���" << endl;
			cout << "��Ĺ��������ܵ�!" << endl;
		}
	}
	else 
	{
		cout << "����ս���ˣ�Խ��Խ��Ĺ��忪ʼ��Ц�����ˣ������������ϵ���ؤ���ڳ�Ц" << this->name << endl;
		cout << "��������5" << endl;
		this->prestige = this->prestige - 5;
	}
}
void crusder::rebel()
{
	Sleep(1000);
	cout << "һ���µ����壬" << endl;
	Sleep(1000);
	cout << "�������ǵ�ս�ܣ��ֵ��������" << endl;
	Sleep(1000);
	cout << this->name << "����������������" << endl;
	Sleep(500);
	int temp = rand() % (this->nation.citizen / 10);
	cout << "�Ѿ���������" << temp << endl;
	if (temp > this->nation.army)
	{
		HP = 0;
	}
	else
	{
		nation.army = nation.army - temp / 2;
		Sleep(1000);
		cout << "����Ѿ������ǵľ����������أ���������" << temp << endl;
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
	cout << "�µ�ս��!" << endl;
	Sleep(1000);
	char xxx[100] = "�������޴���Ұ���˷�ȥ�˴�Ǹ��ŵ���ս���󣬵����Ǻ���̫����";
	Sleep(1000);
	char xxxx[100] = "�Ķ����Ӱ��������������˲�֪���˲�����Խ��Խ����˾������ⳡս��";
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
	char lost[100] = "һ��ʧ�ܵ�ս�ۣ����ǽ�����Դ���������룬����ʬ�屻������ս���Ե�ˮ�����棬�Ҿ���ʧ��";
	char won[100] = "һ��ʤ����ս�ۣ����˽�����Դ���������룬����ʬ�屻������ս���Ե�ˮ�����棬�Ҿ���ʧ��";
	char peo[100] = "����ѹ�ǳ����ݣ��׹����ս��ۿ�";
	char peo1[100] = "����������ɫ�������֬��ҹ��";
	char peo2[200] = "սʿ��һ��������ȥ, �����Ŵ�ԡѪ��ս, һ��������, ��һ��������ȥ, һ��սʿ������ϡ��, �ڵ���ȥ��һ��, ���ߺ��ں�, ��׳����!";
	char peo3[200] = "Ѫ�����ϼ�ڽ�������, ˫������������������, ��û���κ�һ������, Ҳû���κ�һ����ɱ, �ȵ���ս���ϵ�����ʬ��Ͷ�����ս�����Ҳû���κ�һ������.������ֻ�ͻ������Ӷ���, ˭Ҳ������������ս��.";
	int rd = rand() % 3;

	if (this->nation.army > x.nation.army)
	{
		cout << "�µ�ս��!" << endl;
		Sleep(500);
		cout << "�Ҿ�ռ����������" << endl;
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
		cout << "�µ�ս��!" << endl;
		Sleep(500);
		cout << "����ռ����������" << endl;
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
	cout << "Ӣ�ۣ�" << name << endl;
	cout << "����λ�ã�" << crown << endl;
	cout << "����ֵ��" << HP << "   ��������" << DA << "   ��������" << DEF << endl;
	cout << "���ӣ�" << nation.army << "   ������" << nation.citizen << "   ��Ǯ��" << nation.money << endl;
	cout << "�⽻����" << prestige << endl;
}

//////////////////////////////////////////////////////////////����
void crusder::Hit(crusder &knight)//��ս
{
	print(0, 0, mainfile);
	srand(time(NULL));
	int rd = rand() % 4;
	int harm = rand() % 20 + 10;
	if (rd == 0)//����
	{
		cout<<endl;
		cout<<"�µ�ս����"<<endl;
		cout << this->name << "�ν�����" << knight.name << "һ��";
		cout<<endl;
		if (this->LUC > knight.LUC)
		{
			srand(time(NULL));
			int s = rand() % 2;
			if (s == 0)
			{
				cout << "����" << knight.name << "ˤ���ˣ�" << this->name << "��ȥ�����������" << 2 * harm << "���˺�" << endl;
				cout<<endl;
				knight.HP = knight.HP - harm;
			}
			else if (s == 1)
			{
				cout << "�����" << harm << "���˺�" << endl;
				cout<<endl;
				knight.HP = knight.HP - harm;

			}
		}
		else
		{
			int s = rand() % 3;
			if (s == 0)
			{
				cout << this->name << "�����ˣ��ɴ˱�" << knight.name << "������" << this->name << "�ܵ�" << harm << "���˺�" << endl;
				cout<<endl;
				this->HP = this->HP - 2 * harm;
			}
			else if (s == 1)
			{
				this->HP = this->HP - 2 * harm;
				cout << "������ղ���Է������Է���ĺ��޻���֮�����ܵ���" << 2 * harm << "���˺�" << endl;
				cout<<endl;
				
			}
			else if (s == 2)
			{
				this->HP = this->HP - 3 * harm;
				cout << "������ղ�������Է����������ְ����ˣ��ܵ���" << 3 * harm << "�ش�" << endl;
				cout<<endl;
			}
		}
	}
	else if (rd == 1)//�ü�ڭ��
	{
		cout<<endl;
		cout<<"�µ�ս����"<<endl;
		cout<<this->name<<"�������Լ���ߵ������ȳ���Է�"<<endl;
		cout<<endl;
		print(9, 9, mainfile);
		if (this->prestige > knight.prestige)
		{
			cout << this->name << "�������½�5��" << endl;
			cout<<endl;
			this->DEF = this->DEF - 5;
		}
		else
		{
			cout << knight.name << "�������½�5��" << endl;
			cout<<endl;
			knight.DEF = knight.DEF - 5;
		}
	}
	else if (rd == 2)//��ʯͷ
	{
		cout<<endl;
		cout<<"�µ�ս����"<<endl;
		cout<<this->name<<"���������һ���ʯͷ"<<endl;
		cout<<endl;
		print(10, 10, mainfile);
		if (this->DA > knight.DA)
		{
			cout << this->name << "�ӳ�ȥ��ʯͷ���˻������Լ���ʯͷ���صĻ�����" << endl;
			cout << "����ֵ�½�5��" << endl;
			cout<<endl;
			this->HP = this->HP - 5;
		}
		else
		{
			cout << knight.name << "��ʯͷ���صĻ�����" << endl;
			cout << "����ֵ�½�5��" << endl;
			cout<<endl;
			knight.HP = knight.HP - 5;
		}
	}
	else if (rd == 3)//���Ŷ���ײ��
	{
		cout<<endl;
		cout<<"�µ�ս����"<<endl;
		cout << this->name;
		print(8, 8, mainfile);
		if (this->DEF > knight.DEF)
		{
			cout << this->name << "ʹ�ö���ײ���˶Է�" << endl;
			cout << "�Է��ܵ�6���˺�" << endl;
			cout<<endl;
			knight.HP = knight.HP - 6;
		}
		else
		{
			cout << this->name << "���Է�ʹ�ö���ײ����" << endl;
			cout << this->name << "�ܵ�5���˺�" << endl;
			cout<<endl;
			this->HP = this->HP - 5;
		}
	}

}
void crusder::Horse(crusder &knight)//����
{
	cout<<endl;
	cout<<"�µ�ս����"<<endl;
	cout<<this->name<<"����������������"<<endl;
	cout<<endl;
	print(1, 1, mainfile);
	srand(time(NULL));
	int rd = rand() % 2;
	if (rd == 0)//�ó�ǹ�̹�ȥ
	{
		cout << this->name;
		print(5, 5, mainfile);
		if (this->DA > knight.DA)
		{
			cout << this->name;
			print(7,7, mainfile);
			knight.HP = knight.HP - 10;
			cout << knight.name << "���ˣ�����10����ֵ" << endl;
			cout<<endl;
		}
		else
		{
			print(6, 6, mainfile);
			cout << this->name << "���ˣ�����10����ֵ" << endl;
			cout<<endl;
			this->HP = this->HP - 10;
		}
	}
	else if (rd == 1)//����ײ��ȥ
	{
		cout<<endl;
		cout<<"�µ�ս����"<<endl;
		cout << this->name;
		print(8,8, mainfile);
		if (this->DEF > knight.DEF)
		{
			cout<<endl;
			cout << this->name << "ʹ�ö���ײ����" << knight.name << endl;
			cout << "�Է��ܵ�5���˺�" << endl;
			cout<<endl;
			knight.HP = knight.HP - 5;
		}
		else
		{
			cout<<endl;
			cout << this->name << "���Է�ʹ�ö���ײ����" << endl;
			cout << this->name << "�ܵ�5���˺�" << endl;
			cout<<endl;
			this->HP = this->HP - 5;
		}
	}
}
void crusder::Toxic(crusder &knight)
{
	cout<<endl;
	cout<<this->name<<"������Ͷ���"<<endl; 
	cout<<endl;
	print(4, 4, mainfile);
	cout<<endl;
	srand(time(NULL));
	int rd = rand() % 2;
	if (rd == 0)//Ͷ���ɹ�
	{
		cout << "���ڶԷ����ڷ���ĳ�־��ж��Ե�ҩ�����ѶԶ�ҩ�����˿��壬��Ķ��ֲ�û�б�����" << endl;
		cout<<endl;
		if (knight.LUC >= 98)//û��
		{

		}
		else//������
		{
			cout << "��Ķ��ֱ��㰵���ˣ����ڳ������˶������֮���һ���غ���" << endl;
			cout<<endl;
			knight.HP = 0;
		}
	}
	else if (rd == 1)//����������
	{
		
		if (this->LUC > 60)//����
		{
			cout << "����Ͷ����ʱ�򱻷����ˣ����ǲ�û�б�����ץס��������ӹ�һ��" << endl;
			cout << "�����������½�15" << endl;
			cout<<endl;
			this->prestige = this->prestige - 15;
		}
		else
		{
			cout << "����Ͷ����ʱ���˷����ˣ����Һܲ��ҵı�����ץס�ˣ�" << this->name << "�������ڳǱ�����ǽ��" << endl;
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
		cout << knight.name << "���һ��������ɱ��" << endl;
		this->HP = 0;
	}
	else if (rd == 1)
	{
		cout << "����ǰ������������5" << endl;
		cout<<endl;
		this->prestige = this->prestige + 5;
	}
}
void crusder::win()
{
		if (strcmp(crown, "����") == 0)
		{
			strcpy(crown, "����");
			cout << "�������������ͽ���̻ʾ���������Ϊ����Ħ��������" << this->name << "�ĵ�λ��������" << endl;
		}
		else if (strcmp(crown, "����") == 0)
		{
			strcpy(crown, "�ʵ�");
			cout << "������Ӯ���˱�����ʤ�����������Զ��������" << this->name << "�ļ����ѳ�Ϊ���Ժյļ���֮һ��" << endl;
		}
		else if (strcmp(crown, "�ʵ�") == 0)
		{
			strcpy(crown, "�¹�˹��");
			cout << this->name << "����������۹��������κ���ĳ����ܹ��뵫����ʷʫ������û���谭�ش�����׵��ǵ���̫���ٵ���ʿ̹�������ε۹���" << endl;
			cout << "��Ĺ��������ܵ�!" << endl;
		}
	}
void crusder::fullIndi()
{
	cout << this->name;
	print(11, mainfile);
	if (this->LUC = 100)
	{
		cout << this->name << "����ֵȫ��" << endl;
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
};//�¼���
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
	char s[200] = "ҹ������������һֱ����Ϊ������ĩ�յ����ף�һ����޴�����������������۵�������ڱ�������Ŀ������˲�С�Ļ���";
	x.addCitizen(100);
	for (int i = 0; s[i] != '\0'; i++)
	{
		Sleep(40);
		cout << s[i];
	}
	cin.get();
	cout << "��ϣ��������һ��������ʱ��" << endl;
	cout << "������100" << endl;
}


void death(crusder &x)
{
	cout << endl;
	cout << endl;
	cout << x.ShowName() << "��ɱ��" << endl;
	cout << endl;
	x.Show();
	print(0, 50, peom);
	exit(1);
}
void emperor(crusder &x)
{
	cout << x.ShowName() << "�����Ϊΰ��İ¹�˹��" << endl;
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
	else if (x.checkHP() > 0 && strcmp(x.checkStatus(), "�¹�˹��") == 0)
	{
		emperor(x);
	}
}
void choice(crusder &x, crusder &y)
{
	int i = 1;
	cout << "���������ѡ�� 1. ������������ս  2.Ѱ�Ҷ��־��� 3.������Ϣ 4.���沢�˳���Ϸ" << endl;
	cin >> i;
	if (i == 1)//��ս
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
				cout << "�����ѷ�ʤ��������" << x.ShowName() << "��" << y.ShowName() << "�޽��˺�ƽ��Լ" << endl;
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
				cout << "�����ѷ�ʤ��������" << x.ShowName() << "��" << y.ShowName() << "�޽��˺�ƽ��Լ" << endl;	
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
			cout << "�ش��¼����𾴵�"<<x.checkStatus()<<"����"<< endl;
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
		cout<<"��Ϸ�ѳɹ�����"<<endl;
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

	char status[100] = "����";
	cout << "�������������" << endl;
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

	char status[100] = "����";
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
	cout << "			         ����Ħ����Ұ��" << endl;
	cout << endl;
	cout << "************************************************************************************************" << endl;
	cout << endl;
	cout<<endl;
	print(6,6,read);
	cout<<endl;
	print(2,5,read);
	cin.get();
	//print(0, 10, title);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);//������ɫ
	cin.get();
	int c;
	srand(time(NULL));
	crusder king;
	InitKing(king);
	while (1)
	{
		cout << "��0�뿪����1����ѡ����棬��2�鿴״̬����3��ȡ�浵" << endl;
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
				cerr<<"�浵��ȡʧ��"<<endl;
			}
			in.open("memory.txt");
			
			in>>HP>>DA>>DEF>>LUC>>name>>crown>>money>>army>>citizen>>prestige;
			if (strcmp(crown,"dutch")==0)
			{
				strcpy(crown,"����"); 
			}
			else if (strcmp(crown,"king")==0)
			{
				strcpy(crown,"����"); 
			}
			else if (strcmp(crown,"emperor")==0)
			{
				strcpy(crown,"�ʵ�"); 
			}
			
			king.setIndi(HP, DA, DEF, LUC);
			king.setGov(money, army, citizen);
			king.setPlace(name, crown);
			king.setDip(prestige);

			crusder robot;
			in>>HP>>DA>>DEF>>LUC>>name>>crown>>money>>army>>citizen>>prestige;
			if (strcmp(crown,"dutch")==0)
			{
				strcpy(crown,"����"); 
			}
			else if (strcmp(crown,"king")==0)
			{
				strcpy(crown,"����"); 
			}
			else if (strcmp(crown,"emperor")==0)
			{
				strcpy(crown,"�ʵ�"); 
			}
			robot.setIndi(HP, DA, DEF, LUC);
			robot.setGov(money, army, citizen);
			robot.setPlace(name, crown);
			robot.setDip(prestige);
			in.close();
			cout<<"�浵�Ѿ��ɹ���ȡ"<<endl;
			cout<<endl;
			choice(king, robot);
		}
	}
	
	return 0;
}
