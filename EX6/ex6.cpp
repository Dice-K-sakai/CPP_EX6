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
	PackSet kuronekoSet[] = { {60,2},{80,5},{100,10},{120,15},{140,20},{160,25} };

	//JP�̃T�C�Y https://www.post.japanpost.jp/send/fee/kokunai/parcel.html#01
	PackSet jpSize[] = { {60,25},{80,25},{100,25},{120,25},{140,25},{160,25},{170,25} };

	//����}�ւ̃T�C�Y https://www.sagawa-exp.co.jp/send/fare/list/sagawa_faretable/attention.html
	PackSet sagawaSize[] = { {60,2},{80,5},{100,10},{140,25},{160,30} };


	unsigned int i = InputUINT("�`�́H�i0:���^ 1:�~��)", 2);

	Pack* pack =nullptr;
	switch (i) { 
	case 0:
		pack =  new Box();
		break;
	case 1:
		pack =  new Cylinder();
		break;
	default:
		break;
	}
	pack->Input();

	Takuhai* takuhai = nullptr;

	//�����ő�z�̉�Ђ���ʂ��Ă���B
	i = InputUINT("�Ǝ҂́H�i0:�N���l�R 1:JP 2:����)", 3);
	switch (i) { //��ʂ�����Ђ��Ƃ̃f�[�^�����
	case 0: 
		takuhai = new Takuhai(pack,&PackSizeList(kuronekoSet,_countof( kuronekoSet)));
		break;
	case 1:
		takuhai = new Takuhai(pack, &PackSizeList(jpSize, _countof(jpSize)));
		break;
	case 2 :
		takuhai = new Takuhai(pack, &PackSizeList(sagawaSize, _countof(sagawaSize)));
		break;
	default:
		break;
	}

	//�����ő傫������ʂ���class�Ɉړ�
	double packSize = takuhai->GetPackSize();

	if (packSize != 0)
	{
		cout << "��z�̃T�C�Y��" << packSize << endl;
	}
	else 
	{
		cout << "��z�ł͑���܂���";
	}

	delete(takuhai);
	delete(pack);
	return 0;
}