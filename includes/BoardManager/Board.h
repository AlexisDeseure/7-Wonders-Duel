//
// Created by mateo on 08/05/2024.
//

#ifndef INC_7_WONDERS_DUEL_BOARD_H
#define INC_7_WONDERS_DUEL_BOARD_H
namespace Board{
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
}
#endif //INC_7_WONDERS_DUEL_BOARD_H
