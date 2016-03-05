////
//  Created by v144 on 02.03.16.
//
//

#include "LevelStorage.hpp"

LevelStorage* LevelStorage::instance=NULL;
LevelStorageDestroyer LevelStorage::destroyer;

LevelStorageDestroyer::~LevelStorageDestroyer()
{
    delete instance;
}


void LevelStorageDestroyer::initialize( LevelStorage* p ) {
    instance = p;
}

LevelStorage* LevelStorage::getInstance()
{
    if (instance==NULL)
    {
        instance = new LevelStorage;
        destroyer.initialize(instance);
    }
    return instance;
}

cocos2d::Node *LevelStorage::getLevel(int levelNumber)
{
    std::string levelName="res/Level"+std::to_string(levelNumber)+".csb";
    cocos2d::Node* node = cocos2d::CSLoader::createNode(levelName);
    auto vectorOfNodes=node->getChildren();
    for(auto i=vectorOfNodes.begin();i!=vectorOfNodes.end();++i)
    {
        //if (  std::strcmp( ((char*)( (*i)->getUserData() )),"floor") || std::strcmp( ((char*)( (*i)->getUserData() )),"box") || std::strcmp( ((char*)( (*i)->getUserData() )),"chest")) //if we use userData
            if ((*i)->getTag()==TAG_OF_BOX || (*i)->getTag()==TAG_OF_CHEST || (*i)->getTag()==TAG_OF_FLOOR) // if we use tags
        {
            auto body = cocos2d::PhysicsBody::createBox((*i)->getContentSize());
            body->setDynamic(false);
            body->setCategoryBitmask(1);
            body->setCollisionBitmask(1);
            body->setContactTestBitmask(1);
            body->setGravityEnable(false);
            body->setEnabled(true);
            (*i)->setPhysicsBody(body);
        }
    }
    return node;
}