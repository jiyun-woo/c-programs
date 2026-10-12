//Form.C
#include "Form.h"
#include "wordBook.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int agrc, char * argv[]){
    WordBook wordBook = {
        { {"","","",""},
            {"","","",""},
            {"","","",""},
            {"","","",""},
            {"","","",""},
            {"","","",""},
            {"","","",""},
            {"","","",""},
            {"","","",""},
            {"","","",""}},
        MAX, 0
    };
    int menu;
    Long count;
    
    count = Load(&wordBook);
    DisplayMainMenu();
    rewind(stdin);
    scanf("%d", &menu);
    
    while (menu != 0){
        switch (menu){
            case 1: FormForRecording(&wordBook);
                break;
            case 2: FormForFinding(&wordBook);
                break;
            case 3: FormForCorrecting(&wordBook);
                break;
            case 4: FormForErasing(&wordBook);
                break;
            case 5: FormForArranging(&wordBook);
                break;
            case 6: FormForSavingAll(&wordBook);
                break;
            default :
                break;
        }
        DisplayMainMenu();
        rewind(stdin);
        scanf("%d", &menu);
    }
    Save(&wordBook);
    return 0;
    
}

void DisplayMainMenu(void){
    system("clear");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t단어장 Version 0.05\n");
    printf("\t\t\t==============================\n");
    printf("\t\t\t[1]기재하기\n");
    printf("\t\t\t[2]찾    기\n");
    printf("\t\t\t[3]고 치 기\n");
    printf("\t\t\t[4]지 우 기\n");
    printf("\t\t\t[5]정리하기\n");
    printf("\t\t\t[6]전체보기\n");
    printf("\t\t\t[0]끝 내 기\n");
    printf("\t\t\t------------------------------\n");
    printf("\t\t\t메뉴를 선택하십시오:");
}

void FormForRecording(WordBook *wordBook){
    char spelling[64];
    char partOfSpeech[16];
    char meaning[64];
    char exampleSentence[128];
    char going = 'Y';
    char recording;
    Long index;
    Long number;
    
    while (going == 'Y'|| going == 'y'){
        system("clear");
        printf("\n\n\n");
        printf("단어장 Version 0.05 - 기재하기\n");
        printf("==================================================================================\n");
        printf("철  자 :"); rewind(stdin); scanf("%s", spelling);getchar();
        printf("----------------------------------------------------------------------------------\n"); //50+15+7
        printf("1.명  사\t 2.대명사\t 3.동  사\t 4.형용사\n");
        printf("5.부  사\t 6.전치사\t 7.감탄사\t 8.접속사\n");
        printf("----------------------------------------------------------------------------------\n");
        
        printf("품  사 :"); rewind(stdin); scanf("%ld", &number);getchar();
        switch (number){
            case 1: strcpy(partOfSpeech, "명사");
                break;
            case 2: strcpy(partOfSpeech, "대명사");
                break;
            case 3: strcpy(partOfSpeech, "동사");
                break;
            case 4: strcpy(partOfSpeech, "형용사");
                break;
            case 5: strcpy(partOfSpeech, "부사");
                break;
            case 6: strcpy(partOfSpeech, "전치사");
                break;
            case 7: strcpy(partOfSpeech, "감탄사");
                break;
            case 8: strcpy(partOfSpeech, "접속사");
                break;
            default:
                break;
        }
        printf("  뜻   :"); rewind(stdin); scanf("%s", meaning);getchar();
        printf("예  문 :"); rewind(stdin); gets(exampleSentence);
        printf("----------------------------------------------------------------------------------\n");
        printf("기재하시겠습니까?(Yes/No):");
        rewind(stdin); recording = getchar();getchar();
        
        if (recording == 'Y'|| recording == 'y'){
            printf("\n===== 디버깅.. =====\n");
            printf("spelling = %s\n", spelling);
            printf("partOfSpeech = %s\n", partOfSpeech);
            printf("meaning = %s\n", meaning);
            printf("example = %s\n", exampleSentence);
            printf("=================\n");
            index = Record(wordBook, spelling, partOfSpeech, meaning, exampleSentence);
            printf("==================================================================================\n");
            printf("번호  철자              품사        뜻          예문                            \n");
            printf("----------------------------------------------------------------------------------\n");
            printf("%-5ld %-18s %-13s %-15s %s\n", index+1, wordBook -> words[index].spelling,
                   wordBook -> words[index].partOfSpeech, wordBook -> words[index].meaning, wordBook -> words[index].exampleSentence);
        }
        printf("==================================================================================\n");
        printf("계속 하시겠습니까? (Yes/No): ");
        rewind(stdin); going = getchar();getchar();
    }
}

