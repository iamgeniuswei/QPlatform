#ifndef QPMAINTITLEBUILDER_P
#define QPMAINTITLEBUILDER_P
class QPMainTitleBuilder;
class QPUITitle;
class QPMainTitleBuilderPrivate
{
public:
    QPMainTitleBuilderPrivate():
    mainTitle(nullptr)
    {}
    void init();

public:
    QPUITitle *mainTitle;
};

#endif // QPMAINTITLEBUILDER_P

