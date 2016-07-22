#ifndef QPMESSAGEBOXTITLEBUILDER_P
#define QPMESSAGEBOXTITLEBUILDER_P
class QPMessageBoxTitleBuilder;
class QPUITitle;
class QPMessageBoxTitleBuilderPrivate
{
public:
    QPMessageBoxTitleBuilderPrivate():
    mainTitle(nullptr)
    {}
    void init();

public:
    QPUITitle *mainTitle;
};
#endif // QPMESSAGEBOXTITLEBUILDER_P

