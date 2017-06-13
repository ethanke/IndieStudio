//
// IndieGame.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 05:48:01 2017 Sousa Victor
// Last update Tue Jun 13 05:27:40 2017 Sousa Victor
//

#include "IndieGame.hpp"

using namespace indie;

IndieGame::IndieGame(int width, int height) : AGame(width, height) {
    _pos = NULL;
    bulletPhysSys = NULL;
    _mainmenu = NULL;
    this->_error = NULL;
    this->_money = NULL;
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

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0.0, 7.0);
    this->_car = new Car(this->_smgr, this->_gui, this, bulletPhysSys, Circuit(), dist(mt));
    this->_objectList.push_back(this->_car);

    int j = 1;
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, j++, GameCheckpoint::ONLINE, 3, irr::core::vector3df(20, 0, 0)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, j++, GameCheckpoint::COURSE, 3, irr::core::vector3df(-5, 0, 0)));
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

    this->_race = new Race(this->_smgr, this->_gui, this, this->bulletPhysSys);
    this->_race->InitCircuit();
    this->_race->setPlayer(this->_car);
    this->_race->addAICar();
    this->_race->addAICar();
    this->_race->addAICar();
    this->_objectList.push_back(this->_race);

    //GUI DEBUG
    // this->_pos = this->_gui->addStaticText(L"", irr::core::rect<irr::s32>(20, 20, 400, 400));
    // this->_pos->setTextAlignment(irr::gui::EGUIA_SCALE , irr::gui::EGUIA_SCALE);
    // this->_pos->setOverrideColor(irr::video::SColor(255, 180, 180, 180));

//     this->_error = this->_gui->addStaticText(L"Error Message", irr::core::rect<irr::s32>(0, 0, this->getWindowSize().Width, this->getWindowSize().Height / 2.5));
//     irr::gui::IGUIFont* font = this->_gui->getFont("misc/error.xml");
//     if (font)
//         this->_error->setOverrideFont(font);
//     this->_error->setOverrideColor(irr::video::SColor(255, 255, 0, 0));
//     this->_error->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
//     this->_error->setVisible(false);
//
//     this->_money = this->_gui->addStaticText(L"0 $", irr::core::rect<irr::s32>(this->getWindowSize().Width - 100, 0, this->getWindowSize().Width, 50));
//     this->_money->setOverrideColor(irr::video::SColor(255, 133, 187, 101));
//     this->_money->setTextAlignment(irr::gui::EGUIA_UPPERLEFT, irr::gui::EGUIA_LOWERRIGHT);
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
    this->_operation["send engine"] = i++;
    this->_operation["send pos"] = i++;
    this->_operation["add car"] = i++;
    this->_operation["delete car"] = i++;
    this->_operation["join race"] = i++;
    this->_operation["leave race"] = i++;
    this->_operation["error message"] = i++;
    Client::Instance().init(this);
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
            case 3:
                this->addNetworkCar(str.second);
                break;
            case 4:
                this->deleteNetworkCar(str.second);
                break;
            case 5:
                if (this->_course)
                    this->_course->addPlayer(str.second->get_map()["short_id"]->get_string());
                break;
            case 6:
                if (this->_course && str.second->get_map()["is_leader"]->get_bool() == true) {
                    this->_course->setVisible(false);
                }
                else if (this->_course)
                    this->_course->ripPlayer(str.second->get_map()["short_id"]->get_string());
                break;
            case 7:
                if (this->_error) {
                    this->_error->setText(Utils::StrToWstr(str.second->get_map()["error"]->get_string()));
                    this->_error->setVisible(true);
                }
                break;
            default:
                std::cerr << "Command not found" << std::endl;
                break;
        }
    }
    this->_cmdBuffer.clear();
    this->unlockEventBuffer();
    //
    // if (_pos) {
    //     std::wstring ws(this->_pos->getText());
    //     std::string get(ws.begin(), ws.end());
    //     std::string str("online id: " + Client::Instance().getShortId() + " && connected to: " + this->_connectedTo);
    //     if (get != str) {
    //         this->_pos->setText(Utils::StrToWstr(str));
    //     }
    // }


    if (bulletPhysSys)
        bulletPhysSys->OnUpdate(DeltaTimer::DeltaTime * 1000);

    // if (this->_error) {
    //     if (this->_error->isVisible() == true) {
    //         this->_errorTimer += DeltaTimer::DeltaTime;
    //         if (this->_errorTimer >= 3) {
    //             this->_error->setVisible(false);
    //             this->_errorTimer = 0;
    //         }
    //     }
    // }
    //
    // if (this->_money) {
    //     std::wstring ws(this->_money->getText());
    //     std::string get(ws.begin(), ws.end());
    //     std::string money = std::to_string(Client::Instance().getMoney());
    //     std::string str(money + "$");
    //     if (str != get) {
    //         this->_money->setText(Utils::StrToWstr(str));
    //     }
    // }
}

