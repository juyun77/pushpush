#include <iostream>
#include<conio.h>
#include"Consola.h"
#include"map.h"
#include"pushman.h"
#include"key.h"
#include"loading.h"
#include"skillmenu.h"
using namespace std;

int scorework=0; //총걸음수를 저장해줄변수
int work=0;     //걸음수를 세줄 변수
int map[10][10]; //맵저장할 배열

int getkey()  //키를 받는 함수
{
	int retval=getch();//getch()로 키보드 입력받음
	return (retval==0xe0)?((retval<<8)|getch()):retval;  //확장키인지 검사후 키값 반환
}


int main()
{
	Loading l; //Loding클레스 ㅣ객체 선언
	SkillMenu m(0,"XXXXX"); //SkillMenu 클레스 m객체선언 
	Map a;            //Map클레스 a객체 선언
	PushMan man(0,0); //Pushman man 객체 선언

	m.stagecopy(map); //mapstage배열에 저장되있는 해당 스테이지의 값들을 map배열에 넣어줌.
	
	l.PrintLoading(); //로딩화면 출력





	while(1)
	{ 
		int key;  //키를 받을 변수선언
		key=getkey(); //사용자로부터 키를 받음

		if(key==ENTERKEY||key==OPENKEY){     //ENTER키를 누르거나 이전게임 불러오기를 했을때
			if(key==OPENKEY)  //만약 키가 OPENKEY면
				m.open(map,work,scorework); //이전에 저장했던 상태를 불러옴 	

			clrscr();  //Clean the screen


			while(1)
			{
				a.MapEdge(24,45,4,15,BLACK); //맵의 테두리를 그려줌
				textbackground(WHITE);       //글씨 배경들을 흰색으로 해줌//안해주면 모든 글씨가 검정배경이 되버림
				a.displayMap(map); // 맵을그려줌
				man.findPushman(map);//푸시맨의 현재 위치를 찾아줌
				m.Printmenu(work); //메뉴를 출력해줌
				key=getkey(); //키를 받음



				switch(key)
				{      
				case LEFTKEY:  man.moveLeft(); break; //방향키 ←
				case RIGHTKEY: man.moveRight(); break;//방향키 →
				case UPKEY:   man.moveUp();break;     //방향키 ↑
				case DOWNKEY:  man.moveDown(); break; //방향키 ↓
				case REPALYKEY:  m.stagecopy(map); scorework+=work;work=0; break;//r키를 누르면 그스테이지의 처음으로 돌아감
				case ESCKEY: m.printending();exit(1); break;  //esc키를 누르면 종료됨
				case NEXTKEY: m.nextstage(map,work);break;// n키를 누르면 다음스테이지로 넘어감
				case PREKEY: m.prestage(map,work);  break;   //p키를 누르면 이전스테이지로 돌아감
				case STOREKEY: m.store(map,work,scorework); break;//s키를 누르면 게임저장
				case OPENKEY: m.open(map,work,scorework); break;//o키를 누르면 게임불러오기
				default: break;


				}


				man.WorkPushman(map,work);//누른키에 따라 푸시맨을 이동시켜줌
				m.StageClearCheak(map,work,scorework); //스테이지를 성공했는지 체크해줌
				if((m.CheakAllClear())==1)        //5개의 스테이지를 모두 성공했는지 검사,성공했으면 1반환
				{
					m.AllClearStage(map,work,scorework);   //모든 클리어 성공
					break;
				}

			}
		}
		else if(key==ESCKEY) //esc키를 누르면 종료 
			break;


		else if(key==EXPLAINKEY) //e키를 누르면
			m.explain();   //게임설명
	}
	m.printending(); //게임을 종료했을때 엔딩


	return 0;
}