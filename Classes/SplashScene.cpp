#include "SplashScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"
#include "cocostudio/CocoStudio.h"

#include "SplashScene.h"
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    /**  you can create scene with following comment code instead of using csb file.*/
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    this->scheduleOnce(schedule_selector(SplashScene::GoToMainMenuScene), DISPLAY_TIME_SPLASH_SCENE);
    
    auto backgroundSprite = Sprite::create("splash.png");
    backgroundSprite->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height/2 + origin.y));
    this->addChild(backgroundSprite);
    
    return true;
}

void SplashScene::GoToMainMenuScene(float dt)
{
    auto scene = MainMenuScene::createScene();
    
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
