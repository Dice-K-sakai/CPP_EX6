#pragma once

class Pack {
public:
	//�d�� �`�Ɋ֌W�Ȃ��d���͂���̂�
	double weight = 0;
	void InputWeight()
	{
		std::cout << "�d�������(kg)";
		std::cin >> weight;
	}

	//�`�ŕς��
	virtual double GetPackSize() = 0; //�T�C�Y�̎擾�A�h����Ŏ�����K�{�ɂ���A�`�ɑ�H�Ď���

	//�`�ŕς��
	virtual void InputSize() = 0;     //�T�C�Y�̓��́A�h����Ŏ�����K�{�ɂ���A�`�ɑ�H�Ď���
};

//���������̑傫��
class Box:public Pack {
public : //�錾�t�F�C�Y
	double width;  // ��
	double height; // ����
	double depth;  // ���s
	
	double GetPackSize() override { //�h�����̐錾���ꂽVirtual���Ē�`����
		return width + height + depth;
	}

	Box(double w=0,double h=0, double d=0 , double we = 0) // �ϐ�=0�͂Ȃɂ������Ƃ��͗낪���ɓ���B
	{
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

		Pack::InputWeight();//�d���̓���
	}

};

//�������~���̑傫��
class Cylinder :public Pack {
public: //�錾�t�F�C�Y
	double radius; // ���a
	double height; // ����

	double GetPackSize() override {//�h�����̐錾���ꂽVirtual���Ē�`����
		return radius * 4 + height;
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

		Pack::InputWeight();//�d���̓���
	}
};

//�����ŋ�ʂ��ꂽ��z�̉�Ђ̃f�[�^�i�傫���Ȃǁj���󂯎��
class PackSizeList {
public: //�錾�t�F�C�Y
	double* size; //�z����󂯎��
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

//�Ǝ҂̉ו���\���B
class Takuhai{
public: //�錾�t�F�C�Y�FPackSizeList��Pack�̎Q�Ƃ�����
	Pack* pack;
	PackSizeList* packSizeList; //�����ɂ��Ă�

	int sizeLength = 0;

	//�����ŋ�ʂ��ꂽ��z�̉�Ђ̃f�[�^����傫������ʂ��Ă���B
	double GetPackSize() {
		double judgeSize = 0;

		//�T�C�Y
		for (int i = 0; i < packSizeList->sizeLength; i++) {
			if (pack->GetPackSize() <= packSizeList->size[i])
			{
				judgeSize = packSizeList->size[i];
				sizeLength = i;
				break;
			}
		}

		return judgeSize;
	}

	bool GetPackWeight() {
		bool judgeWeight = false;

		//�d���������ĂȂ���΃W���b�`���g�D���[�ɂ���B
		for (int w = 0; w < packSizeList->weightLength; w++) {
			if (pack->weight <= packSizeList->weight[sizeLength])
			{
				judgeWeight = true;
				break;
			}
		}

		return judgeWeight;

	}
};

