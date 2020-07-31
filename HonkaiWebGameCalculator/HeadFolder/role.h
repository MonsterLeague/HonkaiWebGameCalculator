#pragma once
#include "HurtPakge.h"
#include <string>

class Role {
private:
	std::string name;
	int attack;
	int defence;
	int speed;//根据速度大小判定下一回合出手方
	int hp;
	int maxHP;
	int accuracy;
	bool member; //是否是单人队伍
	bool movable;//是否被跳过回合
	int skillable;//被沉默几个回合
	int attackDebuff;//伤害永久下降
	int burnTimes;//点燃标记持续时间
	int burnHurt;//点燃标记持续伤害
public:
	Role() { 
		baseInit();
	}
	virtual HurtPakge FisterSkill(HurtPakge& hurtPakge) = 0;		//一技能
	virtual HurtPakge SecondSkill(HurtPakge& hurtPakge) = 0;		//二技能
	virtual void enemyRound(HurtPakge& hurtPakge) = 0;			//敌方回合收到伤害计算方法
	virtual HurtPakge myRound(HurtPakge& hurtPakge) = 0;			//我方回合造成伤害计算方法
	virtual void init() = 0;									//初始化角色
	void baseInit() {
		this->accuracy = 100;
		this->maxHP = 100;
		this->movable = 0;
		this->skillable = 0;
		this->burnHurt = 0;
		this->burnTimes = 0;
		this->attackDebuff = 100;
	}
	std::string getName();
	unsigned int getRandNum();
	HurtPakge basicPakge(HurtPakge& hurtPakge);
	int getHurt(HurtPakge& hurtPakge);
	void cal(HurtPakge& hurtPakge);
	bool isAccuracy();
	void getBurnHurt();

	//increase
	void addHP(int blood);
	void addAttack(int effect);
	void addDefence(int effect);
	void addAccuracy(int effect);
	void addAttackDebuff(int effect);
	
	//setting
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
	void setMovable(bool moveFlag) {
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
	bool getMoveable() {
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
	int superFlag;
public:
	Kiana() {
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(24);
		this->setDefence(11);
		this->setHp(100);
		this->setSpeed(23);
		this->superFlag = 0;
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Mei :public Role {
	int superFlag;
public:
	Mei() {
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(22);
		this->setDefence(12);
		this->setHp(100);
		this->setSpeed(30);
		this->superFlag = 0;
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Bronya :public Role {
	int superFlag;
public:
	Bronya() {
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(21);
		this->setDefence(10);
		this->setHp(100);
		this->setSpeed(20);
		this->superFlag = 0;
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Himeko :public Role {
	int superFlag;
public:
	Himeko() {
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(23);
		this->setDefence(9);
		this->setHp(100);
		this->setSpeed(12);
		this->superFlag = 0;
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Rita :public Role {
	int superFlag;
public:
	Rita() {
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(26);
		this->setDefence(11);
		this->setHp(100);
		this->setSpeed(17);
		this->superFlag = 0;
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Sakura :public Role {
	int superFlag;
public:
	Sakura() {
		this->setMember(0);
		init();
	}
	void init() {
		this->setAttack(20);
		this->setDefence(9);
		this->setHp(100);
		this->setSpeed(18);
		this->superFlag = 0;
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Raven :public Role {
	int superFlag;
public:
	Raven() {
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(23);
		this->setDefence(14);
		this->setHp(100);
		this->setSpeed(14);
		this->superFlag = 0;
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Theresa :public Role {
	int superFlag;
public:
	Theresa() {
		this->setMember(0);
		init();
	}
	void init() {
		this->setAttack(19);
		this->setDefence(12);
		this->setHp(100);
		this->setSpeed(22);
		this->superFlag = 0;
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Rozaliya :public Role {
	int superFlag;
public:
	Rozaliya() {
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

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Seele :public Role {
	int superFlag;
	int passiveFlag;
public:
	Seele() {
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(23);
		this->setDefence(13);
		this->setHp(100);
		this->setSpeed(26);
		this->superFlag = 0;
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Durandal :public Role {
	int superFlag;
	int passiveFlag;
public:
	Durandal() {
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(19);
		this->setDefence(10);
		this->setHp(100);
		this->setSpeed(15);
		this->superFlag = 0;
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Fuhua :public Role {
	int secondFlag;
public:
	Fuhua() {
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(17);
		this->setDefence(15);
		this->setHp(100);
		this->setSpeed(16);
		this->secondFlag = 0;
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};