#include <iostream>
#include <fstream>
#include <string>
#include "Abonent.cpp"
#include "Phone_book.cpp"
using namespace std;

int main()
{
	Abonent ab1("Michael", "Jones", "Boricovich", 320024, 3349, 89289999999);
	Abonent ab2("Dasha", "Brooks", "Alexandrovna", 123424, 2134, 89230412312);
	Abonent ab3("James", "Lanister", "Ivanovich", 121743, 1247, 89499564375);
	Abonent ab4("James", "Lanister", "Ivanovich", 121743, 1247, 89499564375, "princess");
	Phone_book pb(ab1);
	pb.addAb(ab2);
	cout << "before: " << endl;
	pb.print();
	pb.delAb(0);
	pb.addAb(ab3);
	cout << "after: " << endl;
	pb.print();
	pb.addAb(ab1);
	pb.addAb(ab4);
	cout << endl;
	pb.print();
	pb.addInfo(pb.search_firstName("Dasha"), "Proud inhabitant of Middle-earth");
	pb.addInfo(pb.search_lastName("Jones"), "Handsome descendant of the royal family");
	pb.addInfo(pb.search_othestvo("Ivanovich"), "The brave conqueror of Africa");
	cout << endl;
	pb.print();
	cout << endl;
	string path = "..\\text.txt";
	pb.saveInFile(path);
	cout << "read of file: " << endl;
	pb.readFile(path);
}