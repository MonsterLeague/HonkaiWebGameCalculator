#pragma once
#include "HurtPakge.h"
#include <string>

class Role {
private:
	std::string name;		//名字
	int attack;				//攻击
	int defence;			//防御
	int speed;				//根据速度大小判定下一回合出手方
	int hp;					//血量
	int maxHP;				//血量上限
	int accuracy;			//命中率
	bool member;			//是否是单人队伍
	int movable;			//是否被跳过回合
	int skillable;			//被沉默几个回合
	int attackDebuff;		//伤害永久下降
	int burnTimes;			//点燃标记持续时间
	int burnHurt;			//点燃标记持续伤害
public:
	Role() { 
		baseInit();
	}
	/*
		一技能逻辑接口
	*/
	virtual HurtPakge FisterSkill(HurtPakge& hurtPakge) = 0;

	/*
		二技能逻辑接口
	*/
	virtual HurtPakge SecondSkill(HurtPakge& hurtPakge) = 0;

	/*
		对方回合时我方角色行为
	*/
	virtual void enemyRound(HurtPakge& hurtPakge) = 0;

	/*
		我方回合时我方角色行为
	*/
	virtual HurtPakge myRound(HurtPakge& hurtPakge) = 0;

	/*
		角色数值初始化
	*/
	virtual void init() = 0;

	/*
		基础数值初始化
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
		返回一个int范围内的随机数
	*/
	unsigned int getRandNum();

	/*
		返回一个基础数值伤害包
	*/
	HurtPakge basicPakge(HurtPakge& hurtPakge);

	/*
		返回计算伤害
	*/
	int getHurt(HurtPakge& hurtPakge);

	/*
		对伤害包的通常结算逻辑
	*/
	void cal(HurtPakge& hurtPakge);

	/*
		返回该角色是否命中
	*/
	bool isAccuracy();

	/*
		返回是否被沉默
	*/
	bool isSkillable(bool isOutput = 0);
	
	__declspec(deprecated) void getBurnHurt();

	/*
		回合结束时调用
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
	int superFlag;
public:
	Kiana() {
		this->setName("琪亚娜");
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
		this->setName("芽衣");
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
		this->setName("布洛妮娅");
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
		this->setName("姬子");
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
		this->setName("丽塔");
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
		this->setName("八重樱");
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
		this->setName("渡鸦");
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
		this->setName("德莉莎");
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
public:
	Rozaliya() {
		this->setName("阿琳姐妹");
		this->setMember(0);
		init();
	}
	void init() {
		this->setAttack(18);
		this->setDefence(10);
		this->setHp(100);
		this->setSpeed(10);
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Seele :public Role {
public:
	Seele() {
		this->setName("希儿");
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(23);
		this->setDefence(13);
		this->setHp(100);
		this->setSpeed(26);
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};

class Durandal :public Role {
public:
	Durandal() {
		this->setName("幽兰戴尔");
		this->setMember(1);
		init();
	}
	void init() {
		this->setAttack(19);
		this->setDefence(10);
		this->setHp(100);
		this->setSpeed(15);
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
		this->setName("符华");
		this->setMember(1);
		this->secondFlag = 3;
		init();
	}
	void init() {
		this->setAttack(17);
		this->setDefence(15);
		this->setHp(100);
		this->setSpeed(16);
		this->baseInit();
	}

	HurtPakge FisterSkill(HurtPakge& hurtPakge);

	HurtPakge SecondSkill(HurtPakge& hurtPakge);

	HurtPakge myRound(HurtPakge& hurtPakge);

	void enemyRound(HurtPakge& hurtPakge);
};