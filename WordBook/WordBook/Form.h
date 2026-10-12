#ifndef _FORM_H
#define _FORM_H

typedef struct _wordBook WordBook;

void DisplayMainMenu(void);
void FormForRecording(WordBook *wordBook);
void FormForFinding(WordBook *wordBook);
void DisplaySubMenu(void);
void FormForFindingByMeaning(WordBook *wordBook);
void FormForFindingBySpelling(WordBook *wordBook);
void FormForCorrecting(WordBook *wordBook);
void FormForErasing(WordBook *wordBook);
void FormForArranging(WordBook *wordBook);
void FormForSavingAll(WordBook *wordBook);

#endif //_FORM_H