void IndieGame::updateCarsData(sio::message::ptr const &msg) {
    if (this->_cars.count(msg->get_map()["short_id"]->get_string()) == 0)
        return;
    this->_cars[msg->get_map()["short_id"]->get_string()]->setEngineForce(msg->get_map()["engine"]->get_double());
    this->_cars[msg->get_map()["short_id"]->get_string()]->setBreakingForce(msg->get_map()["breaking"]->get_double());
    this->_cars[msg->get_map()["short_id"]->get_string()]->setSteeringValue(msg->get_map()["steering"]->get_double());
    irr::core::vector3df pos(0, 0, 0);
    pos.X = msg->get_map()["LinearX"]->get_double();
    pos.Y = msg->get_map()["LinearY"]->get_double();
    pos.Z = msg->get_map()["LinearZ"]->get_double();
    this->_cars[msg->get_map()["short_id"]->get_string()]->setLinearVelocity(pos);
    pos.X = msg->get_map()["AngularX"]->get_double();
    pos.Y = msg->get_map()["AngularY"]->get_double();
    pos.Z = msg->get_map()["AngularZ"]->get_double();
    this->_cars[msg->get_map()["short_id"]->get_string()]->setAngularVelocity(pos);
}

void IndieGame::updateCarsPosition(sio::message::ptr const &msg) {
    if (this->_cars.count(msg->get_map()["short_id"]->get_string()) == 0)
        return;
    irr::core::vector3df pos(0, 0, 0);
    pos.X = msg->get_map()["posX"]->get_double();
    pos.Y = msg->get_map()["posY"]->get_double();
    pos.Z = msg->get_map()["posZ"]->get_double();
    this->_cars[msg->get_map()["short_id"]->get_string()]->setPosition(pos);
    pos.X = msg->get_map()["rotX"]->get_double();
    pos.Y = msg->get_map()["rotY"]->get_double();
    pos.Z = msg->get_map()["rotZ"]->get_double();
    this->_cars[msg->get_map()["short_id"]->get_string()]->setRotation(pos);
}

void IndieGame::addNetworkCar(sio::message::ptr const &msg) {
    if (this->_cars.count(msg->get_map()["car_id"]->get_string()) == 0) {
        Car *nc = new NetworkCar(this->_smgr, this->_gui, this, bulletPhysSys, Circuit(), msg->get_map()["car_no"]->get_int());
        this->_cars[msg->get_map()["car_id"]->get_string()] = nc;
        this->_objectList.push_back(nc);
    }
}

void IndieGame::deleteNetworkCar(sio::message::ptr const &msg) {
    for (std::unordered_map<std::string, Car *>::iterator it = this->_cars.begin(); it != this->_cars.end(); it++) {
        if ((it->first) == msg->get_map()["short_id"]->get_string()) {
            for (auto &obj : this->_objectList) {
                if (obj == it->second) {
                    this->_cars.erase(it);
                    delete obj;
                    obj = NULL;
        		    return;
                }
            }
        }
    }
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
    this->_course->addPlayer(Client::Instance().getShortId());
    Client::Instance().creatingCourseLobby(ch.getID());
}

void IndieGame::OnLeavingCourse() {
    this->_course->setVisible(false);
    this->_device->getCursorControl()->setVisible(false);
    this->_smgr->getActiveCamera()->setInputReceiverEnabled(true);
    Client::Instance().leavingCourseLobby();
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
        case irr::KEY_SPACE: //TMP POUR EXPORTER LA POS DE LA COM DANS UN FICHIER
            system(std::string("echo " + std::to_string(this->_smgr->getActiveCamera()->getPosition().X) + ", 0, " + std::to_string(this->_smgr->getActiveCamera()->getPosition().Z) + "    " + std::to_string(this->_car->getRotation().X) + ", " + std::to_string(this->_car->getRotation().Y) + ", " + std::to_string(this->_car->getRotation().Z) + " >> pos").c_str());
            break;
        default:
            break;
    }
}

void IndieGame::OnReleaseKey(irr::EKEY_CODE keyCode) {
    (void)keyCode;
}
