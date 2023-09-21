#include "iostream"
#include <vector>

using namespace std;

class code
{
    public:
        code(int n, int m);
        int checkCorrect(const code& guess);
        int checkIncorrect(const code& guess);
        void setCode();

    private:
        int length, range;
        vector<int> master_code;
};

// Constructor for code object
code::code(int n, int m)
{
    length = n;
    range = m;
}

void code::setCode()
{
    int random = rand() % (range - 1);
    for (int i = 0; i < length; i ++)
        {
            master_code.push_back(random);
        }
}

int code::checkCorrect(const code& guess)
{
    // Add checkCorrect implementation
}

int code::checkIncorrect(const code& guess)
{
    // Add checkIncorrect implementation
}




