#pragma once

class Pack {
public:
	//形で変わる
	virtual double GetPackSize() = 0; //サイズの取得、派生先で実装を必須にする、形に大路て実装

	//形で変わる
	virtual void InputSize() = 0;     //サイズの入力、派生先で実装を必須にする、形に大路て実装

	//重さ
	virtual double GetPackWeight() = 0;
};

//ここが箱の大きさ
class Box:public Pack {
public : //宣言フェイズ
	double width;  // 幅
	double height; // 高さ
	double depth;  // 奥行

	double weight; // 重さ
	
	double GetPackSize() override { //派生元の宣言されたVirtualを再定義する
		return width + height + depth;
	}

	double GetPackWeight() override {//派生元の宣言されたVirtualを再定義する
		return weight;
	}

	Box(double w=0,double h=0, double d=0 , double we = 0) {
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
		
		std::cout << "重さを入力(kg)";
		std::cin >> weight;
	}

};

//ここが円柱の大きさ
class Cylinder :public Pack {
public: //宣言フェイズ
	double radius; // 半径
	double height; // 高さ

	double weight; // 重さ

	double GetPackSize() override {//派生元の宣言されたVirtualを再定義する
		return radius * 4 + height;
	}

	double GetPackWeight() override {//派生元の宣言されたVirtualを再定義する
		return weight;
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

		std::cout << "重さを入力(kg)";
		std::cin >> weight;
	}
};

//ここで区別された宅配の会社のデータ（大きさなど）を受け取る。＊１
class PackSizeList {
public: //宣言フェイズ
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
public: //宣言フェイズ
	Pack* pack;
	PackSizeList* packSizeList; //ここにきてる。＊１

	//ここで区別された宅配の会社のデータから大きさを区別している。
	double GetPackSize() {
		double judgeSize = 0;

		//サイズ
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

		//重さ
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

