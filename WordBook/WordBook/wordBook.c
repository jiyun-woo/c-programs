#include "wordBook.h"
#include <stdio.h>
#include <string.h>
#define MAX 10

/*int main (int agrc, char * argv[]){
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
    Long index;
    Long indexes [MAX];
    Long count;
    Long i = 0;
    
    //Load
    count = Load(&wordBook);
    while (i < count){
        printf("%s\t%s\t%s\t%s\n", wordBook.words[i].spelling, wordBook.words[i].partOfSpeech, wordBook.words[i].meaning, wordBook.words[i].exampleSentence);
        i++;
    }
    
    //Record
    index = Record(&wordBook, "attempt","동사", "시도하다", "I will attempt to solve the problem.");
    printf("%s\t%s\t%s\t%s\n", wordBook.words[index].spelling,wordBook.words[index].partOfSpeech,wordBook.words[index].meaning,wordBook.words[index].exampleSentence);
  
    index = Record(&wordBook, "change","동사", "바꾸다", "People can change their habits.");
    printf("%s\t%s\t%s\t%s\n", wordBook.words[index].spelling,wordBook.words[index].partOfSpeech,wordBook.words[index].meaning,wordBook.words[index].exampleSentence);
 
    index = Record(&wordBook, "study","동사", "공부하다", "I study Spanish everyday.");
    printf("%s\t%s\t%s\t%s\n", wordBook.words[index].spelling,wordBook.words[index].partOfSpeech,wordBook.words[index].meaning,wordBook.words[index].exampleSentence);
   
    index = Record(&wordBook, "study","명사", "연구", "Studies found that people are selfish.");
    printf("%s\t%s\t%s\t%s\n", wordBook.words[index].spelling,wordBook.words[index].partOfSpeech,wordBook.words[index].meaning,wordBook.words[index].exampleSentence);
   
    index = Record(&wordBook, "attempt","명사", "시도", "Making an attempt is a good thing.");
    printf("%s\t%s\t%s\t%s\n", wordBook.words[index].spelling,wordBook.words[index].partOfSpeech,wordBook.words[index].meaning,wordBook.words[index].exampleSentence);
    
    index = Record(&wordBook, "improve","동사", "향상시키다", "Regular practice improves their English.");
    printf("%s\t%s\t%s\t%s\n", wordBook.words[index].spelling,wordBook.words[index].partOfSpeech,wordBook.words[index].meaning,wordBook.words[index].exampleSentence);
    
    index = Record(&wordBook, "change","명사", "변화", "An attempt bring change to your life.");
    printf("%s\t%s\t%s\t%s\n", wordBook.words[index].spelling,wordBook.words[index].partOfSpeech,wordBook.words[index].meaning,wordBook.words[index].exampleSentence);
    
    index = Record(&wordBook, "reliable","형용사", "믿을 수 있는", "She is a reliable coworker.");
    printf("%s\t%s\t%s\t%s\n", wordBook.words[index].spelling,wordBook.words[index].partOfSpeech,wordBook.words[index].meaning,wordBook.words[index].exampleSentence);
    

    index = Record(&wordBook, "credible","형용사", "믿을 수 있는", "The witness gave a credible explanation.");
    printf("%s\t%s\t%s\t%s\n", wordBook.words[index].spelling,wordBook.words[index].partOfSpeech,wordBook.words[index].meaning,wordBook.words[index].exampleSentence);
    
    index = Record(&wordBook, "quickly", "부사", "빠르게", "He quickly finished his homework.");
    printf("%s\t%s\t%s\t%s\n", wordBook.words[index].spelling,wordBook.words[index].partOfSpeech,wordBook.words[index].meaning,wordBook.words[index].exampleSentence);
    
    //FindByMeaning
    FindByMeaning(&wordBook, "attempt", indexes, &count);
    i = 0;
    while ( i < count){
        printf("%s\t%s\t%s\t%s\n", wordBook.words[indexes[i]].spelling,wordBook.words[indexes[i]].partOfSpeech,wordBook.words[indexes[i]].meaning,wordBook.words[indexes[i]].exampleSentence);
        i++;
    }
    
    //FindBySpelling
    FindBySpelling(&wordBook, "믿을 수 있는", indexes, &count);
    i = 0;
    while ( i < count){
        printf("%s\t%s\t%s\t%s\n", wordBook.words[indexes[i]].spelling,wordBook.words[indexes[i]].partOfSpeech,wordBook.words[indexes[i]].meaning,wordBook.words[indexes[i]].exampleSentence);
        i++;
    }
    
    //Correct
    index = Correct (&wordBook, 5, "더 좋아지다\t", "The weather is improving!");
    printf("%s\t%s\n", wordBook.words[index].meaning, wordBook.words[index].exampleSentence);
    
    //Erase
    index = Erase(&wordBook, 5);
    if (index == -1){
        printf("지워졌습니다.\n");
    }

    //Arrange
    Arrange(&wordBook);
    i=0;
    while (i < wordBook.length){
        printf("%s\t%s\t%s\t%s\n", wordBook.words[i].spelling,wordBook.words[i].partOfSpeech,wordBook.words[i].meaning,wordBook.words[i].exampleSentence);
        i++;
    }
    
    //Save
    Save(&wordBook);
    printf("저장 완료.");
    
    return 0;
}
*/

