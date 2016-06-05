#include <stdio.h>

/*関数プロトタイプ宣言*/
void Angou(void);
void fukugou(void);

#define N 1000//入力最大文字数

char in[N];
char out[N];

int main(void) {

	char c;
	printf("This program is Caesar Cipher．\n\n");
	printf("暗号作成のときは0を\n暗号解読のときは1を\n終了するときは2を\n入力してください：");
	while (1){
		c = getch();//ENTERなしで判定する．
		printf("%c\n", c);
		if (c == '0') {
			Angou();
			printf("\n\n暗号作成のときは0を\n暗号解読のときは1を\n終了するときは2を\n入力してください：");
		}
		else if (c == '1') {
			fukugou();
			printf("\n\n暗号作成のときは0を\n暗号解読のときは1を\n終了するときは2を\n入力してください：");
		}
		else if (c == '2'){
			printf("正常終了");
			return 0;
		}
		else {
			printf("\n\n暗号作成のときは0を\n暗号解読のときは1を\n終了するときは2を\n入力してください：");
		}
	}
}

void Angou(void){
	int i = 0, leng;
	printf("\n文字列を入力してください：");

	while (1) {
		in[i] = getch();
		printf("%c", in[i]);
		if (in[i] == 0x0d) {//ENTER
			printf("\n");
			leng = i;//文字数記憶
			break;
		}
		else if ((0x21 <= in[i] && in[i] <= 0x7e)||in[i] == 0x08){//制御コード以外(アルファベット・図形・数字)
			out[i] = in[i] + 3;
			i++;
			if (in[i] == 0x08)//バックスペースを除外
			{
				i--;
				out[i] = '\0';
			}
		}
		else
		{
			perror("この文字は非対応です．\n");
		}
	}
	printf("\nin\n");
	for (int i = 0; i < leng; i++)
	{
		printf("%c", in[i]);
	}
	printf("\nout\n");
	for (int i = leng; i > 0; i--)
	{
		printf("%c", out[leng - i]);
	}
}

void fukugou(void){
	int i = 0, leng;
	printf("文字列を入力してください：");
	while (1) {
		in[i] = getch();
		printf("%c", in[i]);
		if (in[i] == 0x0d || in[i] == 0x0a) {//16進(0x)改行コード
			printf("\n");
			leng = i;
			break;
		}
		else if ((0x21<=in[i] && in[i] <= 0x7e)||in[i] == 0x08){//制御コード以外(アルファベット・図形・数字)
			out[i] = in[i] - 3;
			i++;
			if (in[i] == 0x08)//バックスペースを除外
			{
				i--;
				out[i] = '\0';
			}
		}
		else {
			perror("この文字は非対応です．\n");

		}
	}
	printf("\nin\n");
	for (int i = 0; i < leng; i++)
	{
		printf("%c", in[i]);
	}
	printf("\nout\n");
	for (int i = leng; i > 0; i--)
	{
		printf("%c", out[leng - i]);
	}
}