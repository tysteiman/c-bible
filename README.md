# c-bible

The easiest way to quickly search biblical texts from a unix terminal

# Dependencies

- make
- gcc

# Installation

    make

# Usage

    ./bible 'jesus wept'

## Command Line Arguments

    -b: book -- specify book to search within

        ./bible -b mat thief
        ./bible -b matthew thief

        Note: books names are case insensitive and work with either 3 digit abbreviation or full name.

        See below for list of books in name, abbreviation format.

    -c: chapter -- specify chapter or chapter range to search within.

        ./bible -b mat -c 5 blessed   # will search in all of chapter Matthew 5
        ./bible -b mat -c 5-7 blessed # will search in all of Matthew 5-7

    -v: verse -- specify verse or verse range to search within.

        ./bible -b mat -c 4 -v 1-7 jesus # search Matthew 4:1-7

    -n: count mode -- prints number of results only

        ./bible -c babylon
        Number of results: 265

    -d: debug mode -- print debug information

## Available books for searching

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
