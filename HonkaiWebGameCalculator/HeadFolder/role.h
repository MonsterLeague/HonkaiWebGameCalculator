#pragma once
#include "HurtPakge.h"
#include <string>

class Role {
private:
	std::string name;		//����
	int attack;				//����
	int defence;			//����
	int speed;				//�����ٶȴ�С�ж���һ�غϳ��ַ�
	int hp;					//Ѫ��
	int maxHP;				//Ѫ������
	int accuracy;			//������
	bool member;			//�Ƿ��ǵ��˶���
	int movable;			//�Ƿ������غ�
	int skillable;			//����Ĭ�����غ�
	int attackDebuff;		//�˺������½�
	int burnTimes;			//��ȼ��ǳ���ʱ��
	int burnHurt;			//��ȼ��ǳ����˺�
public:
	Role() { 
		baseInit();
	}
	/*
		һ�����߼��ӿ�
	*/
	virtual HurtPakge FirstSkill(HurtPakge& hurtPakge) = 0;

	/*
		�������߼��ӿ�
	*/
	virtual HurtPakge SecondSkill(HurtPakge& hurtPakge) = 0;

	/*
		�Է��غ�ʱ�ҷ���ɫ��Ϊ
	*/
	virtual void enemyRound(HurtPakge& hurtPakge) = 0;

	/*
		�ҷ��غ�ʱ�ҷ���ɫ��Ϊ
	*/
	virtual HurtPakge myRound(HurtPakge& hurtPakge) = 0;

	/*
		��ɫ��ֵ��ʼ��
	*/
	virtual void init() = 0;

	/*
		������ֵ��ʼ��
	*/
	void baseInit() {
		this->accuracy = 100;
		this->maxHP = 100;
		this->movable = 0;
		this->skillable = 0;
		this->burnHurt = 0;
		this->burnTimes = 0;
		this->attackDebuff = 100;
	}

	/*
		����һ��int��Χ�ڵ������
	*/
	unsigned int getRandNum();

	/*
		����һ��������ֵ�˺���
	*/
	HurtPakge basicPakge(HurtPakge& hurtPakge);

	/*
		���ؼ����˺�
	*/
	int getHurt(HurtPakge& hurtPakge);

	/*
		���˺�����ͨ�������߼�
	*/
	void cal(HurtPakge& hurtPakge);

	/*
		���ظý�ɫ�Ƿ�����
	*/
	bool isAccuracy();

	/*
		�����Ƿ񱻳�Ĭ
	*/
	bool isSkillable(bool isOutput = 0);
	
	__declspec(deprecated) void getBurnHurt();

	/*
		�غϽ���ʱ����
	*/
	void roundEnd();

	//increase
	void addHP(int blood);
	void addAttack(int effect);
	void addDefence(int effect);
	void addAccuracy(int effect);
	void addAttackDebuff(int effect);
	
	//setting
	std::string setName(std::string name) {
		this->name = name;
	}
	void setAttack(int attack) {
		this->attack = attack;
	}
	void setDefence(int defence) {
		this->defence = defence;
	}
	void setSpeed(int speed) {
		this->speed = speed;
	}
	void setHp(int hp) {
		this->hp = hp;
	}
	void setAccuracy(int effect) {
		this->accuracy = effect;
	}
	void setMember(int member) {
		this->member = member;
	}
	void setMovable(int moveFlag) {
		this->movable = moveFlag;
	}
	void setSkillable(int skillFlag) {
		this->skillable = skillFlag;
	}
	void setBurnHurt(int burnTimes, int burnHurt) {
		this->burnTimes = burnTimes;
		this->burnHurt = burnHurt;
	}
	void setAttackDebuff(int effect) {
		this->attackDebuff = effect;
	}
	//getting
	std::string getName() {
		return name;
	}
	int getAttack() {
		return this->attack;
	}
	int getDefence() {
		return this->defence;
	}
	int getSpeed() {
		return this->speed;
	}
	int getHP() {
		return this->hp;
	}
	int getAccuracy() {
		return this->accuracy;
	}
	int getMember() {
		return this->member;
	}
	int getMoveable() {
		return this->movable;
	}
	int getSkillable() {
		return this->skillable;
	}
	int getAttackDebuff() {
		return this->attackDebuff;
	}
};

