#include <iostream>
using namespace std;
#include "Box.h"

unsigned int InputUINT(string message, unsigned int max) {
	unsigned int i;
	while (true) {
		cout << message;
		cin >> i;
		if (i < max) { //�ő���傫����������̓G���[�Əo��B
			break;
		}
		else {
			cout << "���̓G���[" << endl;
		}
	}
	return i;
}

int main()
{
	//�N���l�R�̃T�C�Y https://www.kuronekoyamato.co.jp/ytc/search/payment/size/
	double kuronekoSize[] = { 60,80,100,120,160 };
	//�N���l�R�̏d��
	double kuronekoWeight[] = { 2 ,5,10,15,20,25 };

	//JP�̃T�C�Y https://www.post.japanpost.jp/send/fee/kokunai/parcel.html#01
	double jpSize[] = { 60,80,100,120,140,160,170 };
	double jpWeight[] = { 25 };

	//����}�ւ̃T�C�Y https://www.sagawa-exp.co.jp/send/fare/list/sagawa_faretable/attention.html
	double sagawaSize[] = { 60,80,100,140,160,170,180,200,220,240,260 };
	double sagawaWeight[] = { 2,5,10,20,30 };

	unsigned int i = InputUINT("�`�́H�i0:���^ 1:�~��)", 2);

	Pack* pack =nullptr;
	switch (i) { //�����ŃT�C�Y�̎w��ł���class�ֈړ�����
	case 0:
		pack =  new Box();
		break;
	case 1:
		pack =  new Cylinder();
		break;
	default:
		break;
	}
	pack->InputSize();

	Takuhai takuhai = Takuhai();
	takuhai.pack = pack;

	//�����ő�z�̉�Ђ���ʂ��Ă���B
	i = InputUINT("�Ǝ҂́H�i0:�N���l�R 1:JP 2:����)", 3);
	switch (i) { //��ʂ�����Ђ��Ƃ̃f�[�^�����
	case 0: 
		takuhai.packSizeList = new PackSizeList(kuronekoSize,_countof( kuronekoSize) , kuronekoWeight, _countof(kuronekoWeight));
		break;
	case 1:
		takuhai.packSizeList = new PackSizeList(jpSize, _countof(jpSize) , jpWeight,_countof(jpWeight));
		break;
	case 2 :
		takuhai.packSizeList = new PackSizeList(sagawaSize, _countof(sagawaSize) , sagawaWeight,_countof(sagawaWeight));
		break;
	default:
		break;
	}

	//�����ő傫������ʂ���class�Ɉړ�
	double packSize = takuhai.GetPackSize();
	bool packWeight = takuhai.GetPackWeight();

	if (packSize != 0 && packWeight)
	{
		cout << "��z�̃T�C�Y��" << packSize << endl;
		cout << "��z���̏d����" << pack->GetPackWeight() << "(kg)" << endl;
	}
	else if (packSize != 0 && !packWeight) 
	{
		cout << "���̏d���ő�z�͑���܂���" << endl;
	}
	else 
	{
		cout << "��z�ł͑���܂���";
	}

	delete(pack);
	return 0;
}