//Load
Long Load(WordBook *wordBook){
    Word word;
    Long i=0;
    size_t size;
    
    FILE *file;
    file = fopen("/Users/jiyunwoo/Desktop/xcode/algorithm/WordBook/WordBook/Words.dat","rb");
    
    if (file != NULL){
        //1.1. 철자, 품사, 뜻, 예문을 입력받는다.
        size = fread(&word, sizeof(Word), 1, file);
        
        //1. 파일의 끝이 아닌 동안 반복한다.
        while (!feof(file)&& size != 0){
            //1.2. 단어들에 적는다.
            wordBook -> words[i] = word;
            i++;
            //1.3. 저장량을 센다.
            wordBook -> length++;
            //1.1. 철자, 품사, 뜻, 예문을 입력받는다.
            size = fread(&word, sizeof(Word),1, file);
        }
        //2. 저장량을 출력한다.
        //3. 끝내다.
        fclose(file);
    }
    return wordBook -> length;
}

//Record
Long Record (WordBook *wordBook, char (*spelling), char (*partOfSpeech), char (*meaning), char (*exampleSentence)){
    Long index = -1;
    Long i = 0;
    
    //1. 철자, 품사, 뜻, 예문을 입력 받는다.
    //2. 빈 줄을 찾는다.
    while ( i < wordBook -> capacity && strcmp(wordBook -> words[i].spelling, "")!=0){
        i++;
    }
    //3. 만약 빈 줄이 있으면
    if ( i < wordBook -> capacity){
        //3.1. 각 란에 적는다.
        index = i;
        strcpy(wordBook -> words[index].spelling, spelling);
        strcpy(wordBook -> words[index].partOfSpeech, partOfSpeech);
        strcpy(wordBook -> words[index].meaning, meaning);
        strcpy(wordBook -> words[index].exampleSentence, exampleSentence);
        wordBook -> length ++;
    }
    //4. 적은 줄의 위치를 출력한다.
    return index;
    //5. 끝내다.
}

//FindByMeaning
void FindByMeaning(WordBook *wordBook, char (*meaning), Long (*indexes), Long *count){
    Long i = 0;
    Long j = 0;
    *count = 0;
    
    //1. 뜻을 입력받는다.
    //2. 저장량만큼 반복한다.
    while ( i < wordBook -> length){
        //2.1. 뜻이 같으면
        if (strcmp(wordBook -> words[i].meaning, meaning)==0){
            //2.1.1. 위치를 구한다.
            indexes[j] = i;
            j++;
            //2.1.2. 개수를 센다.
            (*count)++;
        }
        i++;
    }
    //3. 개수, 위치들을 출력한다.
    //4. 끝내다.
}

