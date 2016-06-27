

#include "string.hpp"


String::String ()
{
    str  = malloc (1);
    size = 1;

    *str = '\0';
}

String::String (const String& s)
{
    size = s.size; 
    str  = malloc (sizeof (char) * size);
    strcpy (str, s.str);
}

String::String (const char *str)
{
    // this is of type String*
    this->size = strlen(str) + 1;
    this->str  = malloc (sizeof (char) * this->size);
        
    strcpy (this->str, str);
}

String::~String ()
{
    free (str);
}

void String::add (const char *s)
{
    int sz = strlen (s);

    size += sz;
    char *nstr = malloc (sizeof (char) * size);

    strcpy (nstr, str);
    strcat (nstr, s);

    free (str);
    str = nstr;
}

String& String::operator+= (const char* str)
{
    add (str);
    return *this;
}


void func1 (String* s)
{
}

void func2 (String& s)
{
    s += "bar";
}
void func3 (String s)
{
    s += "bar";
}


void func ()
{
    if (true) 
    {
        if (true) {
            int a = 0;
            String ex("foo");

            func1 (&ex);
            func2 (ex);
            func3 (ex);
        }
    }

    ex += "bar";
}





