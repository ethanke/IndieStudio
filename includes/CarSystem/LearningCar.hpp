//
// LearningCar.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/includes/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu Jun  1 03:34:22 2017 Sousa Victor
// Last update Thu Jun  1 04:09:23 2017 Sousa Victor
//

#ifndef LEARNINGCAR_HPP_
#define LEARNINGCAR_HPP_

#include "AICar.hpp"

namespace indie {

    class LearningCar : public AICar {

    public:
        LearningCar(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem, int car_no = 0);
        ~LearningCar();

        virtual void OnFrame();

        void SaveNetwork() const;

        int getGenomeID() const;
        void setGenomeID(int genomeID);

        int getGenerationID() const;
        void setGenerationID(int generationID);

        float getFitness() const;
        void setFitness(float fitness);

        bool getFailed() const;
        void setFailed(bool failed);

    private:
        int _genomeID;
        int _generationID;
        float _fitness;
        bool _hasFailed;
        int _indic;

    };

}

#endif /*LEARNINGCAR_HPP_*/
