#include <iostream>
#include<conio.h>
#include"Consola.h"
#include"map.h"
#include"pushman.h"
#include"key.h"
#include"loading.h"
#include"skillmenu.h"
using namespace std;

int scorework=0; //�Ѱ������� �������ٺ���
int work=0;     //�������� ���� ����
int map[10][10]; //�������� �迭

int getkey()  //Ű�� �޴� �Լ�
{
	int retval=getch();//getch()�� Ű���� �Է¹���
	return (retval==0xe0)?((retval<<8)|getch()):retval;  //Ȯ��Ű���� �˻��� Ű�� ��ȯ
}


int main()
{
	Loading l; //LodingŬ���� �Ӱ�ü ����
	SkillMenu m(0,"XXXXX"); //SkillMenu Ŭ���� m��ü���� 
	Map a;            //MapŬ���� a��ü ����
	PushMan man(0,0); //Pushman man ��ü ����

	m.stagecopy(map); //mapstage�迭�� ������ִ� �ش� ���������� ������ map�迭�� �־���.
	
	l.PrintLoading(); //�ε�ȭ�� ���





	while(1)
	{ 
		int key;  //Ű�� ���� ��������
		key=getkey(); //����ڷκ��� Ű�� ����

		if(key==ENTERKEY||key==OPENKEY){     //ENTERŰ�� �����ų� �������� �ҷ����⸦ ������
			if(key==OPENKEY)  //���� Ű�� OPENKEY��
				m.open(map,work,scorework); //������ �����ߴ� ���¸� �ҷ��� 	

			clrscr();  //Clean the screen


			while(1)
			{
				a.MapEdge(24,45,4,15,BLACK); //���� �׵θ��� �׷���
				textbackground(WHITE);       //�۾� ������ ������� ����//�����ָ� ��� �۾��� ��������� �ǹ���
				a.displayMap(map); // �����׷���
				man.findPushman(map);//Ǫ�ø��� ���� ��ġ�� ã����
				m.Printmenu(work); //�޴��� �������
				key=getkey(); //Ű�� ����



				switch(key)
				{      
				case LEFTKEY:  man.moveLeft(); break; //����Ű ��
				case RIGHTKEY: man.moveRight(); break;//����Ű ��
				case UPKEY:   man.moveUp();break;     //����Ű ��
				case DOWNKEY:  man.moveDown(); break; //����Ű ��
				case REPALYKEY:  m.stagecopy(map); scorework+=work;work=0; break;//rŰ�� ������ �׽��������� ó������ ���ư�
				case ESCKEY: m.printending();exit(1); break;  //escŰ�� ������ �����
				case NEXTKEY: m.nextstage(map,work);break;// nŰ�� ������ �������������� �Ѿ
				case PREKEY: m.prestage(map,work);  break;   //pŰ�� ������ �������������� ���ư�
				case STOREKEY: m.store(map,work,scorework); break;//sŰ�� ������ ��������
				case OPENKEY: m.open(map,work,scorework); break;//oŰ�� ������ ���Ӻҷ�����
				default: break;


				}


				man.WorkPushman(map,work);//����Ű�� ���� Ǫ�ø��� �̵�������
				m.StageClearCheak(map,work,scorework); //���������� �����ߴ��� üũ����
				if((m.CheakAllClear())==1)        //5���� ���������� ��� �����ߴ��� �˻�,���������� 1��ȯ
				{
					m.AllClearStage(map,work,scorework);   //��� Ŭ���� ����
					break;
				}

			}
		}
		else if(key==ESCKEY) //escŰ�� ������ ���� 
			break;


		else if(key==EXPLAINKEY) //eŰ�� ������
			m.explain();   //���Ӽ���
	}
	m.printending(); //������ ���������� ����


	return 0;
}