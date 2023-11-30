#include <iostream>
#include"Consola.h"
#include"menu.h"

class Store{
friend class Menu ;	

public:
	
	Store();
	~Store();

	void store(int map[10][10],int &work,int &scorework,Menu a)
	{
		int j;
		FILE *fp=fopen("store.txt","wt");


		for(int i=0;i<10;i++){
			fprintf(fp,"\n");
			for(int j=0;j<10;j++)
				fprintf(fp,"%-2d",map[i][j]);
		}


		
		fprintf(fp,"%s",a.stagecheak);
		fprintf(fp," %d",a.stagenumber);
		fprintf(fp,"\n%d",work);
		fprintf(fp,"\n%d",scorework);
		fclose(fp);
		gotoxy(10,19);
		printf("저장되었습니다. \n");
		return;
	}

	void open(int map[10][10],int &work,int &scorework)
	{
		

		FILE *fp=fopen("store.txt", "rt");

		if(fp==NULL)
			puts("파일 오픈 실패!");

		for(int i=0;i<10;i++){	
			for(int j=0;j<10;j++)
			{
				fscanf(fp,"%d",&map[i][j]);
			}
		}

		fscanf(fp,"%s",stagecheak);
		fscanf(fp,"%d",&stagenumber);
		fscanf(fp,"%d",&work);
		fscanf(fp,"%d",&scorework);
	
		fclose(fp);
	


	}

}