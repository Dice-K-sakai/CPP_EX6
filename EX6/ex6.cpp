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
	double kuronekoSize[] = { 60,80,100,120,160 };
	//クロネコの重さ
	double kuronekoWeight[] = { 2 ,5,10,15,20,25 };

	//JPのサイズ https://www.post.japanpost.jp/send/fee/kokunai/parcel.html#01
	double jpSize[] = { 60,80,100,120,140,160,170 };
	double jpWeight[] = { 25 };

	//佐川急便のサイズ https://www.sagawa-exp.co.jp/send/fare/list/sagawa_faretable/attention.html
	double sagawaSize[] = { 60,80,100,140,160,170,180,200,220,240,260 };
	double sagawaWeight[] = { 2,5,10,20,30 };

	unsigned int i = InputUINT("形は？（0:箱型 1:円柱)", 2);

	Pack* pack =nullptr;
	switch (i) { //ここでサイズの指定できるclassへ移動する
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

	//ここで宅配の会社を区別している。
	i = InputUINT("業者は？（0:クロネコ 1:JP 2:佐川)", 3);
	switch (i) { //区別した会社ごとのデータを搬送
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

	//ここで大きさを区別するclassに移動
	double packSize = takuhai.GetPackSize();
	bool packWeight = takuhai.GetPackWeight();

	if (packSize != 0 && packWeight)
	{
		cout << "宅配のサイズは" << packSize << endl;
		cout << "宅配物の重さは" << pack->GetPackWeight() << "(kg)" << endl;
	}
	else if (packSize != 0 && !packWeight) 
	{
		cout << "この重さで宅配は送れません" << endl;
	}
	else 
	{
		cout << "宅配では送れません";
	}

	delete(pack);
	return 0;
}