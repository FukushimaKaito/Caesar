#include <stdio.h>

/*�֐��v���g�^�C�v�錾*/
void Angou(void);
void fukugou(void);

#define N 1000//���͍ő啶����

char in[N];
char out[N];

int main(void) {

	char c;
	printf("This program is Caesar Cipher�D\n\n");
	printf("�Í��쐬�̂Ƃ���0��\n�Í���ǂ̂Ƃ���1��\n�I������Ƃ���2��\n���͂��Ă��������F");
	while (1){
		c = getch();//ENTER�Ȃ��Ŕ��肷��D
		printf("%c\n", c);
		if (c == '0') {
			Angou();
			printf("\n\n�Í��쐬�̂Ƃ���0��\n�Í���ǂ̂Ƃ���1��\n�I������Ƃ���2��\n���͂��Ă��������F");
		}
		else if (c == '1') {
			fukugou();
			printf("\n\n�Í��쐬�̂Ƃ���0��\n�Í���ǂ̂Ƃ���1��\n�I������Ƃ���2��\n���͂��Ă��������F");
		}
		else if (c == '2'){
			printf("����I��");
			return 0;
		}
		else {
			printf("\n\n�Í��쐬�̂Ƃ���0��\n�Í���ǂ̂Ƃ���1��\n�I������Ƃ���2��\n���͂��Ă��������F");
		}
	}
}

void Angou(void){
	int i = 0, leng;
	printf("\n���������͂��Ă��������F");

	while (1) {
		in[i] = getch();
		printf("%c", in[i]);
		if (in[i] == 0x0d) {//ENTER
			printf("\n");
			leng = i;//�������L��
			break;
		}
		else if ((0x21 <= in[i] && in[i] <= 0x7e)||in[i] == 0x08){//����R�[�h�ȊO(�A���t�@�x�b�g�E�}�`�E����)
			out[i] = in[i] + 3;
			i++;
			if (in[i] == 0x08)//�o�b�N�X�y�[�X�����O
			{
				i--;
				out[i] = '\0';
			}
		}
		else
		{
			perror("���̕����͔�Ή��ł��D\n");
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
	printf("���������͂��Ă��������F");
	while (1) {
		in[i] = getch();
		printf("%c", in[i]);
		if (in[i] == 0x0d || in[i] == 0x0a) {//16�i(0x)���s�R�[�h
			printf("\n");
			leng = i;
			break;
		}
		else if ((0x21<=in[i] && in[i] <= 0x7e)||in[i] == 0x08){//����R�[�h�ȊO(�A���t�@�x�b�g�E�}�`�E����)
			out[i] = in[i] - 3;
			i++;
			if (in[i] == 0x08)//�o�b�N�X�y�[�X�����O
			{
				i--;
				out[i] = '\0';
			}
		}
		else {
			perror("���̕����͔�Ή��ł��D\n");

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