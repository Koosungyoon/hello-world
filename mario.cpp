#include<stdio.h>
#include<windows.h>
#include<conio.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 

void titleDraw(void);
int keyControl(void);
void gotoxy(int, int);
int menuDraw(void);


int main(void)
{
	titleDraw();
	menuDraw();

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
	printf("\t��      ��  ��  ��  ��  ��      ��  ��\n");
	printf("\t����  ��  ��  ����  ����  ����\n");
	printf("\t    ��  ��  ��  ��      ��      ���\n");
	printf("\t����  ����  ��      ����  ��  ��\n");
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


