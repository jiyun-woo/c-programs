# WordBook & AddressBook

Two console programs I wrote in C while teaching myself programming in summer 2026, after finishing my psychology degree. Both were built in Xcode on macOS.

The code in this repository is uploaded exactly as I wrote it. Nothing has been edited or cleaned up.

## WordBook (단어장 Version 0.05)

A vocabulary notebook. Each entry stores a word, its part of speech (noun, pronoun, verb, adjective, adverb, preposition, interjection, conjunction), its meaning, and an example sentence.

Menu: record, find (by meaning or by spelling), correct, erase, arrange (sort), view all. Records are loaded from a binary file when the program starts and saved when it ends.

Files: `WordBook/WordBook/wordBook.c`, `wordBook.h`, `Form.c`, `Form.h`, sample data in `Words.dat`.

## AddressBook (주소록 Version 0.05)

An address book with the same structure. Each entry stores a name, address, telephone number, and email address. Menu: record, find, correct, erase, arrange, view all; records are loaded at start and saved on exit.

Files: `AddressBook/AddressBook.c/AddressBook.c/AddressBook.c`, `addressBook.h`, `Form.c`, `Form.h`. The data file is not included because it contains real contact details.

## What I practised

- Structs and fixed-size arrays of records
- Splitting logic (`wordBook.c`, `AddressBook.c`) from the console screens (`Form.c`)
- Linear search, sorting, insert and delete in an array
- Reading and writing records to a binary file with `fopen`, `fread`, `fwrite`

## Notes for running it

- The data file paths are absolute paths on my own Mac (`/Users/jiyunwoo/Desktop/...`), so saving and loading only work if you change that path in the source.
- `AddressBook.c` includes `"AddressBook.h"` while the file is named `addressBook.h`. This works on macOS, which ignores case in file names, but not on Linux.
- Menus and prompts are in Korean.
