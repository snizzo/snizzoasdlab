#ifndef TOKEN_H
#define TOKEN_H

#include <cstdlib>
#include <cstring>

class Token {
    private:
        std::string m_content;
        
    public:
        Token();
        Token(std::string content);
        
        std::string getContent() const;
        void setContent(std::string content);
        
        //define an order relation between vertex objects
        friend std::ostream& operator<< (std::ostream &os, Token const &m);
};

#endif
