#include <iostream>
#include <cstdio>
#include <cstring>
#include "token.h"

using namespace std;

/*
 * Empty constructor
 */
Token::Token()
{
}

/**
 * Constructor that sets name
 */
Token::Token(std::string content)
{
    setContent(content);
}

std::string Token::getContent() const
{
    return m_content;
}

void Token::setContent(std::string content)
{
    m_content = content;
}

std::ostream& operator<< (std::ostream &os, Token const &m)
{
    return os << "(Token:"<<m.getContent()<<")";
}

