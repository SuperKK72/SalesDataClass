#pragma once
#include <iostream>
#include <string>

class Sales_data {
//友元声明
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream& read(std::istream&, Sales_data&);
friend std::ostream& print(std::ostream&, const Sales_data&);
friend std::ostream& operator<<(std::ostream&, const Sales_data&);
friend std::istream& operator>>(std::istream&, Sales_data&);
friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
	//构造函数
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p):
				bookNo(s), uints_sold(n), revenue(p*n) {}
	Sales_data(const std::string &s): bookNo(s) {}
	Sales_data(std::istream&);
	//返回书籍的isbn号
	std::string isbn() const { return bookNo; }
	//执行Sales_data的+=操作，related to be replaced by += operator
	Sales_data& combine(const Sales_data&);
	Sales_data& operator+=(const Sales_data&);

private:
	double avg_price() const { return uints_sold ? revenue / uints_sold : 0; }
	std::string bookNo;//书籍的isbn号
	unsigned uints_sold = 0;//书籍的售出数目
	double revenue = 0.;//书籍的销售额

};

Sales_data add(const Sales_data&, const Sales_data&);

std::istream& read(std::istream&, Sales_data&);

std::ostream& print(std::ostream&, const Sales_data&);
//输入输出运算符必须为非成员函数
std::ostream& operator<<(std::ostream&, const Sales_data&);

std::istream& operator>>(std::istream&, Sales_data&);

Sales_data operator+(const Sales_data&, const Sales_data&);







