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
