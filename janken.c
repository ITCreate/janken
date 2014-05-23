#include <stdio.h>

#define G	84			// 001 010 100
#define C	161			// 010 100 001
#define P	266			// 100 001 010
#define MASK 448	//ビット演算用 111 000 000
#define HE 	"彼氏"
#define SHE "彼女"

int choice(int input, short * p){
	switch(input){
		case 1:
			*p = G; break;
		case 2:
			*p = C; break;
		case 3:
			*p = P;	break;
		default:
			return 0;
	}
	return 1;
}

int main(void){
	short input, turn = 0;
	unsigned short he, she;
	puts("じゃんけんゲーッム!!\n 1 = グー, 2 = チョキ, 3 = パー");
	while(1){
		printf("%sの手は:", !turn ? HE : SHE);	
		scanf("%d", &input);
		if(!turn){
			if(choice(input, &he)){
				turn++;
			}
			continue;
		}else{
			if(choice(input, &she)){
					break;
			}
		}
	}
	if(she == he){
		puts("あいこです。");
	}else{
		he = (he << 6) & MASK;
		she = she & MASK;
		if(he != she){
			puts("勝ちました。");
		}else{
			puts("負けました。");
		}
	}
	return 0;
}
