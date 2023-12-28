#include"TowerBase.h"
TowerBase::~TowerBase()
{
	CC_SAFE_RELEASE_NULL(towerPanel);//�ͷ�ָ������ָ��
	CC_SAFE_RELEASE_NULL(target);//�ͷ�ָ�򹥻�Ŀ���ָ��
	CC_SAFE_RELEASE_NULL(gradeMark);//�ͷŵȼ���ָ��
}
TowerBase* TowerBase::init(TowerType type, Vec2 targetPos)
{
	if (type != BOTTLE && type != STAR && type != SHIT)
		return nullptr;
	else {
		switch (type) {
			case BOTTLE:
<<<<<<< HEAD
				towerPanel = Sprite::create(ƿ��������)��
=======
				towerPanel = Sprite::create(ƿ��������);
>>>>>>> 3cc07b4 (lyy2)
					break;
			case STAR:
				towerPanel = Sprite::create(����������);
					break;
			case SHIT:
				towerPanel = Sprite::create(ʺ������);
				break;
			default:
				break;
		}
		towerPanel->setPosition(targetPos);//���þ����λ��
		this->addChild(towerPanel);//���������ӵ�������
		setParameter();//���ò���
		return this;//���س�ʼ���ɹ��ı�־
	}
}
<<<<<<< HEAD
bool TowerBase::upGrade(std::string&FileName)
{
	if (grade <= TOWER_MAX_GRADE && checkMoney()) {
		grade++;
		CC_SAFE_RELEASE_NULL(gradeMark);
		gradeMark = Sprite::create(FileName + std::to_string(grade));//�����ȼ���ͼƬ
=======
bool TowerBase::upGrade(int money)
{
	if (grade <= TOWER_MAX_GRADE && checkMoney(money)) {
		grade++;
		CC_SAFE_RELEASE_NULL(gradeMark);
		gradeMark = Sprite::create(TowerTypeName[type] + std::to_string(grade));//�����ȼ���ͼƬ
>>>>>>> 3cc07b4 (lyy2)

		attack += dAttack;//���ӹ�����
		setDAttack(dAttack + BOTTLE_EVERY_ATTACK);//���ӹ�����������

		attackRange += dAttackRange;//���ӹ�����Χ
		setDAttackRange(dAttackRange + BOTTLE_EVERY_ATTACK_RANGE);//���ӹ�����Χ������

		upCost += dUpCost;//��������ʱ�Ļ���
		setDUpCost(dUpCost + BOTTLE_EVERY_UP_COST);//��������ʱ�Ļ��ѵ�����
		return true;
	}
	else
		return false;
}
<<<<<<< HEAD
bool TowerBase::checkMoney()
{
	if (getMoney() >= upCost)
=======
bool TowerBase::checkMoney(int money)
{
	if (money >= upCost)
>>>>>>> 3cc07b4 (lyy2)
		return true;
	else
		return false;
}
bool TowerBase::isInAttackRange(VictimEntityBase* newTarget)
{
	auto targetPos = newTarget->getPosition();//��ȡĿ���λ��
	auto myPos = towerPanel->getPosition();//��ȡ��������λ��
	auto dis = myPos.distance(targetPos);//�������֮��ľ���
<<<<<<< HEAD
	if (dis <= getAttackRange())
=======
	if (dis <= attackRange)
>>>>>>> 3cc07b4 (lyy2)
		return true;
	else
		return false;
}
void TowerBase::setTarget(VictimEntityBase* newTarget)
{
	target = nullptr;
	target = newTarget;//�����µĹ���Ŀ��
	setHaveTarget(true);
}
void TowerBase::chooseTarget()
{
	MonsterVec& monsters = MonsterManager::getVec();//��ȡ�洢�����vector
	if (!target) {//���û�й���Ŀ��
		for (auto currentMonster : monsters)//��һ�ѹ�����ѡ��һ���ڷ�Χ�ڵĹ���
		{
			if (isInAttackRange(currentMonster)) {//����ù���λ�ڹ�����Χ��
				setTarget(currentMonster);//���ù�����Ϊ����Ŀ��
				setHaveTarget(true);//�����Ƿ��й����״̬
				break;
			}
		}
	}
}
void TowerBase::fire()
{
	if (target && !target->getIsDead())
		fireAction();
	else if (target->getIsDead())
		missTarget();
}
void TowerBase::missTarget()
{
	target = nullptr;
}
void TowerBase::showGradeMark()
{
	gradeMark->setVisible(true);
}
void TowerBase::hideGradeMark()
{
	gradeMark->setVisible(false);
}