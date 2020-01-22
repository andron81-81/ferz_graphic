#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
//using namespace sf;
using namespace sf;

const int l = 50;
//const int a = 50;

int x = 10;
float qtyferz = 0.01;
bool q;
float desk[8][8];
float deskResult[8][8];

int qty = 0;

bool pometit_bityie_kletki(int x, int y);
void copyArray();
bool tryferz(int i);
bool full();
void printMatrix();
bool full() {
	float p = 1;
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j <= 7; j++) {
			p = p * desk[i][j];
		}
	} return (p != 0);
		

	
}

int GetYFerz(int x);

bool pometit_bityie_kletki(int x, int y) {
	int ff=0;
	int x1, y1;
	//сначала проверим , а можно ли ставить
	//проверим вертикали и горизонтали
	if (desk[x][y] != 0) { return false; }
	if (x < 7) {
		for (int i = x; i < 7; i++) {
			//desk[x][y]++;
			if (desk[i][y] >0 && desk[i][y]<1) { ff = 555; return false; }
		}
	}
	if (y < 7) {
		for (int i = y; i < 7; i++) {
			//desk[x][y]++;
			if (desk[x][i] >0 && desk[x][i]<1) { ff = 555; return false; }
		}
	}


	if (x > 1) {
		for (int i = 0; i < x - 1; i++) {
			//desk[x][y]++;
			if (desk[i][y] > 0 && desk[i][y]<1) { ff = 555; return false; }
		}
	}
	if (y > 1) {
		for (int i = 0; i < y - 1; i++) {
			//desk[x][y]++;
			if (desk[x][i]>0 && desk[x][i]<1) { ff = 555; return false; }
		}
	}
	
	//проверим диагонали 
	x1 = x - 1;
	y1 = y - 1;
	while (x1 >= 0 && y1 >= 0) {
		if (desk[x1][y1] > 0 && desk[x1][y1]<1) { ff = 555; return false; }
		x1 = x1 - 1;
		y1 = y1 - 1;
	}

	x1 = x + 1;
	y1 = y + 1;
	while (x1 <= 7 && y1 <= 7) {
		if (desk[x1][y1] > 0 && desk[x1][y1]<1) { ff = 555; return false; }
		x1 = x1 + 1;
		y1 = y1 + 1;
	}

	x1 = x + 1;
	y1 = y - 1;
	while (x1 <= 7 && y1 >= 0) {
		if (desk[x1][y1] > 0 && desk[x1][y1]<1) { ff = 555; return false; }
		x1 = x1 + 1;
		y1 = y1 - 1;
	}

	x1 = x - 1;
	y1 = y + 1;
	while (y1 <= 7 && x1 >= 0) {
		if (desk[x1][y1] > 0 && desk[x1][y1]<1) { ff = 555; return false; }
		x1 = x1 - 1;
		y1 = y1 + 1;
	}


	


	if (x < 7) {
		for (int i = x+1; i <= 7; i++) {
			desk[i][y]++;
			}
	}
	if (y < 7) {
		for (int i = y+1; i <= 7; i++) {
			desk[x][i]++;
			
		}
	}


	if (x > 0) {
		for (int i = 0; i <= x - 1; i++) {
			desk[i][y]++;
			
		}
	}
	if (y > 0) {
		for (int i = 0; i <= y - 1; i++) {
			desk[x][i]++;
		
		}
	}

	//закрасим диагонали 
	x1 = x - 1;
	y1 = y - 1;
	while (x1 >= 0 && y1 >= 0) {
		desk[x1][y1]++;
		x1 = x1 - 1;
		y1 = y1 - 1;
	}

	x1 = x + 1;
	y1 = y + 1;
	while (x1 <= 7 && y1 <= 7) {
		desk[x1][y1]++;
		x1 = x1 + 1;
		y1 = y1 + 1;
	}

	x1 = x + 1;
	y1 = y - 1;
	while (x1 <= 7 && y1 >= 0) {
		desk[x1][y1]++;
		x1 = x1 + 1;
		y1 = y1 - 1;
	}

	x1 = x - 1;
	y1 = y + 1;
	while (y1 <= 7 && x1 >= 0) {
		desk[x1][y1]++;
		x1 = x1 - 1;
		y1 = y1 + 1;
	}


	desk[x][y] = qtyferz;
	return true;
}


