#include <iostream>
#include"Consola.h"
#include"loading.h"
#include"screen.h"

using namespace std;
Loading::Loading(){};
Loading::~Loading(){};


void Loading::PrintLoading ()  //�ε�ȭ���� ��Ÿ���ִ� �Լ�
{	

	textbackground(YELLOW);  //����� �����
	for(int i=0;i<5;i++){
		gotoxy(5,i+10);     
		textcolor(BLUE);     //�ؽ�Ʈ�� �Ķ���
		cout<<screen[i];  	 //�ε�ȭ�鿡 screen�迭�� �������
	}
	textbackground(WHITE); 
	textcolor(RED);      
	for(int i=0;i<25;i++){
		gotoxy(i+55,15);
		cout<<madeby[i];         //�ε�ȭ�鿡 madeby�迭 ���
		delay(100);    //����
	}

	textcolor(RED);
	gotoxy(5,18);
	cout<<"���ӽ���:enter       ����:esc      ���Ӽ���:E     �������Ӻҷ�����:O"; //����Ű�� ���� ��ɵ� �����ֱ�



}


