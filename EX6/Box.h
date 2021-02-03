#pragma once

class Pack {
public:
	//�d�� �`�Ɋ֌W�Ȃ��d���͂���̂ŁB
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
class Box :public Pack {
public: //�錾�t�F�C�Y
	double width;  // ��
	double height; // ����
	double depth;  // ���s

	double GetPackSize() override { //�h�����̐錾���ꂽVirtual��Ē�`����
		return width + height + depth;
	}

	Box(double w = 0, double h = 0, double d = 0)// �ϐ�=0�͂Ȃɂ�����Ƃ��͗낪���ɓ���B
	{
		width = w;
		height = h;
		depth = d;
	}

	//class�̏�������
	void InputSize() override { //�h�����̐錾���ꂽVirtual��Ē�`����
		std::cout << "�������(cm)";
		std::cin >> width;
		std::cout << "���������(cm)";
		std::cin >> height;
		std::cout << "���s�������(cm)";
		std::cin >> depth;
	}

};

//�������~���̑傫��
class Cylinder :public Pack {
public: //�錾�t�F�C�Y
	double radius; // ���a
	double height; // ����

	double GetPackSize() override {//�h�����̐錾���ꂽVirtual��Ē�`����
		return radius * 4 + height;
	}

	Cylinder(double r = 0, double h = 0) {
		radius = r;
		height = h;
	}

	//class�̏�������
	void InputSize() override {//�h�����̐錾���ꂽVirtual��Ē�`����
		std::cout << "���a�����(cm)";
		std::cin >> radius;
		std::cout << "���������(cm)";
		std::cin >> height;
	}
};

struct PackSet
{
	double size = 0;
	double weight = 0;
};

//�����ŋ�ʂ��ꂽ��z�̉�Ђ̃f�[�^�i�傫���Ȃǁj��󂯎��
class PackSizeList {
public: //�錾�t�F�C�Y
	PackSet* packSet; //�z���󂯎��
	unsigned int Length;

	PackSizeList(PackSet p[], unsigned int l) {
		packSet = p;
		Length = l;
	}
};

//�Ǝ҂̉ו���\���B
class Takuhai {
public: //�錾�t�F�C�Y�FPackSizeList��Pack�̎Q�Ƃ����
	Pack* pack;
	PackSizeList* packSizeList; //�����ɂ��Ă�

	//�����ŋ�ʂ��ꂽ��z�̉�Ђ̃f�[�^����傫�����ʂ��Ă���B
	double GetPackSize() {
		double judge = 0;
		double packSize = pack->GetPackSize();
		double packWeight = pack->GetWeight();

		//�T�C�Y
		for (int i = 0; i < packSizeList->Length; i++) {
			PackSet* packSet = &packSizeList->packSet[i];
			if (packWeight <= packSizeList->packSet[i].size && packWeight)
			{
				judge = packSizeList->packSet[i].size;
				break;
			}
		}

		return judge;
	}

	Takuhai(Pack* pk, PackSizeList* pks) {
		pack = pk;
		packSizeList = pks;
	}

};

