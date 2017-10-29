#ifndef CF_CROP_H
#define CF_CROP_H
#include "Plant.h"
#include "BaseFarmland.h"

class BaseFarmLand;

class Crop : public Plant
{
	class CropState* state;																	//״̬�������ڻ������
public:
	Crop(vector<Abstract*>* abs_list, int size, int max_age);
	~Crop(){}
	void absorb_water();																	//����ˮ��
	void weaken(int num);																	//���ٽ���ֵ
	bool defend();																			//��������
	void bloom();																			//����
	void photosynthesis();																	//�������
	void breath();																			//����
	void time_pass_by();																	//ʱ��仯
	void when_atmosphere_changed();															//�����仯
	void update(AbstractType type);															//ʱ��������仯ʱ����
	void grow();																			//����
	void bear_fruit();																		//���
	void reproduce();																		//��ֳ
	void growbigger();																		//��������
	void setState(CropState* s);
	int get_fruit_size() { return (float(fruit_size_))*output_rate_; }
	int get_mature_age() { return mature_age_; }
	void plant_on(BaseFarmLand* farmland);
	void set_output_rate(float new_rate){ output_rate_ = new_rate; }
	float get_output_rate(){ return output_rate_; }
	virtual const char* get_class_name(){ return "Crop"; }
private:
	int fruit_size_;																		//��ʵ�������ʼ��Ϊ0
	int mature_age_;																		//�������䣬��ʼ��Ϊ5
	float output_rate_;																		//������ʣ���ʼ��Ϊ1.0
	void die();
};

class CropState
{
public:
	virtual void grow(Crop* c);
	virtual void reproduce(Crop* c);
};

class Growing :public CropState																//������
{
public:
	void grow(Crop* c);
};

class Mature :public CropState																//������
{
public:
	void reproduce(Crop* c);
};
#endif