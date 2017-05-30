//
// Genome.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/includes/NeuralNetwork/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Tue May 30 15:39:58 2017 Sousa Victor
// Last update Tue May 30 15:47:05 2017 Sousa Victor
//

#ifndef GENOME_HPP_
#define GENOME_HPP_

#include <vector>

namespace Neural {

    class Genome {
    public:
        Genome();
        Genome(const Genome &gen);
        ~Genome();
        Genome &operator =(const Genome &gen);

        float getFitness() const;
        void setFitness(float fitness);

        int getId() const;
        void setId(int id);

        std::vector<float> const &getWeights() const;
        void setWeights(std::vector<float> const &weight);


    private:
        float _fitness;
        int _id;
        std::vector<float> _weights;
    };

};

#endif /*GENOME_HPP_*/