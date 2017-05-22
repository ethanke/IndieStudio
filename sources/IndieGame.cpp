//
// IndieGame.cpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/sources/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 05:48:01 2017 Sousa Victor
// Last update Mon May 22 23:57:33 2017 Sousa Victor
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

    // irr::SKeyMap keyMap1[5];                    // re-assigne les commandes
    // keyMap1[0].Action = irr::EKA_MOVE_FORWARD;  // avancer
    // keyMap1[0].KeyCode = irr::KEY_KEY_W;        // w
    // keyMap1[1].Action = irr::EKA_MOVE_BACKWARD; // reculer
    // keyMap1[1].KeyCode = irr::KEY_KEY_S;        // s
    // keyMap1[2].Action = irr::EKA_STRAFE_LEFT;   // a gauche
    // keyMap1[2].KeyCode = irr::KEY_KEY_A;        // a
    // keyMap1[3].Action = irr::EKA_STRAFE_RIGHT;  // a droite
    // keyMap1[3].KeyCode = irr::KEY_KEY_D;        // d
    // keyMap1[4].Action = irr::EKA_JUMP_UP;       // saut
    // keyMap1[4].KeyCode = irr::KEY_SPACE;        // barre espace
    // GameCameraFPS *cameraFps1 = new GameCameraFPS(this->_smgr, 0, 100.0f, 0.5f, -1, keyMap1, 5, true, 0.1, false, true);
    // this->_objectList.push_back(cameraFps1);
    // cameraFps1->setFarValue(1000);

    irr::scene::ISceneNode* skydome = this->_smgr->addSkyDomeSceneNode(this->_driver->getTexture("skybox/Skydome1.png"),16,8,0.95f,2.0f);
    this->_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);

    this->_car = NULL; //NE PAS ENLEVER / COMMENTER
    this->_car = new Car(this->_smgr, this->_gui, this, bulletPhysSys, 0);
    this->_objectList.push_back(this->_car);

    // Minimap *map = new Minimap(this->_smgr, NULL, -1, this->_car, this->_driver, this->_device, irr::core::vector3df(0, 0, 0), irr::core::vector3df(5, 5, 5));
    // this->_objectList.push_back(map);

    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, -1, GameCheckpoint::GARAGE, irr::core::vector3df(384.2, 0, 4.4)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, -1, GameCheckpoint::COURSE, irr::core::vector3df(744.1, 0, 502.7)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, -1, GameCheckpoint::CONCESSIONNAIRE, irr::core::vector3df(313.75, 0, -215.9)));
    this->_checkpoints.push_back(GameCheckpoint(this->_smgr, 3, 0, NULL, -1, GameCheckpoint::GARAGE, irr::core::vector3df(-1700.6, 0, 70.4)));

    this->_carWatch = new carWatcher(this->_car, this->_checkpoints, this, this->_smgr);
    this->_objectList.push_back(this->_carWatch);

    this->_events = new RandomEvent(this->_smgr, this->_carWatch);
    this->_objectList.push_back(this->_events);

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
    node_road->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
    node_road->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
    node_road->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
    node_road->addShadowVolumeSceneNode(mesh_road, -1, true);
    bulletPhysSys->AddMeshSceneNode(node_road, node_road->getMesh(), true);


    irr::scene::IMesh* mesh_road2 = this->_smgr->getMesh(std::string("BigCity/BigCityRoad_2.obj").c_str());
    irr::scene::IMeshSceneNode *node_road2 = this->_smgr->addOctreeSceneNode(mesh_road2, 0, -1);
    node_road2->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    node_road2->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
    node_road2->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
    node_road2->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
    node_road2->addShadowVolumeSceneNode(NULL, -1, true);
    bulletPhysSys->AddMeshSceneNode(node_road2, node_road2->getMesh(), true);

    #ifndef DEBUG
        irr::scene::IMesh* mesh1 = this->_smgr->getMesh(std::string("BigCity/BigCity_1.obj").c_str());
        irr::scene::IMeshSceneNode *node1 = this->_smgr->addOctreeSceneNode(mesh1, 0, -1);

        node1->setMaterialFlag(irr::video::EMF_LIGHTING, true);
        node1->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
        node1->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
        node1->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
        node1->addShadowVolumeSceneNode(NULL, -1, true);
        bulletPhysSys->AddMeshSceneNode(node1, node1->getMesh(), true);

        irr::scene::IMesh* mesh2 = this->_smgr->getMesh(std::string("BigCity/BigCity_2.obj").c_str());
        irr::scene::IMeshSceneNode *node2 = this->_smgr->addOctreeSceneNode(mesh2, 0, -1);

        node2->setMaterialFlag(irr::video::EMF_LIGHTING, true);
        node2->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
        node2->setMaterialFlag(irr::video::EMF_BACK_FACE_CULLING, true);
        node2->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING,true);
        node2->addShadowVolumeSceneNode(NULL, -1, true);
        bulletPhysSys->AddMeshSceneNode(node2, node2->getMesh(), true);
    #endif
}

void IndieGame::OnFrame() {
    std::string str("      \nX: " + std::to_string(this->_smgr->getActiveCamera()->getPosition().X) + "\nZ: " + std::to_string(this->_smgr->getActiveCamera()->getPosition().Z));
    this->_pos->setText(Utils::StrToWstr(str));

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
