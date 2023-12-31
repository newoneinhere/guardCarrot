#include "MonsterBase.h"
#include "base/CCScheduler.h"
#include "PublicSourceDefine.h"

void MonsterBase::create(Vec2 position)
{

	init(position);
	switch (nowMonsterType) {
	case NORMAL:monster = Sprite::create(NORMAL01); break;
	case FAST:monster = Sprite::create(FAST01); break;
	case SLOW:monster = Sprite::create(SLOW01); break;
	default:monster = Sprite::create(SLOW01); break;
	}
	beSlowTime = 0;
	monster->setPosition(position);
	myHp->setPosition(Vec2(monster->getContentSize().width / 2, monster->getContentSize().height + 0));
	monster->addChild(myHp);
	myHp->setScale(0.5);
	victim = monster;

}

bool MonsterBase::init( Vec2 position)
{
	if (!VictimEntityBase::init())
		return false;
	startPosition = position;
	void srand(unsigned int seed);
	int type;
	type= (rand() % 3) + 1;
	nowMonsterType = static_cast<MonsterType>(type);
	myHp = new Hp;
	switch (nowMonsterType)
	{
		case NORMAL:normSpeed = 1; slowSpeed = normSpeed / 2; nowSpeed = normSpeed; myHp->init(50); money = 100; break;
		case FAST:normSpeed = 0.5; slowSpeed = normSpeed / 2; nowSpeed = normSpeed; myHp->init(30); money = 80; break;
		case SLOW:normSpeed = 1.5; slowSpeed = normSpeed / 2;  nowSpeed = normSpeed; myHp->init(70); money = 120; break;
		default:normSpeed = 1.5; slowSpeed = normSpeed / 2;  nowSpeed = normSpeed; myHp->init(70); money = 120; break;
	}
	return true;
}

bool MonsterBase::monsterMove(std::vector<Vec2> path, MonsterType type)
{
	/*auto animation = Animation::create();//创建移动动画
	for (int i = 1; i <= 2; ++i) {
		std::string frameName;
		switch (type) {
		case NORMAL: frameName = StringUtils::format("pictures/items/normal0%d.png", i); break;
		case FAST: frameName = StringUtils::format("pictures/items/fast0%d.png", i); break;
		case SLOW: frameName = StringUtils::format("pictures/items/slow0%d.png", i); break;
		default: break;
		}
		auto texture = Director::getInstance()->getTextureCache()->addImage(frameName);
		auto frame = SpriteFrame::createWithTexture(texture, Rect(0, 0, texture->getContentSize().width, texture->getContentSize().height));

		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName);
		animation->addSpriteFrame(frame);
	}
	animation->setDelayPerUnit(0.2f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);*/

	auto moveAction1 = MoveTo::create(getNowSpeed(), path[1]);
	auto moveAction2 = MoveTo::create(getNowSpeed(), path[2]);
	auto moveAction3 = MoveTo::create(getNowSpeed(), path[3]);
	auto moveAction4 = MoveTo::create(getNowSpeed(), path[4]);
	auto moveAction5 = MoveTo::create(getNowSpeed(), path[5]);
	auto moveAction6 = MoveTo::create(getNowSpeed(), path[6]);
	auto moveAction7 = MoveTo::create(getNowSpeed(), path[7]);
	auto moveAction8 = MoveTo::create(getNowSpeed(), path[8]);
	auto moveAction9 = MoveTo::create(getNowSpeed(), path[9]);
	auto moveAction10 = MoveTo::create(getNowSpeed(), path[10]);

	auto moveAction11 = MoveTo::create(getNowSpeed(), path[11]);
	auto moveAction12 = MoveTo::create(getNowSpeed(), path[12]);
	auto moveAction13 = MoveTo::create(getNowSpeed(), path[13]);
	auto moveAction14 = MoveTo::create(getNowSpeed(), path[14]);
	auto moveAction15 = MoveTo::create(getNowSpeed(), path[15]);
	auto moveAction16 = MoveTo::create(getNowSpeed(), path[16]);
	auto moveAction17 = MoveTo::create(getNowSpeed(), path[17]);
	auto moveAction18 = MoveTo::create(getNowSpeed(), path[18]);
	auto moveAction19 = MoveTo::create(getNowSpeed(), path[19]);
	auto moveAction20 = MoveTo::create(getNowSpeed(), path[20]);

	auto moveAction21 = MoveTo::create(getNowSpeed(), path[21]);
	auto moveAction22 = MoveTo::create(getNowSpeed(), path[22]);
	auto moveAction23 = MoveTo::create(getNowSpeed(), path[23]);
	auto moveAction24 = MoveTo::create(getNowSpeed(), path[24]);
	auto moveAction25 = MoveTo::create(getNowSpeed(), path[25]);
	auto moveAction26 = MoveTo::create(getNowSpeed(), path[26]);
	auto moveAction27 = MoveTo::create(getNowSpeed(), path[27]);
	auto moveAction28 = MoveTo::create(getNowSpeed(), path[28]);
	auto moveAction29 = MoveTo::create(getNowSpeed(), path[29]);
	auto moveAction30 = MoveTo::create(getNowSpeed(), path[30]);

	auto moveAction31 = MoveTo::create(getNowSpeed(), path[31]);
	auto moveAction32 = MoveTo::create(getNowSpeed(), path[32]);
	auto moveAction33 = MoveTo::create(getNowSpeed(), path[33]);
	auto moveAction34 = MoveTo::create(getNowSpeed(), path[34]);

	// 创建动作序列，按顺序执行 moveAction1 和 moveAction2
	/*auto sequence = Sequence::create(
		moveAction1, moveAction2, moveAction3, moveAction4,
		moveAction5, moveAction6, moveAction7, moveAction8,
		moveAction9, moveAction10, moveAction11, moveAction12,
		moveAction13, moveAction14,moveAction15, moveAction16, 
		moveAction17, moveAction18,moveAction19, moveAction20,
		moveAction21, moveAction22, moveAction23, moveAction24,
		moveAction25, moveAction26, moveAction27, moveAction28,
		moveAction29, moveAction30, moveAction31, moveAction32, 
		moveAction33, moveAction34,nullptr);*/
	// 将动作序列应用到节点上
	//yourNode->runAction(sequence);

	//// 添加动作到 actions 中
	//actions.pushBack(moveAction);
	//actions.pushBack(rotateAction);
	//actions.pushBack(scaleAction);

	// 使用 Sequence 执行动作（按顺序执行）
	//auto sequence = Sequence::create(actions);

	// 或者使用 Spawn 同时执行动作
	// auto spawn = Spawn::create(actions);

	// 将动作应用到节点上
	/*yourNode->runAction(sequence);*/
	auto sequence = Sequence::create(moveAction1, moveAction2, moveAction3, moveAction4,
		moveAction5, moveAction6, moveAction7, moveAction8,
		moveAction9, moveAction10, moveAction11, moveAction12,
		moveAction13, moveAction14, moveAction15, moveAction16,
		moveAction17, moveAction18, moveAction19, moveAction20,
		moveAction21, moveAction22, moveAction23, moveAction24,
		moveAction25, moveAction26, moveAction27, moveAction28,
		moveAction29, moveAction30, moveAction31, moveAction32,
		moveAction33, moveAction34,nullptr);

	monster->runAction(sequence);
	return true;
	//auto moveAction = MoveTo::create(nowSpeed, currentPath);//创建移动
	////auto spawnAction = Spawn::create(moveAction, animate);//创建同时动作
	//monster->runAction(moveAction);
}