//FindBySpelling
void FindBySpelling(WordBook *wordBook, char (*spelling), Long (*indexes), Long *count){
    Long i = 0;
    Long j = 0;
    *count = 0;
    
    //1. 철자를 입력받는다.
    //2. 저장량만큼 반복한다.
    while ( i < wordBook -> length){
        //2.1. 철자가 같으면
        if (strcmp(wordBook -> words[i].spelling, spelling)==0){
            //2.1.1. 위치를 구한다.
            indexes[j] = i;
            j++;
            //2.1.2. 개수를 센다.
            (*count)++;
        }
        i++;
    }
    //3. 개수, 위치들을 출력한다.
    //4. 끝내다.
}

//Correct
Long Correct(WordBook *wordBook, Long index, char(*meaning), char (*exampleSentence)){
    
    //1. 수정할 위치, 뜻, 예문을 입력받는다.
    //2. 입력받은 뜻으로 적는다.
    strcpy(wordBook -> words[index].meaning, meaning);
    //3. 입력받은 예문으로 적는다.
    strcpy(wordBook -> words[index].exampleSentence, exampleSentence);
    //4. 수정된 위치를 출력한다.
    return index;
    //5. 끝내다.
}

//Erase
Long Erase(WordBook *wordBook, Long index){
    
    //1. 지울 위치를 입력받는다.
    //2. 위치의 철자에 지움 표시를 한다.
    strcpy(wordBook -> words[index].spelling, "-");
    //3. 위치를 옮긴다.
    index = -1;
    //4. 위치를 출력한다.
    return index;
    //5. 끝내다.
}

//Arrange
void Arrange(WordBook *wordBook){
    Word temp;
    Long i = 0;
    Long j;
    Long count = 0;
    
    //1. 철자로 내림차순 한다.
    while ( i < wordBook -> length){
        j = i+1;
        while (j < wordBook -> length){
            if (strcmp(wordBook -> words[i].spelling, wordBook -> words[j].spelling)<0){
                temp = wordBook -> words[i];
                wordBook -> words[i] = wordBook -> words[j];
                wordBook -> words[j] = temp;
            }
            j++;
        }
        i++;
    }
    //2. 지운 줄을 뺀 적힌 줄을 센다.
    i = 0;
    while (i <  wordBook -> length && strcmp(wordBook -> words[i].spelling, "-")!=0){
        count++;
        i++;
    }
    //3. 철자로 오름차순 한다.
    i=1;
    while ( i < count){
        temp = wordBook -> words[i];
        j=i-1;
        while ( j >=0 && strcmp(temp.spelling, wordBook -> words[j].spelling)<=0){
            wordBook -> words[j+1] = wordBook -> words[j];
            j--;
        }
        wordBook -> words[j+1] = temp;
        i++;
    }
   /* 버블정렬
    i=0;
    while ( i < count){
        j = 0;
        while (j< count -i){
            if (strcmp(wordBook -> words[j].spelling, wordBook -> words[j+1].spelling)>0){
                temp = wordBook -> words[j];
                wordBook -> words[j] = wordBook -> words[j+1];
                wordBook -> words[j+1] = temp;
            }
            j++;
        }
        i++;
    }
    */
    //4. wordBook을 출력한다.
    //5. 끝내다.
}

//Save
Long Save(WordBook *wordBook){
    Long i=0;
    
    FILE *file;
    file = fopen("/Users/jiyunwoo/Desktop/xcode/algorithm/WordBook/WordBook/Words.dat", "wb");
    
    if(file != NULL){
        while ( i < wordBook -> length){ //1. 사용량만큼 반복한다.
            //1.1. 철자, 품사, 뜻, 예문을 출력한다.
            fwrite(wordBook -> words+i, sizeof(Word),1,file);
            i++;
        }
        //2. 개수를 출력한다.
        //3. 끝내다.
        fclose(file);
    }
    return wordBook -> length;
}
