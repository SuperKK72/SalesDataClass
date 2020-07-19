// SalesData.cpp : 定义静态库的函数。
//
#include "framework.h"
#include "SalesData.h"
#include <cassert>
//#include <iostream>

Sales_data::Sales_data(std::istream& is) {
	read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data& item) {
	assert(bookNo == item.bookNo);
	uints_sold += item.uints_sold;
	revenue += item.revenue;
	return *this;
}

Sales_data add(const Sales_data& item1, const Sales_data& item2) {
	assert(item1.bookNo == item2.bookNo);
	Sales_data item;
	item.bookNo = item1.bookNo;
	item.uints_sold = item1.uints_sold + item2.uints_sold;
	item.revenue = item1.revenue + item2.revenue;
	return item;
	
}

std::istream& read(std::istream& is, Sales_data& item) {
	double price = 0.;
	is >> item.bookNo >> item.uints_sold >> price;
	item.revenue = item.uints_sold * price;
	return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item) {
	os << item.bookNo << '\t' << item.uints_sold << '\t' <<
		item.revenue << '\t' << item.avg_price();
	return os;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.uints_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

std::istream& operator>>(std::istream& is, Sales_data& item) {
	double price = 0.;
	is >> item.bookNo >> item.uints_sold >> price;
	if (is) {
		item.revenue = item.uints_sold * price;
	}
	else {
		item = Sales_data();
	}
	return is;

}

Sales_data& Sales_data::operator+=(const Sales_data& item) {
	assert(bookNo == item.bookNo);
	uints_sold += item.uints_sold;
	revenue += item.revenue;
	return *this;
}

Sales_data operator+(const Sales_data& item1, const Sales_data& item2) {
	Sales_data sum = item1;
	sum += item2;
	return sum;
}





// TODO: 这是一个库函数示例

