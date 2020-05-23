#ifndef ACTION_H
#define ACTION_H

enum Option
{
    fo=0,
    ca,
    be,
    ra,
    ch
};

class Action
{
    private:
        Option action;
        double bet;

    public:
        Action() { action = fo; bet = 0; }
        Action(Option act, double size) { action = act; bet = size; }
        void check() { action = ch; bet = 0; }
        void call(double size) { action = ca; bet = size; }
        void make_bet(double size) { action = be; bet = size; }
        void raise(double size) { action = ra; bet = size; }
        void fold() { action = fo; bet = 0; }
        Option get_action() { return action; }
        double get_bet() { return bet; }
};

#endif
