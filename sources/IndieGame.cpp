//
// IndieGame.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 05:48:01 2017 Sousa Victor
// Last update Sun Jun 11 18:10:47 2017 Sousa Victor
//

#include "IndieGame.hpp"

using namespace indie;

IndieGame::IndieGame(int width, int height) : AGame(width, height) {
    _pos = NULL;
    bulletPhysSys = NULL;
    _mainmenu = NULL;
    this->_connectedTo = "-1";
}

IndieGame::~IndieGame() {

}

void IndieGame::addGameObject() {
    bulletPhysSys = new physics::CBulletPhysics();
	if (bulletPhysSys->Create() == false) {
		printf("bullet init failed..");
	}

    irr::scene::ISceneNode* skydome = this->_smgr->addSkyDomeSceneNode(this->_driver->getTexture("skybox/Skydome1.png"),16,8,0.95f,2.0f);
    this->_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);

    int i = 10000;
    this->_circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, i++, GameCheckpoint::IN_COURSE, 3, irr::core::vector3df(6.177781, 0, 0.647438));
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

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 7.0);
    this->_car = new Car(this->_smgr, this->_gui, this, bulletPhysSys, this->_circuit, dist(mt));
    this->_objectList.push_back(this->_car);

    this->_aiCar = NULL; //NE PAS ENLEVER / COMMENTER
    this->_aiCar = new AICar(this->_smgr, this->_gui, this, bulletPhysSys, this->_circuit, 0);
    this->_objectList.push_back(this->_aiCar);

    int j = 1;
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, j++, GameCheckpoint::ONLINE, 3, irr::core::vector3df(20, 0, 0)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, j++, GameCheckpoint::COURSE, 3, irr::core::vector3df(40, 0, 0)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, j++, GameCheckpoint::GARAGE, 10, irr::core::vector3df(384.2, 0, 4.4)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, j++, GameCheckpoint::COURSE, 10, irr::core::vector3df(200, 0, 0)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, j++, GameCheckpoint::CONCESSIONNAIRE, 10, irr::core::vector3df(280, 0, 0)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, j++, GameCheckpoint::ONLINE, 10, irr::core::vector3df(313.75, 0, -215.9)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, j++, GameCheckpoint::GARAGE, 10, irr::core::vector3df(-1700.6, 0, 70.4)));

    this->_carWatch = new carWatcher(this->_car, this->_checkpoints, this, this->_smgr);
    this->_objectList.push_back(this->_carWatch);

    this->_events = new RandomEvent(this->_smgr, this->_carWatch);
    this->_objectList.push_back(this->_events);

    Minimap *map = new Minimap(this->_smgr, NULL, -1, this->_car, this->_carWatch, this->_driver, this->_device, this->_gui, this->getWindowSize());
    this->_objectList.push_back(map);

    // Menu *_menu = new Menu(this->_gui, this->_driver, this->_windowSize);
    // _menu->SetupGUI();
    // this->_objectList.push_back(_menu);

    // Settings *settings = new Settings(this->_gui);

    loadMap();

    irr::scene::ILightSceneNode *sun_node;
    irr::video::SLight sun_data;
    sun_node = this->_smgr->addLightSceneNode();
    sun_data.Direction = irr::core::vector3df(0, 0, 0);
    sun_data.Type = irr::video::ELT_DIRECTIONAL;
    sun_data.AmbientColor = irr::video::SColorf(0.1f, 0.1f, 0.1f, 1);
    sun_data.SpecularColor = irr::video::SColorf(0.4f, 0.4f, 0.4f, 1);
    sun_data.DiffuseColor = irr::video::SColorf(1.0f, 1.0f, 1.0f, 1);
    sun_data.CastShadows = true;
    sun_node->setLightData(sun_data);
    sun_node->setPosition(irr::core::vector3df(0, 0, 0));
    sun_node->setRotation(irr::core::vector3df(0, 0, 0));
    this->_smgr->setAmbientLight(irr::video::SColorf(1.85, 1.85, 2, 2.5));

    this->_garage = NULL;
    this->_menu = NULL;
    this->_course = NULL;
    this->_onlineUI = NULL;
    this->_concessionnaire = NULL;

    //GUI DEBUG
    this->_pos = this->_gui->addStaticText(L"", irr::core::rect<irr::s32>(20, 20, 400, 400));
    this->_pos->setTextAlignment(irr::gui::EGUIA_SCALE , irr::gui::EGUIA_SCALE);

}

