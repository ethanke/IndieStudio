//
// GeneticTrainer.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/IndieStudio/sources/NeuralNetwork/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Thu Jun  1 04:22:47 2017 Sousa Victor
// Last update Sun Jun  4 14:13:32 2017 Sousa Victor
//

#include "GeneticTrainer.hpp"

using namespace indie;

GeneticTrainer::GeneticTrainer(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem) {
    this->_smgr = sceneManager;
    this->_gui = guiManager;
    this->_eventReceiver = eventReceiver;
    this->_bulletPhysicsSystem = bulletPhysicsSystem;

    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10001, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(40.363483, 0, -7.120950));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10002, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(116.477867, 0, 4.145689));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10003, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(136.052933, 0, 49.592808));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10004, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(137.606277, 0, 117.132492));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10005, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(141.872253, 0, 182.362442));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10006, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(149.394592, 0, 252.318558));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10007, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(148.314362, 0, 317.658539));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10008, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(148.278168, 0, 400.024536));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10009, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(147.463898, 0, 486.366882));
    this->_circuit << GameCheckpoint(this->_smgr, 0, 0, NULL, 100010, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(150.664978, 0, 516.441711));
    this->_circuit << GameCheckpoint(this->_smgr, 0, 0, NULL, 100011, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(185.088089, 0, 530.357361));
    this->_circuit << GameCheckpoint(this->_smgr, 0, 0, NULL, 100012, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(247.074554, 0, 527.202698));

    this->_genPool.GenerateNewPopulation (15, 198);
    this->_currentAgentFitness = 0.0f;
    this->_bestFitness = 0.0f;

    Neural::Genome *genome = this->_genPool.GetNextGenome();
    this->_aiCar = NULL;
    this->_aiCar = new LearningCar(this->_smgr, this->_gui, this->_eventReceiver, this->_bulletPhysicsSystem, this->_circuit);
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
    this->_circuit.OnFrame();
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
    this->_aiCar = new LearningCar(this->_smgr, this->_gui, this->_eventReceiver, this->_bulletPhysicsSystem, this->_circuit);
    this->_aiCar->LoadGenome(*genome);
}

void GeneticTrainer::EvolveGenomes(){
    this->_genPool.BreedPopulation();
    NextTestSubject();
}

Car *GeneticTrainer::getCar() const {
    return this->_aiCar;
}
