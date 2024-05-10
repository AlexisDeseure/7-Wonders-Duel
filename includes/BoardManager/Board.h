#ifndef BOARD_H
#define BOARD_H

class Board{
    private:
//        static Board* instance;

        Board(const Board&);
    public:
        Board()=default;
        ~Board()=default;
//        void advanceAgeInstance(){
//            age++;
//        };
//        void advanceAge(){
//            Board& instance_unique = getInstance();
//            instance_unique.advanceAgeInstance();
//        }

//        void updateMarketInstance(){
//
//        };
//        void updateMarket(){
//            Board& instance_unique = getInstance();
//            instance_unique.updateMarketInstance();
//        }
//        Je ne pense pas qu'on ait besoin de design pattern singleton car si le jeu est destiné à tourner sur
//        sur un serveur il faudra plusieurs instances de Board pour gérer les différentes parties
//
//        Board& getInstance(){
//            if(!instance){
//                instance = new Board;
//            }
//            return *instance;
//        }
};

#endif