class Kiana :public Role {
	int firstFlag;
public:
	Kiana() {
		this->setName("������");
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(24);
		this->setDefence(11);
		this->setHp(100);
		this->setSpeed(23);
		this->firstFlag = 2;
		this->baseInit();
	}

	HurtPakge FirstSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Mei :public Role {
	int secondFlag;
public:
	Mei() {
		this->setName("ѿ��");
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(22);
		this->setDefence(12);
		this->setHp(100);
		this->setSpeed(30);
		this->secondFlag = 2;
		this->baseInit();
	}

	HurtPakge FirstSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Bronya :public Role {
	Role* firstFLag;
	int secondFlag;
public:
	Bronya() {
		this->setName("�������");
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(21);
		this->setDefence(10);
		this->setHp(100);
		this->setSpeed(20);
		this->firstFLag = NULL;
		this->secondFlag = 3;
		this->baseInit();
	}

	HurtPakge FirstSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Himeko :public Role {
	int firstFlag;
	int secondFlag;
public:
	Himeko() {
		this->setName("����");
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(23);
		this->setDefence(9);
		this->setHp(100);
		this->setSpeed(12);
		this->firstFlag = 1;
		this->secondFlag = 2;
		this->baseInit();
	}

	HurtPakge FirstSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Rita :public Role {
	int superFlag;
public:
	Rita() {
		this->setName("����");
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(26);
		this->setDefence(11);
		this->setHp(100);
		this->setSpeed(17);
		this->superFlag = 4;
		this->baseInit();
	}

	HurtPakge FirstSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Sakura :public Role {
	int superFlag;
public:
	Sakura() {
		this->setName("����ӣ");
		this->setMember(0);
		init();
	}
	void init() {
		this->setAttack(20);
		this->setDefence(9);
		this->setHp(100);
		this->setSpeed(18);
		this->superFlag = 2;
		this->baseInit();
	}

	HurtPakge FirstSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Raven :public Role {
	int firstFlag;
	int secondFlag;
public:
	Raven() {
		this->setName("��ѻ");
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(23);
		this->setDefence(14);
		this->setHp(100);
		this->setSpeed(14);
		this->firstFlag = 1;
		this->secondFlag = 3;
		this->baseInit();
	}

	HurtPakge FirstSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Theresa :public Role {
	int superFlag;
public:
	Theresa() {
		this->setName("����ɯ");
		this->setMember(0);
		init();
	}
	void init() {
		this->setAttack(19);
		this->setDefence(12);
		this->setHp(100);
		this->setSpeed(22);
		this->superFlag = 3;
		this->baseInit();
	}

	HurtPakge FirstSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Rozaliya :public Role {
	int superFlag;
public:
	Rozaliya() {
		this->setName("���ս���");
		this->setMember(0);
		init();
	}
	void init() {
		this->setAttack(18);
		this->setDefence(10);
		this->setHp(100);
		this->setSpeed(10);
		this->superFlag = 0;
		this->baseInit();
	}

	HurtPakge FirstSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Seele :public Role {
	int firstFlag;
public:
	Seele() {
		this->setName("ϣ��");
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(23);
		this->setDefence(13);
		this->setHp(100);
		this->setSpeed(26);
		this->firstFlag = 0;
		this->baseInit();
	}

	HurtPakge FirstSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Durandal :public Role {
public:
	Durandal() {
		this->setName("��������");
		this->setMember(0);
		init();
	}
	void init() {
		this->setAttack(19);
		this->setDefence(10);
		this->setHp(100);
		this->setSpeed(15);
		this->baseInit();
	}

	HurtPakge FirstSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Fuhua :public Role {
	int firstFlag;
	int secondFlag;
public:
	Fuhua() {
		this->setName("����");
		this->setMember(1);
		this->secondFlag = 3;
		init();
	}
	void init() {
		this->setAttack(17);
		this->setDefence(15);
		this->setHp(100);
		this->setSpeed(16);
		this->firstFlag = 1;
		this->secondFlag = 3;
		this->baseInit();
	}

	HurtPakge FirstSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};