void ubrat_ferzy(int x, int y) {
	int ff = 0;
	int x1, y1;
	





	if (x < 7) {
		for (int i = x + 1; i <= 7; i++) {
			desk[i][y]--;
		}
	}
	if (y < 7) {
		for (int i = y + 1; i <= 7; i++) {
			desk[x][i]--;

		}
	}


	if (x > 0) {
		for (int i = 0; i <= x - 1; i++) {
			desk[i][y]--;

		}
	}
	if (y > 0) {
		for (int i = 0; i <= y - 1; i++) {
			desk[x][i]--;

		}
	}

	//закрасим диагонали 
	x1 = x - 1;
	y1 = y - 1;
	while (x1 >= 0 && y1 >= 0) {
		desk[x1][y1]--;
		x1 = x1 - 1;
		y1 = y1 - 1;
	}

	x1 = x + 1;
	y1 = y + 1;
	while (x1 <= 7 && y1 <= 7) {
		desk[x1][y1]--;
		x1 = x1 + 1;
		y1 = y1 + 1;
	}

	x1 = x + 1;
	y1 = y - 1;
	while (x1 <= 7 && y1 >= 0) {
		desk[x1][y1]--;
		x1 = x1 + 1;
		y1 = y1 - 1;
	}

	x1 = x - 1;
	y1 = y + 1;
	while (y1 <= 7 && x1 >= 0) {
		desk[x1][y1]--;
		x1 = x1 - 1;
		y1 = y1 + 1;
	}


	desk[x][y] = 0;
	
}


bool tryferz(int i) {
	bool tupic = false;
	for (int j = 0; j <= 7; j++) {
		q = pometit_bityie_kletki(i, j);
		if (q == true) {
			//cout << "Add Queen:" << endl;  printMatrix(); 
			qty++;
			tupic = tryferz(i + 1);
		}
		if (tupic) {
			ubrat_ferzy(i, j);
			qty--;
			//cout << "Del Queen:" << endl;  printMatrix();
			tupic = false; //убираем индикатор тупика
		}

		if (qty == 8) { 
			copyArray();
		}

	} 	return true;
}


void printMatrix() {
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++) {
			if (desk[i][j] < 1 && desk[i][j] > 0) { cout << "F"; }
			else { cout << desk[i][j]; }
		}
		cout << endl;
	}
	cout << endl;
}

int GetYFerz(int x) {
	for (int i = 0; i <= 7; i++) {

		if (deskResult[i][x] < 1 && deskResult[i][x] > 0) { return i; }
	}

}


void copyArray() {

	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++) {
			deskResult[i][j] = desk[i][j];
		}
	}


}

