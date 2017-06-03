//
// Circuit.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sat Jun  3 20:09:08 2017 Sousa Victor
// Last update Sat Jun  3 21:08:31 2017 Sousa Victor
//

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <vector>
#include "GameCheckpoint.hpp"

namespace indie {

    class Circuit : public IGameObject {

    public:
        Circuit();
        Circuit(const Circuit& obj);
        ~Circuit();
        Circuit &operator=(const Circuit& obj);

        virtual void OnFrame();

        Circuit &operator <<(GameCheckpoint const &point);

        std::vector<GameCheckpoint> const &getNextCheckpoints(unsigned index) const;
        std::vector<GameCheckpoint> const &getCheckpoints() const;

    private:
        std::vector<GameCheckpoint> _checkpoints;

    };

}

#endif /*CIRCUIT_HPP_*/
