#include "converter.cpp"
//i = begining x = decimal
int getPrecision(char *str)
{
    unsigned int     i;
    unsigned int     x;

    i = 0;
    while (str[i] && str[i] != '.')
    {
        i += 1;
    }
    x = i + 1;
    while (str[x] && isdigit(str[x]))
    {
        x += 1;
    }
    x -= i;
    return ((strlen(str) == i || x == 1) ? 1 : x - 1);
}

int main(int argc, char *argv[])
{
    double              value;
    int                 precision;
    Conversion          conversion;

    if (argc == 2) {
    for (int i = 1; i < argc; i += 1)
        {
            std::cout << "input : " << argv[i] << std::endl;
            precision = getPrecision(argv[i]);
            value = atof(argv[i]);
            checkChar(conversion, value);
            checkInt(conversion, value);
            checkDouble(conversion, value, precision);
            checkFloat(conversion, value, precision);
            std::cout << std::endl;
        }
    } else 
        std::cout << "invalid input" << std::endl;
    
    return (0);
}