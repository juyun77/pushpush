#include <iostream>
#include"Consola.h"
#include"Skillmenu.h"
#include"mapstage.h"
#include<time.h>
#include<cstring>


using namespace std;

    SkillMenu::SkillMenu (int w,char *cheak)
	{  
		stagenumber=w;                   //맴버변수 초기화//스테이지 넘버
		strcpy(stagecheak,cheak);        // 스테이지클리어체크하는 배열값 초기화
		
	}
	SkillMenu::~SkillMenu(){}




	void SkillMenu::Printmenu(int &work)//메뉴를 출력해주는 함수
	{	
		struct tm *tp;    // 
		time_t now;       //
 		now=time(NULL);   //
		tp=localtime(&now);//  현재시간을 받아옴          
		gotoxy(1,1); cout<<"☞현재시간:"<<tp->tm_hour<<"시"<<tp->tm_min<<"분☜";  //현재시간 출력
		gotoxy(51,3); cout<<" ┏━━━━━━━━━━━┓";            
		gotoxy(51,4); cout<<" ┃     ★starpush★     ┃";
		gotoxy(51,5); cout<<" ┗━━━━━━━━━━━┛";
		gotoxy(51,7);cout<<"          UP ";
		gotoxy(51,8);cout<<"          ↑ ";
		gotoxy(51,9);cout<<"    LEFT←  →RIGHT ";
		gotoxy(51,10);cout<<"          ↓   ";
		gotoxy(51,11);cout<<"         DOWN   ";
		gotoxy(51,13);cout<<"  *다음스테이지 :N   ";
		gotoxy(51,15);cout<<"  *이전스테이지 :P    ";
		gotoxy(51,17);cout<<"  *다시하기      :R    ";
		gotoxy(51,19);cout<<"  *게임종료      :ESC   ";
		gotoxy(51,21);cout<<"  *저장하기      :S   ";
		gotoxy(51,23);cout<<"  *불러오기      :O   ";
		gotoxy(25,17);cout<<"   <이동횟수: "<<work<<">"; //걸음수
		gotoxy(27,3);cout<<"<stage:"<<stagenumber+1<<">"; //스테이지 넘버
		gotoxy(1,10);cout<<" 1탄 2탄 3탄 4탄 5탄 ";  
		gotoxy(1,11);
		for(int i=0;i<5;i++)
			cout<<"   "<<stagecheak[i];       //스테이지 클리어 여부 나타내기


	}



	void SkillMenu:: StageClear(int map[10][10], int cheakdata,int &work,int &storework)//스테이지를 클리어 했을 경우 
	{

		if(cheakdata==0)  //남아있는 공의 갯수가 0일 경우, 스테이지 클리어
		{
			stagecheak[stagenumber]='O';      //스테이지 클리어 여부를 O로 바꿈
			stagenumber++;                    //스테이지 넘버 ++  
			clrscr();                                 
			gotoxy(10,10);
			cout<<"성공하셨습니다! 다음스테이지로 넘어갑니다~^^*";
			delay(800);
			storework+=work;        // 걸음수를 총걸음수 세는 변수에 더해줌
			work=0;                  //걸음수 초기화
			clrscr();
			stagecopy(map);          //map배열에 stagenumber에 해당하는 스테이지 복사


		}
		else 
			return ;

	}



	void SkillMenu::StageClearCheak(int map[10][10],int &work,int &scorework)//스테이지 클리어 확인해주는 함수
	{
		int cheakdata=0;   //공의 갯수를 세줄 변수

		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
			{
				if(map[i][j]==2)    //(공:2) 배열에 공이 있으면
					cheakdata++;   //cheakdata 1증가
			}
			StageClear(map,cheakdata,work,scorework); //stageclear배열로 값을 전달

	}

	void SkillMenu::nextstage(int map[10][10],int &work) //다음스테이지로 넘어가는 함수
	{
		if(stagecheak[stagenumber]=='O')  //현재스테이지가 클리어 되있으면
		{
			stagenumber++;                 //다음스테이지로
			stagecopy(map);                //넘어감
			work=0;                        //걸음수 초기화
			clrscr();

		}
		else{                         //현재스테이지를 클리어하지 못했을 경우
			gotoxy(10,19);
			cout<<"현재스테이지를 성공해야합니다!!";   
			delay(800);
			clrscr();
		}
	}


	void SkillMenu::stagecopy(int map[10][10])   //스테이지를 복사해주는 함수
	{
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				map[i][j]=mapstage[stagenumber][i][j];
	

	}
	void SkillMenu::prestage(int map[10][10],int &work) //이전스테이지로 넘어가는 함수
	{
		if(stagenumber!=0)
		{
			stagenumber--;
			stagecopy(map);
			work=0;
		}
	}

	void SkillMenu::printending()//종료 
	{	clrscr();
	gotoxy(20,10);
	cout<<"게임을 종료합니다.*^^*";
	gotoxy(1,20);

	}

	
	void SkillMenu::initialization(int &work)//걸음수,스테이지넘버,스테이지체크 초기화
	{
		stagenumber=0;
		strcpy(stagecheak,"XXXXX");
		work=0;
	}




	void SkillMenu::AllClearStage(int map[10][10],int &work,int &scorework)//모든 스테이지를 클리어 했을때
	{
		clrscr();
		initialization(work);//걸음수,스테이지넘버,스테이지체크 초기화
		stagecopy(map);      //처음 맵 복사   
		cout<<"모든 스테이지 성공^^*"<<endl;
		cout<<"점수:";
			sc.TotalScore(scorework);      //총걸음수에 따라 점수를 출력해주는 함수
		
		cout<<endl<<"종료:ESC     처음으로:ENTER"<<endl;  
		scorework=0; //총걸음수 초기화
	}

	int SkillMenu::CheakAllClear() //모든 스테이지를 클리어했는지 검사해주는 함수
	{
		if(stagecheak[4]=='O') //5번째 스테이지를 클리어 되면
		{  
			return 1;   //1반환

		}
		else
			return 0;

	}


	void SkillMenu::explain()//게임설명을 해주는 함수
	{
		clrscr();
		
		gotoxy(3,5);cout<<"****************************게임 설명******************************"<<endl;
		gotoxy(5,7);cout<<"＆로 ☆을 밀어서 목적지인 ■에 넣습니다."<<endl;
		gotoxy(5,8);cout<<"＆과 ☆은 벽을 통과할 수 없습니다. "<<endl;
		gotoxy(5,9);cout<<"모든 ☆을 ■로 넣으면 성공!"<<endl;
		gotoxy(5,10);cout<<"현재스테이지를 깨지 않으면 다음스테이지로 넘어갈 수 없다는걸 유의하세요~"<<endl<<endl;
		gotoxy(5,12);cout<<"게임시작:ENTER           종료:ESC     이전게임불러오기:O";

	}


		void SkillMenu::store(int map[10][10],int &work,int &scorework)//저장해주는 함수
	{
		int j;
		FILE *fp=fopen("store.txt","wt");  //파일 쓰기


		for(int i=0;i<10;i++){
			fprintf(fp,"\n");          
			for(int j=0;j<10;j++)
				fprintf(fp,"%-2d",map[i][j]);     //현재 맵상태
		}
		fprintf(fp,"%s",stagecheak);            //스테이지 클리어여부
		fprintf(fp," %d",stagenumber);          //스테이지넘버
		fprintf(fp,"\n%d",work);                //걸음수
		fprintf(fp,"\n%d",scorework);          //총걸음수를 store.txt파일에 출력
		fclose(fp);                        //파일닫기
		gotoxy(10,19);
		printf("저장되었습니다. \n");
		return;
	}

	void SkillMenu::open(int map[10][10],int &work,int &scorework)//저장된 게임을 불러오는 함수
	{
		

		FILE *fp=fopen("store.txt", "rt"); //파일 읽기

		if(fp==NULL)
			puts("파일 오픈 실패!");

		for(int i=0;i<10;i++){	
			for(int j=0;j<10;j++)
			{
				fscanf(fp,"%d",&map[i][j]);
			}
		}

		fscanf(fp,"%s",stagecheak);                  //
		fscanf(fp,"%d",&stagenumber);                //파일에서 
		fscanf(fp,"%d",&work);                       //읽어옴
		fscanf(fp,"%d",&scorework);                  //
	
		fclose(fp);//파일닫기
	


	}
	
