

#include <cctype>
#include <string>
#include "scanner.h"
using namespace std;

TokenScanner::TokenScanner()
{
    setInput("");
}

TokenScanner::TokenScanner(string str)
{
    setInput(str);
}

void TokenScanner::setInput(string str)
{
    buffer = str;
    cp = 0;
    ignoreWhitespaceFlag = false;
}

bool TokenScanner::hasMoreTokens()
{
    if (ignoreWhitespaceFlag) skipWhitespace();
    return cp < buffer.length();
}

string TokenScanner::nextToken()
{
    if (ignoreWhitespaceFlag) skipWhitespace();
    if (cp >= buffer.length()) return "";
    if (isalnum(buffer[cp])) return scanString();
    return string(1, buffer[cp++]);
}

void TokenScanner::ignoreWhitespace()
{
    ignoreWhitespaceFlag = true;
}

void TokenScanner::skipWhitespace()
{
    while (cp < buffer.length() && isspace(buffer[cp]))
    {
        cp++;
    }
}

string TokenScanner::scanString()
{
    int start = cp;
    while (cp < buffer.length() && isalnum(buffer[cp]))
    {
        cp++;
    }
    return buffer.substr(start, cp - start);
}
