#ifndef COLOR_H
#define COLOR_H


typedef enum {
    Red = 0,
    RedShing = 1,
    Green = 2,
    GreenShing = 3,
    Blue = 4,
    BlueShing = 5,
    EMPTY = 6,
    White = 6,
    Black = 7,
    Barrier = 8,
    PlayerUI = 9,
    BGBlue = 10,
    RedBlockText = 11,
    GreenBlockText = 12,
    BlueBlockText = 13,
    PointText = 14,
    BGWhite = 15,
    BGGray = 16,
    DevilUI = 17,
    DevilHP = 18,
    BarrierBlockText = 19,
    PlayerMain = 20,
    DevilMain = 21,
    PlayerYellow = 22,
    DevilPuple = 23,
    BrightPuple = 24,
    BrightBarrier = 25
    
    
} ColorEnum;



struct ColorRGB 
{
    int R;
    int G;
    int B;

};



extern ColorEnum colorEnum;

extern ColorRGB RedColor;
extern ColorRGB GreenColor;
extern ColorRGB BlueColor;
extern ColorRGB WhiteColor;
extern ColorRGB BlackColor;
extern ColorRGB BarrierColor;

extern ColorRGB RedColorShing;
extern ColorRGB GreenColorShing;
extern ColorRGB BlueColorShing;
extern ColorRGB PlayerUIColor;
extern ColorRGB BGBlueColor;

extern ColorRGB RedBlockTextColor;
extern ColorRGB GreenBlockTextColor;
extern ColorRGB BlueBlockTextColor;
extern ColorRGB PointBlockTextColor;

extern ColorRGB BGWhiteColor;
extern ColorRGB BGGrayColor;

extern ColorRGB DevilUIColor;
extern ColorRGB DevilHPColor;

extern ColorRGB BarrierBlockTextColor;

extern ColorRGB PlayerMainColor;
extern ColorRGB DevilMainColor;
extern ColorRGB PlayerYellowColor;
extern ColorRGB DevilPupleColor;
extern ColorRGB BrightPupleColor;

extern ColorRGB BrightBarrierColor;

extern ColorRGB colors[];

extern ColorRGB gradientColorList[];



#endif
