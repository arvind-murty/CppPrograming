#ifndef STRING_H_
#define STRING_H_

class String
{
public:
    String ();
    String (const char *str);
    String (const String& src);

    ~String ();

    String& operator+= (const char *s);


    void add (const char *str);

private:
    char *str;
    int   size;
};



#endif
