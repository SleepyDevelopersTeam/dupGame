#include "MainMenuScene.h"
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    /**  you can create scene with following comment code instead of using csb file.*/
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
   
    
    auto backgroundSprite=Sprite::create("backgroundMenu.jpg");
    backgroundSprite->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height/2 + origin.y));
    this->addChild(backgroundSprite);
    
    auto playItem=MenuItemImage::create("button.png","buttonClicked.png",CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));
    
    playItem->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2+origin.y));
    
    auto menu=Menu::create(playItem,NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    auto label = Label::createWithTTF("label test","fonts/arial.ttf",32);
    label->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height-label->getLineHeight()));
    label->enableOutline(Color4B(255,0,0,255),5);
    this->addChild(label);
    
    return true;
}

void  MainMenuScene::GoToGameScene(cocos2d::Ref *sender)
{
    auto scene=GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
