//
// GeneticTrainer.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/NeuralNetwork/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu Jun  1 04:22:47 2017 Sousa Victor
// Last update Thu Jun  1 17:55:39 2017 Sousa Victor
//

#include "GeneticTrainer.hpp"

using namespace indie;

GeneticTrainer::GeneticTrainer(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem) {
    this->_smgr = sceneManager;
    this->_gui = guiManager;
    this->_eventReceiver = eventReceiver;
    this->_bulletPhysicsSystem = bulletPhysicsSystem;

    this->_aiCar = NULL;
    this->_aiCar = new LearningCar(this->_smgr, this->_gui, this->_eventReceiver, this->_bulletPhysicsSystem);

    this->_genPool.GenerateNewPopulation (15, 560);
    this->_currentAgentFitness = 0.0f;
    this->_bestFitness = 0.0f;

    Neural::Genome *genome = this->_genPool.GetNextGenome();
    this->_aiCar->LoadGenome(*genome);

    this->_infoFit = this->_gui->addStaticText(L"", irr::core::rect<irr::s32>(400, 20, 1500, 80));
    this->_infoFit->setTextAlignment(irr::gui::EGUIA_SCALE , irr::gui::EGUIA_SCALE);
    this->_infoBestFit = this->_gui->addStaticText(L"", irr::core::rect<irr::s32>(400, 80, 1500, 140));
    this->_infoBestFit->setTextAlignment(irr::gui::EGUIA_SCALE , irr::gui::EGUIA_SCALE);
    this->_infoGenome = this->_gui->addStaticText(L"", irr::core::rect<irr::s32>(400, 140, 1500, 200));
    this->_infoGenome->setTextAlignment(irr::gui::EGUIA_SCALE , irr::gui::EGUIA_SCALE);
    this->_infoGeneration = this->_gui->addStaticText(L"", irr::core::rect<irr::s32>(400, 200, 1500, 260));
    this->_infoGeneration->setTextAlignment(irr::gui::EGUIA_SCALE , irr::gui::EGUIA_SCALE);
}

GeneticTrainer::~GeneticTrainer() {

}


void GeneticTrainer::OnFrame() {
    this->_aiCar->OnFrame();
    std::string str1("      \nCurrentFitness: " + std::to_string(_currentAgentFitness));
    std::string str2("      \nBestFitness: " + std::to_string(_bestFitness));
    std::string str3("      \nGenome: " + std::to_string(this->_genPool.GetCurrentGenomeIndex()));
    std::string str4("      \nGeneration: " + std::to_string(this->_genPool.GetCurrentGeneration()));
    this->_infoFit->setText(Utils::StrToWstr(str1));
    this->_infoBestFit->setText(Utils::StrToWstr(str2));
    this->_infoGenome->setText(Utils::StrToWstr(str3));
    this->_infoGeneration->setText(Utils::StrToWstr(str4));

    this->_aiCar->setGenomeID(this->_genPool.GetCurrentGenomeIndex());
    this->_aiCar->setGenerationID(this->_genPool.GetCurrentGeneration());

    if (this->_aiCar->getFailed()) {
        if (this->_genPool.GetCurrentGenomeIndex() == 15 - 1){
            EvolveGenomes();
            return;
        }
        NextTestSubject();
    }
    this->_currentAgentFitness = this->_aiCar->getFitness();
    if (this->_currentAgentFitness > this->_bestFitness) {
        this->_bestFitness = this->_currentAgentFitness;
    }
}

void GeneticTrainer::NextTestSubject(){
    this->_aiCar->SaveNetwork();

    this->_genPool.SetGenomeFitness(this->_currentAgentFitness, this->_genPool.GetCurrentGenomeIndex());
    this->_currentAgentFitness = 0.0f;
    Neural::Genome *genome = this->_genPool.GetNextGenome();

    delete this->_aiCar;
    this->_aiCar = new LearningCar(this->_smgr, this->_gui, this->_eventReceiver, this->_bulletPhysicsSystem);
    this->_aiCar->LoadGenome(*genome);
}

void GeneticTrainer::EvolveGenomes(){
    this->_genPool.BreedPopulation();
    NextTestSubject();
}

Car *GeneticTrainer::getCar() const {
    return this->_aiCar;
}
