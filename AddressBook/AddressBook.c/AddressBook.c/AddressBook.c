#include <stdio.h>
#include<string.h>
#include "AddressBook.h"
#include "Form.h"

/*void DisplayMenu(void);
void FormForRecording(AddressBook *addressBook);
void FormForFinding(AddressBook *addressBook);
void FormForCorrecting(AddressBook *addressBook);
void FormForErasing(AddressBook *addressBook);
void FormForArranging(AddressBook *addressBook);
void FormForSavingAll(AddressBook *addressBook); */

/*int main(int argc, char *argv[]){
    
    AddressBook addressBook =
    { {{"","","",""},
        {"","","",""},
        {"","","",""},
        {"","","",""},
        {"","","",""},
        {"","","",""}},
        MAX, 0
    };
   //Long index;
    //Long indexes[MAX];
    //Long count;
    //Long i=0;
    
    
    int menu;

    Load(&addressBook);

    DisplayMenu();
    rewind(stdin);
    scanf("%d", &menu);
/
    while (menu != 0) {
        switch (menu) {
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
                
            case 6: FormForSavingAll(&addressBook);
                break;
                
            default: break;
        }
        
        DisplayMenu();
        rewind(stdin); scanf("%s",menu);
    }
    Save(&addressBook);
            
    return 0;
}
*/
    
    /*count = Load(&addressBook);
    while (i < count){
        printf("%s\t%s\t%s\t%s\n", addressBook.personals[i].name, addressBook.personals[i].address, addressBook.personals[i].telephoneNumber, addressBook.personals[i].emailAddress);
        i++;
    }
    printf("%lu개 불러오기 완료\n", count);
    printf("file open\n");
    printf("--------------------------------\n");
 

    index = Record(&addressBook, "양길동","서울시 서초동","010-1234-5678","hong@gmail.com");
    printf("%s\t%s\t%s\t%s\n", addressBook.personals[index].name, addressBook.personals[index].address,
           addressBook.personals[index].telephoneNumber, addressBook.personals[index].emailAddress);
    
    index = Record(&addressBook, "박길동","대전시 중구","010-4321-1234", "go@gmail.com");
    printf("%s\t%s\t%s\t%s\n", addressBook.personals[index].name, addressBook.personals[index].address,
           addressBook.personals[index].telephoneNumber, addressBook.personals[index].emailAddress);
    
    index = Record(&addressBook, "훙길동","대구시","010-3212-2132", "ddong@gmail.com");
    printf("%s\t%s\t%s\t%s\n", addressBook.personals[index].name, addressBook.personals[index].address,
           addressBook.personals[index].telephoneNumber, addressBook.personals[index].emailAddress);
    
    index = Record(&addressBook, "후길동","부산시 해운대구","010-8887-7778", "honghong@gmail.com");
    printf("%s\t%s\t%s\t%s\n", addressBook.personals[index].name, addressBook.personals[index].address,
           addressBook.personals[index].telephoneNumber, addressBook.personals[index].emailAddress);
    
    index = Record(&addressBook, "묭길동","평택시","010-1116-6777", "kang@gmail.com");
    printf("%s\t%s\t%s\t%s\n", addressBook.personals[index].name, addressBook.personals[index].address,
           addressBook.personals[index].telephoneNumber, addressBook.personals[index].emailAddress);
    index = Record(&addressBook, "배길동","울산시","010-8888-7777", "heehee@gmail.com");
    printf("%s\t%s\t%s\t%s\n", addressBook.personals[index].name, addressBook.personals[index].address,
           addressBook.personals[index].telephoneNumber, addressBook.personals[index].emailAddress);
    printf("-------------------------------------------\n");
    Find(&addressBook, "배길동", indexes, &count);
    i=0;
    while (i < count){
        printf("%s\t%s\t%s\t%s\n", addressBook.personals[indexes[i]].name, addressBook.personals[indexes[i]].address,addressBook.personals[indexes[i]].telephoneNumber, addressBook.personals[indexes[i]].emailAddress);
        i++;
    }
    
    printf("------------------------------------------\n");
    index = Correct(&addressBook, 3, "서울시 강남구", "010-3188-8213","newstart@gmail.com");
    printf("%s\t%s\t%s\t%s\n", addressBook.personals[index].name,addressBook.personals[index].address, addressBook.personals[index].telephoneNumber, addressBook.personals[index].emailAddress);
    
    printf("-------------------------------------------\n");
    index = Erase(&addressBook,3);
    if (index == -1){
        printf("지워졌습니다.\n");
    }
    
    index = Erase(&addressBook, 1);
    if (index == -1){
        printf("지워졌습니다.");
    }
    printf("-----------------------\n");
    Arrange(&addressBook);
    i=0;
    while ( i < addressBook.length){
        printf("%s\t%s\t%s\t%s\n", addressBook.personals[i].name, addressBook.personals[i].address, addressBook.personals[i].telephoneNumber, addressBook.personals[i].emailAddress);
        i++;
    }
    printf("정리 완료\n");
    
    count = Save(&addressBook);
    printf("%lu개 저장 완료\n",count);
    
    printf("file close\n");
    printf("끝\n");
    
   // return 0;

//}
*/


