#ifndef SNAKEPART_HPP
#define SNAKEPART_HPP

struct  snakepart{

    int x, y;
    snakepart(int col, int row);
    snakepart();
    snakepart(const snakepart &obj);
    snakepart &operator = (const snakepart &rhs);
    ~snakepart();
};

#endif