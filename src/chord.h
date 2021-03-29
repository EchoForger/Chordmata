#ifndef CHORD_H
#define CHORD_H

enum CHORD_TYPE
{
    MAJ3 = 0,
    MAJ7 = 1,   //大七和弦
    DOM7 = 2,   //属七和弦
    MIN3 = 3,
    MIN7 = 4,   //小属七和弦
};

static const int arr[5][4] =
{
    {0,4,7,-1},
    {0,4,7,11},
    {0,4,7,10},
    {0,3,7,-1},
    {0,3,7,10},
};


class Chord
{
public:
    int level;
    CHORD_TYPE type;
public:
    Chord(int level, CHORD_TYPE type);
};

#endif // CHORD_H
