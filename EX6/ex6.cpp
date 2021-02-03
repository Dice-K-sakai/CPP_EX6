#include <iostream>
using namespace std;
#include "Box.h"

unsigned int InputUINT(string message, unsigned int max) {
	unsigned int i;
	while (true) {
		cout << message;
		cin >> i;
		if (i < max) { //最大より大きかったら入力エラーと出る。
			break;
		}
		else {
			cout << "入力エラー" << endl;
		}
	}
	return i;
}

int main()
{
	//クロネコのサイズ https://www.kuronekoyamato.co.jp/ytc/search/payment/size/
	PackSet kuronekoSet[] = { {60,2},{80,5},{100,10},{120,15},{140,20},{160,25} };

	//JPのサイズ https://www.post.japanpost.jp/send/fee/kokunai/parcel.html#01
	PackSet jpSize[] = { {60,25},{80,25},{100,25},{120,25},{140,25},{160,25},{170,25} };

	//佐川急便のサイズ https://www.sagawa-exp.co.jp/send/fare/list/sagawa_faretable/attention.html
	PackSet sagawaSize[] = { {60,2},{80,5},{100,10},{140,25},{160,30} };


	unsigned int i = InputUINT("形は？（0:箱型 1:円柱)", 2);

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

	//ここで宅配の会社を区別している。
	i = InputUINT("業者は？（0:クロネコ 1:JP 2:佐川)", 3);
	switch (i) { //区別した会社ごとのデータを搬送
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

	//ここで大きさを区別するclassに移動
	double packSize = takuhai->GetPackSize();

	if (packSize != 0)
	{
		cout << "宅配のサイズは" << packSize << endl;
	}
	else 
	{
		cout << "宅配では送れません";
	}

	delete(takuhai);
	delete(pack);
	return 0;
}