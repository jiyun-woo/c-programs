#ifndef _WORDBOOK_H
#define _WORDBOOK_H
#define MAX 10

typedef signed long int Long;

typedef struct _word {
    char spelling [64];
    char partOfSpeech [16];
    char meaning [64];
    char exampleSentence[128];
}Word;

typedef struct _wordBook{
    Word words [MAX];
    Long capacity;
    Long length;
}WordBook;

int main (int argc, char * argv []);
Long Load(WordBook *wordBook);
Long Record (WordBook *wordBook, char (*spelling), char (*partOfSpeech), char (*meaning), char (*exampleSentence));
void FindByMeaning(WordBook *wordBook, char (*meaning), Long (*indexes), Long *count);
void FindBySpelling (WordBook *wordBook, char (*spelling), Long (*indexes), Long *count);
Long Correct (WordBook *wordBook, Long index, char (*meaning), char (*exampleSentence));
Long Erase (WordBook *wordBook, Long index);
void Arrange(WordBook *wordBook);
Long Save(WordBook *wordBook);

#endif //_WORDBOOK_H
