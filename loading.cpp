#include <iostream>
#include"Consola.h"
#include"loading.h"
#include"screen.h"

using namespace std;
Loading::Loading(){};
Loading::~Loading(){};


void Loading::PrintLoading ()  //로딩화면을 나타내주는 함수
{	

	textbackground(YELLOW);  //배경을 노란색
	for(int i=0;i<5;i++){
		gotoxy(5,i+10);     
		textcolor(BLUE);     //텍스트는 파란색
		cout<<screen[i];  	 //로딩화면에 screen배열을 출력해줌
	}
	textbackground(WHITE); 
	textcolor(RED);      
	for(int i=0;i<25;i++){
		gotoxy(i+55,15);
		cout<<madeby[i];         //로딩화면에 madeby배열 출력
		delay(100);    //지연
	}

	textcolor(RED);
	gotoxy(5,18);
	cout<<"게임시작:enter       종료:esc      게임설명:E     이전게임불러오기:O"; //누른키에 따른 기능들 보여주기



}


