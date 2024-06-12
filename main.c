#include <stdio.h>
#include <stdlib.h>	//rand()
#include <time.h>	//time()
//============================
//キャラクター構造体
//============================
typedef struct
{
	char name[10];	//名前
	int hp;			//ヒットポイント
	int str;		//攻撃力
	int damage;		//ダメージ結果
	int befHP;		//ダメージ前HP記録
}CHARACTER;
//============================
// 　　　システム
//============================
//ステータスを表示関数
void Character_Info(CHARACTER* chara)
{
	printf("%sのステータス HP = %d 攻撃力 = %d\n", chara->name, chara->hp, chara->str);
	printf("\n");
}
void Game_End(CHARACTER* winner)
{
	printf("===========================\n");
	printf("%sの勝利\n", winner->name);
	printf("===========================\n");
}
//============================
// 　　アタックシステム
//============================
void Game_Damage_Get(CHARACTER* attacker, CHARACTER* deffender)
{
	int strrand = rand() % 20 - 10;
	int damage = attacker->str + strrand;
	deffender->befHP = deffender->hp;
	printf("%sの攻撃 HP: %d\n", attacker->name, attacker->hp);

	if (damage > 0) {
		deffender->hp -= damage;
		printf("%dダメージ  || %d -> %d\n\n", damage, /*deffender->name,*/ deffender->befHP, deffender->hp);
	}
	else
	{
		printf("ミス\n\n");
	}
}
void main()
{
	CHARACTER charaA = { "キャラ1" , 100, 10 };
	CHARACTER charaB = { "キャラ2" , 200, 5 };

	srand((unsigned int)time(NULL)); //RESET
	Character_Info(&charaA);
	Character_Info(&charaB);

	while (1)
	{
		Game_Damage_Get(&charaA, &charaB);
		Game_Damage_Get(&charaB, &charaA);

		if (charaA.hp <= 0) {
			Game_End(charaB.name);
			break;
		}
		else if (charaB.hp <= 0) {
			Game_End(charaA.name);
			break;
		}
	}
}
