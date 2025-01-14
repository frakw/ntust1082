#pragma once
class Creature;
class Character;//不可include 標頭檔，會出現遺漏類型規範-假設為int
class Monster;//不可include 標頭檔，會出現遺漏類型規範-假設為int
using namespace std;

class Map {
public:
	Map();
	Map(int in_row, int in_col);
	~Map();
	void set(string input);
	void choose_pos(int,string);//int為第幾隻腳色，string 為wasd
	void set_choosing_environment();//變更選擇位置的char與怪物位置的char
	void show_choosing_room();//選擇時專用的顯示地圖
	bool check_room();//檢查可視範圍，可視座標show[y][x]設為true，有開門則回傳true
	void fill_room(Coord pos);//遞迴函式，由check_room呼叫
	void show_room();//呼叫前記得先check找出可視範圍
	void update_all_creature();//更新生物位置，或死亡刪除
	Coord& find_pos(Coord*, int max, Coord pos);
	int now_monster_amount();//目前場上怪物數(活著)
	int door_amount();//門剩餘的數量
	Creature* creature_in(Coord);//回傳該座標的生物指標，沒有則回傳nullptr
	char& coord_in_body(Coord);//回傳該座標的char
	bool coord_legal(Coord);//檢查該座標是否合法
	void check();//角色行動前，輸入check，要列出所有角色與怪物的hp與防禦值

	int a_star_path_step(Creature*, Creature*);//A星演算法找尋最短步數
	bool in_vision(Coord, Coord);//線性差值法
	int row=0, col=0;
	char** body = nullptr;//地圖主體
	bool** show = nullptr;//是否在視野內
	Coord star_pos;//星星位置
	Coord start_pos[4];//可選位置，設為-1,-1代表已選擇
	Coord fill_start;//遞迴起始位置，預設start_pos[0]
	Coord* door_pos = nullptr;//門的位置，開門後記得設為-1,-1
	int door_total_amount = 0;//總共門的數量(輸入地圖時計算)

	Character* character = nullptr;//角色陣列頭指標
	int character_amount = 0;//角色陣列數量
	Monster* monster = nullptr;//怪物陣列頭指標
	int monster_amount = 0;//怪物陣列數量
};