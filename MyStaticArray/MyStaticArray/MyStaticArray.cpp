// MyStaticArray.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"

// Student's name: Naoyuki Yokoyama
// Student's ID: 1635297
#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>
#include "StaticArray.h"


int main()
{
  string buf;
  StaticArray<double, 100> array;
  StaticArray<bool, 100> flag;

  while (true) {
	cout << "Input an index and a value [Q to quit]: ";

	cin >> buf;
	if (buf == "Q" || buf == "q") {
	  break;
	}
	int index = atoi(buf.c_str());
	
	cin >> buf;
	if (buf == "Q" || buf == "q") {
	  break;
	}
	double value = atof(buf.c_str());
	array[index] = value;
	flag[index] = 1;
  }

  int count = 0;
  for (int i = 0; i < flag.capacity(); i++) {
	if (flag[i])
	  count++;
  }

  cout << endl << "You have stored this many values: " << count << endl;
  cout << "THe index-value pairs are: " << endl << endl;

  for (int i = 0; i < flag.capacity(); i++) {
	if (flag[i]) {
	  cout << i << " => " << array[i] << endl;
	}
  }

  cout << endl;
  while (true) {
	cout << "Input an index for me to look up [Q to quit]: ";
	cin >> buf;
	if (buf == "Q" || buf == "q") {
	  break;
	}
	int index = atoi(buf.c_str());
	if (flag[index] && array[index] != array[-1]) {
	  cout << "Found it -- the value stored at " << index << " is " << array[index] << endl;
	}
	else {
	  cout << "I didn't find it" << endl;
	}
  }
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
