#ifndef MISC_ENUM_H
#define MISC_ENUM_H
enum OrientationPoint{
    TOPLEFT,
    TOPMIDDLE,
    TOPRIGHT,
    RIGHTMIDDLE,
    RIGHTBOTTOM,
    BOTTOMMIDDLE,
    LEFTBOTTOM,
    LEFTMIDDLE,
    CENTER
};

enum NODETYPE
{
    PC = 1,
    SERVER,
    SWITCH,
    CORESWITCH,
    ROUTER,
    COREROUTER,
    FIREWALL,
    IDS,
    CABINET,
    MISC
};

enum NODESTATUS
        {
    FINE = 1,
    FALUT,
    UNSERVICE
};

#endif // MISC_ENUM_H
