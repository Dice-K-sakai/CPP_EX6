#pragma once

class Pack {
public:
	//重さ 形に関係なく重さはあるので。
	double weight = 0;
	void InputWeight()
	{
		std::cout << "重さを入力(kg)";
		std::cin >> weight;
	}

	double GetWeight() 
	{
		return weight;
	}

	void Input() 
	{
		InputSize();
		InputWeight();
	}

	//形で変わる
	virtual double GetPackSize() = 0; //サイズの取得、派生先で実装を必須にする、形に大路て実装

	//形で変わる
	virtual void InputSize() = 0;     //サイズの入力、派生先で実装を必須にする、形に大路て実装
};

//ここが箱の大きさ
class Box:public Pack {
public : //宣言フェイズ
	double width;  // 幅
	double height; // 高さ
	double depth;  // 奥行
	
	double GetPackSize() override { //派生元の宣言されたVirtualを再定義する
		return width + height + depth;
	}

	Box(double w=0,double h=0, double d=0)// 変数=0はなにも無いときは零が中に入る。
	{
		width = w;
		height = h;
		depth = d;
	}

	//classの処理部分
	void InputSize() override { //派生元の宣言されたVirtualを再定義する
		std::cout << "幅を入力(cm)";
		std::cin >> width;
		std::cout << "高さを入力(cm)";
		std::cin >> height;
		std::cout << "奥行きを入力(cm)";
		std::cin >> depth;
	}

};

//ここが円柱の大きさ
class Cylinder :public Pack {
public: //宣言フェイズ
	double radius; // 半径
	double height; // 高さ

	double GetPackSize() override {//派生元の宣言されたVirtualを再定義する
		return radius * 4 + height;
	}

	Cylinder(double r = 0, double h = 0){
		radius = r;
		height = h;
	}

	//classの処理部分
	void InputSize() override {//派生元の宣言されたVirtualを再定義する
		std::cout << "半径を入力(cm)";
		std::cin >> radius;
		std::cout << "高さを入力(cm)";
		std::cin >> height;
	}
};

struct PackSet
{
	double size = 0;
	double weight = 0;
};

//ここで区別された宅配の会社のデータ（大きさなど）を受け取る
class PackSizeList {
public: //宣言フェイズ
	PackSet* packSet; //配列を受け取る
	unsigned int Length;

	PackSizeList(PackSet p[],unsigned int l) {
		packSet = p;
		Length = l;
	}
};

//業者の荷物を表す。
class Takuhai{
public: //宣言フェイズ：PackSizeListとPackの参照を持つ
	Pack* pack;
	PackSizeList* packSizeList; //ここにきてる

	//ここで区別された宅配の会社のデータから大きさを区別している。
	double GetPackSize() {
		double judge = 0;
		double packSize = pack->GetPackSize();
		double packWeight = pack->GetWeight();

		//サイズ
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

