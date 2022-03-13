#include<stdio.h>
#include<windows.h>
#include<conio.h>  

int curX=0,curY=0;

char map[10][15]={
		"*W*************",
		"***WWW***WW****",
		"WWW*****WW***W*",
		"*W**W*WW*W****W",
		"******W****WWW*",
		"WWWW****W*W*W**",
		"W*WWW***WWW*W*W",
		"WW***WW****W***",
		"****WWWW***W*W*",
		"WW***W***W****P",
	};

void printPosition()
{
	COORD pos;
	pos.X=curX;
	pos.Y=curY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void printMap()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<15;j++)
			printf("%c",map[i][j]);
		printf("\n");
	}
}

void move(char dir)
{
	switch(dir)
	{
		case'w':
			curY--;
			if(curY<0)
				curY=0;
			if(map[curY][curX]=='W')
				curY++;break;
		case'a':
			curX--;
			if(curX<0)
				curX=0;
			if(map[curY][curX]=='W')
				curX++;break;
		case's':
			curY++;
			if(curY>15)
				curY=15;
			if(map[curY][curX]=='W')
				curY--;break;
		case'd':
			curX++;
			if(curX>15)
				curX=15;
			if(map[curY][curX]=='W')
				curX--;break;
	}
}

void main()
{
	char dir;
	printf("迷宫游戏即将开始，你准备好了吗？\n\n提示：w：上 a：左 s：下 d：右");
	system("pause");
	while(1)
	{
		system("cls");
		printMap();
		printPosition();
		dir=getch();
		move(dir);
		if(map[curY][curX]=='P')
		{
			printf("\n恭喜你，成功通关！\n");
			break;
		}
	}
}