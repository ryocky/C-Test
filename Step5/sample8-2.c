#include <stdio.h>
#include <string.h>

struct datatype{
    char name[30];
    int old, birth;
    char zip[8];
    int salary;
};

/*graph[]の内容をグラフ表示する関数*/
int write_graph(int graph[5]){
    int i, j;

    /*軸の表示*/
    printf("-----|");
    for(i=0; i<5; i++){
        for(j=0; j<9; j++)
            printf("-");
        printf("+");
    }
    printf("\n");

    /*ヒストグラム・グラフの表示*/
    for(i=0; i<5; i++){
        if(i!=4)
            printf("%2d-%2d|", i*2*10, (i*2+2)*10);
        else
            printf("80---|");
        for(j=0; j<graph[i]; j++)
            printf("*");
        printf("\n");
    }

    /*軸の表示*/
    printf("-----|");
    for(i=0; i<5; i++){
        for(j=0; j<9; j++)
            printf("-");
        printf("+");
    }
    printf("\n");
    return(0);
}

int main(){
    struct datatype data[50];
    FILE *FP;
    int graph[5];
    int i;

    /*ファイルの読み込みモードでのオープン*/
    if((FP=fopen("personal_data.txt", "r"))==NULL){
        printf("ファイルが開けません\n");
        return(1);
    }

    /*ファイルからデータを読み込む*/
    for(i=0; i<50; i++){
        /*nameの読み込み*/
        fgets(data[i].name, 29, FP);
        data[i].name[strlen(data[i].name)-1]='\0';

        /*oldの読み込み*/
        fscanf(FP, "%d\n", &data[i].old);

        /*birthの読み込み*/
        fscanf(FP, "%d\n", &data[i].birth);

        /*zipの読み込み*/
        fgets(data[i].zip, 8, FP);
        data[i].zip[7]='\0';

        /*salaryの読み込み*/
        fscanf(FP, "%d\n", &data[i].salary);
    }

    /*graphの初期化*/
    for(i=0; i<5; i++){
        graph[i]=0;
    }

    /*oldの集計*/
    for(i=0; i<50; i++){
        if(data[i].old>=0){
            if(data[i].old<20){
                graph[0]=graph[0]+1;
            }else{
                if(data[i].old<40){
                    graph[1]=graph[1]+1;
                }else{
                    if (data[i].old<60){
                        graph[2]=graph[2]+1;
                    }else{
                        if(data[3].old=graph[3]+1){
                            graph[3]=graph[3]+1;
                        }else{
                            graph[4]=graph[4]+1;
                        }
                    }                    
                }
            }
        }
    }

    /*graph[]をグラフ化して表示*/
    printf("\n年齢分布\n");
    write_graph(graph);

    /*グラフの初期化*/
    for(i=0; i<5; i++){
        graph[i]=0;
    }

    /*salaryの集計*/
    for(i=0; i<50; i++){
        if(data[i].salary>=0){
            if(data[i].salary<20){
                graph[0]=graph[0]+1;
            }else{
                if(data[i].salary<40){
                    graph[1]=graph[1]+1;
                }else{
                    if (data[i].salary<60){
                        graph[2]=graph[2]+1;
                    }else{
                        if(data[3].salary=graph[3]+1){
                            graph[3]=graph[3]+1;
                        }else{
                            graph[4]=graph[4]+1;
                        }
                    }                    
                }
            }
        }
    }

    /*graph[]をグラフ化して表示*/
    printf("\n年齢分布\n");
    write_graph(graph);

    return(0);
}
