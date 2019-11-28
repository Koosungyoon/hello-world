
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 


void titleDraw(void);
int keyControl(void);
void gotoxy(int, int);
int menuDraw(void);
void Stage(char(*aryStage)[51]);
void objectXY(int x, int y);
void move(char(*aryStage)[51]);
void jump(char(*aryStage)[51]);


int px = 2;
int py = 8;
int playing = 1;

int main(void)
{
	char aryStage[10][51] = {
		{"11111111111111111111111111111111111111111111111131"},
		{"11111111111111110001111111111111111001111100111000"},
		{"11111111110011111111111100111100111111111111111111"},
		{"00000011111111111111111111111111111111111111111111"},
		{"11111111100111111111111111111111111111111111111111"},
		{"11111111111111100111111111100111144111111111111111"},
		{"11111111111111111111100111111110011110000111111111"},
		{"11111114411111144111111111111111111111111110014411"},
		{"11111111111111111111111111144441111111111111111111"},
		{"00000001100000110011000011000000001111000001100000"}
	};
	int menuCode;
	while (1)
	{
		titleDraw();

		menuCode = menuDraw();
		if (menuCode == 0)
		{
			Stage(aryStage);
			move(aryStage);
		}

		else if (menuCode == 1)

		{

			//infoDraw();

		}

		else if (menuCode == 2)

		{

			break;

		}

		//menuCode = 5;

		system("cls");

	}



	gotoxy(12, 16);

	printf("������ ����Ǿ����ϴ�!!!");

	_getch();



	return 0;

}

void gotoxy(int x, int y) {

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ鰡������ 
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void titleDraw(void)
{
	printf("\n\n");
	printf("\t����  ��  ��  ����  ����  ����\n");
	printf("\t��    ��  ��  �� ��  ��    �� ��\n");
	printf("\t����  ��  ��  ����  ����  ����\n");
	printf("\t  ��  ��  ��  ��    ��    ���\n");
	printf("\t����  ����   ��    ����  �� ��\n");
	printf("\n");
	printf("\t\t��      ��  �ââ�  �ââ�  ��    ��\n");
	printf("\t\t�â�  �â�  ��  ��  ��  ��  ��  ��  ��\n");
	printf("\t\t��  ��  ��  �ââ�  �ââ�  ��  ��  ��\n");
	printf("\t\t��      ��  ��  ��  �â�    ��  ��  ��\n");
	printf("\t\t��      ��  ��  ��  ��  ��  ��    ��\n");

}

int keyControl() {
	char temp = _getch();

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') { // �����̽���(����)�� ���� ��ư  
		return SUBMIT;
	}
}

int menuDraw() {

	int x = 24;
	int y = 15;
	gotoxy(x - 2, y); // -2 �� ������ > �� ����ؾ��ϱ� ������  
	printf("> ���ӽ���");
	gotoxy(x, y + 1);
	printf("��������");
	gotoxy(x, y + 2);
	printf("  ����  ");

	while (1) { // ���ѹݺ�  
		int n = keyControl(); // Ű���� �̺�Ʈ�� Ű������ �޾ƿ���  
		switch (n) {
		case UP: { // �Էµ� Ű�� ���� UP�ΰ�� (w) 
			if (y > 15) { // y�� 12~14������ �̵�  
				gotoxy(x - 2, y); // x-2 �ϴ� ������ ">"�� ��ĭ ������ ����ϱ�����  
				printf(" "); // ���� ��ġ�� �����  
				gotoxy(x - 2, --y); // ���� �̵��� ��ġ�� �̵��Ͽ�  
				printf(">"); // �ٽ� �׸���  
			}
			break;
		}
		case DOWN: { // �Էµ� Ű�� ���� DOWN�ΰ�� (s) 
			if (y < 17) { // �ִ� 14  
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 15; // �����̽���(����)�Ǿ��� ��� y-12
			// y ���� ��ġ�� 12�����Ƿ� y-12 �� �ϸ� 0, 1, 2 �� ���ڸ� ���� �� �ִ�. 
		}
		}
	}
}

void Stage(char(*aryStage)[51])
{
	system("cls");
	if (px > 43) {
		px = 43;
	}
	for (int i = py - 4; i <= py + 2; i++) {
		for (int j = px - 2; j < px + 8; ++j) {
			if (i == py && j == px) {
				printf("��");
			}
			else if (aryStage[i][j] == '0') {   // 0:�� 1:�� 2:������ 3:������ 4:����
				printf("��");
			}
			else if (aryStage[i][j] == '1') {
				printf("  ");
			}
			else if (aryStage[i][j] == '2') {
				printf("��");
			}
			else if (aryStage[i][j] == '3') {
				printf("��");
			}
			else if (aryStage[i][j] == '4') {
				printf("��");
			}
		}
		printf("\n");
	}
}

void objectXY(int x, int y)
{
	px += x;
	py += y;
}

void move(char(*aryStage)[51])

{
	int mKey;
	while (playing)

	{

		mKey = keyControl();

		switch (mKey)
		{
		case UP:

			objectXY(0, -1);
			Stage(aryStage);
			break;

		case DOWN:

			objectXY(0, 1);
			Stage(aryStage);
			break;

		case RIGHT:

			objectXY(1, 0);
			Stage(aryStage);
			break;

		case LEFT:

			objectXY(-1, 0);
			Stage(aryStage);
			break;

		case SUBMIT:
			jump(aryStage); // �����Լ� �������� !! 
			break;
		}
	}

	playing = 1;

}

void jump(char (*aryStage)[51])
{
	bool isJumping = true;
	bool isBottom = true;
	const int gravity = 1;
	int marioY = py;  //�������� py����
	int marioX = px;  //�������� px����

	while (isBottom)
	{
		if (isJumping) {
			py -= gravity;
		}
		else {
			py += gravity;
		}
		if (py == marioY) {
			isBottom = false;
		}
		if (py <= 6) {
			isJumping = false;
		}
		objectXY(1, 0);
		Stage(aryStage);     //�ؾ� �Ұ�: object�� ��ġ�� �ٲٴ� ���� �ƴ϶� ���� �ڷ� �������ߵ� (�����ΰ��� ����Ű ������������ ���� �� ��� ������ �� �� �ֵ���)
	}
}





/*#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdbool.h>

void jump()
{
	bool isJumping = false;
	bool isBottom = true;
	const int gravity = 3;
	int marioY = py;  //�������� py����

	while (true)
	{
		if (isBottom){
			isJumping = true;
			isBottom = false;
		}
		if (isJumping) {
			marioY -= gravity;
		}
		else {
			marioY += gravity;
		}
		if (marioY >= py) {
			marioY = py;
			isBottom = true;
		}
		if (marioY <= 3) {
			isJumping = false;
		}
	}

}*/