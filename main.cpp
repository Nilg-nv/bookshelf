#include <iostream>
#include "Book.h"
#include "PrintBook.h"
#include "Shelf.h"
#include "BShelf.h"
#include<cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	system ("chcp 1251");
	//Режим работы
	int mode = -1;
	//Шкафы
	vector <BookShelf> bshelfs;
	BookShelf bshelf; //Пустой шкаф
	while(mode!=0){//mode = 0 - ВЫХОД
		cout<<"-= МЕНЮ =- "<<endl;
		cout<<"1.Добавить шкаф."<<endl;
		cout<<"2.Добавить полку в шкаф."<<endl;
		cout<<"3.Добавить книгу."<<endl;
		cout<<"4.Вывод на экран."<<endl;
		cout<<"0.Выход."<<endl;
		cout<<"Введите номер и нажмите <ENTER>"<<endl;
		cin >> mode;
		switch(mode){
			case 0: continue; //Прекращает итерацию цикла
			case 1: //Добавить шкаф
				
				bshelfs.push_back(bshelf);
				cout<<"Шкаф добавлен!"<<endl<<endl;
				break;
			case 2: //Добавить полку в шкаф
				if(bshelfs.size()>0){//Проверка на наличие шкафов
					cout<<"Доступно "<<bshelfs.size()<<" шкафов"<<endl;
					cout<<"Введите номер шкафа (от 1 до "<<bshelfs.size()<<"): ";
					int n = 0;
					cin>>n;
					if(n>0 && n<=bshelfs.size()){//Проверка на допустимость значения
						bshelfs[n-1].addShelf();
						cout<<"Полка добавлена."<<endl<<endl;
					}else {
						cout<<"Ошибка в номере шкафа. Повторите. "<<endl<<endl;
					}
				}else {
					cout<<"Доступные шкафы отсутствуют!"<<endl<<endl;
				}
				break;
			case 3: //Добавить книгу
				if(bshelfs.size()>0){//Проверка на наличие шкафов
					cout<<"Доступно "<<bshelfs.size()<<" шкафов"<<endl;
					cout<<"Введите номер шкафа (от 1 до "<<bshelfs.size()<<"): ";
					int n = 0;
					cin>>n;
					if(n>0 && n<=bshelfs.size()){//Проверка на допустимость значения
						cout<<"Доступно: "<<bshelfs[n-1].SizeShel()<<" полок"<<endl;
						cout<<"Введите номер полки (от 1 до "<<bshelfs[n-1].SizeShel()<<"): ";
						int k = 0;
						cin>>k;
						if(k>0 && k<=bshelfs[n-1].SizeShel()){//Проверка на допустимость значений
						
							string i1;
							int i2;
							PrintBook pb;
							cout<<"Введите название книги: ";
							cin>>i1;
							cout<<"Введите количество страниц: ";
							cin>>i2;
							pb.setName(i1);
							pb.setPages(i2);
							bshelfs[n-1].addBook(pb, k-1);
						}else {
							cout<<"Ошибка в номере полки. Повтрите. "<<endl<<endl;
						}
					}else {
						cout<<"Ошибка в номере шкафа. Повторите. "<<endl<<endl;
					}
				}else{
					cout<<"Доступные шкафы отсутствуют!"<<endl<<endl;
				}
			break;
			case 4:
				if(bshelfs.size()>0){//Проверка на наличие шкафов
					for(int i=0; i<bshelfs.size();i++){
						bshelfs[i].Print();
						
						
					}
				}else{
					cout<<"Доступные шкафы отсутствуют!"<<endl<<endl;
				}
		}
	}
	return 0;
}
