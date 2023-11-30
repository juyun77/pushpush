#include<iostream>
#include"score.h"

	void Score::TotalScore(int scorework)//총걸음수에 따라 점수를 출력해줌
	{
		if(290<=scorework&&scorework<300)
			cout<<"100점 입니다.";
		else if(320<=scorework&&scorework<330)
			cout<<"95점 입니다.";
		else if(330<=scorework&&scorework<340)
			cout<<"90점 입니다.";
		else if(340<=scorework&&scorework<350)
			cout<<"85점 입니다.";
		else if(350<=scorework&&scorework<360)
			cout<<"80점 입니다.";
		else if(360<=scorework&&scorework<370)
			cout<<"75점 입니다.";
		else if(370<=scorework&&scorework<380)
			cout<<"70점 입니다.";
		else if(380<=scorework&&scorework<390)
			cout<<"65점 입니다.";
		else if(390<=scorework&&scorework<400)
		    cout<<"60점 입니다.";
		else
			 cout<<"50점 입니다.";

	}
