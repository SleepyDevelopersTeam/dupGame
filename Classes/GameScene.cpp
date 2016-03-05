#include "GameScene.h"


USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    /**  you can create scene with following comment code instead of using csb file.*/
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto paraNode = ParallaxNode::create();

	/*auto background = Sprite::create("backgroundPara.png");
	paraNode->addChild(background, -1, Vec2(0.4f, 0), Vec2::ZERO);

	auto middleLayer = Sprite::create("middlePara.png");
	paraNode->addChild(middleLayer, 1, Vec2(2, 0), Vec2::ZERO);

	auto topLayer = Sprite::create("topPara.png");
	paraNode->addChild(topLayer, -1, Vec2(4.0f, 0), Vec2::ZERO);

	this->addChild(paraNode);
	*/
    
    return true;
}
