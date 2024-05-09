#ifndef BOARD_H
#define BOARD_H

class Board{
    private:
        int age;
        static Board* instance;
        Board();
        ~Board();
        Board(const Board&);
    public:
        void advanceAgeInstance(){
            age++;
        };
        void advanceAge(){
            Board& instance_unique = getInstance();
            instance_unique.advanceAgeInstance();
        }

        void updateMarketInstance(){

        };
        void updateMarket(){
            Board& instance_unique = getInstance();
            instance_unique.updateMarketInstance();
        }

        Board& getInstance(){
            if(!instance){
                instance = new Board;
            }
            return *instance;
        }
};

#endif
