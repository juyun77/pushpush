#ifndef MENU_H
#define MENU_H

#include"score.h"


using namespace std;

class SkillMenu{
	Score sc;
	int stagenumber;
	char stagecheak[6];



public:
	SkillMenu(int w,char *cheak);
	~SkillMenu();




void Printmenu(int &work);//�޴����
void StageClear(int map[10][10], int cheakdata,int &work,int &storework);//���������� Ŭ���� ���� ��� 
void StageClearCheak(int map[10][10],int &work,int &scorework);//���������� Ŭ�����ߴ��� �˻�
void nextstage(int map[10][10],int &work);//�������������� �Ѿ�� �Լ�
void stagecopy(int map[10][10]);//���� �������ִ� �Լ�
void prestage(int map[10][10],int &work);//���������̷� �Ѿ�� �Լ�
void printending();//������ ��� Ŭ���������� ���� ������ִ� �Լ�
void initialization(int &work);//������,���������ѹ�,��������üũ �ʱ�ȭ
void AllClearStage(int map[10][10],int &work,int &scorework);//��罺�������� Ŭ���� ������
int CheakAllClear();//��罺�������� Ŭ���� �ߴ��� �˻����ִ� �Լ�
void explain();//���Ӽ����� ������ִ� �Լ�
void store(int map[10][10],int &work,int &scorework);//������ �����ϴ� �Լ�
void open(int map[10][10],int &work,int &scorework);//����� ������ �ҷ����� �Լ�

};


#endif