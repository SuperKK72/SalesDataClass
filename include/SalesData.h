#pragma once
#include <iostream>
#include <string>

class Sales_data {
//��Ԫ����
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream& read(std::istream&, Sales_data&);
friend std::ostream& print(std::ostream&, const Sales_data&);
friend std::ostream& operator<<(std::ostream&, const Sales_data&);
friend std::istream& operator>>(std::istream&, Sales_data&);
friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
	//���캯��
	Sales_data() = default;
	Sales_data(const std::string &s, unsigned n, double p):
				bookNo(s), uints_sold(n), revenue(p*n) {}
	Sales_data(const std::string &s): bookNo(s) {}
	Sales_data(std::istream&);
	//�����鼮��isbn��
	std::string isbn() const { return bookNo; }
	//ִ��Sales_data��+=������related to be replaced by += operator
	Sales_data& combine(const Sales_data&);
	Sales_data& operator+=(const Sales_data&);

private:
	double avg_price() const { return uints_sold ? revenue / uints_sold : 0; }
	std::string bookNo;//�鼮��isbn��
	unsigned uints_sold = 0;//�鼮���۳���Ŀ
	double revenue = 0.;//�鼮�����۶�

};

Sales_data add(const Sales_data&, const Sales_data&);

std::istream& read(std::istream&, Sales_data&);

std::ostream& print(std::ostream&, const Sales_data&);
//����������������Ϊ�ǳ�Ա����
std::ostream& operator<<(std::ostream&, const Sales_data&);

std::istream& operator>>(std::istream&, Sales_data&);

Sales_data operator+(const Sales_data&, const Sales_data&);







