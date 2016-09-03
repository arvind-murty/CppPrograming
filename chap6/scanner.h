#ifndef _scanner_h
#define _scanner_h

#include <string>

class TokenScanner
{
public:
    TokenScanner();
    TokenScanner(std::string str);

    void setInput (std::string str);

    bool hasMoreTokens();

    std::string nextToken();

    void ignoreWhitespace();

private:
    std::string buffer;
    int cp;
    bool ignoreWhitespaceFlag;

    void skipWhitespace();
    std::string scanString();
};

#endif