void MonsterBase::hurtAction()
{
	auto shit = Sprite::create(SHIT_ON_MONSTER);
	if (getBeSlowTime() > 0) {
		monster->addChild(shit,10);
		shit->setPosition(Vec2(monster->getContentSize().width / 2, 0));
	}
	std::function<void(float)> slowDown = [this, shit](float)
	{
		if (getBeSlowTime() > 0) {
			setNowSpeed(getSlowSpeed());
			setBeSlowTime(getBeSlowTime() - 1);
			if (getBeSlowTime() == 0) {
				shit->removeFromParent();
				unschedule("Slowdownshit");
			}
		}
	};
	monster->schedule(slowDown, 1.0f, "Slowdownshit");
}

/*void MonsterBase::move(float dt, MonsterType type)
{
	auto animation = Animation::create();//创建移动动画
	for (int i = 1; i <= 2; ++i) {
		switch (type) {
		case NORMAL:auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("pictures/items/normal0%d.png", i)); animation->addSpriteFrame(frame); break;
		case FAST:auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("pictures/items/fast0%d.png", i)); animation->addSpriteFrame(frame); break;
		case SLOW:auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("pictures/items/slow0%d.png", i)); animation->addSpriteFrame(frame); break;
		default:break;
		}
	}
	animation->setDelayPerUnit(0.2f);
	animation->setLoops(-1);
	auto animate = Animate::create(animation);
	for (int i = 0; i < path.size() - 1; i++) {
		auto moveAction = MoveTo::create(nowSpeed, path[i]);//创建移动
		auto spawnAction = Spawn::create(moveAction, animate);//创建同时动作
		this->runAction(spawnAction);
	}
}*/

void MonsterBase::whenDead()
{
	VictimEntityBase::whenDead();
	AudioManager::getInstance()->playKillSound();
	monster = nullptr;
}

Sprite* MonsterBase::setVictim(Vec2 _position)
{
	if (position == _position) {
		IsTarget = true;
	}
	if (IsTarget)
		return monster;
}

void MonsterBase::unsetVictim()
{
	IsTarget = false;
}
