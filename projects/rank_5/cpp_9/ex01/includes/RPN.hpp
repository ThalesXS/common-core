
#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cmath>
# include <stack>

class RPN
{
    private:
        std::stack<std::string> expression;

    public:
        RPN();
        RPN(RPN& obj);
        RPN& operator=(RPN& obj);
        ~RPN();
        
};

#endif