Long Load(AddressBook *addressBook){
    Personal personal;
    Long i=0;
    
    FILE *file;
    file =fopen("/Users/jiyunwoo/Desktop/xcode/algorithm/AddressBook/AddressBook.c/AddressBook.c/addressBook.dat","rb");
    
    if(file != NULL){
        fread(&personal, sizeof(Personal), 1, file);

        while(!feof(file)){
            addressBook -> personals[i] = personal;
            i++;
            addressBook ->length ++;
            fread(&personal, sizeof(Personal), 1, file);
        }
        fclose(file);
    }
    
    return addressBook -> length;
}



//Record
Long Record(AddressBook *addressBook, char (*name), char (*address), char (*telephoneNumber), char (*emailAddress)){
    Long i=0;
    Long index = -1;
    
    //1. 성명, 주소, 전화번호, 이메일 주소를 입력 받는다.
    //2. 빈 줄을 찾는다.
    while ( i < addressBook -> capacity && strcmp(addressBook -> personals[i].name,"")!=0){
        i++;
    }
    if (i < addressBook -> capacity){//3. 빈 줄이 있으면
        //3.1. 각 란에 적는다.
        index = i;
        
        strcpy(addressBook -> personals[index].name, name);
        strcpy(addressBook -> personals[index].address, address);
        strcpy(addressBook -> personals[index].telephoneNumber, telephoneNumber);
        strcpy(addressBook -> personals[index].emailAddress, emailAddress);
        addressBook -> length ++;
    }
    //4. 적힌 줄의 위치를 출력한다.
    return index;
    //5. 끝내다.
}

//Find
void Find(AddressBook *addressBook, char (*name), Long (*indexes), Long *count){
    Long i=0;
    Long j =0;
    *count =0;
    
    //1. 성명을 입력 받는다.
    //2. 사용량만큼 반복한다.
    while (i < addressBook -> length){
        if (strcmp(addressBook -> personals[i].name, name)==0){
            indexes[j] = i; //2.1.1. 위치를 구한다.
            j ++;
            (*count)++; //2.1.2. 개수를 세다.
        }
        i++;
    }
    //4. 위치들, 개수를 출력한다.
    //5. 끝내다.
}

//Correct
Long Correct(AddressBook *addressBook, Long index, char (*address), char (*telephoneNumber), char (*emailAddress)){
    
    //1. 수정할 위치, 주소, 전화번호, 이메일 주소를 입력 받는다.
    //2. 입력받은 주소로 바꾼다.
    strcpy(addressBook -> personals[index].address, address);
    //3. 입력받은 전화번호로 바꾼다.
    strcpy(addressBook -> personals[index].telephoneNumber, telephoneNumber);
    //4. 입력받은 이메일 주소로 바꾼다.
    strcpy(addressBook -> personals[index].emailAddress, emailAddress);
    
    //5. 수정된 위치를 출력한다.
    return index;
    //6. 끝내다.
}
    
//Erase

Long Erase (AddressBook *addressBook, Long index){
    
    //1. 지울 위치를 입력 받는다.
    //2. 위치의 성명을 지운다.
    strcpy(addressBook -> personals[index].name, "X");
    //3. 위치를 옮긴다.
    index = -1;
    //4. 위치를 출력하다.
    return index;
    //5. 끝내다.
}

void Arrange(AddressBook *addressBook){
    Personal temp;
    Long j;
    Long i=0;
    Long count =0;
    //1. 사용량만큼 반복한다.
    while ( i< addressBook -> length -1){
        j = i+1;
        while (j < addressBook -> length){
            if (strcmp(addressBook -> personals[i].name, addressBook -> personals[j].name)<0){//1.1. 만약 이름이 더 크면
                //1.1.1. 위로 올려 정리한다.
                temp = addressBook -> personals[i];
                addressBook -> personals[i] = addressBook -> personals[j];
                addressBook -> personals[j] = temp;
            }
            j++;
        }
        i++;
    }
    //2. 사용량 만큼 반복한다.
    i =0;
    while ( i<addressBook -> length && strcmp(addressBook -> personals[i].name,"X")!=0){ //2.1. 삭제 표시가 없으면
        count ++; //2.1.1. 개수를 센다.
        i++;
    }
    //3. 개수만큼 반복한다.
    i = 1;
    while (i < count){ //3.1. 오름차순으로 정렬한다.
        temp = addressBook -> personals[i];
        j = i-1;
        while (j >=0 && strcmp(temp.name, addressBook -> personals[j].name)<=0){
            addressBook -> personals[j+1] = addressBook -> personals[j];
            j--;
        }
        addressBook -> personals[j+1] = temp;
        i++;
    }
    //4. addressBook을 출력한다.
    //5. 끝내다.
}

Long Save(AddressBook *addressBook){
    Long i=0;
    
    FILE *file;
    file = fopen("/Users/jiyunwoo/Desktop/xcode/algorithm/AddressBook/AddressBook.c/AddressBook.c/addressBook.dat","wb");
    
    if (file != NULL){
        while ( i < addressBook -> length){
            fwrite(addressBook -> personals + i, sizeof(Personal), 1, file);
            i++;
        }
        fclose(file);
    }
    return addressBook -> length;
}


