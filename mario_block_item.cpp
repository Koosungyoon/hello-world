#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>
#include<string.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 


void titleDraw(void);
int keyControl(void);
void gotoxy(int, int);
int menuDraw(void);
void Stage(char(*aryStage)[70]);
void objectXY(int x, int y);
void move(char(*aryStage)[70]);
void jump(char(*aryStage)[70]);


int px = 2;
int py = 8;
int playing = 1;
bool Go = false;
bool item = true;

char tempStage[10][70] = {
	{"11111111111111111111111111111111111111111111111111111111111111111111"},
	{"111111111111111100011111111111111110011111001110001111111111111111000"},
	{"111111111100111111111111001111001111111111111111111111111111001111111"},
	{"000000111111111111111111111111111111111111111111110000001111111111111"},
	{"111111111001111111111111111111111111111111111111111111111110011111111"},
	{"111111111111111001111111111001111441111111111111111111111111111110011"},
	{"111111110511111111111160111111110011110000111111111111111111111111111"},
	{"111111111111001111441111111111111111111110014411111111144111111441111"},
	{"111111111111111111111111111444411111111111111111111111111111111111133"},
	{"000000000000000000110000110000000011110000011000000000000110000011001"}
};

int main(void)
{
	char aryStage[10][70] = {
		{"11111111111111111111111111111111111111111111111111111111111111111111"},
		{"111111111111111100011111111111111110011111001110001111111111111111000"},
		{"111111111100111111111111001111001111111111111111111111111111001111111"},
		{"000000111111111111111111111111111111111111111111110000001111111111111"},
		{"111111111001111111111111111111111111111111111111111111111110011111111"},
		{"111111111111111001111111111001111441111111111111111111111111111110011"},
		{"111111110511111111111160111111110011110000111111111111111111111111111"},
		{"111111111111001111441111111111111111111110014411111111144111111441111"},
		{"111111111111111111111111111444411111111111111111111111111111111111133"},
		{"000000000000000000110000110000000011110000011000000000000110000011001"}
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

void Stage(char(*aryStage)[70])
{
	system("cls");
	/*if (px > 43) {
		px = 43;
	}*/
	for (int i = py - 4; i <= py + 2; i++) {
		for (int j = px - 2; j < px + 8; ++j) {
			if (i == py && j == px) {
				printf("��");
			}
			else if (tempStage[i][j] == '0' || tempStage[i][j] == '5' || tempStage[i][j] == '6') {   // 0:�� 1:�� 2:������ 3:������ 4:����
				if (item) {
					printf("��");
				}
				else {
					if (tempStage[i][j] == '0') {
						printf("��");
					}
					if (tempStage[i][j] == '5') {
						printf("��");
					}
					else if (tempStage[i][j] == '6') {
						printf("��");
					}
				}
			}
			else if (tempStage[i][j] == '1') {
				printf("  ");
			}
			else if (tempStage[i][j] == '2') {
				printf("��");
			}
			else if (tempStage[i][j] == '3') {
				printf("��");
			}
			else if (tempStage[i][j] == '4') {
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

void move(char(*aryStage)[70])

{
	int mKey;
	while (playing)

	{

		mKey = keyControl();

		switch (mKey)
		{
		case UP:

			jump(aryStage);
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

			Go = true;
			jump(aryStage);
			break;
		}
		if (aryStage[py + 1][px] != '0') {   //���� �� ���� ������ �ƴ϶�� �ٴ�����
			while (py < 8) {
				py++;
				Stage(aryStage);
			}
		}
		if (aryStage[py + 1][px] == '1') {
			py++;
			Stage(aryStage);
			Sleep(20);
			system("cls");
			printf("�÷��̾� ���\n");     //�� �� ȭ���ϰ� �ٹ� ��  (ex : ��ź bomb �ϸ鼭 ������ �׷���)
			px = 2;
			py = 8;
			memcpy(tempStage, aryStage, sizeof(tempStage));
			Sleep(1000);
			playing = 0;

		}
	}

	playing = 1;

}

void jump(char(*aryStage)[70])
{
	bool isJumping = true;
	bool isBottom = true;
	const int gravity = 1;
	int marioY = py;  //�������� py����
	//int marioX = px;  //�������� px����

	while (isBottom)
	{
		if (isJumping) {
			py -= gravity;
		}
		else {
			py += gravity;
		}
		if (Go) {
			px++;
		}
		if (py == marioY) {
			isBottom = false;
		}
		if (aryStage[py][px] == '0' || aryStage[py][px] == '5' || aryStage[py][px] == '6')
			if (item) {
				if (aryStage[py][px] == '0') {
					isJumping = false;
				}
				else {
					item = false;
					// ����������� �����ڸ��� ������  (���� or �Ѿ�)
				}
				py++;
			}
			else {
				if (aryStage[py][px] == '0') {
					isJumping = false;
					py++;
				}
				else {
					tempStage[py][px] = '1';  //������ ������� ���ھ� �ö� (�� ���� ���ھ�) 
				}
			}

		if (aryStage[py + 1][px] == '0') {  //���� �� ���� �����̶�� ���� ��
			isBottom = false;
		}
		if (py <= 6) {
			isJumping = false;
		}
		//Sleep(200);
		Sleep(20);
		Stage(aryStage);
		printf("%d", py);

	}
	Go = false;
	item = true;
}