int main()
{
	

tryferz(0);

//	return 0;
printMatrix();

	RenderWindow window(VideoMode(l * 8, l * 8), "Chess");
	RectangleShape rectangle0(Vector2f(l, l));
	RectangleShape rectangle1(Vector2f(l, l));
	RectangleShape rectangle2(Vector2f(l, l));
	RectangleShape rectangle3(Vector2f(l, l));
	RectangleShape rectangle4(Vector2f(l, l));
	RectangleShape rectangle5(Vector2f(l, l));
	RectangleShape rectangle6(Vector2f(l, l));
	RectangleShape rectangle7(Vector2f(l, l));
	RectangleShape rectangle8(Vector2f(l, l));
	RectangleShape rectangle9(Vector2f(l, l));
	RectangleShape rectangle10(Vector2f(l, l));
	RectangleShape rectangle11(Vector2f(l, l));
	RectangleShape rectangle12(Vector2f(l, l));
	RectangleShape rectangle13(Vector2f(l, l));
	RectangleShape rectangle14(Vector2f(l, l));
	RectangleShape rectangle15(Vector2f(l, l));


	RectangleShape rectangle16(Vector2f(l, l));
	RectangleShape rectangle17(Vector2f(l, l));
	RectangleShape rectangle18(Vector2f(l, l));
	RectangleShape rectangle19(Vector2f(l, l));
	RectangleShape rectangle20(Vector2f(l, l));
	RectangleShape rectangle21(Vector2f(l, l));
	RectangleShape rectangle22(Vector2f(l, l));
	RectangleShape rectangle23(Vector2f(l, l));
	RectangleShape rectangle24(Vector2f(l, l));
	RectangleShape rectangle25(Vector2f(l, l));
	RectangleShape rectangle26(Vector2f(l, l));
	RectangleShape rectangle27(Vector2f(l, l));
	RectangleShape rectangle28(Vector2f(l, l));
	RectangleShape rectangle29(Vector2f(l, l));
	RectangleShape rectangle30(Vector2f(l, l));
	RectangleShape rectangle31(Vector2f(l, l));

	Texture texture;

	texture.loadFromFile("resources/ferz.png");


	Sprite sprite0(texture);
	Sprite sprite1(texture);
	Sprite sprite2(texture);
	Sprite sprite3(texture);
	Sprite sprite4(texture);
	Sprite sprite5(texture);
	Sprite sprite6(texture);
	Sprite sprite7(texture);



	sprite0.setPosition(l*0, l*GetYFerz(0)); // сначала сдвинем наш спрайт вниз
	sprite0.setScale(0.3f, 0.9f); // абсолютное значение масштаба
	sprite0.setScale(0.05f, 0.05f);

	sprite1.setPosition(l*1, l * GetYFerz(1)); // сначала сдвинем наш спрайт вниз
	sprite1.setScale(0.3f, 0.9f); // абсолютное значение масштаба
	sprite1.setScale(0.05f, 0.05f);

	sprite2.setPosition(l*2, l * GetYFerz(2)); // сначала сдвинем наш спрайт вниз
	sprite2.setScale(0.3f, 0.9f); // абсолютное значение масштаба
	sprite2.setScale(0.05f, 0.05f);

	sprite3.setPosition(l*3, l * GetYFerz(3)); // сначала сдвинем наш спрайт вниз
	sprite3.setScale(0.3f, 0.9f); // абсолютное значение масштаба
	sprite3.setScale(0.05f, 0.05f);

	sprite4.setPosition(l*4, l * GetYFerz(4)); // сначала сдвинем наш спрайт вниз
	sprite4.setScale(0.3f, 0.9f); // абсолютное значение масштаба
	sprite4.setScale(0.05f, 0.05f);

	sprite5.setPosition(l*5, l * GetYFerz(5)); // сначала сдвинем наш спрайт вниз
	sprite5.setScale(0.3f, 0.9f); // абсолютное значение масштаба
	sprite5.setScale(0.05f, 0.05f);

	sprite6.setPosition(l*6, l * GetYFerz(6)); // сначала сдвинем наш спрайт вниз
	sprite6.setScale(0.3f, 0.9f); // абсолютное значение масштаба
	sprite6.setScale(0.05f, 0.05f);

	sprite7.setPosition(l*7, l * GetYFerz(7)); // сначала сдвинем наш спрайт вниз
	sprite7.setScale(0.3f, 0.9f); // абсолютное значение масштаба
	sprite7.setScale(0.05f, 0.05f);




	//sprite.scale(1.5, 0.9);
	//sprite.move(10, 10);
	//sprite.

   //rectangle0.move(50, 0);
	rectangle1.move(l * 2, 0);
	rectangle2.move(l * 4, 0);
	rectangle3.move(l * 6, 0);

	rectangle4.move(l * 1, l);
	rectangle5.move((l * 3), l);
	rectangle6.move(l * 5, l);
	rectangle7.move(l * 7, l);


	rectangle8.move(l * 0, 2 * l);
	rectangle9.move(l * 2, 2 * l);
	rectangle10.move(l * 4, 2 * l);
	rectangle11.move(l * 6, 2 * l);

	rectangle12.move(l * 1, 3 * l);
	rectangle13.move((l * 3), 3 * l);
	rectangle14.move(l * 5, 3 * l);
	rectangle15.move(l * 7, 3 * l);

	rectangle16.move(l * 0, 4 * l);
	rectangle17.move(l * 2, 4 * l);
	rectangle18.move(l * 4, 4 * l);
	rectangle19.move(l * 6, 4 * l);

	rectangle20.move(l * 1, 5 * l);
	rectangle21.move((l * 3), 5 * l);
	rectangle22.move(l * 5, 5 * l);
	rectangle23.move(l * 7, 5 * l);

	rectangle24.move(l * 0, 6 * l);
	rectangle25.move(l * 2, 6 * l);
	rectangle26.move(l * 4, 6 * l);
	rectangle27.move(l * 6, 6 * l);

	rectangle28.move(l * 1, 7 * l);
	rectangle29.move((l * 3), 7 * l);
	rectangle30.move(l * 5, 7 * l);
	rectangle31.move(l * 7, 7 * l);


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//if (Keyboard::isKeyPressed(Keyboard::D)) { sprite.setPosition(l, 0); };
		//if (Keyboard::isKeyPressed(Keyboard::S)) { sprite.setPosition(0, l); };
		window.clear();
		window.draw(rectangle0);
		window.draw(rectangle1);
		window.draw(rectangle2);
		window.draw(rectangle3);
		window.draw(rectangle4);
		window.draw(rectangle5);
		window.draw(rectangle6);
		window.draw(rectangle7);
		window.draw(rectangle8);
		window.draw(rectangle9);
		window.draw(rectangle10);
		window.draw(rectangle11);

		window.draw(rectangle12);
		window.draw(rectangle13);
		window.draw(rectangle14);
		window.draw(rectangle15);

		window.draw(rectangle16);
		window.draw(rectangle17);
		window.draw(rectangle18);
		window.draw(rectangle19);

		window.draw(rectangle20);
		window.draw(rectangle21);
		window.draw(rectangle22);
		window.draw(rectangle23);

		window.draw(rectangle24);
		window.draw(rectangle25);
		window.draw(rectangle26);
		window.draw(rectangle27);

		window.draw(rectangle28);
		window.draw(rectangle29);
		window.draw(rectangle30);
		window.draw(rectangle31);
		window.draw(sprite0);
		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);
		window.draw(sprite5);
		window.draw(sprite6);
		window.draw(sprite7);



		window.display();

	}
	return 0;

}


