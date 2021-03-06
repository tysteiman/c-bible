#include <string.h>

#include <stdio.h>
#include <stdlib.h>

#include "books.h"

book_t books[]= {
    {"Genesis","gen"},
    {"Exodus","exo"},
    {"Leviticus","lev"},
    {"Numbers","num"},
    {"Deuteronomy","deu"},
    {"Joshua","jos"},
    {"Judges","jdg"},
    {"Ruth","rut"},
    {"1 Samuel","sa1"},
    {"2 Samuel","sa2"},
    {"1 Kings","kg1"},
    {"2 Kings","kg2"},
    {"1 Chronicles","ch1"},
    {"2 Chronicles","ch2"},
    {"Ezra","ezr"},
    {"Nehemiah","neh"},
    {"Esther","est"},
    {"Job","job"},
    {"Psalms","psa"},
    {"Proverbs","pro"},
    {"Ecclesiastes","ecc"},
    {"Song of Solomon","sol"},
    {"Isaiah","isa"},
    {"Jeremiah","jer"},
    {"Lamentations","lam"},
    {"Ezekiel","eze"},
    {"Daniel","dan"},
    {"Hosea","hos"},
    {"Joel","joe"},
    {"Amos","amo"},
    {"Obadiah","oba"},
    {"Jonah","jon"},
    {"Micah","mic"},
    {"Nahum","nah"},
    {"Habakkuk","hab"},
    {"Zephaniah","zep"},
    {"Haggai","hag"},
    {"Zechariah","zac"},
    {"Malachi","mal"},
    {"Matthew","mat"},
    {"Mark","mar"},
    {"Luke","luk"},
    {"John","joh"},
    {"Acts","act"},
    {"Romans","rom"},
    {"1 Corinthians","co1"},
    {"2 Corinthians","co2"},
    {"Galatians","gal"},
    {"Ephesians","eph"},
    {"Philippians","phi"},
    {"Colossians","col"},
    {"1 Thessalonians","th1"},
    {"2 Thessalonians","th2"},
    {"1 Timothy","ti1"},
    {"2 Timothy","ti2"},
    {"Titus","tit"},
    {"Philemon","plm"},
    {"Hebrews","heb"},
    {"James","jam"},
    {"1 Peter","pe1"},
    {"2 Peter","pe2"},
    {"1 John","jo1"},
    {"2 John","jo2"},
    {"3 John","jo3"},
    {"Jude","jde"},
    {"Revelation","rev"},
};

char *booktitle(char *abbrev)
{
    return findbook(abbrev).title;
}

book_t findbook(char *abbrev)
{
    book_t book;

    for (int i = 0; i < sizeof(books) / sizeof(book_t); ++i)
    {
        if (strncmp(books[i].abbrev, abbrev, 3) == 0)
        {
            return books[i];
        }
    }

    book.abbrev = "?";
    book.title = "?";

    return book;
}
