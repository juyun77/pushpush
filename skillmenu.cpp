#include <iostream>
#include"Consola.h"
#include"Skillmenu.h"
#include"mapstage.h"
#include<time.h>
#include<cstring>


using namespace std;

    SkillMenu::SkillMenu (int w,char *cheak)
	{  
		stagenumber=w;                   //�ɹ����� �ʱ�ȭ//�������� �ѹ�
		strcpy(stagecheak,cheak);        // ��������Ŭ����üũ�ϴ� �迭�� �ʱ�ȭ
		
	}
	SkillMenu::~SkillMenu(){}




	void SkillMenu::Printmenu(int &work)//�޴��� ������ִ� �Լ�
	{	
		struct tm *tp;    // 
		time_t now;       //
 		now=time(NULL);   //
		tp=localtime(&now);//  ����ð��� �޾ƿ�          
		gotoxy(1,1); cout<<"������ð�:"<<tp->tm_hour<<"��"<<tp->tm_min<<"�Т�";  //����ð� ���
		gotoxy(51,3); cout<<" ��������������������������";            
		gotoxy(51,4); cout<<" ��     ��starpush��     ��";
		gotoxy(51,5); cout<<" ��������������������������";
		gotoxy(51,7);cout<<"          UP ";
		gotoxy(51,8);cout<<"          �� ";
		gotoxy(51,9);cout<<"    LEFT��  ��RIGHT ";
		gotoxy(51,10);cout<<"          ��   ";
		gotoxy(51,11);cout<<"         DOWN   ";
		gotoxy(51,13);cout<<"  *������������ :N   ";
		gotoxy(51,15);cout<<"  *������������ :P    ";
		gotoxy(51,17);cout<<"  *�ٽ��ϱ�      :R    ";
		gotoxy(51,19);cout<<"  *��������      :ESC   ";
		gotoxy(51,21);cout<<"  *�����ϱ�      :S   ";
		gotoxy(51,23);cout<<"  *�ҷ�����      :O   ";
		gotoxy(25,17);cout<<"   <�̵�Ƚ��: "<<work<<">"; //������
		gotoxy(27,3);cout<<"<stage:"<<stagenumber+1<<">"; //�������� �ѹ�
		gotoxy(1,10);cout<<" 1ź 2ź 3ź 4ź 5ź ";  
		gotoxy(1,11);
		for(int i=0;i<5;i++)
			cout<<"   "<<stagecheak[i];       //�������� Ŭ���� ���� ��Ÿ����


	}



	void SkillMenu:: StageClear(int map[10][10], int cheakdata,int &work,int &storework)//���������� Ŭ���� ���� ��� 
	{

		if(cheakdata==0)  //�����ִ� ���� ������ 0�� ���, �������� Ŭ����
		{
			stagecheak[stagenumber]='O';      //�������� Ŭ���� ���θ� O�� �ٲ�
			stagenumber++;                    //�������� �ѹ� ++  
			clrscr();                                 
			gotoxy(10,10);
			cout<<"�����ϼ̽��ϴ�! �������������� �Ѿ�ϴ�~^^*";
			delay(800);
			storework+=work;        // �������� �Ѱ����� ���� ������ ������
			work=0;                  //������ �ʱ�ȭ
			clrscr();
			stagecopy(map);          //map�迭�� stagenumber�� �ش��ϴ� �������� ����


		}
		else 
			return ;

	}



	void SkillMenu::StageClearCheak(int map[10][10],int &work,int &scorework)//�������� Ŭ���� Ȯ�����ִ� �Լ�
	{
		int cheakdata=0;   //���� ������ ���� ����

		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
			{
				if(map[i][j]==2)    //(��:2) �迭�� ���� ������
					cheakdata++;   //cheakdata 1����
			}
			StageClear(map,cheakdata,work,scorework); //stageclear�迭�� ���� ����

	}

	void SkillMenu::nextstage(int map[10][10],int &work) //�������������� �Ѿ�� �Լ�
	{
		if(stagecheak[stagenumber]=='O')  //���罺�������� Ŭ���� ��������
		{
			stagenumber++;                 //��������������
			stagecopy(map);                //�Ѿ
			work=0;                        //������ �ʱ�ȭ
			clrscr();

		}
		else{                         //���罺�������� Ŭ�������� ������ ���
			gotoxy(10,19);
			cout<<"���罺�������� �����ؾ��մϴ�!!";   
			delay(800);
			clrscr();
		}
	}


	void SkillMenu::stagecopy(int map[10][10])   //���������� �������ִ� �Լ�
	{
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				map[i][j]=mapstage[stagenumber][i][j];
	

	}
	void SkillMenu::prestage(int map[10][10],int &work) //�������������� �Ѿ�� �Լ�
	{
		if(stagenumber!=0)
		{
			stagenumber--;
			stagecopy(map);
			work=0;
		}
	}

	void SkillMenu::printending()//���� 
	{	clrscr();
	gotoxy(20,10);
	cout<<"������ �����մϴ�.*^^*";
	gotoxy(1,20);

	}

	
	void SkillMenu::initialization(int &work)//������,���������ѹ�,��������üũ �ʱ�ȭ
	{
		stagenumber=0;
		strcpy(stagecheak,"XXXXX");
		work=0;
	}




	void SkillMenu::AllClearStage(int map[10][10],int &work,int &scorework)//��� ���������� Ŭ���� ������
	{
		clrscr();
		initialization(work);//������,���������ѹ�,��������üũ �ʱ�ȭ
		stagecopy(map);      //ó�� �� ����   
		cout<<"��� �������� ����^^*"<<endl;
		cout<<"����:";
			sc.TotalScore(scorework);      //�Ѱ������� ���� ������ ������ִ� �Լ�
		
		cout<<endl<<"����:ESC     ó������:ENTER"<<endl;  
		scorework=0; //�Ѱ����� �ʱ�ȭ
	}

	int SkillMenu::CheakAllClear() //��� ���������� Ŭ�����ߴ��� �˻����ִ� �Լ�
	{
		if(stagecheak[4]=='O') //5��° ���������� Ŭ���� �Ǹ�
		{  
			return 1;   //1��ȯ

		}
		else
			return 0;

	}


	void SkillMenu::explain()//���Ӽ����� ���ִ� �Լ�
	{
		clrscr();
		
		gotoxy(3,5);cout<<"****************************���� ����******************************"<<endl;
		gotoxy(5,7);cout<<"���� ���� �о �������� �ῡ �ֽ��ϴ�."<<endl;
		gotoxy(5,8);cout<<"���� ���� ���� ����� �� �����ϴ�. "<<endl;
		gotoxy(5,9);cout<<"��� ���� ��� ������ ����!"<<endl;
		gotoxy(5,10);cout<<"���罺�������� ���� ������ �������������� �Ѿ �� ���ٴ°� �����ϼ���~"<<endl<<endl;
		gotoxy(5,12);cout<<"���ӽ���:ENTER           ����:ESC     �������Ӻҷ�����:O";

	}


		void SkillMenu::store(int map[10][10],int &work,int &scorework)//�������ִ� �Լ�
	{
		int j;
		FILE *fp=fopen("store.txt","wt");  //���� ����


		for(int i=0;i<10;i++){
			fprintf(fp,"\n");          
			for(int j=0;j<10;j++)
				fprintf(fp,"%-2d",map[i][j]);     //���� �ʻ���
		}
		fprintf(fp,"%s",stagecheak);            //�������� Ŭ�����
		fprintf(fp," %d",stagenumber);          //���������ѹ�
		fprintf(fp,"\n%d",work);                //������
		fprintf(fp,"\n%d",scorework);          //�Ѱ������� store.txt���Ͽ� ���
		fclose(fp);                        //���ϴݱ�
		gotoxy(10,19);
		printf("����Ǿ����ϴ�. \n");
		return;
	}

	void SkillMenu::open(int map[10][10],int &work,int &scorework)//����� ������ �ҷ����� �Լ�
	{
		

		FILE *fp=fopen("store.txt", "rt"); //���� �б�

		if(fp==NULL)
			puts("���� ���� ����!");

		for(int i=0;i<10;i++){	
			for(int j=0;j<10;j++)
			{
				fscanf(fp,"%d",&map[i][j]);
			}
		}

		fscanf(fp,"%s",stagecheak);                  //
		fscanf(fp,"%d",&stagenumber);                //���Ͽ��� 
		fscanf(fp,"%d",&work);                       //�о��
		fscanf(fp,"%d",&scorework);                  //
	
		fclose(fp);//���ϴݱ�
	


	}
	
