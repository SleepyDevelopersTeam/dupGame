//
//  LevelStorage.hpp
//  SPH
//
//  Created by v144 on 02.03.16.
//
//

#ifndef LevelStorage_hpp
#define LevelStorage_hpp

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "Definitions.h"

class LevelStorage;

class LevelStorageDestroyer
{
private:
    LevelStorage* instance;
public:
    ~LevelStorageDestroyer();
    void initialize( LevelStorage* p );
};

class LevelStorage {
public:
    static LevelStorage* getInstance();
    cocos2d::Node *getLevel(int levelNumber);
private:
    static LevelStorage* instance;
    static LevelStorageDestroyer destroyer;
    ~LevelStorage() { }
    friend class LevelStorageDestroyer;
};

#endif /* LevelStorage_hpp */
