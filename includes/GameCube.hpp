//
// Cube.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio/includes/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Sun May  7 20:26:16 2017 Sousa Victor
// Last update Tue May  9 19:17:01 2017 Sousa Victor
//

#ifndef GAMECUBE_HPP
#define GAMECUBE_HPP

#include "AGameObject.hpp"

namespace indie {

    class GameCube : public AGameObject, public irr::scene::IMeshSceneNode {

    public:
        GameCube(irr::scene::ISceneManager *sceneManager, std::shared_ptr<irrBulletWorld> world,
                 irr::f32 size, irr::f32 mass, irr::scene::ISceneNode *parent, irr::s32 id,
                 const irr::core::vector3df &position = irr::core::vector3df(0,0,0),
                 const irr::core::vector3df &rotation = irr::core::vector3df(0,0,0),
                 const irr::core::vector3df &scale = irr::core::vector3df(1.0f, 1.0f, 1.0f));
         GameCube(const GameCube &obj);
         GameCube &operator=(const GameCube &obj);
        ~GameCube();

        virtual void OnFrame();

        //CCubeSceneNode
        void render();
        const irr::core::aabbox3d<irr::f32>& getBoundingBox() const;

        //IMeshSceneNode
        void setMesh(irr::scene::IMesh* mesh);
        irr::scene::IMesh* getMesh(void);
        irr::scene::IShadowVolumeSceneNode *addShadowVolumeSceneNode(const irr::scene::IMesh *shadowMesh = 0, irr::s32 id = -1, bool zfailmethod = true, irr::f32 infinity = 1000.0f);
        void setReadOnlyMaterials(bool readonly);
        bool isReadOnlyMaterials() const;

    private:
        irr::scene::IMeshSceneNode *_cube;
        ICollisionShape *_shape;
        IRigidBody *_body;

    public: ///!\ do not ever think to touch this!   we are redirecting ISceneNode function with custom parameter
		virtual const irr::c8* getName() const {
			return this->_cube->getName();
		}
		virtual void setName(const irr::c8* name) {
			this->_cube->setName(name);
		}
		virtual void setName(const irr::core::stringc& name) {
			this->_cube->setName(name);
		}
		virtual const irr::core::aabbox3d<irr::f32> getTransformedBoundingBox() const {
            return this->_cube->getTransformedBoundingBox();
		}
        virtual const irr::core::matrix4& getAbsoluteTransformation() const {
			return this->_cube->getAbsoluteTransformation();
		}
		virtual irr::core::matrix4 getRelativeTransformation() const {
            return this->_cube->getRelativeTransformation();
		}
		virtual bool isVisible() const {
            return this->_cube->isVisible();
		}
		virtual bool isTrulyVisible() const {
            return this->_cube->isTrulyVisible();
		}
		virtual void setVisible(bool isVisible) {
            this->_cube->setVisible(isVisible);
		}
        virtual irr::s32 getID() const {
			return this->_cube->getID();
		}
		virtual void setID(irr::s32 id) {
            this->_cube->setID(id);
		}
		virtual void addChild(irr::scene::ISceneNode* child) {
            this->_cube->addChild(child);
		}
		virtual bool removeChild(irr::scene::ISceneNode* child) {
            return this->_cube->removeChild(child);
		}
		virtual void removeAll() {
            this->_cube->removeAll();
		}
		virtual void remove() {
            this->_cube->remove();
		}
		virtual void addAnimator(irr::scene::ISceneNodeAnimator* animator) {
            this->_cube->addAnimator(animator);
		}
		const irr::core::list<irr::scene::ISceneNodeAnimator*>& getAnimators() const {
			return this->_cube->getAnimators();
		}
		virtual void removeAnimator(irr::scene::ISceneNodeAnimator* animator) {
            this->_cube->removeAnimator(animator);
		}
		virtual void removeAnimators() {
            this->_cube->removeAnimators();
		}
		virtual irr::video::SMaterial& getMaterial(irr::u32 num) {
			return this->_cube->getMaterial(num);
		}
		virtual irr::u32 getMaterialCount() const {
			return this->_cube->getMaterialCount();
		}
		void setMaterialFlag(irr::video::E_MATERIAL_FLAG flag, bool newvalue) {
            this->_cube->setMaterialFlag(flag, newvalue);
		}
		void setMaterialTexture(irr::u32 textureLayer, irr::video::ITexture* texture) {
            this->_cube->setMaterialTexture(textureLayer, texture);
		}
		void setMaterialType(irr::video::E_MATERIAL_TYPE newType) {
            this->_cube->setMaterialType(newType);
		}
		virtual const irr::core::vector3df& getScale() const {
			return this->_cube->getScale();
		}
		virtual void setScale(const irr::core::vector3df& scale) {
            this->_cube->setScale(scale);
		}
		virtual const irr::core::vector3df& getRotation() const {
			return this->_cube->getRotation();
		}
		virtual void setRotation(const irr::core::vector3df& rotation) {
			this->_cube->setRotation(rotation);
		}
		virtual const irr::core::vector3df& getPosition() const {
			return this->_cube->getPosition();
		}
		virtual void setPosition(const irr::core::vector3df& newpos) {
			this->_cube->setPosition(newpos);
		}
		virtual irr::core::vector3df getAbsolutePosition() const {
			return this->_cube->getAbsolutePosition();
		}
		void setAutomaticCulling( irr::u32 state) {
			this->_cube->setAutomaticCulling(state);
		}
		irr::u32 getAutomaticCulling() const {
			return this->_cube->getAutomaticCulling();
		}
		virtual void setDebugDataVisible(irr::u32 state) {
			this->_cube->setDebugDataVisible(state);
		}
		irr::u32 isDebugDataVisible() const {
			return this->_cube->isDebugDataVisible();
		}
		void setIsDebugObject(bool debugObject) {
			this->_cube->setIsDebugObject(debugObject);
		}
		bool isDebugObject() const {
            return this->_cube->isDebugObject();
		}
		const irr::core::list<irr::scene::ISceneNode*>& getChildren() const {
			return this->_cube->getChildren();
		}
		virtual void setParent(irr::scene::ISceneNode* newParent) {
            this->_cube->setParent(newParent);
		}
		virtual irr::scene::ITriangleSelector* getTriangleSelector() const {
			return this->_cube->getTriangleSelector();
		}
		virtual void setTriangleSelector(irr::scene::ITriangleSelector* selector) {
			this->_cube->setTriangleSelector(selector);
		}
		virtual void updateAbsolutePosition() {
			this->_cube->updateAbsolutePosition();
		}
		irr::scene::ISceneNode* getParent() const {
			return this->_cube->getParent();
		}
		virtual irr::scene::ESCENE_NODE_TYPE getType() const {
			return this->_cube->getType();
		}
		virtual void serializeAttributes(irr::io::IAttributes* out, irr::io::SAttributeReadWriteOptions* options=0) const {
			this->_cube->serializeAttributes(out, options);
		}
		virtual void deserializeAttributes(irr::io::IAttributes* in, irr::io::SAttributeReadWriteOptions* options=0) {
			this->_cube->deserializeAttributes(in, options);
		}
		virtual irr::scene::ISceneNode* clone(irr::scene::ISceneNode* newParent=0, irr::scene::ISceneManager* newManager=0) {
			return this->_cube->clone();
		}
		virtual irr::scene::ISceneManager* getSceneManager(void) const {
            return this->_cube->getSceneManager();
        }

    };

}

#else

namespace indie {
    class GameCube : public AGameObject, public irr::scene::IMeshSceneNode;
}

#endif /*GAMECUBE_HPP*/
