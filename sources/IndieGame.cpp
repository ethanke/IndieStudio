//
// IndieGame.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 05:48:01 2017 Sousa Victor
// Last update Sun Jun  4 23:59:41 2017 Sousa Victor
//

#include "IndieGame.hpp"

using namespace indie;

IndieGame::IndieGame(int width, int height) : AGame(width, height) {
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

#ifndef AIDEBUG
    // this->_car = NULL; //NE PAS ENLEVER / COMMENTER
    // this->_car = new Car(this->_smgr, this->_gui, this, bulletPhysSys, Circuit(), 0);
    // this->_objectList.push_back(this->_car);
    //
    // this->_aiCar = NULL; //NE PAS ENLEVER / COMMENTER
    // this->_aiCar = new AICar(this->_smgr, this->_gui, this, bulletPhysSys, Circuit(), 0);
    // this->_objectList.push_back(this->_aiCar);

    Circuit *circuit = new Circuit();
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10001, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(41.907440, 0, -1.561529));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10002, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(98.776421, 0, -2.324740));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10003, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(117.770309, 0, -3.066118));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10004, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(130.029495, 0, -18.802727));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10005, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(132.472397, 0, -42.372440));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10006, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(128.778763, 0, -85.412750));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10007, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(126.353058, 0, -113.734451));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10008, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(123.282791, 0, -152.628357));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 10009, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(133.096786, 0, -173.476974));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100010, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(164.909134, 0, -180.785385));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100011, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(202.363037, 0, -184.392593));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100012, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(236.357895, 0, -188.374603));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100013, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(267.142151, 0, -196.617065));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100014, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(308.940857, 0, -211.333496));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100015, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(352.182251, 0, -222.352295));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100016, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(393.277832, 0, -230.603226));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100017, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(431.864441, 0, -238.350555));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100018, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(473.407959, 0, -246.691513));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100019, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(517.125610, 0, -255.469193));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100020, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(571.248657, 0, -272.288940));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100021, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(589.422485, 0, -281.576874));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100022, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(585.868469, 0, -307.293854));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100023, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(584.245361, 0, -338.126495));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100024, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(582.346680, 0, -374.235809));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100025, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(579.556641, 0, -427.298370));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100026, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(577.992554, 0, -457.046387));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100027, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(575.322815, 0, -489.621002));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100028, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(572.670471, 0, -512.188599));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100029, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(544.540222, 0, -521.229980));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100030, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(493.372131, 0, -516.829346));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100031, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(450.889130, 0, -514.424072));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100032, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(436.077393, 0, -522.799561));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100033, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(427.145966, 0, -548.326843));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100034, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(420.931671, 0, -572.526367));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100035, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(401.181549, 0, -579.828186));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100036, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(353.279633, 0, -562.357910));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100037, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(312.473846, 0, -545.127319));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100038, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(266.363159, 0, -531.269470));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100039, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(215.496124, 0, -520.022034));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100040, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(168.508499, 0, -510.341644));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100041, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(136.110672, 0, -507.059662));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100042, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(112.413773, 0, -494.546112));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100043, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(110.795876, 0, -464.753052));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100044, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(110.948669, 0, -420.985718));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100045, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(112.555084, 0, -376.995361));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100046, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(114.624924, 0, -330.619141));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100047, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(118.452034, 0, -261.921936));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100048, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(121.310341, 0, -210.531403));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100049, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(123.917709, 0, -163.638885));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100051, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(126.520348, 0, -115.915413));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100052, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(129.530014, 0, -59.770920));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100053, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(132.783081, 0, 1.030067));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100054, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(134.732559, 0, 37.498192));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100055, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(137.245346, 0, 84.251678));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100056, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(139.946564, 0, 134.308228));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100057, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(142.427612, 0, 180.247162));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100058, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(144.886276, 0, 225.952103));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100059, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(148.166595, 0, 274.692627));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100060, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(145.837433, 0, 313.119843));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100061, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(146.506607, 0, 358.357056));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100062, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(148.107300, 0, 412.932068));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100063, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(148.319214, 0, 462.972321));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100064, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(148.339890, 0, 500.497253));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100065, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(155.385117, 0, 532.196472));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100066, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(192.651672, 0, 527.302551));
    *circuit << GameCheckpoint(this->_smgr, 0,  0, NULL, 100067, GameCheckpoint::IN_COURSE, 10, irr::core::vector3df(256.374908, 0, 525.204407));

    this->_car = NULL; //NE PAS ENLEVER / COMMENTER
    this->_car = new AICar(this->_smgr, this->_gui, this, bulletPhysSys, *circuit, 0);
    this->_objectList.push_back(this->_car);
