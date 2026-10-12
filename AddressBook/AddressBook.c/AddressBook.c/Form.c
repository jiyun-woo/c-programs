#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Form.h"
#include "addressBook.h"

#define COUNT 10

int main (int argc, char * argv[]){
    AddressBook addressBook =
    { {{"","","",""},
        {"","","",""},
        {"","","",""},
        {"","","",""},
        {"","","",""},
        {"","","",""}},
        MAX, 0
    };
    int menu;

    Load(&addressBook);
    DisplayMenu();
    rewind(stdin);
    scanf("%d", &menu);
    
    while (menu != 0) {
        switch (menu){
            case 1: FormForRecording(&addressBook);
                break;
            case 2: FormForFinding(&addressBook);
                break;
            case 3: FormForCorrecting(&addressBook);
                break;
            case 4: FormForErasing(&addressBook);
                break;
            case 5: FormForArranging(&addressBook);
                break;
            case 6: FormForSaving(&addressBook);
                break;
            default : break ;
        }
        
        DisplayMenu();
        rewind(stdin);
        scanf("%d", &menu);
    }
    Save(&addressBook);
    
    return 0;
}
    
void DisplayMenu(void){
    
    system("clear");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t주소록 Version 0.05\n");
    printf("\t\t\t==============================\n");
    printf("\t\t\t[1] 기재하기\n");
    printf("\t\t\t[2] 찾    기\n");
    printf("\t\t\t[3] 고 치 기\n");
    printf("\t\t\t[4] 지 우 기\n");
    printf("\t\t\t[5] 정리하기\n");
    printf("\t\t\t[6] 전체보기\n");
    printf("\t\t\t[0] 끝 내 기\n");
    printf("\t\t\t------------------------------\n");
    printf("\t\t\t메뉴를 선택하세요 : ");
}

void FormForRecording(AddressBook *addressBook){
    char name[16];
    char address[64];
    char telephoneNumber[12];
    char emailAddress[64];
    char recording;
    char going = 'Y';
    Long index;
    
    while (going == 'Y'|| going == 'y'){
        system("clear");
        printf("\n\n\n\n\n");
        printf("\t주소록 Version 0.05 - 기재하기\n");
        printf("\t=================================================================\n");
        
        printf("\t성      명 :"); rewind(stdin); scanf("%s", name); getchar(); //scanf 이후 뒤로 밀려 gets가 안먹힘
        
        printf("\t주      소 :"); rewind(stdin); gets(address);
        
        printf("\t전화  번호 :"); rewind(stdin); scanf("%s", telephoneNumber); getchar();
        
        printf("\t이메일주소 :"); rewind(stdin); scanf("%s", emailAddress); getchar();
        
        printf("\t------------------------------------------------------------------\n");
        printf("\t기재하시겠습니까? (Yes/No): "); rewind(stdin); recording = getchar(); getchar();//enter 제거
        
        printf("\n");
        if (recording == 'Y' || recording == 'y'){
            index = Record(addressBook, name, address, telephoneNumber, emailAddress);
            
            if (index != -1){
                printf("\t==================================================================\n");
                printf("\t번호     성명    주소         전화 번호        이메일 주소            \n");
                printf("\t------------------------------------------------------------------\n");
                printf("\t%ld\t%s\t%s\t%s\t%s\n", index+1, addressBook -> personals[index].name,
                       addressBook -> personals[index].address, addressBook -> personals[index].telephoneNumber,addressBook -> personals[index].emailAddress);
            }
            else {
                printf("\t주소록이 가득 찼습니다.\n");
            }
        }
        printf("\t==================================================================\n");
        printf("\t계속 하시겠습니까?(Yes/No): ");
        rewind(stdin); going = getchar(); getchar();
    }
}

