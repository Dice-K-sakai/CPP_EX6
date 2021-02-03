#pragma once

class Pack {
public:
	//重さ 形に関係なく重さはあるので
	double weight = 0;
	void InputWeight()
	{
		std::cout << "重さを入力(kg)";
		std::cin >> weight;
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

	Box(double w=0,double h=0, double d=0 , double we = 0) // 変数=0はなにも無いときは零が中に入る。
	{
		width = w;
		height = h;
		depth = d;

		weight = we;
	}

	//classの処理部分
	void InputSize() override { //派生元の宣言されたVirtualを再定義する
		std::cout << "幅を入力(cm)";
		std::cin >> width;
		std::cout << "高さを入力(cm)";
		std::cin >> height;
		std::cout << "奥行きを入力(cm)";
		std::cin >> depth;

		Pack::InputWeight();//重さの入力
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

	Cylinder(double r = 0, double h = 0, double we = 0) {
		radius = r;
		height = h;

		weight = we;
	}

	//classの処理部分
	void InputSize() override {//派生元の宣言されたVirtualを再定義する
		std::cout << "半径を入力(cm)";
		std::cin >> radius;
		std::cout << "高さを入力(cm)";
		std::cin >> height;

		Pack::InputWeight();//重さの入力
	}
};

//ここで区別された宅配の会社のデータ（大きさなど）を受け取る
class PackSizeList {
public: //宣言フェイズ
	double* size; //配列を受け取る
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

//業者の荷物を表す。
class Takuhai{
public: //宣言フェイズ：PackSizeListとPackの参照を持つ
	Pack* pack;
	PackSizeList* packSizeList; //ここにきてる

	int sizeLength = 0;

	//ここで区別された宅配の会社のデータから大きさを区別している。
	double GetPackSize() {
		double judgeSize = 0;

		//サイズ
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

		//重さが超えてなければジャッチをトゥルーにする。
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

