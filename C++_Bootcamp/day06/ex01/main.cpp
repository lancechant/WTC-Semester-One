#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>

struct Data
{
    int            n;
    std::string    s1;
    std::string    s2;
};

struct serialData
{
    int            n;
    char            s1[9];
    char            s2[9];
};

void
*serialize(void)
{
    serialData           *ret = new serialData;
    static char    set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

    for (int i = 0; i < 8; i += 1)
    {
        ret->s1[i] = set[rand() % 62];
    }
    ret->s1[8] ='\0';
    ret->n = rand() * (rand() & 1 ? 1 : -1);
    for (int i = 0; i < 8; i += 1)
    {
        ret->s2[i] = set[rand() % 62];
    }
    ret->s2[8] ='\0';
    return (ret);
}

Data
*deserialize(void *raw)
{
    serialData           *ret = reinterpret_cast<serialData*>(raw);
    Data                *d = new Data;
    d->s1 = static_cast<std::string>(ret->s1);
    d->s2 = static_cast<std::string>(ret->s2);
    d->n = ret->n;
    return (d);
}

int
main(void)
{
    srand(time(NULL));
    void           *ser = serialize();
    Data           *des = deserialize(ser);

std::cout << ser << std::endl;
    std::cout << des->s1 << std::endl \
              << des->n << std::endl \
              << des->s2 << std::endl;
    delete des;
    return (0);

}
