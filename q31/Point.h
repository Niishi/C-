#ifndef __POINT__
#define __POINT__

class Point{
private:
public:
    int edge_migi;
    int edge_shita;
    int edge_ue;
    int edge_hidari;
    int r, c;
    Point(int, int);
    void set_road(int, bool);
    void move(bool);
};

#endif
