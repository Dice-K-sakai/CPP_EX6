#pragma once

class Pack {
public:
	//�`�ŕς��
	virtual double GetPackSize() = 0; //�T�C�Y�̎擾�A�h����Ŏ�����K�{�ɂ���A�`�ɑ�H�Ď���

	//�`�ŕς��
	virtual void InputSize() = 0;     //�T�C�Y�̓��́A�h����Ŏ�����K�{�ɂ���A�`�ɑ�H�Ď���

	//�d��
	virtual double GetPackWeight() = 0;
};

//���������̑傫��
class Box:public Pack {
public : //�錾�t�F�C�Y
	double width;  // ��
	double height; // ����
	double depth;  // ���s

	double weight; // �d��
	
	double GetPackSize() override { //�h�����̐錾���ꂽVirtual���Ē�`����
		return width + height + depth;
	}

	double GetPackWeight() override {//�h�����̐錾���ꂽVirtual���Ē�`����
		return weight;
	}

	Box(double w=0,double h=0, double d=0 , double we = 0) {
		width = w;
		height = h;
		depth = d;

		weight = we;
	}

	//class�̏�������
	void InputSize() override { //�h�����̐錾���ꂽVirtual���Ē�`����
		std::cout << "�������(cm)";
		std::cin >> width;
		std::cout << "���������(cm)";
		std::cin >> height;
		std::cout << "���s�������(cm)";
		std::cin >> depth;
		
		std::cout << "�d�������(kg)";
		std::cin >> weight;
	}

};

//�������~���̑傫��
class Cylinder :public Pack {
public: //�錾�t�F�C�Y
	double radius; // ���a
	double height; // ����

	double weight; // �d��

	double GetPackSize() override {//�h�����̐錾���ꂽVirtual���Ē�`����
		return radius * 4 + height;
	}

	double GetPackWeight() override {//�h�����̐錾���ꂽVirtual���Ē�`����
		return weight;
	}

	Cylinder(double r = 0, double h = 0, double we = 0) {
		radius = r;
		height = h;

		weight = we;
	}

	//class�̏�������
	void InputSize() override {//�h�����̐錾���ꂽVirtual���Ē�`����
		std::cout << "���a�����(cm)";
		std::cin >> radius;
		std::cout << "���������(cm)";
		std::cin >> height;

		std::cout << "�d�������(kg)";
		std::cin >> weight;
	}
};

//�����ŋ�ʂ��ꂽ��z�̉�Ђ̃f�[�^�i�傫���Ȃǁj���󂯎��B���P
class PackSizeList {
public: //�錾�t�F�C�Y
	double* size;
	unsigned int sizeLength;

	double* weight;
	unsigned int weightLength;

	PackSizeList(double s[],unsigned int ls , double w[] , unsigned int lw) {
		size = s;
		sizeLength = ls;

		weight = w;
		weightLength = lw;
	}
};


class Takuhai{
public: //�錾�t�F�C�Y
	Pack* pack;
	PackSizeList* packSizeList; //�����ɂ��Ă�B���P

	//�����ŋ�ʂ��ꂽ��z�̉�Ђ̃f�[�^����傫������ʂ��Ă���B
	double GetPackSize() {
		double judgeSize = 0;

		//�T�C�Y
		for (int i = 0; i < packSizeList->sizeLength; i++) {
			if (pack->GetPackSize() <= packSizeList->size[i])
			{
				judgeSize = packSizeList->size[i];
				break;
			}
		}

		return judgeSize;
	}

	double GetPackWeight() {
		bool judgeWeight = false;

		//�d��
		for (int w = 0; w < packSizeList->weightLength; w++) {
			if (pack->GetPackWeight() <= packSizeList->weight[w])
			{
				judgeWeight = true;
				break;
			}
		}

		return judgeWeight;

	}
};

