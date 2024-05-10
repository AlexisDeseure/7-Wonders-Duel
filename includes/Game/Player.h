#ifndef PLAYER_H
#define PLAYER_H

class City;

class Player{
    private:
        City& city;
        bool isAI;
    public:
        Player(bool ai=false);
        ~Player();
        bool isAIPlayer() const {return isAI;};
        City& getCity() const {return city;};
        void play();
        void setAI(bool ai){isAI = ai;};

};
#endif
