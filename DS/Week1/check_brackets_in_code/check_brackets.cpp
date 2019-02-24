#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
        
    int failedPos = -1;
    for (int position=0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{')
        {
            opening_brackets_stack.push(Bracket(next,position));
        }

        if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.empty())
            {
                failedPos = position +1;
                break;
            }
            Bracket b = opening_brackets_stack.top();
            if(b.Matchc(next))
                opening_brackets_stack.pop();
            else
            {
                failedPos=position+1;
                break;
            }
        }
    }

    if(failedPos != -1)
        std::cout << failedPos <<std::endl;
    else if (!opening_brackets_stack.empty())
        std::cout << opening_brackets_stack.top().position+1<<std::endl;
    else
        std::cout<<"Success"<<std::endl;

    return 0;
}