void IndieGame::loadMap() {
    irr::scene::IMesh* mesh_road = this->_smgr->getMesh(std::string("BigCity/BigCityRoad_1.obj").c_str());
    irr::scene::IMeshSceneNode *node_road = this->_smgr->addOctreeSceneNode(mesh_road, 0, -1);
    node_road->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    bulletPhysSys->AddMeshSceneNode(node_road, node_road->getMesh(), true);


    irr::scene::IMesh* mesh_road2 = this->_smgr->getMesh(std::string("BigCity/BigCityRoad_2.obj").c_str());
    irr::scene::IMeshSceneNode *node_road2 = this->_smgr->addOctreeSceneNode(mesh_road2, 0, -1);
    node_road2->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    bulletPhysSys->AddMeshSceneNode(node_road2, node_road2->getMesh(), true);

    #ifndef DEBUG
        irr::scene::IMesh* mesh1 = this->_smgr->getMesh(std::string("BigCity/BigCity_1.obj").c_str());
        irr::scene::IMeshSceneNode *node1 = this->_smgr->addOctreeSceneNode(mesh1, 0, -1);
        node1->setMaterialFlag(irr::video::EMF_LIGHTING, true);
        bulletPhysSys->AddMeshSceneNode(node1, node1->getMesh(), true);

        irr::scene::IMesh* mesh2 = this->_smgr->getMesh(std::string("BigCity/BigCity_2.obj").c_str());
        irr::scene::IMeshSceneNode *node2 = this->_smgr->addOctreeSceneNode(mesh2, 0, -1);
        node2->setMaterialFlag(irr::video::EMF_LIGHTING, true);
        bulletPhysSys->AddMeshSceneNode(node2, node2->getMesh(), true);
    #endif
}

void IndieGame::addEventReceiver() {
    int i = 0;
    this->_operation["connected_to"] = i++;
    this->_operation["truc velocity"] = i++;
    this->_operation["truc engine"] = i++;
    // this->_operation["setid"] = i++;
    // this->_operation["getmoney"] = i++;
    // this->_operation["connected"] = i++;
    // this->_operation["cardata"] = i++;
    // this->_operation["disconnect"] = i++;
    // this->_operation["move"] = i++;
    // this->_operation["newcourseplayer"] = i++;
    // this->_operation["addcars"] = i++;
    Client::Instance().init(this);
    Client::Instance().requestId();
}

void IndieGame::OnFrame() {

    this->lockEventBuffer();
    for (auto const &str: this->_cmdBuffer) {
        switch (this->_operation[str.first]) {
            case 0:
                this->_connectedTo = str.second->get_map()["connected_to"]->get_string();
                this->_car->mustSendData(true);
                break;
            case 1:
                this->updateCarsData(str.second);
                break;
            case 2:
                this->updateCarsPosition(str.second);
                break;
            default:
                std::cerr << "Command not found" << std::endl;
                break;
            // case 0:
            //     Client::Instance().setId(data("id"));
            //     break;
            // case 1:
            //     std::cout << data("value") << std::endl;
            //     break;
            // case 2:
            //     this->_connectedTo = std::atoi(data("value").c_str());
            //     this->_car->mustSendData(true);
            //     break;
            // case 3:
            //     updateCarsData(data);
            //     break;
            // case 4:
            //     this->_connectedTo = -1;
            //     this->_car->mustSendData(false);
            //     break;
            // case 5:
            //     updateCarsPosition(data);
            //     break;
            // case 6:
            //     if (this->_course)
            //         this->_course->addPlayer(std::atoi(data("id").c_str()));
            // case 7:
            //     this->addNetworkCar(data);
            //     break;
            // default:
            //     std::cerr << "Command not found" << std::endl;
            //     break;
        }
    }
    this->_cmdBuffer.clear();
    this->unlockEventBuffer();

    if (!_pos)
        return;
    // std::string str("      \nspeed: " + std::to_string(this->_car->getVel()) + "\nmax speed: " + std::to_string(this->_car->getMaxSpeed()));
    std::string str("            \nonline id: " + Client::Instance().getShortId() + "\nconnected to id: " + this->_connectedTo);

    this->_pos->setText(Utils::StrToWstr(str));

    if (!bulletPhysSys)
        return;
    bulletPhysSys->OnUpdate(DeltaTimer::DeltaTime * 1000);
}

