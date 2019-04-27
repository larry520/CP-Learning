#pragma once
class Arry
{
public:
	Arry(int m_ilen);
	~Arry();
	void setLen(int m_ilen);
	int get() const;
	void printInfo();
private:
	int m_iLen;
};

