#include <stdio.h>
#include <stdlib.h>   // system("pause")를 사용하기 위해 추가한 코드
#include <windows.h>  // Sleep(숫자)를 사용하기 위해 추가한 코드
int main(void)

{
	int a = 0, b = 0;  // a와 b는 {a,b} 위치를 나타내는 값 선언 및 초기화
					   // 초기값  {0,0}


	char miro[9][9] = {
	{'S', 'x', 'x', 'o', 'x', 'x', 'x', 'o', 'x'},
	{'o', 'o', 'o', 'o', 'x', 'o', 'o', 'o', 'x'},
	{'x', 'o', 'x', 'o', 'o', 'o', 'x', 'o', 'x'},
	{'o', 'o', 'o', 'o', 'x', 'o', 'o', 'o', 'o'},
	{'x', 'x', 'x', 'x', 'o', 'o', 'x', 'x', 'x'},
	{'o', 'o', 'o', 'o', 'o', 'x', 'x', 'o', 'o'},
	{'o', 'x', 'o', 'x', 'o', 'o', 'x', 'o', 'x'},
	{'o', 'o', 'o', 'x', 'x', 'o', 'o', 'o', 'x'},
	{'o', 'x', 'o', 'x', 'x', 'x', 'x', 'o', 'F'}
	};   // 9*9 형태의 2차원 배열 선언 


	printf("              miro miro\n\n");

	for (int i = 8; i >= 0; i--) // i는 반복 횟수를 제어하기 위한 변수 
  //★ for (int i = 0; i <= 8; i++) 굳이 거꾸로 해야하나? 출발점을 (0,0)으로 설정하기 위해 거꾸로 설정
	{

		printf("%3c %3c %3c %3c %3c %3c %3c %3c %3c\n\n",  // 왕미로 만들기
			miro[i][0], miro[i][1], miro[i][2], miro[i][3], miro[i][4], miro[i][5],
			miro[i][6], miro[i][7], miro[i][8]);
		//★★★ 반복문(for문)을 사용해서 간단하게 출력해보기
	}   // 미로 그림을 화면에 출력하기 
	char  enter; // 엔터 입력하기 위한 변수 설정 _command

	printf("▶미로게임에 오신걸 환영합니다~!\n");
	printf("▶시작 위치는 ☞ S 입니다\n");
	printf("▶행운을 빕니다\n\n");

	printf("Enter를 누르면 게임이 시작됩니다\n");  // 엔터 만들기 
	scanf("%c", &enter);
	if (enter != '\n')                             // 엔터가 아닌 다른 입력을 할 시 바로 게임 종료
	{
		printf("게임이 종료되었습니다");
		return 0;

	}                                              //엔터


	while (miro[a][b] != 'F')   //  F일때까지 게임 반복  _while 전체로 묶어주기
	{



		system("cls");  // 화면 삭제


		printf("              miro miro\n\n");
		for (int i = 8; i >= 0; i--)  // 문제 풀면서도 지도 화면에 띄어 놓기
		{
			printf("%3c %3c %3c %3c %3c %3c %3c %3c %3c\n\n", 
				miro[i][0], miro[i][1], miro[i][2], miro[i][3], miro[i][4], miro[i][5],
				miro[i][6], miro[i][7], miro[i][8]);
		}   


		// 전진   8
		// 오른쪽 6
		// 왼쪽   4
		// 뒤로   2

		int move = 0; // 위치를 제어할 변수 선언
		printf("◆현재 위치는 [ %d , %d ] 입니다\n", b, a);
		printf("◆어디로 가실 건가요?\n");
		printf("   △     8\n ◁  ▷ 4   6\n   ▽     2 \n");

		// ▼움직일 수 있는 방향 표시하기
		if (miro[a + 1][b] == 'o'|| miro[a + 1][b] == 'F' && (a + 1 >= 0 && a + 1 < 9) && (b >= 0 && b < 9))   printf("위로 8\n");
		if (miro[a][b - 1] == 'o'|| miro[a][b - 1] == 'F' && (a >= 0 && a < 9) && (b - 1 >= 0 && b - 1 < 9))   printf("왼쪽 4\n");
		if (miro[a][b + 1] == 'o'|| miro[a][b + 1] == 'F' && (a >= 0 && a < 9) && (b + 1 >= 0 && b + 1 < 9))   printf("오른쪽 6\n");
		if (miro[a - 1][b] == 'o'|| miro[a - 1][b] == 'F' && (a - 1 >= 0 && a - 1 < 9) && (b >= 0 && b < 9))   printf("아래로 2\n");
		//★ F 일때 방향 입력칸

		//printf("◆현재 위치는 [ %d , %d ] 입니다", a, b);   //★★★ 왜 안나와 → scaf 전에!!! printf 써주기
		scanf("%d", &move);                               //(scanf는 입력받을 값을 기다리므로...)


		//★ 지도가 위에 떠 있었으면 좋겠어요

		//★ if((a>=0 && a<9) && (b>=0 && b<9))
	


		switch (move)  // 이동 방향 선택창?
		{
		case 8:   // 위로
			if ((miro[a + 1][b] == 'x') || (a+1<0 || a+1>8) || (b<0 || b>8))
				printf("이 방향으로 갈 수 없어요\n");     // 막혀 있는 2468 방향을 눌렀을 때도 갈수 없다는 글 출력하기!!! 
			    Sleep(2000);                              //
				
				break;
			a += 1;


			break;

		case 4:  // 왼쪽으로
			if (miro[a][b - 1] == 'x' || (a<0 || a > 8) || (b -1< 0 || b-1 >8)) 
				printf("이 방향으로 갈 수 없어요\n");
			    Sleep(2000);

				break;
			b -= 1;

			break;

		case 6:  // 오른쪽으로
			if (miro[a][b + 1] == 'x' || (a <0 || a >8) || (b+1 <0 || b+1 >8)) 
				printf("이 방향으로 갈 수 없어요\n");
			    Sleep(2000);

				break;
			b += 1;

			break;

		case 2:  // 아래로
			if (miro[a - 1][b] == 'x' || (a-1< 0 || a-1 >8) || (b <0 || b >8))
				printf("이 방향으로 갈 수 없어요\n");
			    Sleep(2000);

				break;
			a -= 1;

			break;
		
		default:
			printf("이 방향으로 갈 수 없어요\n");
			Sleep(2000);        //  Sleep(숫자) ★ 1000 → 1초!!! 동안 프린트를 잠깐 출력함       
			//system("pause");  // system("pause") ★ 게임을 잠시 중단시킨다
				

			/* ★ defaul문의 break 후 다시 while문 시작으로 가서 system("cls"); 때문에
			   ★ 프린트를 출력하기도 전에 화면이 지워지므로 Sleep 이나 pause 둘 중 에 하나 사용하기 !!!*/
			break;
		}   

	}


	if (a == 8 && b == 8)
		printf("★도착입니다!");
	//★ 어디에 써야 할까? while문 자체가 F면 끝나기 때문에 while문 끝난 후에 써 주었다

	return 0;

}      // 정답 : 8 6 6 6 8 6 6 8 8 4 8 8 6 8 6 6 6 8 6 