void IndieGame::updateCarsData(sio::message::ptr const &msg) {
    if (this->_cars.count(msg->get_map()["id"]->get_int()) == 0)
        return;
    this->_cars[msg->get_map()["id"]->get_int()]->setEngineForce(msg->get_map()["engine"]->get_double());
    this->_cars[msg->get_map()["id"]->get_int()]->setBreakingForce(msg->get_map()["breaking"]->get_double());
    this->_cars[msg->get_map()["id"]->get_int()]->setSteeringValue(msg->get_map()["steering"]->get_double());
    irr::core::vector3df pos(0, 0, 0);
    pos.X = msg->get_map()["LinearX"]->get_double();
    pos.Y = msg->get_map()["LinearY"]->get_double();
    pos.Z = msg->get_map()["LinearZ"]->get_double();
    this->_cars[msg->get_map()["id"]->get_int()]->setLinearVelocity(pos);
    pos.X = msg->get_map()["AngularX"]->get_double();
    pos.Y = msg->get_map()["AngularY"]->get_double();
    pos.Z = msg->get_map()["AngularZ"]->get_double();
    this->_cars[msg->get_map()["id"]->get_int()]->setAngularVelocity(pos);
}

void IndieGame::updateCarsPosition(sio::message::ptr const &msg) {
    if (this->_cars.count(msg->get_map()["id"]->get_int()) == 0)
        return;
    irr::core::vector3df pos(0, 0, 0);
    pos.X = msg->get_map()["posX"]->get_double();
    pos.Y = msg->get_map()["posY"]->get_double();
    pos.Z = msg->get_map()["posZ"]->get_double();
    this->_cars[msg->get_map()["id"]->get_int()]->setPosition(pos);
    pos.X = msg->get_map()["rotX"]->get_double();
    pos.Y = msg->get_map()["rotY"]->get_double();
    pos.Z = msg->get_map()["rotZ"]->get_double();
    this->_cars[msg->get_map()["id"]->get_int()]->setRotation(pos);
}

// void IndieGame::addNetworkCar(Message &msg) {
//     if (this->_cars.count(std::atoi(msg("id").c_str())) == 0) {
//         Car *nc = new NetworkCar(this->_smgr, this->_gui, this, bulletPhysSys, this->_circuit, std::atoi(msg("car_no").c_str()));
//         this->_cars[std::atoi(msg("id").c_str())] = nc;
//         this->_objectList.push_back(nc);
//     }
// }