void FormForFinding(AddressBook *addressBook){
    char name[16];
    Long indexes [MAX];
    Long count;
    char going = 'Y';
    Long i;
    
    while (going =='Y' || going =='y'){
        system("clear");
        printf("\n\n\n\n\n");
        printf("\t주소록 Version 0.05 - 찾   기\n");
        printf("\t==================================================================\n");
        printf("\t성      명 :"); rewind(stdin); scanf("%s", name); getchar();
        printf("\t==================================================================\n");
        printf("\t번호    성명    주소         전화 번호        이메일 주소            \n");
        printf("\t------------------------------------------------------------------\n");
        
        Find(addressBook, name, indexes, &count);
        
        i=0;
        while ( i < count){
            printf("\t%ld\t%s\t%s\t%s\t%s\n", i+1, addressBook -> personals[indexes[i]].name,
                   addressBook -> personals[indexes[i]].address, addressBook -> personals[indexes[i]].telephoneNumber,addressBook -> personals[indexes[i]].emailAddress);
            i++;
        }
        printf("\t===================================================================\n");
        printf("\t계속 하시겠습니까? (Yes/No): ");
        rewind(stdin); going = getchar(); getchar();
    }
}

void FormForCorrecting(AddressBook *addressBook){
    char name[16];
    char address[64];
    char telephoneNumber[12];
    char emailAddress[64];
    Long index;
    Long indexes[MAX];
    Long count;
    Long number;
    char correcting;
    char going = 'Y';
    Long i;
    
    while (going == 'Y'|| going == 'y'){
        system("clear");
        printf("\n\n\n\n\n");
        printf("\t주소록 Version 0.05 - 고 치 기\n");
        printf("\t==================================================================\n");
        printf("\t성      명 :"); rewind(stdin); scanf("%s", name);
        printf("\t==================================================================\n");
        printf("\t번호    성명    주소         전화 번호        이메일 주소            \n");
        printf("\t-------------------------------------------------------------------\n");
        
        Find(addressBook, name, indexes, &count);
        
        i=0;
        while ( i < count){
            printf("\t%ld\t%s\t%s\t%s\t%s\n", i+1, addressBook -> personals[indexes[i]].name,
                   addressBook -> personals[indexes[i]].address, addressBook -> personals[indexes[i]].telephoneNumber,addressBook -> personals[indexes[i]].emailAddress);
            i++;
        }

        if (count > 0){
            printf("\t==================================================================\n");
            printf("\t번      호:"); rewind(stdin); scanf("%ld", &number); getchar();
            index = indexes[number-1];
            printf("\t==================================================================\n");
            
            printf("\t주      소 : %s", addressBook -> personals[index].address);
            rewind(stdin); gets(address);
            if(strcmp(address,"")==0){
                strcpy(address, addressBook -> personals[index].address);
            }
            
            printf("\t전화  번호 : %s", addressBook -> personals[index].telephoneNumber);
            rewind(stdin); gets(telephoneNumber);
            if (strcmp(telephoneNumber,"")==0){
                strcpy(telephoneNumber, addressBook -> personals[index].telephoneNumber);
            }
            
            printf("\t이메일주소 : %s",addressBook -> personals[index].emailAddress);
            rewind(stdin); gets(emailAddress);
            if (strcmp(emailAddress,"")==0){
                strcpy(emailAddress, addressBook -> personals[index].emailAddress);
            }
            
            printf("\t==================================================================\n");
            printf("\t고치시겠습니까? (Yes/No): ");
            rewind(stdin); correcting = getchar(); getchar();
            
            if (correcting == 'Y' || correcting == 'y'){
                index = Correct(addressBook, index, address, telephoneNumber, emailAddress);
                
                printf("\t==================================================================\n");
                printf("\t번호    성명    주소         전화 번호        이메일 주소            \n");
                printf("\t------------------------------------------------------------------\n");
                printf("\t%ld\t%s\t%s\t%s\t%s\n", index+1, addressBook -> personals[index].name,
                       addressBook -> personals[index].address, addressBook -> personals[index].telephoneNumber,addressBook -> personals[index].emailAddress);
            }
        }
        printf("\t==================================================================\n");
        printf("\t계속 하시겠습니까? (Yes/No): ");
        rewind(stdin); going = getchar(); getchar();
    }
}