#else
    this->_genTrainer = NULL; //NE PAS ENLEVER / COMMENTER
    this->_genTrainer = new GeneticTrainer(this->_smgr, this->_gui, this, bulletPhysSys);
    this->_objectList.push_back(this->_genTrainer);

    irr::SKeyMap keyMap1[5];                    // re-assigne les commandes
    keyMap1[0].Action = irr::EKA_MOVE_FORWARD;  // avancer
    keyMap1[0].KeyCode = irr::KEY_KEY_W;        // w
    keyMap1[1].Action = irr::EKA_MOVE_BACKWARD; // reculer
    keyMap1[1].KeyCode = irr::KEY_KEY_S;        // s
    keyMap1[2].Action = irr::EKA_STRAFE_LEFT;   // a gauche
    keyMap1[2].KeyCode = irr::KEY_KEY_A;        // a
    keyMap1[3].Action = irr::EKA_STRAFE_RIGHT;  // a droite
    keyMap1[3].KeyCode = irr::KEY_KEY_D;        // d
    keyMap1[4].Action = irr::EKA_JUMP_UP;       // saut
    keyMap1[4].KeyCode = irr::KEY_SPACE;        // barre espace
    GameCameraFPS *cameraFps1 = new GameCameraFPS(this->_smgr, 0, 100.0f, 0.5f, -1, keyMap1, 5, true, 0.1, false, true);
    this->_objectList.push_back(cameraFps1);
    cameraFps1->setFarValue(1000);

#endif

    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, -1, GameCheckpoint::GARAGE, 10, irr::core::vector3df(384.2, 0, 4.4)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, -1, GameCheckpoint::ONLINE, 10, irr::core::vector3df(200, 0, 0)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, -1, GameCheckpoint::COURSE, 10, irr::core::vector3df(744.1, 0, 502.7)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, -1, GameCheckpoint::CONCESSIONNAIRE, 10, irr::core::vector3df(313.75, 0, -215.9)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, -1, GameCheckpoint::GARAGE, 10, irr::core::vector3df(-1700.6, 0, 70.4)));

    this->_carWatch = new carWatcher(this->_car, this->_checkpoints, this, this->_smgr);
    this->_objectList.push_back(this->_carWatch);

    this->_events = new RandomEvent(this->_smgr, this->_carWatch);
    this->_objectList.push_back(this->_events);

#ifndef AIDEBUG
    Minimap *map = new Minimap(this->_smgr, NULL, -1, this->_car, this->_carWatch, this->_driver, this->_device, this->_gui, this->getWindowSize());
    this->_objectList.push_back(map);
#endif

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

    //GUI DEBUG
    this->_pos = this->_gui->addStaticText(L"", irr::core::rect<irr::s32>(20, 20, 400, 400));
    this->_pos->setTextAlignment(irr::gui::EGUIA_SCALE , irr::gui::EGUIA_SCALE);

}

void IndieGame::addEventReceiver() {

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

core::vector3df rotateByAngle2(const core::vector3df &vec, const core::vector3df &up, float angle) {
    core::quaternion rotation;
    rotation.fromAngleAxis(angle, up);
    return rotation * vec;
}

void IndieGame::OnFrame() {
#ifndef AIDEBUG
    std::string str("      \nspeed: " + std::to_string(this->_car->getVel()) + "\nmax speed: " + std::to_string(this->_car->getMaxSpeed()));
    this->_pos->setText(Utils::StrToWstr(str));
#else
    std::string str("      \nspeed: " + std::to_string(this->_genTrainer->getCar()->getVel()) + "\nmax speed: " + std::to_string(this->_genTrainer->getCar()->getMaxSpeed()));
    this->_pos->setText(Utils::StrToWstr(str));
#endif

    bulletPhysSys->OnUpdate(DeltaTimer::DeltaTime * 1000);
}

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
                        //QUIT
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
                        this->OnLeavingOnline();
                        // DIRE AU SERVER QUE WESH IL FAUT SE CONNECTER
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

void IndieGame::OnEnterCourse(void) {
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
}

void IndieGame::OnLeavingCourse(void) {
    this->_course->setVisible(false);
    this->_device->getCursorControl()->setVisible(false);
    this->_smgr->getActiveCamera()->setInputReceiverEnabled(true);
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

void IndieGame::OnEnterMoney() {
    //Ajouter de l'argent --> serveur
}

void IndieGame::OnEnterInCourseChPt(GameCheckpoint const &ch) {
    // Dire à la class course de Jordan que la $_car a passé le checkoint $ch
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

void IndieGame::guiVisible(IGUI *obj)
{
    for (auto & gui : _guiVisible)
    {
        if (gui->isVisible() == true && gui != obj)
            gui->setVisible(false);
    }
}

void IndieGame::OnEnterKey(irr::EKEY_CODE keyCode) {
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
