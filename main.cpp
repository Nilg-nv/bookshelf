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
	//����� ������
	int mode = -1;
	//�����
	vector <BookShelf> bshelfs;
	BookShelf bshelf; //������ ����
	while(mode!=0){//mode = 0 - �����
		cout<<"-= ���� =- "<<endl;
		cout<<"1.�������� ����."<<endl;
		cout<<"2.�������� ����� � ����."<<endl;
		cout<<"3.�������� �����."<<endl;
		cout<<"4.����� �� �����."<<endl;
		cout<<"0.�����."<<endl;
		cout<<"������� ����� � ������� <ENTER>"<<endl;
		cin >> mode;
		switch(mode){
			case 0: continue; //���������� �������� �����
			case 1: //�������� ����
				
				bshelfs.push_back(bshelf);
				cout<<"���� ��������!"<<endl<<endl;
				break;
			case 2: //�������� ����� � ����
				if(bshelfs.size()>0){//�������� �� ������� ������
					cout<<"�������� "<<bshelfs.size()<<" ������"<<endl;
					cout<<"������� ����� ����� (�� 1 �� "<<bshelfs.size()<<"): ";
					int n = 0;
					cin>>n;
					if(n>0 && n<=bshelfs.size()){//�������� �� ������������ ��������
						bshelfs[n-1].addShelf();
						cout<<"����� ���������."<<endl<<endl;
					}else {
						cout<<"������ � ������ �����. ���������. "<<endl<<endl;
					}
				}else {
					cout<<"��������� ����� �����������!"<<endl<<endl;
				}
				break;
			case 3: //�������� �����
				if(bshelfs.size()>0){//�������� �� ������� ������
					cout<<"�������� "<<bshelfs.size()<<" ������"<<endl;
					cout<<"������� ����� ����� (�� 1 �� "<<bshelfs.size()<<"): ";
					int n = 0;
					cin>>n;
					if(n>0 && n<=bshelfs.size()){//�������� �� ������������ ��������
						cout<<"��������: "<<bshelfs[n-1].SizeShel()<<" �����"<<endl;
						cout<<"������� ����� ����� (�� 1 �� "<<bshelfs[n-1].SizeShel()<<"): ";
						int k = 0;
						cin>>k;
						if(k>0 && k<=bshelfs[n-1].SizeShel()){//�������� �� ������������ ��������
						
							string i1;
							int i2;
							PrintBook pb;
							cout<<"������� �������� �����: ";
							cin>>i1;
							cout<<"������� ���������� �������: ";
							cin>>i2;
							pb.setName(i1);
							pb.setPages(i2);
							bshelfs[n-1].addBook(pb, k-1);
						}else {
							cout<<"������ � ������ �����. ��������. "<<endl<<endl;
						}
					}else {
						cout<<"������ � ������ �����. ���������. "<<endl<<endl;
					}
				}else{
					cout<<"��������� ����� �����������!"<<endl<<endl;
				}
			break;
			case 4:
				if(bshelfs.size()>0){//�������� �� ������� ������
					for(int i=0; i<bshelfs.size();i++){
						bshelfs[i].Print();
						
						
					}
				}else{
					cout<<"��������� ����� �����������!"<<endl<<endl;
				}
		}
	}
	return 0;
}