bool IndieGame::OnEvent(const irr::SEvent& event){
    if (event.EventType == irr::EET_GUI_EVENT) {
        irr::s32 id = event.GUIEvent.Caller->getID();
        switch(event.GUIEvent.EventType) {
            case irr::gui::EGET_BUTTON_CLICKED:
                switch(id) {
                    case Garage::REPAIR:
                        //this->_car->repair();
                        break;
                    case Garage::LEAVE:
                        OnLeavingGarage();
                        break;
                    case Menu::SETTING:
                        _menu->OnEnterSetting();
                        this->_objectList.push_back(this->_menu->getSettings());
                        this->_guiVisible.push_back(this->_menu->getSettings());
                        this->guiVisible(this->_menu->getSettings());
                        break;
                   case Settings::GRAPHIC:
                        _menu->getSettings()->OnEnterGraphic();
                        this->_objectList.push_back(this->_menu->getSettings()->getGraphic());
                        this->_guiVisible.push_back(this->_menu->getSettings()->getGraphic());
                        this->guiVisible(this->_menu->getSettings()->getGraphic());
                        break;
                   case Settings::AUDIO:
                        _menu->getSettings()->OnEnterAudio();
                        this->_objectList.push_back(this->_menu->getSettings()->getAudio());
                        this->_guiVisible.push_back(this->_menu->getSettings()->getAudio());
                        this->guiVisible(this->_menu->getSettings()->getAudio());
                        break;
                   case Settings::KEYBOARD:
                        _menu->getSettings()->OnEnterKeyboard();
                        this->_objectList.push_back(this->_menu->getSettings()->getKeyboard());
                        this->_guiVisible.push_back(this->_menu->getSettings()->getKeyboard());
                        this->guiVisible(this->_menu->getSettings()->getKeyboard());
                        break;
                   case Keyboard::up:
                       _menu->getSettings()->getKeyboard()->resetUp();
                       break;
                   case Keyboard::down:
                       _menu->getSettings()->getKeyboard()->resetDown();
                       break;
                   case Keyboard::left:
                       _menu->getSettings()->getKeyboard()->resetLeft();
                       break;
                   case Keyboard::right:
                       _menu->getSettings()->getKeyboard()->resetRight();
                       break;
                   case Keyboard::forward:
                       _menu->getSettings()->getKeyboard()->resetForward();
                       break;
                   case Keyboard::backward:
                       _menu->getSettings()->getKeyboard()->resetBackward();
                       break;
                   case Keyboard::space:
                       _menu->getSettings()->getKeyboard()->resetBrake();
                       break;
                   case Keyboard::quit:
                       _menu->getSettings()->getKeyboard()->setVisible(false);
                       break;
                    case Audio::PLUS:
                      _menu->getSettings()->getAudio()->plus();
                      break;
                  case Audio::MOIN:
                      _menu->getSettings()->getAudio()->moin();
                      break;
                    case Menu::RESUME:
                        OnLeavingMenu();
                        break;
                    case Menu::QUIT:
                        this->_device->closeDevice();
                        // Client::Instance().stop();
                        break;
                    case Concessionnaire::LEAVE:
                         this->_concessionnaire->setVisible(false);
                         break;
                    case Concessionnaire::NEXTC:
                        this->_concessionnaire->colorManager(1);
                        break;
                    case Concessionnaire::PREVC:
                        this->_concessionnaire->colorManager(0);
                        break;
                    case Course::RUN:
                        //LANCER LA COURSE SA MERE
                        break;
                    case Course::CANCEL:
                        OnLeavingCourse();
                        break;
                    case Audio::Quit:
                        _menu->getSettings()->getAudio()->setVisible(false);
                        break;
                    case JoinServer::LEAVE:
                        this->OnLeavingOnline();
                        break;
                    case JoinServer::JOIN:
                        if (this->_connectedTo == "-1")
                            Client::Instance().joinId(this->_onlineUI->getText());
                        this->OnLeavingOnline();
                        break;
                    case MainMenu::PLAY:
                        // this->_image = this->_driver->getTexture("misc/loading.jpg");
                        // this->_driver->draw2DImage(this->_image, irr::core::position2d<irr::s32>(0, 0), irr::core::rect<irr::s32>(0, 0, this->_windowSize.Width, this->_windowSize.Height));
                        delete _mainmenu;
                        _mainmenu = NULL;
                        addEventReceiver();
                        addGameObject();
                        this->_device->getCursorControl()->setVisible(false);
                        break;
                    case MainMenu::MULTIJOUEUR:
                        //todo écran sein dés
                        break;
                    case MainMenu::QUIT:
                        this->_device->closeDevice();
                        break;
                    default:
                        break;
                }
            default:
                break;
         }
    }

    return EventReceiver::OnEvent(event);
}

void IndieGame::OnEnterCourse(GameCheckpoint const &ch) {
    if (!this->_course) {
        this->_course = new Course(this->_gui, this->_driver, this->_windowSize);
        this->_course->SetupGUI();
        this->_objectList.push_back(this->_course);
        this->_guiVisible.push_back(this->_course);
    }
    this->_course->setVisible(true);
    this->_device->getCursorControl()->setVisible(true);
    this->_smgr->getActiveCamera()->setInputReceiverEnabled(false);
    this->guiVisible(this->_course);
    // Client::Instance().creatingCourseLobby(ch.getID());
}

void IndieGame::OnLeavingCourse() {
    this->_course->setVisible(false);
    this->_device->getCursorControl()->setVisible(false);
    this->_smgr->getActiveCamera()->setInputReceiverEnabled(true);
    // Client::Instance().leavingCourseLobby();
}

void IndieGame::OnEnterGarage(void) {
    if (!this->_garage) {
        this->_garage = new Garage(this->_gui, this->_driver, this->_windowSize);
        this->_garage->SetupGUI();
        this->_objectList.push_back(this->_garage);
        this->_guiVisible.push_back(this->_garage);
    }
    this->_garage->setVisible(true);
    this->_device->getCursorControl()->setVisible(true);
    this->_smgr->getActiveCamera()->setInputReceiverEnabled(false);
    this->guiVisible(_garage);
}

