#include <stdio.h>
#include <string.h>

struct private_data{ //①
    char blood;
    char area[5];
    int old, exp, wage;
};

int main(){
    struct private_data Adata, Bdata; //②
    int input;
    int same;

    /*③A君の既定データの代入*/
    Adata.blood = 'A';
    strcpy(Adata.area, "長野");
    Adata.old = 21;
    Adata.exp = 15;
    Adata.wage = 800;

    /*③B君の既定データの代入*/
    Bdata.blood = 'B';
    strcpy(Bdata.area, "長野");
    Bdata.old = 22;
    Bdata.exp = 12;
    Bdata.wage = 800;

    /*質問の表示と選択結果の入力*/
    printf("何で比較しますか？\n");
    printf("1:血液型 2:出身地 3:年齢 4:アルバイト経験 5:時給\n");
    scanf("%d", &input);
    same = 0;

    /*判定と結果表示*/
    switch(input){
    case 1:if(Adata.blood == Bdata.blood) same = 1;
        break;
    case 2:if(strcmp(Adata.area, Bdata.area) == 0) same = 1;
        break;
    case 3:if(Adata.old == Bdata.old) same = 1;
        break;
    case 4:if(Adata.exp == Bdata.exp) same = 1;
        break;
    case 5:if(Adata.wage == Bdata.wage) same = 1;
        break;
    default:printf("そんな項目番号はありません\n"); same = 2;
        break;
    }

    if(same == 0){
        printf("二人は違います\n");
    }else{
        if(same == 1){
            printf("二人は同じです\n");
        }
    }
    return(0); 
}
