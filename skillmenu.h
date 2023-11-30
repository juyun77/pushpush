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




void Printmenu(int &work);//메뉴출력
void StageClear(int map[10][10], int cheakdata,int &work,int &storework);//스테이지를 클리어 했을 경우 
void StageClearCheak(int map[10][10],int &work,int &scorework);//스테이지를 클리어했는지 검사
void nextstage(int map[10][10],int &work);//다음스테이지로 넘어가는 함수
void stagecopy(int map[10][10]);//맵을 복사해주는 함수
void prestage(int map[10][10],int &work);//이전스테이로 넘어가는 함수
void printending();//게임을 모두 클리어했을때 엔딩 출력해주는 함수
void initialization(int &work);//걸음수,스테이지넘버,스테이지체크 초기화
void AllClearStage(int map[10][10],int &work,int &scorework);//모든스테이지를 클리어 했을때
int CheakAllClear();//모든스테이지를 클리어 했는지 검사해주는 함수
void explain();//게임설명을 출력해주는 함수
void store(int map[10][10],int &work,int &scorework);//게임을 저장하는 함수
void open(int map[10][10],int &work,int &scorework);//저장된 게임을 불러오는 함수

};


#endif