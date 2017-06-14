/*
** Race.cpp for IndieStudio in /Users/Vacca_J/Epitech/Tek2/Projet/IndieStudio/sources
**
** Made by Vacca_J
** Login   <Vacca_J@epitech.net>
**
** Started on  Thu Jun 01 01:32:46 2017 Vacca_J
** Last update Wed Jun 14 01:54:32 2017 Lucas Gambini
*/

#include "Race.hpp"

using namespace indie;

Race::Race(irr::scene::ISceneManager *sceneManager, irr::gui::IGUIEnvironment* guiManager, EventReceiver *eventReceiver, physics::CBulletPhysics *bulletPhysicsSystem):
    AGameObject(sceneManager), _carWatcher(NULL, Circuit().getCheckpoints(), this, sceneManager) {
    this->_gui = guiManager;
    this->_eventReceiver = eventReceiver;
    this->_bulletPhysSys = bulletPhysicsSystem;
    this->_player = NULL;
    this->_currentPlayerAmount = 0;
}

Race::~Race() {

}

void Race::OnFrame() {
    this->_carWatcher.OnFrame();
    for (auto check : this->_circuit.getCheckpoints()) {
        if (check.getID() == this->_n1Check) {
            check.setChVisible(true);
        } else if (check.getID() == this->_n2Check) {
            check.setChVisible(true);
        } else if (check.getID() == this->_n3Check) {
            check.setChVisible(true);
        } else {
            check.setChVisible(false);
        }
    }
    for (auto &ai: this->_aiCars)
        ai->OnFrame();
}

void Race::InitCircuit() {
    int i = 10000;
    this->_circuit << std::pair<irr::core::vector3df const&, irr::core::vector3df const &>(irr::core::vector3df(37.936714, 34.5, 0.023841), irr::core::vector3df(-3.097296, 1.548306, 3.094469));
    this->_circuit << std::pair<irr::core::vector3df const&, irr::core::vector3df const &>(irr::core::vector3df(25.886589, 34.5, 0.781414), irr::core::vector3df(-3.097296, 1.548306, 3.094469));
    this->_circuit << std::pair<irr::core::vector3df const&, irr::core::vector3df const &>(irr::core::vector3df(15.927394, 34.5, -8.893885), irr::core::vector3df(-3.097296, 1.548306, 3.094469));
    this->_circuit << std::pair<irr::core::vector3df const&, irr::core::vector3df const &>(irr::core::vector3df(32.856030, 34.5, -9.161504), irr::core::vector3df(-3.097296, 1.548306, 3.094469));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(63.486103, 0, -5.896246));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(83.421402, 0, -8.153623));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(103.780258, 0, -4.346308));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(117.091095, 0, 0.646901));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(129.799805, 0, 12.325266));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(132.167374, 0, 33.860195));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(135.678467, 0, 78.331772));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(140.261765, 0, 136.372253));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(143.539978, 0, 188.870239));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(139.341476, 0, 217.380295));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(143.606552, 0, 249.585281));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(146.530106, 0, 263.688538));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(159.904831, 0, 275.473022));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(194.594681, 0, 276.970428));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(227.457291, 0, 272.408752));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(286.860657, 0, 269.559174));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(337.511597, 0, 265.320282));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(366.841309, 0, 262.207062));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(388.477966, 0, 275.413361));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(408.151947, 0, 318.007263));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(405.803436, 0, 354.118866));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(405.372467, 0, 394.978577));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(406.589203, 0, 421.466553));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(407.966980, 0, 450.357971));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(409.532684, 0, 477.916809));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(412.378174, 0, 496.950195));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(420.129150, 0, 511.525970));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(440.441132, 0, 525.009827));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(479.404510, 0, 527.982361));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(527.555176, 0, 525.911987));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(574.259888, 0, 524.090576));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(634.141296, 0, 523.805786));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(666.241150, 0, 523.996155));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(706.453674, 0, 523.822998));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(726.961914, 0, 514.574341));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(735.036560, 0, 504.552551));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(738.810181, 0, 481.175812));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(737.958313, 0, 456.548767));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(728.770203, 0, 416.022400));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(713.151611, 0, 369.307831));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(700.085449, 0, 325.505737));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(692.661987, 0, 297.762451));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(687.266174, 0, 281.147156));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(676.669128, 0, 266.840881));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(667.162537, 0, 260.871033));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(646.274170, 0, 259.757843));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(593.791443, 0, 261.339325));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(550.205383, 0, 263.714233));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(508.175751, 0, 265.748474));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(472.080719, 0, 266.535278));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(443.345337, 0, 267.192657));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(416.587402, 0, 269.082153));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(400.853699, 0, 266.147614));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(386.692749, 0, 245.961014));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(384.536346, 0, 207.959595));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(386.878021, 0, 149.068710));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(388.694550, 0, 80.970871));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(386.202728, 0, 31.856476));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(378.023193, 0, -29.353628));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(358.023438, 0, -103.111282));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(347.834900, 0, -137.843857));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(337.904327, 0, -170.417084));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(325.340729, 0, -199.539398));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(306.709930, 0, -219.287170));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(275.988922, 0, -233.497040));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(220.008545, 0, -244.003342));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(177.677887, 0, -244.838318));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(130.724564, 0, -243.030945));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(70.278206, 0, -245.716583));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(21.070351, 0, -247.1000));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(-33.524269, 0, -248.633591));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(-83.354424, 0, -250.032669));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(-124.888290, 0, -251.198944));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(-166.455521, 0, -252.366257));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(-204.735199, 0, -252.385742));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(-253.507446, 0, -249.289093));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(-294.208771, 0, -248.186111));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(-328.857666, 0, -247.247849));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(-354.914978, 0, -246.522232));
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(-393.625824, 0, -244.262512));

    this->_carWatcher.setCheckpoints(this->_circuit.getCheckpoints());
}

void Race::setPlayer(Car *player) {
    this->_player = player;
    this->_player->setPosition(this->_circuit.getStartingBlock(this->_currentPlayerAmount).first);
    this->_player->setRotation(this->_circuit.getStartingBlock(this->_currentPlayerAmount).second);
    this->_currentPlayerAmount++;

    this->_carWatcher.setCar(this->_player);

    this->_cCheck = 0;
    this->_n1Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;
    this->_n2Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;
    this->_n3Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;
}

void Race::push_ennemy(Car *ennemy) {
    this->_ennemies.push_back(ennemy);
    this->_currentPlayerAmount++;
}

void Race::addAICar() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 7.0);
    AICar *car = new AICar(this->_smgr, this->_gui, this->_eventReceiver, this->_bulletPhysSys, this->_circuit, dist(mt));
    car->setPosition(this->_circuit.getStartingBlock(this->_currentPlayerAmount).first);
    car->setRotation(this->_circuit.getStartingBlock(this->_currentPlayerAmount).second);
    this->_aiCars.push_back(car);
    this->_currentPlayerAmount++;
}

void Race::OnEnterInCourseChPt(GameCheckpoint const &ch) {
    if (ch.getID() == this->_n1Check) {
        this->_n1Check = this->_n2Check;
        this->_n2Check = this->_n3Check;
        this->_n3Check = (this->_circuit.getCheckpoints().size() > this->_cCheck ? this->_circuit.getCheckpoints()[this->_cCheck].getID() : -9); this->_cCheck++;
        for (auto check : this->_circuit.getCheckpoints()) {
            if (check.getID() == ch.getID()) {
                check.setChVisible(false);
            }
        }
    }
}

int Race::getCurrentPlayerAmount() const {
    return this->_currentPlayerAmount;
}