void IndieGame::OnLeavingGarage(void) {
    this->_garage->setVisible(false);
    this->_device->getCursorControl()->setVisible(false);
    this->_smgr->getActiveCamera()->setInputReceiverEnabled(true);
}

void IndieGame::OnLeavingMenu() {
    this->_menu->setVisible(false);
    this->_device->getCursorControl()->setVisible(false);
    this->_smgr->getActiveCamera()->setInputReceiverEnabled(true);
}

void IndieGame::OnOpenningMenu()
{
    if (!this->_menu)
    {
        this->_menu = new Menu(this->_gui, this->_driver, this->_windowSize);
        this->_menu->SetupGUI();
        this->_objectList.push_back(this->_menu);
        this->_guiVisible.push_back(this->_menu);
    }
    if (this->_menu->isVisible() == true) {
        this->_device->getCursorControl()->setVisible(false);
        this->_smgr->getActiveCamera()->setInputReceiverEnabled(true);
        this->_menu->setVisible(false);
    } else {
        this->_device->getCursorControl()->setVisible(true);
        this->_smgr->getActiveCamera()->setInputReceiverEnabled(false);
        this->_menu->setVisible(true);
    }
    this->guiVisible(_menu);
}

void IndieGame::launchMenu()
{
    _mainmenu = new MainMenu(_gui, _driver, _windowSize);
    _mainmenu->SetupGUI();
    //_objectList.push_back(_mainmenu);
}

void IndieGame::OnEnterMoney() {
    // Client::Instance().addMoney(200);
}

void IndieGame::OnEnterInCourseChPt(GameCheckpoint const &ch) {
}

void IndieGame::OnEnterOnline() {
    if (!this->_onlineUI) {
        this->_onlineUI = new JoinServer(this->_gui, this->_driver, this->_windowSize);
        this->_onlineUI->SetupGUI();
        this->_objectList.push_back(this->_onlineUI);
        this->_guiVisible.push_back(this->_onlineUI);
    }
    this->_onlineUI->setVisible(true);
    this->_device->getCursorControl()->setVisible(true);
    this->_smgr->getActiveCamera()->setInputReceiverEnabled(false);
    this->guiVisible(_onlineUI);
}

void IndieGame::OnLeavingOnline() {
    this->_onlineUI->setVisible(false);
    this->_device->getCursorControl()->setVisible(false);
    this->_smgr->getActiveCamera()->setInputReceiverEnabled(true);
}

void IndieGame::OnEnterConcess(void) {
    if (!this->_concessionnaire) {
        this->_concessionnaire = new Concessionnaire(this->_gui, this->_driver, this->_windowSize);
        this->_concessionnaire->SetupGUI();
        this->_objectList.push_back(this->_concessionnaire);
        this->_guiVisible.push_back(this->_concessionnaire);
    }
    this->_concessionnaire->setVisible(true);
    this->_device->getCursorControl()->setVisible(true);
    this->_smgr->getActiveCamera()->setInputReceiverEnabled(false);
    this->guiVisible(_concessionnaire);
}

void IndieGame::OnLeavingConcess(void) {
    this->_concessionnaire->setVisible(false);
    this->_device->getCursorControl()->setVisible(false);
    this->_smgr->getActiveCamera()->setInputReceiverEnabled(true);
}

void IndieGame::guiVisible(IGUI *obj)
{
    for (auto & gui : _guiVisible)
    {
        if (gui->isVisible() == true && gui != obj)
            gui->setVisible(false);
    }
}

void IndieGame::OnEnterKey(irr::EKEY_CODE keyCode) {
    if (_mainmenu)
        return;
    switch (keyCode) {
        case irr::KEY_ESCAPE:
            OnOpenningMenu();
            break;
        case irr::KEY_KEY_Q: // TMP POUR DEBUG LE GUI COURSE
            if (this->_course)
                this->_course->addPlayer(10);
            break;
        case irr::KEY_SPACE: //TMP POUR EXPORTER LA POS DE LA COM DANS UN FICHIER
            system(std::string("echo " + std::to_string(this->_smgr->getActiveCamera()->getPosition().X) + ", 0, " + std::to_string(this->_smgr->getActiveCamera()->getPosition().Z) + " >> pos").c_str());
            break;
        default:
            break;
    }
}

void IndieGame::OnReleaseKey(irr::EKEY_CODE keyCode) {
    (void)keyCode;
}