void FormForFinding(WordBook *wordBook){
    int menu;
    
    DisplaySubMenu();
    rewind(stdin);
    scanf("%d", &menu);
    
    while(menu != 0){
        switch (menu) {
            case 1: FormForFindingByMeaning(wordBook);
                break;
            case 2: FormForFindingBySpelling(wordBook);
                break;
            default:
                break;
        }
        DisplaySubMenu();
        rewind(stdin);
        scanf("%d", &menu);
    }
}

void DisplaySubMenu(void){
    system("clear");
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t단어장 Version 0.05 - 찾    기\n");
    printf("\t\t\t==============================\n");
    printf("\t\t\t[1]뜻으로 찾기\n");
    printf("\t\t\t[2]철자로 찾기\n");
    printf("\t\t\t[0]상 위 메 뉴\n");
    printf("\t\t\t------------------------------\n");
    printf("\t\t\t메뉴를 선택하십시오:");
}


void FormForFindingByMeaning(WordBook *wordBook){
    char meaning[64];
    Long indexes[MAX];
    Long count;
    char going = 'Y';
    Long i;
    
    while (going =='Y'|| going =='y'){
        system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("단어장 Version 0.05 - 뜻으로 찾기\n");
        printf("========================================================================================\n");
        printf("  뜻 :"); rewind(stdin); scanf("%s", meaning);
        printf("========================================================================================\n");
        printf("번호  뜻          철자              품사        예문                            \n");
        printf("----------------------------------------------------------------------------------------\n");
        FindByMeaning(wordBook, meaning, indexes, &count);
        
        i = 0;
        while ( i < count){
            printf("%-5ld %-18s %-13s %-15s %s\n", i+1, wordBook -> words[indexes[i]].meaning,
                   wordBook -> words[indexes[i]].spelling, wordBook -> words[indexes[i]].partOfSpeech,wordBook -> words[indexes[i]].exampleSentence);
            i++;
        }
        printf("========================================================================================\n");
        printf("계속 하시겠습니까?(Yes/No):");
        rewind(stdin); going = getchar();getchar();
    }
}

void FormForFindingBySpelling(WordBook *wordBook){
    char spelling[64];
    Long indexes[MAX];
    Long count;
    char going = 'Y';
    Long i;
    
    while (going =='Y'|| going =='y'){
        system("clear");
        printf("\n\n\n\n\n\n\n");
        printf("단어장 Version 0.05 - 철자로 찾기\n");
        printf("========================================================================================\n");
        printf("철  자 :"); rewind(stdin); scanf("%s", spelling);
        printf("========================================================================================\n");
        printf("번호  철자              품사        뜻          예문                            \n");
        printf("----------------------------------------------------------------------------------------\n");
        FindBySpelling(wordBook, spelling, indexes, &count);
        
        i = 0;
        while ( i < count){
            printf("%-5ld %-18s %-13s %-15s %s\n", i+1, wordBook -> words[indexes[i]].spelling,
                   wordBook -> words[indexes[i]].partOfSpeech, wordBook -> words[indexes[i]].meaning, wordBook -> words[indexes[i]].exampleSentence);
            i++;
        }
        printf("========================================================================================\n");
        printf("계속 하시겠습니까?(Yes/No):");
        rewind(stdin); going = getchar();getchar();
    }
}

void FormForCorrecting(WordBook *wordBook){
    char spelling[64];
    char meaning[64];
    char exampleSentence[128];
    Long indexes[MAX];
    Long count;
    Long index;
    Long number;
    char going = 'Y';
    char correcting;
    Long i;
    
    while (going =='Y'|| going =='y'){
        system("clear");
        printf("\n");
        printf("단어장 Version 0.05 - 고 치 기\n");
        printf("========================================================================================\n");
        printf("철  자 :"); rewind(stdin); scanf("%s", spelling);getchar();
        printf("========================================================================================\n");
        printf("번호  철자              품사        뜻          예문                            \n");
        printf("----------------------------------------------------------------------------------------\n");
        FindBySpelling(wordBook, spelling, indexes, &count);
        
        i = 0;
        while (i < count){
            printf("%-5ld %-18s %-13s %-15s %s\n", i+1, wordBook -> words[indexes[i]].spelling,
                   wordBook -> words[indexes[i]].partOfSpeech, wordBook -> words[indexes[i]].meaning,wordBook -> words[indexes[i]].exampleSentence);
            i++;
        }
        
        if (count > 0){
            printf("========================================================================================\n");
            printf("번  호 :"); rewind(stdin); scanf("%ld", &number);
            index = indexes[number-1];
            printf("========================================================================================\n");
            printf("  뜻   :%s", wordBook -> words[index].meaning);
            rewind(stdin); gets(meaning);
            
            if (strcmp(meaning,"")==0){
                strcpy(meaning, wordBook -> words[index].meaning);
            }

            printf("예  문 :%s", wordBook -> words[index].exampleSentence);
            rewind(stdin); gets(exampleSentence);
            
            if (strcmp(exampleSentence,"")==0){
                strcpy(exampleSentence, wordBook -> words[index].exampleSentence);
            }
            printf("========================================================================================\n");
            printf("고치시겠습니까?(Yes/No):");
            rewind(stdin); correcting = getchar();getchar();
            
            if (correcting == 'Y'|| correcting == 'y'){
                index = Correct(wordBook, index, meaning, exampleSentence);
                printf("========================================================================================\n");
                printf("번호  철자              품사        뜻          예문                            \n");
                printf("----------------------------------------------------------------------------------------\n");
                printf("%-5ld %-18s %-13s %-15s %s\n", index+1, wordBook -> words[index].spelling, wordBook -> words[index].partOfSpeech, wordBook -> words[index].meaning, wordBook -> words[index].exampleSentence);
            }
        }
        printf("========================================================================================\n");
        printf("계속 하시겠습니까?(Yes/No):");
        rewind(stdin); going = getchar();getchar();
    }
}

