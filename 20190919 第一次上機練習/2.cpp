/*
�m�߼��g�@�Ӧ@���{���A�p��C�Ѷ}�����O�ΡA�M����p�ǥѦ@���i�٤U�h
�ֿ��C�o�����ε{���i�H��J�U�C��T�C(1) �C�Ѧ�p���{�F(2) �C�[�ڨT
�o������F(3) �C�[�ڨT�o��p���{�ơF(4) �C�Ѫ������O�F(5)�C�Ѫ��L��
�O�F(6)�@���H�ơC
�п�X(1) �`�O�ΡF(2) �@���C�ӤH�һݪ��O�ΡC
*/

#include <stdio.h>

int main() {
	int km = 0, price = 0, pkm = 0, stop = 0, road = 0, people;
	// scan
	printf("�C�Ѧ�p���{�G");
	scanf("%d", &km);
	printf("�C�[�ڨT�o������G");
	scanf("%d", &price);
	printf("�C�[�ڨT�o��p���{�ơG");
	scanf("%d", &pkm);
	printf("�C�Ѫ������O�G");
	scanf("%d", &stop);
	printf("�C�Ѫ��L���O�G");
	scanf("%d", &road);
	printf("�@���H�ơG");
	scanf("%d", &people);
	// show ans
	int sum = (km / pkm * price) + stop + road;
	printf("�`�O�ΡG%d\n", sum);
	printf("�@���C�ӤH�һݪ��O�ΡG%d\n", sum / people);
	return 0;
}

