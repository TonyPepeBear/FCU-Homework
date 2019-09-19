/*
練習撰寫一個共乘程式，計算每天開車的費用，然後估計藉由共乘可省下多
少錢。這個應用程式可以輸入下列資訊。(1) 每天行駛里程；(2) 每加侖汽
油的價格；(3) 每加侖汽油行駛里程數；(4) 每天的停車費；(5)每天的過路
費；(6)共乘人數。
請輸出(1) 總費用；(2) 共乘每個人所需的費用。
*/

#include <stdio.h>

int main() {
	int km = 0, price = 0, pkm = 0, stop = 0, road = 0, people;
	// scan
	printf("每天行駛里程：");
	scanf("%d", &km);
	printf("每加侖汽油的價格：");
	scanf("%d", &price);
	printf("每加侖汽油行駛里程數：");
	scanf("%d", &pkm);
	printf("每天的停車費：");
	scanf("%d", &stop);
	printf("每天的過路費：");
	scanf("%d", &road);
	printf("共乘人數：");
	scanf("%d", &people);
	// show ans
	int sum = (km / pkm * price) + stop + road;
	printf("總費用：%d\n", sum);
	printf("共乘每個人所需的費用：%d\n", sum / people);
	return 0;
}

