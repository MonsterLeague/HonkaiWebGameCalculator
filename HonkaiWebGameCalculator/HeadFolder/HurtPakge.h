#pragma once
#include "role.h"

class HurtPakge {
	int round;				//�غ���
	int phyDamage;			//�����˺�
	int eleDamage;			//Ԫ���˺�
	int attackNum;			//��ɴ���
	bool movable;			//�������
	bool skillable;			//��Ĭ���
	int burnTimes;			//��ȼ
	int burnHurt;			//��ȼ�˺�
	int accuracyAffected;	//�����ʽ���buff
	int attackDebuff;		//�˺����ý���buff
	int attackDown;			//�������½�buff
	int deffenceDown;		//�������½�buff
	int superSkillFlag;		//��ɱ����־
	bool isOutput;
	Role *resource;
public:
	HurtPakge() {}
	HurtPakge(int phy, int ele) :phyDamage(phy), eleDamage(ele) {
		initRound();
		init();
	}
	void init() {
		this->phyDamage = 0;
		this->eleDamage = 0;
		this->attackNum = 1;
		this->movable = 0;
		this->skillable = 0;
		this->burnTimes = 0;
		this->burnHurt = 0;
		this->accuracyAffected = 0;
		int attackDebuff = 0;
		int attackDown = 0;
		int deffenceDown = 0;
		int superSkillFlag = 0;
	}
	int addRound() {
		round++;
	}
	int initRound() {
		round = 0;
	}
	//getting
	int getRound() {
		return this->round;
	}
	int getPhyDamage() {
		return this->phyDamage;
	}
	int getEleDamage() {
		return this->eleDamage;
	}
	int getAttackNum() {
		return this->attackNum;
	}
	int getMovable() {
		return this->movable;
	}
	int getSkillable() {
		return this->skillable;
	}
	int getBurnTimes() {
		return this->burnTimes;
	}
	int getBurnHurt() {
		return this->burnHurt;
	}
	int getAccuracyAffected() {
		return this->accuracyAffected;
	}
	int getAttackDebuff() {
		return this->attackDebuff;
	}
	int getAttackDown() {
		return this->attackDown;
	}
	int getDeffenceDown() {
		return this->deffenceDown;
	}
	int getSuperSkillFlag() {
		return this->superSkillFlag;
	}
	bool getIsOutput() {
		return this->isOutput;
	}
	Role* getResource() {
		return this->resource;
	}

	//setting
	void setRound(int round) {
		this->round = round;
	}
	void setPhyDamage(int phyDamage) {
		this->phyDamage = phyDamage;
	}
	void setEleDamage(int eleDamage) {
		this->eleDamage = eleDamage;
	}
	void setAttackNum(int attackNum) {
		this->attackNum = attackNum;
	}
	void setMovable(bool movable) {
		this->movable = movable;
	}
	void setSkillable(bool skillable) {
		this->skillable = skillable;
	}
	void setBurnTimes(int burnTimes) {
		this->burnTimes = burnTimes;
	}
	void setBurnHurt(int burnHurt) {
		this->burnHurt = burnHurt;
	}
	void setAccuracyAffected(int accuracyAffected) {
		this->accuracyAffected = accuracyAffected;
	}
	void setAttackDebuff(int attackDebuff) {
		this->attackDebuff = attackDebuff;
	}
	void setAttackDown(int effect) {
		this->attackDown = effect;
	}
	void setDeffenceDown(int effect) {
		this->deffenceDown = effect;
	}
	void setSuperSkillFlag(int effect) {
		this->superSkillFlag = effect;
	}
	void setIsOutput(int isOutput) {
		this->isOutput = isOutput;
	}
	void setResource(Role* role) {
		this->resource = role;
	}
};