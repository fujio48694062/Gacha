#include <stdio.h>
#include <stdlib.h> // 乱数生成
#include <time.h> // 乱数生成
#define BUFFER_SIZE 1000

int main()
{
	int gatya[BUFFER_SIZE]; // 配列（領域数）の宣言
	int num_gatya = 0; // ガチャの回数
	int random = 0; // 乱数
	int num_SSR = 0;// SSRの数
	int num_SR = 0; // SRの数
	int num_R = 0; // Rの数
	float per_SSR = 0;// SSRの割合
	float per_SR = 0;// SRの割合
	float per_R = 0;// Rの割合


	// ガチャの排出率
	printf("ガチャの排出率\n");
	printf("SSR： 3%%\n");
	printf(" SR：17%%\n");
	printf("  R：80%%\n\n");

	// ガチャの回数
	printf("何連引きますか？（単発～100連）\n");
	scanf_s("%d", &num_gatya);

	printf("\n\n☆ガチャ（%d連）\n", num_gatya);


	// 乱数の初期化
	srand((unsigned int)time(NULL));

	// 乱数
	for (int i = 0; i < num_gatya; i++)
	{
		gatya[i] = rand() % 100 + 1;
		// 乱数（rand()） / 母数（whole） = 余り（0～99）
		// 乱数（rand()） / 母数（whole） +1 = 余り（1～100）
		random = gatya[i];
		/* printf("%d ", random); */
	}


	// 結果
	for (int i = 0; i < num_gatya; i++)
	{
		if ((gatya[i] >= 1) && (gatya[i] < 4)) // SSRは3%（1～3）で排出
		{
			printf("SSR ");
			num_SSR++;
		}
		else if ((gatya[i] >= 4) && (gatya[i] < 21)) // SRは17%（4～20）で排出
		{
			printf("SR ");
			num_SR++;
		}
		else // Rは80%（21～100）で排出
		{
			printf("R ");
			num_R++;
		}
	}

	// 集計
	per_SSR = (num_SSR / (float)num_gatya) * 100;
	per_SR = (num_SR / (float)num_gatya) * 100;
	per_R = (num_R / (float)num_gatya) * 100;

	printf("\n\n");
	printf("SSR：%d個（%.1f%%）\n", num_SSR, per_SSR);
	printf(" SR：%d個（%.1f%%）\n", num_SR, per_SR);
	printf("  R：%d個（%.1f%%）\n", num_R, per_R);

	return 0;
}