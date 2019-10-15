#include <string.h>
#include <stdlib.h>

#include "range.h"
#include "lib.h"

/**
 * Determine whether or not an opt string for a chapter or verse matches a target
 * string. This is used to see if a current verse or chapter is within an opt query
 * e.g. "5-7", 6 would be true since we are including all of 5 through 7.
 */
bool evalrange(char *opt, int target)
{
    // if the opt isn't even there we'll return TRUE below.
    if (opt)
    {
        // detect whether or not we are dealing with a range to begin with, if not
        // we just check to see if its the same exact value or not.
        if (!hasrange(opt))
        {
            if (target != atoi(opt))
            {
                return FALSE;
            }
        }
        else
        {
            // since we are dealing with a range, parse the opt into a range_t object.
            range_t range = parserange(opt);

            // if we dont have a to range, treat it as ff, rest of item
            if (!range.to)
            {
                range.to = 999;
            }

            // once we have the range_t, make sure our target is within the
            // from and to range set in opt.
            if (target < range.from || target > range.to)
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}

/**
 * Determine whether or not char * `text` is a range string or not, denoted by a -
 * being present in the string e.g. 5-8.
 */
bool hasrange(char *text)
{
    // simply loop over whole string;
    for (int i = 0; i < strlen(text); ++i)
    {
        if (text[i] == '-')
        {
            // right when we find a -, TRUE.
            return TRUE;
        }
    }

    // we didn't find anything -- not a range
    return FALSE;
}

/**
 * Parse out a range object, returning a range_t with from and to.
 * 5-9: from=5 to=9
 */
range_t parserange(char *text)
{
    // char arrays we will populate as we analyze the string `text`.
    char from[3];
    char to[4];

    // shared iterator as we parse through `text`.
    int i = 0;

    // our first step is to get through the first part of the range up to the - character.
    // everything we encounter up to that point is the from.
    while (text[i] != '-')
    {
        from[i] = text[i];
        ++i;
    }

    // terminate string
    from[i] = '\0';

    // walk iterator forward so we don't include the - in the `to` array.
    ++i;

    // new iterator for our `to` array so we populate at 0.
    int toi = 0;

    // starting at wherever i is, we continue until we're at strlen of `text` arg.
    for (; i < strlen(text); ++i)
    {
        to[toi] = text[i];
        ++toi;
    }

    // terminate
    to[toi] = '\0';

    // our range_t return
    range_t range = { atoi(from), atoi(to) };

    return range;
}