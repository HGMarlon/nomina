#ifndef MAPCELL_H
#define MAPCELL_H


class mapcell
{
    public:
        //int id;
        char id;
        mapcell();
        bool isBlockedCell();
        virtual ~mapcell();

    protected:

    private:
};

#endif // MAPCELL_H