void FormForErasing(AddressBook *addressBook){
    char name[16];
    Long index;
    Long indexes[MAX];
    Long number;
    Long i;
    Long count;
    char erasing;
    char going = 'Y';
    
    while (going == 'Y'|| going == 'y'){
        system("clear");
        printf("\n\n\n\n\n");
        printf("\t주소록 Version 0.05 - 지 우 기\n");
        printf("\t==================================================================\n");
        printf("\t성      명 :"); rewind(stdin); scanf("%s", name);
        printf("\t==================================================================\n");
        printf("\t번호    성명    주소         전화 번호        이메일 주소            \n");
        printf("\t------------------------------------------------------------------\n");
        
        Find(addressBook, name, indexes, &count);
        
        i=0;
        while ( i < count){
            printf("\t%ld\t%s\t%s\t%s\t%s\n", i+1, addressBook -> personals[indexes[i]].name,
                   addressBook -> personals[indexes[i]].address, addressBook -> personals[indexes[i]].telephoneNumber,addressBook -> personals[indexes[i]].emailAddress);
            i++;
        }
        
        if (count > 0){
            printf("\t==================================================================\n");
            printf("\t번     호:"); rewind(stdin); scanf("%ld", &number); getchar();
            index = indexes[number-1];
            printf("\t==================================================================\n");
            printf("\t번호    성명    주소         전화 번호        이메일 주소            \n");
            printf("\t------------------------------------------------------------------\n");
            printf("\t%ld\t%s\t%s\t%s\t%s\n", index+1, addressBook -> personals[index].name,
                   addressBook -> personals[index].address, addressBook -> personals[index].telephoneNumber,addressBook -> personals[index].emailAddress);
            printf("\t=================================================================\n");
            printf("\t지우시겠습니까? (Yes/No):");
            rewind(stdin); erasing = getchar(); getchar();
            
            if (erasing =='Y' || erasing == 'y'){
                index = Erase(addressBook, index);
                printf("\t--------------------------------------------------------------------\n");
                printf("\t지워졌습니다.\n");
            }
        }
        printf("\t=================================================================\n");
        printf("\t계속 하시겠습니까? (Yes/No): ");
        rewind(stdin); going = getchar(); getchar();
    }
}

void FormForArranging(AddressBook *addressBook){
    Long i=0;
    Long count;
    
    Arrange(addressBook);
    while ( i < addressBook -> length){
        system("clear");
        printf("\n\n\n");
        printf("\t주소록 Version 0.05 - 정리하기\n");
        printf("\t==================================================================\n");
        printf("\t번호   성명    주소         전화 번호        이메일 주소            \n");
        printf("\t------------------------------------------------------------------\n");
        
        count = 1;
        while ( i < addressBook -> length && count <= COUNT){
            printf("\t%ld\t%s\t%s\t%s\t%s\n", i+1, addressBook -> personals[i].name,
                   addressBook -> personals[i].address, addressBook -> personals[i].telephoneNumber,addressBook -> personals[i].emailAddress);
            i++;
            count ++;
        }
        printf("\t==================================================================\n");
        printf("\t아무 키나 누르세요!");
        rewind(stdin); getchar(); getchar();
    }
}

void FormForSaving(AddressBook *addressBook){
    Long i=0;
    Long count;
    
    while ( i < addressBook -> length){
        system("clear");
        printf("\n\n\n");
        printf("\t주소록 Version 0.05 - 전체보기\n");
        printf("\t==================================================================\n");
        printf("\t번호   성명    주소         전화 번호        이메일 주소            \n");
        printf("\t------------------------------------------------------------------\n");
    
        count = 1;
        while ( i < addressBook -> length && count <= COUNT){
            printf("\t%ld\t%s\t%s\t%s\t%s\n", i+1, addressBook -> personals[i].name,
                   addressBook -> personals[i].address, addressBook -> personals[i].telephoneNumber,addressBook -> personals[i].emailAddress);
            i++;
            count ++;
        }
        printf("\t==================================================================\n");
        printf("\t아무 키나 누르세요!");
        rewind(stdin); getchar(); getchar();
    }
}