void FormForErasing(WordBook *wordBook){
    char spelling[64];
    Long index;
    Long indexes[MAX];
    Long number;
    Long count;
    Long i;
    char erasing;
    char going = 'Y';
    
    while (going == 'Y'|| going =='y'){
        system("clear");
        printf("\n\n");
        printf("단어장 Version 0.05 - 지 우 기\n");
        printf("========================================================================================\n");
        printf("철  자 :"); rewind(stdin); scanf("%s", spelling);
        printf("========================================================================================\n");
        printf("번호  철자              품사        뜻          예문                            \n");
        printf("----------------------------------------------------------------------------------------\n");
        
        FindBySpelling(wordBook, spelling, indexes, &count);
        
        i = 0;
        while ( i < count){
            printf("%-5ld %-18s %-13s %-15s %s\n", i+1, wordBook -> words[indexes[i]].spelling, wordBook -> words[indexes[i]].partOfSpeech,
                   wordBook -> words[indexes[i]].meaning, wordBook -> words[indexes[i]].exampleSentence);
            i++;
        }
        
        if (count > 0){
            printf("========================================================================================\n");
            printf("번  호 :"); rewind(stdin); scanf("%ld", &number);
            index = indexes[number-1];
            printf("========================================================================================\n");
            printf("번호  철자              품사        뜻          예문                            \n");
            printf("----------------------------------------------------------------------------------------\n");
            
            printf("%-5ld %-18s %-13s %-15s %s\n", index+1, wordBook -> words[index].spelling, wordBook -> words[index].partOfSpeech, wordBook -> words[index].meaning, wordBook -> words[index].exampleSentence);
            printf("========================================================================================\n");
            printf("지우시겠습니까?(Yes/No):");
            rewind(stdin); erasing = getchar();getchar();
            
            if (erasing == 'Y' || erasing == 'y'){
                printf("지우기 시작\n");
                index = Erase(wordBook, index);
                printf("----------------------------------\n");
                printf("지워졌습니다.\n");
            }
        }
        printf("========================================================================================\n");
        printf("계속 하시겠습니까?(Yes/No):");
        rewind(stdin); going = getchar();getchar();
    }
}

void FormForArranging(WordBook *wordBook){
    Long i=0;
    Long count;
    
    Arrange(wordBook);
    while (i < wordBook -> length){
        system("clear");
        printf("\n\n\n\n");
        printf("단어장 Version 0.05 - 정리하기\n");
        printf("========================================================================================\n");
        printf("번호  철자              품사        뜻          예문                            \n");
        printf("----------------------------------------------------------------------------------------\n");
        
        count = 1;
        while (i < wordBook -> length && count <= MAX){
            printf("%-5ld %-18s %-13s %-15s %s\n",i+1, wordBook -> words[i].spelling, wordBook -> words[i].partOfSpeech, wordBook -> words[i].meaning, wordBook -> words[i].exampleSentence);
            i++;
            count++;
        }
        printf("========================================================================================\n");
        printf("아무 키나 누르세요!");
        rewind(stdin); getchar();getchar();
    }
}

void FormForSavingAll(WordBook *wordBook){
    Long i=0;
    Long count;
    

    while (i < wordBook -> length){
        system("clear");
        printf("\n\n\n\n");
        printf("단어장 Version 0.05 - 전체보기\n");
        printf("========================================================================================\n");
        printf("번호  철자              품사         뜻          예문                            \n");
        printf("----------------------------------------------------------------------------------------\n");
        
        count = 1;
        while ( i < wordBook -> length && count <= MAX){
            printf("%-5ld %-18s %-13s %-15s %s\n",i+1, wordBook -> words[i].spelling, wordBook -> words[i].partOfSpeech, wordBook -> words[i].meaning, wordBook -> words[i].exampleSentence);
            i++;
            count++;
        }
        printf("========================================================================================\n");
        printf("아무 키나 누르세요!");
        rewind(stdin); getchar();getchar();
    }
}
